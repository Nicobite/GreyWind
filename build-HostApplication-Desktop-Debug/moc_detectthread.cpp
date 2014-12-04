/****************************************************************************
** Meta object code from reading C++ file 'detectthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../HostApplication/Detection/detectthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'detectthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DetectThread_t {
    QByteArrayData data[11];
    char stringdata[105];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_DetectThread_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_DetectThread_t qt_meta_stringdata_DetectThread = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 16),
QT_MOC_LITERAL(2, 30, 0),
QT_MOC_LITERAL(3, 31, 3),
QT_MOC_LITERAL(4, 35, 3),
QT_MOC_LITERAL(5, 39, 20),
QT_MOC_LITERAL(6, 60, 5),
QT_MOC_LITERAL(7, 66, 6),
QT_MOC_LITERAL(8, 73, 4),
QT_MOC_LITERAL(9, 78, 4),
QT_MOC_LITERAL(10, 83, 20)
    },
    "DetectThread\0sigFrameToObject\0\0Mat\0"
    "mat\0sigDetectedToControl\0Point\0center\0"
    "Size\0size\0handleDetectedObject\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DetectThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06,
       5,    2,   32,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
      10,    2,   37,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 8,    7,    9,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 8,    7,    9,

       0        // eod
};

void DetectThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DetectThread *_t = static_cast<DetectThread *>(_o);
        switch (_id) {
        case 0: _t->sigFrameToObject((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 1: _t->sigDetectedToControl((*reinterpret_cast< Point(*)>(_a[1])),(*reinterpret_cast< Size(*)>(_a[2]))); break;
        case 2: _t->handleDetectedObject((*reinterpret_cast< Point(*)>(_a[1])),(*reinterpret_cast< Size(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DetectThread::*_t)(Mat );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DetectThread::sigFrameToObject)) {
                *result = 0;
            }
        }
        {
            typedef void (DetectThread::*_t)(Point , Size );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DetectThread::sigDetectedToControl)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject DetectThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_DetectThread.data,
      qt_meta_data_DetectThread,  qt_static_metacall, 0, 0}
};


const QMetaObject *DetectThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DetectThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DetectThread.stringdata))
        return static_cast<void*>(const_cast< DetectThread*>(this));
    return QThread::qt_metacast(_clname);
}

int DetectThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void DetectThread::sigFrameToObject(Mat _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DetectThread::sigDetectedToControl(Point _t1, Size _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
