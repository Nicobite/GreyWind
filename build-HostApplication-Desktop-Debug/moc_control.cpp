/****************************************************************************
** Meta object code from reading C++ file 'control.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../HostApplication/control.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'control.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Control_t {
    QByteArrayData data[23];
    char stringdata[232];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Control_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Control_t qt_meta_stringdata_Control = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 17),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 3),
QT_MOC_LITERAL(4, 31, 5),
QT_MOC_LITERAL(5, 37, 18),
QT_MOC_LITERAL(6, 56, 5),
QT_MOC_LITERAL(7, 62, 5),
QT_MOC_LITERAL(8, 68, 4),
QT_MOC_LITERAL(9, 73, 4),
QT_MOC_LITERAL(10, 78, 20),
QT_MOC_LITERAL(11, 99, 6),
QT_MOC_LITERAL(12, 106, 17),
QT_MOC_LITERAL(13, 124, 11),
QT_MOC_LITERAL(14, 136, 3),
QT_MOC_LITERAL(15, 140, 3),
QT_MOC_LITERAL(16, 144, 11),
QT_MOC_LITERAL(17, 156, 20),
QT_MOC_LITERAL(18, 177, 13),
QT_MOC_LITERAL(19, 191, 9),
QT_MOC_LITERAL(20, 201, 2),
QT_MOC_LITERAL(21, 204, 13),
QT_MOC_LITERAL(22, 218, 12)
    },
    "Control\0sendFrameToDetect\0\0Mat\0frame\0"
    "sendDetectedObject\0Point\0point\0Size\0"
    "size\0sendConnectionStatus\0status\0"
    "changeVideoSource\0std::string\0src\0err\0"
    "handleFrame\0handleDetectedObject\0"
    "handleNavdata\0navdata_t\0nd\0resetPosition\0"
    "connectDrone\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Control[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06,
       5,    2,   67,    2, 0x06,
      10,    1,   72,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
      12,    2,   75,    2, 0x0a,
      12,    1,   80,    2, 0x2a,
      16,    1,   83,    2, 0x0a,
      17,    2,   86,    2, 0x0a,
      18,    1,   91,    2, 0x0a,
      21,    0,   94,    2, 0x0a,
      22,    0,   95,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 8,    7,    9,
    QMetaType::Void, QMetaType::Bool,   11,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 13, QMetaType::Int,   14,   15,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 8,    7,    9,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Control::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Control *_t = static_cast<Control *>(_o);
        switch (_id) {
        case 0: _t->sendFrameToDetect((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 1: _t->sendDetectedObject((*reinterpret_cast< Point(*)>(_a[1])),(*reinterpret_cast< Size(*)>(_a[2]))); break;
        case 2: _t->sendConnectionStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->changeVideoSource((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->changeVideoSource((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 5: _t->handleFrame((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 6: _t->handleDetectedObject((*reinterpret_cast< Point(*)>(_a[1])),(*reinterpret_cast< Size(*)>(_a[2]))); break;
        case 7: _t->handleNavdata((*reinterpret_cast< navdata_t(*)>(_a[1]))); break;
        case 8: _t->resetPosition(); break;
        case 9: _t->connectDrone(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Control::*_t)(Mat );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Control::sendFrameToDetect)) {
                *result = 0;
            }
        }
        {
            typedef void (Control::*_t)(Point , Size );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Control::sendDetectedObject)) {
                *result = 1;
            }
        }
        {
            typedef void (Control::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Control::sendConnectionStatus)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject Control::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Control.data,
      qt_meta_data_Control,  qt_static_metacall, 0, 0}
};


const QMetaObject *Control::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Control::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Control.stringdata))
        return static_cast<void*>(const_cast< Control*>(this));
    return QObject::qt_metacast(_clname);
}

int Control::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Control::sendFrameToDetect(Mat _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Control::sendDetectedObject(Point _t1, Size _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Control::sendConnectionStatus(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
