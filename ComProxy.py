import serial 
import serial.tools.list_ports
from threading import Timer
import time
import socket
import json
import sys
import threading

HOST = ''
PORT = 33025
ADDR = (HOST, PORT)
BUFFSIZE = 1024

MAX_LISTEN = 1
TIMEOUT_S=20
gbLog=True

# global variables
g_bClientAlive=False
g_iClientOnlineCounter=0
socketTaskLock = threading.Lock()
g_OpenedComs={}    #store all registered Com object portname:cCOMPort
g_socketSendTasks=[] #list of string for socket send out in order

def SLog(str):
   if gbLog:
      print(str)

def ontime():   
   global g_iClientOnlineCounter
   global g_bClientAlive
   if g_bClientAlive:
      g_iClientOnlineCounter+=1  
      if g_iClientOnlineCounter>TIMEOUT_S :
         SLog("Long Time No Valid Recv,Time out:"+str(g_iClientOnlineCounter))
         g_iClientOnlineCounter=0
         g_bClientAlive=False         
   Timer(1, ontime,()).start() #counter to assert offline without message from client over 12s    

def CloseAllComPort():
   for strComName,cobj in g_OpenedComs.items():
      cobj.Close()      
   SLog("maybe client offline all comport closed")
   

 
class cCOMPort():
   def __init__(self, strPort):
      self.Name=strPort
      self.bOpen=False
      self.Cobj=None
      self.Tasklist=[]
      self.threadLock = threading.Lock()   
   def Open(self,paudrate,parity):
      try:         
         self.Cobj=serial.Serial(self.Name, paudrate, timeout=0)
         self.Cobj.parity=serial.PARITY_EVEN if parity==2 else serial.PARITY_NONE     
         self.bOpen=True
      except Exception as e:
         SLog('Except on Com Open:'+str(e))
         self.bOpen=False
         self.Cobj=None
      if(self.bOpen):
         SLog(self.Name+" Opened...")
         threading.Thread(target=self.ReadTaskLoop).start()
         threading.Thread(target=self.WriteTaskLoop).start()
   def Close(self):
      if self.bOpen and self.Cobj!=None:
         self.Cobj.close()
         self.bOpen=False
         self.Cobj=None
         SLog(self.Name+" Closed!")
   def ReadTaskLoop(self):  
      SLog(self.Name+" Read Thread starts...") 
      while self.bOpen:
         try:
            if (self.Cobj.in_waiting>0):
               strHexRead=self.Cobj.read(self.Cobj.in_waiting).hex()
               SLog(self.Name+' Read: '+strHexRead)
               rtDic={"Cmd":'ComRead' ,'PortName':self.Name,'dataRead':strHexRead} #return json "Cmd":'ComRead'
               strRt=json.dumps(rtDic)
               SocketSendTask_Append(strRt) #Sent to client without any check            
            else:
               time.sleep(0.05)  #sleep 50ms
         except Exception as e:
            SLog(self.Name+" Error on Read: "+str(e))
      self.bOpen=False
      SLog(self.Name+" Read Thread End!")
   def WriteTaskLoop(self):
      SLog(self.Name+" Write Thread starts...") 
      while self.bOpen:
         if len(self.Tasklist)>0:
            self.threadLock.acquire()
            strHexSend=self.Tasklist.pop(0)
            self.threadLock.release()
            SLog(self.Name+' Write: '+strHexSend)
            try:
               self.Cobj.write(bytes.fromhex(strHexSend))               
               time.sleep(0.05)
               continue
            except Exception as e:
               SLog(self.Name+" Error on Write: "+str(e))
               break
         else:
            time.sleep(0.1)
      self.bOpen=False
      SLog(self.Name+" Write Thread End!")
            
   def AppendSendStr(self,str):
      self.threadLock.acquire()
      self.Tasklist.append(str)
      self.threadLock.release()
   def __del__(self):
      self.Close()
#cCOMPort 
def Proc_OpenPort(dic):
   '''Process OpenPort Command'''
   strPortName=dic.get('PortName','COM5')
   if strPortName in g_OpenedComs:
      tempCobj=g_OpenedComs[strPortName]
      tempCobj.Close() 
   else:
      tempCobj=cCOMPort(strPortName)
      g_OpenedComs[strPortName]=tempCobj
   baudrate=dic.get('PaudRate',9600)
   parity=dic.get('Parity',0)
   tempCobj.Open(baudrate,parity) 
   if tempCobj.bOpen:
      rtDic={"Cmd":'PortOpen' ,'PortName':strPortName}   #return json "Cmd":'PortOpen'
   else:
      rtDic={"Cmd":'PortOpenErr' ,'PortName':strPortName} #return json "Cmd":'PortOpenErr'
   strRt=json.dumps(rtDic)
   SocketSendTask_Append(strRt)    
def Proc_ClosePort(dic):
   '''Process ClosePort Command'''
   strPortName=dic.get('PortName','COM5')
   if strPortName in g_OpenedComs:
      tempCobj=g_OpenedComs[strPortName]
      tempCobj.Close() 
   rtDic={"Cmd":'PortClose' ,'PortName':strPortName}
   strRt=json.dumps(rtDic)
   SocketSendTask_Append(strRt)
def Proc_Write(dic):
   strPortName=dic.get('PortName')
   if strPortName in g_OpenedComs:
      tempCobj=g_OpenedComs[strPortName]
      if tempCobj.bOpen:
         strWrite=dic.get('dataWrite',' ') # 
         tempCobj.AppendSendStr(strWrite)
      else:
         rtDic={"Cmd":'PortClose' ,'PortName':strPortName}
         strRt=json.dumps(rtDic)
         SocketSendTask_Append(strRt)
   else:
      rtDic={"Cmd":'PortClose' ,'PortName':strPortName}    #return json "Cmd":'PortClose'
      strRt=json.dumps(rtDic)
      SocketSendTask_Append(strRt)
def Proc_HeartBeat(dic):
   SLog("HeartBeat")
   pass

g_dicFuncForRecv={'OpenComPort':Proc_OpenPort,'CloseComPort':Proc_ClosePort}
g_dicFuncForRecv['ComWrite']=Proc_Write
g_dicFuncForRecv['HeartBeat']=Proc_HeartBeat
def ServerLoop(c,addr):
   global g_bClientAlive,g_iClientOnlineCounter
   SLog('Socket waithing for message...') 
   while g_bClientAlive:
      try:                         
         data = c.recv(BUFFSIZE)         
         if len(data)<6:
            continue
         g_iClientOnlineCounter=0            #still online counter
         strRec=data.decode('utf-8')         #byte array ->string
         SLog("Socket Received: "+strRec)     #output for debug
         dicRec=json.loads(strRec)            #string -> json
         if 'Cmd' in dicRec:
            strCmd=dicRec['Cmd']              #fetch the command code 
            if strCmd in g_dicFuncForRecv:
               g_dicFuncForRecv[strCmd](dicRec)    #call the corresponding function to process 
            else:
               SLog("UnRegister Command: "+strCmd)  #unknown command code
         else:
            SLog('Socket read a Json without "Cmd" Key')   #didnot find a command code       
      except  ConnectionResetError as e:
         SLog('Except on Server Receive Loop:'+str(e))             #network exception processing
         g_bClientAlive=False
         break
      except Exception as e:
         SLog('Except on Server Receive Loop:'+str(e))             #other exception processing         
         continue
   SLog('Main Thread: Socket Reading Loop End!')          #Loop end

def SocketSendTask_Thread(c):      
   '''socket send thread'''
   global g_bClientAlive,g_socketSendTasks,socketTaskLock
   SLog("SocketSent Thread Starts....")
   while g_bClientAlive:      
      if len(g_socketSendTasks)>0:
         socketTaskLock.acquire()
         strSocketSend=g_socketSendTasks.pop(0)
         socketTaskLock.release()
         try:  
            c.send(strSocketSend.encode('utf-8'))
            SLog("Socket send: "+strSocketSend)
         except Exception as e:            
            SLog('Except on SocketSendTask_Thread:'+str(e))
            break
         time.sleep(0.02)
      else:
         time.sleep(0.05)
   g_bClientAlive=False    
   SLog("SocketSent Thread End!")

def SocketSendTask_Append(strSend):
   '''Append a string for send to client by Socket send thread'''
   global g_socketSendTasks
   socketTaskLock.acquire()
   g_socketSendTasks.append(strSend)
   socketTaskLock.release()
def SocketSendTask_Reset():
   global g_socketSendTasks
   socketTaskLock.acquire()
   g_socketSendTasks.clear()
   socketTaskLock.release()

if __name__ == '__main__':   
   port_list = list(serial.tools.list_ports.comports()) #get Comport info and saved into a list
   if len(port_list) == 0:
      SLog('There is no Com Port available')
      exit(2)
   else:
      SLog("There are Com ports:")
      tSendDic={}
      tSendDic['Cmd']='ComInfo'
      tSendDic['ComNum']=len(port_list)
      for i in range(0,len(port_list)):
         tSendDic[str(i)]=port_list[i].device
         print(port_list[i].device)
      g_strComlist=json.dumps(tSendDic)
   Timer(1, ontime,()).start() #counter to assert offline without message from client over 12s  

   socketServer= socket.socket(socket.AF_INET, socket.SOCK_STREAM)         # create socket object,TCP Server
   socketServer.bind(ADDR)        
   socketServer.listen(MAX_LISTEN)
   
   while True:
      SLog('Main Thread: waiting for client ...\n')
      c,addr = socketServer.accept()     # accept and build a connection
      SLog('Main Thread: get a connect from:{}'.format(addr))
      c.setblocking(False)
      c.settimeout(TIMEOUT_S+2)
      g_bClientAlive=True
      threading.Thread(target=SocketSendTask_Thread,args=(c,)).start()
      SocketSendTask_Append(g_strComlist)      
      ServerLoop(c,addr)    
      g_bClientAlive=False         
      c.close() # close the connection
      CloseAllComPort()
      SocketSendTask_Reset()
      time.sleep(3)
      continue
     
      

