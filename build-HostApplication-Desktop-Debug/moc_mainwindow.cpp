/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../HostApplication/GUI/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[38];
    char stringdata[442];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 16),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 11),
QT_MOC_LITERAL(4, 41, 3),
QT_MOC_LITERAL(5, 45, 22),
QT_MOC_LITERAL(6, 68, 3),
QT_MOC_LITERAL(7, 72, 19),
QT_MOC_LITERAL(8, 92, 20),
QT_MOC_LITERAL(9, 113, 10),
QT_MOC_LITERAL(10, 124, 5),
QT_MOC_LITERAL(11, 130, 12),
QT_MOC_LITERAL(12, 143, 8),
QT_MOC_LITERAL(13, 152, 6),
QT_MOC_LITERAL(14, 159, 10),
QT_MOC_LITERAL(15, 170, 8),
QT_MOC_LITERAL(16, 179, 5),
QT_MOC_LITERAL(17, 185, 17),
QT_MOC_LITERAL(18, 203, 9),
QT_MOC_LITERAL(19, 213, 2),
QT_MOC_LITERAL(20, 216, 19),
QT_MOC_LITERAL(21, 236, 5),
QT_MOC_LITERAL(22, 242, 6),
QT_MOC_LITERAL(23, 249, 4),
QT_MOC_LITERAL(24, 254, 4),
QT_MOC_LITERAL(25, 259, 22),
QT_MOC_LITERAL(26, 282, 6),
QT_MOC_LITERAL(27, 289, 15),
QT_MOC_LITERAL(28, 305, 8),
QT_MOC_LITERAL(29, 314, 13),
QT_MOC_LITERAL(30, 328, 4),
QT_MOC_LITERAL(31, 333, 18),
QT_MOC_LITERAL(32, 352, 16),
QT_MOC_LITERAL(33, 369, 17),
QT_MOC_LITERAL(34, 387, 14),
QT_MOC_LITERAL(35, 402, 16),
QT_MOC_LITERAL(36, 419, 11),
QT_MOC_LITERAL(37, 431, 9)
    },
    "MainWindow\0vidSourceChanged\0\0std::string\0"
    "src\0detectFrameRateChanged\0fbd\0"
    "rstPosButtonClicked\0connectButtonClicked\0"
    "laserState\0state\0sonarRequest\0pressCmd\0"
    "keyval\0releaseCmd\0setFrame\0image\0"
    "updateNavdataView\0navdata_t\0nd\0"
    "drawDetectedEllipse\0Point\0center\0Size\0"
    "size\0updateConnectionStatus\0status\0"
    "updateSonarView\0distance\0emitVidSource\0"
    "text\0emitFramesB4Detect\0emitRstPosButton\0"
    "emitConnectButton\0emitLaserState\0"
    "emitSonarRequest\0displayHelp\0display3D\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  119,    2, 0x06,
       5,    1,  122,    2, 0x06,
       7,    0,  125,    2, 0x06,
       8,    0,  126,    2, 0x06,
       9,    1,  127,    2, 0x06,
      11,    0,  130,    2, 0x06,
      12,    1,  131,    2, 0x06,
      14,    0,  134,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
      15,    1,  135,    2, 0x0a,
      17,    1,  138,    2, 0x0a,
      20,    2,  141,    2, 0x0a,
      25,    1,  146,    2, 0x0a,
      27,    1,  149,    2, 0x0a,
      29,    1,  152,    2, 0x08,
      31,    1,  155,    2, 0x08,
      32,    0,  158,    2, 0x08,
      33,    0,  159,    2, 0x08,
      34,    1,  160,    2, 0x08,
      35,    0,  163,    2, 0x08,
      36,    0,  164,    2, 0x08,
      37,    0,  165,    2, 0x08,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QImage,   16,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, 0x80000000 | 21, 0x80000000 | 23,   22,   24,
    QMetaType::Void, QMetaType::Bool,   26,
    QMetaType::Void, QMetaType::Int,   28,
    QMetaType::Void, QMetaType::QString,   30,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->vidSourceChanged((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 1: _t->detectFrameRateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->rstPosButtonClicked(); break;
        case 3: _t->connectButtonClicked(); break;
        case 4: _t->laserState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->sonarRequest(); break;
        case 6: _t->pressCmd((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->releaseCmd(); break;
        case 8: _t->setFrame((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 9: _t->updateNavdataView((*reinterpret_cast< navdata_t(*)>(_a[1]))); break;
        case 10: _t->drawDetectedEllipse((*reinterpret_cast< Point(*)>(_a[1])),(*reinterpret_cast< Size(*)>(_a[2]))); break;
        case 11: _t->updateConnectionStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->updateSonarView((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->emitVidSource((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->emitFramesB4Detect((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: _t->emitRstPosButton(); break;
        case 16: _t->emitConnectButton(); break;
        case 17: _t->emitLaserState((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->emitSonarRequest(); break;
        case 19: _t->displayHelp(); break;
        case 20: _t->display3D(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(std::string );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::vidSourceChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (MainWindow::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::detectFrameRateChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::rstPosButtonClicked)) {
                *result = 2;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::connectButtonClicked)) {
                *result = 3;
            }
        }
        {
            typedef void (MainWindow::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::laserState)) {
                *result = 4;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::sonarRequest)) {
                *result = 5;
            }
        }
        {
            typedef void (MainWindow::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::pressCmd)) {
                *result = 6;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::releaseCmd)) {
                *result = 7;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 21;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::vidSourceChanged(std::string _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::detectFrameRateChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::rstPosButtonClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void MainWindow::connectButtonClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void MainWindow::laserState(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::sonarRequest()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void MainWindow::pressCmd(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MainWindow::releaseCmd()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}
QT_END_MOC_NAMESPACE
