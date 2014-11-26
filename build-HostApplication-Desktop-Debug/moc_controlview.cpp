/****************************************************************************
** Meta object code from reading C++ file 'controlview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../HostApplication/controlview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controlview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ControlView_t {
    QByteArrayData data[6];
    char stringdata[53];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ControlView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ControlView_t qt_meta_stringdata_ControlView = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 8),
QT_MOC_LITERAL(2, 21, 0),
QT_MOC_LITERAL(3, 22, 6),
QT_MOC_LITERAL(4, 29, 10),
QT_MOC_LITERAL(5, 40, 11)
    },
    "ControlView\0pressCmd\0\0keyval\0releaseCmd\0"
    "displayHelp\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ControlView[] = {

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
       4,    0,   32,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       5,    0,   33,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void ControlView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ControlView *_t = static_cast<ControlView *>(_o);
        switch (_id) {
        case 0: _t->pressCmd((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->releaseCmd(); break;
        case 2: _t->displayHelp(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ControlView::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ControlView::pressCmd)) {
                *result = 0;
            }
        }
        {
            typedef void (ControlView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ControlView::releaseCmd)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject ControlView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ControlView.data,
      qt_meta_data_ControlView,  qt_static_metacall, 0, 0}
};


const QMetaObject *ControlView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ControlView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ControlView.stringdata))
        return static_cast<void*>(const_cast< ControlView*>(this));
    return QWidget::qt_metacast(_clname);
}

int ControlView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void ControlView::pressCmd(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ControlView::releaseCmd()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
