#-------------------------------------------------
#
# Project created by QtCreator 2014-11-14T13:19:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HostApplication
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Detection/laserdetect.cpp \
    Detection/facedetection.cpp \
    videoview.cpp \
    Threads/facethread.cpp \
    Threads/videothread.cpp \
    includes.cpp \
    help.cpp	\
    Drone_Interface/droneinterface.cpp \
    Drone_Interface/Daemon_Interface/controlthread.cpp \
    Drone_Interface/Daemon_Interface/daemoninterface.cpp \
    Drone_Interface/Daemon_Interface/navdatathread.cpp \
    Drone_Interface/UDP_Interface/udp_wrapper.cpp	\
    controlview.cpp \
    control.cpp

LIBS += `pkg-config opencv --libs`

HEADERS  += mainwindow.h \
    Detection/laserdetect.hpp \
    Detection/facedetection.hpp \
    videoview.h \
    Threads/facethread.h \
    includes.h \
    includes.h \
    Threads/videothread.hpp \
    help.h	\
    Drone_Interface/droneinterface.h \
    Drone_Interface/Daemon_Interface/control_states.h \
    Drone_Interface/Daemon_Interface/controlthread.h \
    Drone_Interface/Daemon_Interface/daemoninterface.h \
    Drone_Interface/Daemon_Interface/daemoninterface.h.autosave \
    Drone_Interface/Daemon_Interface/navdatathread.h \
    Drone_Interface/UDP_Interface/udp_wrapper.hpp \
    controlview.h \
    control.h

FORMS    += mainwindow.ui \
    videoview.ui \
    help.ui \
    controlview.ui

RESOURCES += \
    HostApplication.qrc
