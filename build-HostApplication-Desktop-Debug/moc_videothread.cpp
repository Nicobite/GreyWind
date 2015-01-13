/****************************************************************************
** Meta object code from reading C++ file 'videothread.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../HostApplication/Video/videothread.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'videothread.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VideoThread_t {
    QByteArrayData data[14];
    char stringdata[159];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_VideoThread_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_VideoThread_t qt_meta_stringdata_VideoThread = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 18),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 3),
QT_MOC_LITERAL(4, 36, 5),
QT_MOC_LITERAL(5, 42, 14),
QT_MOC_LITERAL(6, 57, 18),
QT_MOC_LITERAL(7, 76, 11),
QT_MOC_LITERAL(8, 88, 3),
QT_MOC_LITERAL(9, 92, 3),
QT_MOC_LITERAL(10, 96, 9),
QT_MOC_LITERAL(11, 106, 18),
QT_MOC_LITERAL(12, 125, 20),
QT_MOC_LITERAL(13, 146, 11)
    },
    "VideoThread\0sendDetectionFrame\0\0Mat\0"
    "frame\0sendVideoFrame\0cannotChangeSource\0"
    "std::string\0src\0err\0setSource\0"
    "setDetectionPeriod\0nbFramesBeforeDetect\0"
    "savePicture\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VideoThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06,
       5,    1,   47,    2, 0x06,
       6,    2,   50,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
      10,    1,   55,    2, 0x0a,
      11,    1,   58,    2, 0x0a,
      13,    0,   61,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QImage,    4,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int,    8,    9,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,

       0        // eod
};

void VideoThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VideoThread *_t = static_cast<VideoThread *>(_o);
        switch (_id) {
        case 0: _t->sendDetectionFrame((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 1: _t->sendVideoFrame((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 2: _t->cannotChangeSource((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->setSource((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 4: _t->setDetectionPeriod((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->savePicture(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (VideoThread::*_t)(Mat );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VideoThread::sendDetectionFrame)) {
                *result = 0;
            }
        }
        {
            typedef void (VideoThread::*_t)(QImage );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VideoThread::sendVideoFrame)) {
                *result = 1;
            }
        }
        {
            typedef void (VideoThread::*_t)(std::string , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VideoThread::cannotChangeSource)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject VideoThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_VideoThread.data,
      qt_meta_data_VideoThread,  qt_static_metacall, 0, 0}
};


const QMetaObject *VideoThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VideoThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VideoThread.stringdata))
        return static_cast<void*>(const_cast< VideoThread*>(this));
    return QThread::qt_metacast(_clname);
}

int VideoThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void VideoThread::sendDetectionFrame(Mat _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void VideoThread::sendVideoFrame(QImage _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void VideoThread::cannotChangeSource(std::string _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
