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
    QByteArrayData data[40];
    char stringdata[529];
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
QT_MOC_LITERAL(13, 124, 12),
QT_MOC_LITERAL(14, 137, 13),
QT_MOC_LITERAL(15, 151, 9),
QT_MOC_LITERAL(16, 161, 2),
QT_MOC_LITERAL(17, 164, 13),
QT_MOC_LITERAL(18, 178, 19),
QT_MOC_LITERAL(19, 198, 11),
QT_MOC_LITERAL(20, 210, 4),
QT_MOC_LITERAL(21, 215, 21),
QT_MOC_LITERAL(22, 237, 3),
QT_MOC_LITERAL(23, 241, 11),
QT_MOC_LITERAL(24, 253, 17),
QT_MOC_LITERAL(25, 271, 3),
QT_MOC_LITERAL(26, 275, 3),
QT_MOC_LITERAL(27, 279, 20),
QT_MOC_LITERAL(28, 300, 26),
QT_MOC_LITERAL(29, 327, 4),
QT_MOC_LITERAL(30, 332, 20),
QT_MOC_LITERAL(31, 353, 17),
QT_MOC_LITERAL(32, 371, 21),
QT_MOC_LITERAL(33, 393, 27),
QT_MOC_LITERAL(34, 421, 30),
QT_MOC_LITERAL(35, 452, 13),
QT_MOC_LITERAL(36, 466, 10),
QT_MOC_LITERAL(37, 477, 10),
QT_MOC_LITERAL(38, 488, 22),
QT_MOC_LITERAL(39, 511, 16)
    },
    "Control\0sendFrameToDetect\0\0Mat\0frame\0"
    "sendDetectedObject\0Point\0point\0Size\0"
    "size\0sendConnectionStatus\0status\0"
    "sendSizeBlackList\0connectDrone\0"
    "handleNavdata\0navdata_t\0nd\0resetPosition\0"
    "updateDetectionAlgo\0std::string\0algo\0"
    "updateDetectionObject\0obj\0handleFrame\0"
    "changeVideoSource\0src\0err\0"
    "handleDetectedObject\0handleDetectThreadMessages\0"
    "mess\0addObjectToBlacklist\0clearAllBlackList\0"
    "handleValidatedObject\0handleTrackerInitialisation\0"
    "handleCollimatorThreadMessages\0"
    "addNewMission\0subMission\0runMission\0"
    "disconnectSonarMission\0collimatorDeinit\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Control[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  134,    2, 0x06,
       5,    2,  137,    2, 0x06,
      10,    1,  142,    2, 0x06,
      12,    1,  145,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
      13,    0,  148,    2, 0x0a,
      14,    1,  149,    2, 0x0a,
      17,    0,  152,    2, 0x0a,
      18,    1,  153,    2, 0x0a,
      21,    1,  156,    2, 0x0a,
      23,    1,  159,    2, 0x0a,
      24,    2,  162,    2, 0x0a,
      24,    1,  167,    2, 0x2a,
      27,    2,  170,    2, 0x0a,
      28,    1,  175,    2, 0x0a,
      30,    2,  178,    2, 0x0a,
      31,    0,  183,    2, 0x0a,
      32,    2,  184,    2, 0x0a,
      33,    0,  189,    2, 0x0a,
      34,    1,  190,    2, 0x0a,
      35,    2,  193,    2, 0x0a,
      36,    0,  198,    2, 0x0a,
      37,    0,  199,    2, 0x0a,
      38,    0,  200,    2, 0x0a,
      39,    0,  201,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 8,    7,    9,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Int,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void, 0x80000000 | 19,   22,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 19, QMetaType::Int,   25,   26,
    QMetaType::Void, 0x80000000 | 19,   25,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 8,    7,    9,
    QMetaType::Void, 0x80000000 | 19,   29,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 8,    7,    9,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 8,    7,    9,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19,   29,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   20,   22,
    QMetaType::Void,
    QMetaType::Void,
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
        case 3: _t->sendSizeBlackList((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->connectDrone(); break;
        case 5: _t->handleNavdata((*reinterpret_cast< navdata_t(*)>(_a[1]))); break;
        case 6: _t->resetPosition(); break;
        case 7: _t->updateDetectionAlgo((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 8: _t->updateDetectionObject((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 9: _t->handleFrame((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 10: _t->changeVideoSource((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->changeVideoSource((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 12: _t->handleDetectedObject((*reinterpret_cast< Point(*)>(_a[1])),(*reinterpret_cast< Size(*)>(_a[2]))); break;
        case 13: _t->handleDetectThreadMessages((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 14: _t->addObjectToBlacklist((*reinterpret_cast< Point(*)>(_a[1])),(*reinterpret_cast< Size(*)>(_a[2]))); break;
        case 15: _t->clearAllBlackList(); break;
        case 16: _t->handleValidatedObject((*reinterpret_cast< Point(*)>(_a[1])),(*reinterpret_cast< Size(*)>(_a[2]))); break;
        case 17: _t->handleTrackerInitialisation(); break;
        case 18: _t->handleCollimatorThreadMessages((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 19: _t->addNewMission((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 20: _t->subMission(); break;
        case 21: _t->runMission(); break;
        case 22: _t->disconnectSonarMission(); break;
        case 23: _t->collimatorDeinit(); break;
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
        {
            typedef void (Control::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Control::sendSizeBlackList)) {
                *result = 3;
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
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 24)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 24;
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

// SIGNAL 3
void Control::sendSizeBlackList(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
