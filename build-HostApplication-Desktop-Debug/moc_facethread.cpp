/****************************************************************************
** Meta object code from reading C++ file 'facethread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../HostApplication/Threads/facethread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'facethread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Facethread_t {
    QByteArrayData data[10];
    char stringdata[87];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Facethread_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Facethread_t qt_meta_stringdata_Facethread = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 14),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 5),
QT_MOC_LITERAL(4, 33, 9),
QT_MOC_LITERAL(5, 43, 9),
QT_MOC_LITERAL(6, 53, 6),
QT_MOC_LITERAL(7, 60, 9),
QT_MOC_LITERAL(8, 70, 11),
QT_MOC_LITERAL(9, 82, 3)
    },
    "Facethread\0displayedFrame\0\0image\0"
    "sigReqSrc\0dispFrame\0getSrc\0updateSrc\0"
    "std::string\0src\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Facethread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06,
       4,    0,   42,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       5,    1,   43,    2, 0x0a,
       6,    0,   46,    2, 0x0a,
       7,    1,   47,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

void Facethread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Facethread *_t = static_cast<Facethread *>(_o);
        switch (_id) {
        case 0: _t->displayedFrame((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 1: _t->sigReqSrc(); break;
        case 2: _t->dispFrame((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 3: _t->getSrc(); break;
        case 4: _t->updateSrc((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Facethread::*_t)(QImage );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Facethread::displayedFrame)) {
                *result = 0;
            }
        }
        {
            typedef void (Facethread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Facethread::sigReqSrc)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject Facethread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_Facethread.data,
      qt_meta_data_Facethread,  qt_static_metacall, 0, 0}
};


const QMetaObject *Facethread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Facethread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Facethread.stringdata))
        return static_cast<void*>(const_cast< Facethread*>(this));
    return QThread::qt_metacast(_clname);
}

int Facethread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Facethread::displayedFrame(QImage _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Facethread::sigReqSrc()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
