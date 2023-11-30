/****************************************************************************
** Meta object code from reading C++ file 'cremotecom.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cremotecom.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cremotecom.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CRemoteComConn_t {
    QByteArrayData data[17];
    char stringdata0[192];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CRemoteComConn_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CRemoteComConn_t qt_meta_stringdata_CRemoteComConn = {
    {
QT_MOC_LITERAL(0, 0, 14), // "CRemoteComConn"
QT_MOC_LITERAL(1, 15, 7), // "Reflesh"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 6), // "strMsg"
QT_MOC_LITERAL(4, 31, 5), // "bConn"
QT_MOC_LITERAL(5, 37, 5), // "bRecv"
QT_MOC_LITERAL(6, 43, 5), // "bSend"
QT_MOC_LITERAL(7, 49, 16), // "ReadyRead_RmtCom"
QT_MOC_LITERAL(8, 66, 6), // "strCmd"
QT_MOC_LITERAL(9, 73, 14), // "comlistUpdated"
QT_MOC_LITERAL(10, 88, 10), // "rmtComList"
QT_MOC_LITERAL(11, 99, 15), // "OnConnect2Proxy"
QT_MOC_LITERAL(12, 115, 10), // "OnNetError"
QT_MOC_LITERAL(13, 126, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(14, 155, 11), // "socketError"
QT_MOC_LITERAL(15, 167, 12), // "OnDisconnect"
QT_MOC_LITERAL(16, 180, 11) // "OnDataReady"

    },
    "CRemoteComConn\0Reflesh\0\0strMsg\0bConn\0"
    "bRecv\0bSend\0ReadyRead_RmtCom\0strCmd\0"
    "comlistUpdated\0rmtComList\0OnConnect2Proxy\0"
    "OnNetError\0QAbstractSocket::SocketError\0"
    "socketError\0OnDisconnect\0OnDataReady"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CRemoteComConn[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   49,    2, 0x06 /* Public */,
       7,    1,   58,    2, 0x06 /* Public */,
       9,    1,   61,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   64,    2, 0x0a /* Public */,
      12,    1,   65,    2, 0x0a /* Public */,
      15,    0,   68,    2, 0x0a /* Public */,
      16,    0,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QStringList,   10,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CRemoteComConn::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CRemoteComConn *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Reflesh((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 1: _t->ReadyRead_RmtCom((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->comlistUpdated((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 3: _t->OnConnect2Proxy(); break;
        case 4: _t->OnNetError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 5: _t->OnDisconnect(); break;
        case 6: _t->OnDataReady(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CRemoteComConn::*)(QString , bool , bool , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRemoteComConn::Reflesh)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CRemoteComConn::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRemoteComConn::ReadyRead_RmtCom)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CRemoteComConn::*)(QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRemoteComConn::comlistUpdated)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CRemoteComConn::staticMetaObject = { {
    &QThread::staticMetaObject,
    qt_meta_stringdata_CRemoteComConn.data,
    qt_meta_data_CRemoteComConn,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CRemoteComConn::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CRemoteComConn::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CRemoteComConn.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int CRemoteComConn::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void CRemoteComConn::Reflesh(QString _t1, bool _t2, bool _t3, bool _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CRemoteComConn::ReadyRead_RmtCom(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CRemoteComConn::comlistUpdated(QStringList _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
struct qt_meta_stringdata_CRmtCom_t {
    QByteArrayData data[4];
    char stringdata0[32];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CRmtCom_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CRmtCom_t qt_meta_stringdata_CRmtCom = {
    {
QT_MOC_LITERAL(0, 0, 7), // "CRmtCom"
QT_MOC_LITERAL(1, 8, 9), // "readyRead"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 12) // "stateChanged"

    },
    "CRmtCom\0readyRead\0\0stateChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CRmtCom[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,
       3,    0,   25,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CRmtCom::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CRmtCom *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->readyRead(); break;
        case 1: _t->stateChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CRmtCom::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRmtCom::readyRead)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CRmtCom::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRmtCom::stateChanged)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject CRmtCom::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_CRmtCom.data,
    qt_meta_data_CRmtCom,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CRmtCom::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CRmtCom::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CRmtCom.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CRmtCom::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void CRmtCom::readyRead()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CRmtCom::stateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
