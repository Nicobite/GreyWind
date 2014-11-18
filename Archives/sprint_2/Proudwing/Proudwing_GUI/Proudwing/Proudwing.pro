#-------------------------------------------------
#
# Project created by QtCreator 2014-11-18T08:01:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Proudwing
TEMPLATE = app


SOURCES += main.cpp\
        proudwingapp.cpp \
    Drone_Interface/Daemon_Interface/daemoninterface.cpp \
    Drone_Interface/Daemon_Interface/navdatathread.cpp \
    Drone_Interface/UDP_Interface/udp_wrapper.cpp \
    Drone_Interface/Daemon_Interface/controlthread.cpp \
    Drone_Interface/droneinterface.cpp

HEADERS  += \
    proudwingapp.h \
    Drone_Interface/Daemon_Interface/daemoninterface.h \
    Drone_Interface/Daemon_Interface/navdatathread.h \
    Drone_Interface/UDP_Interface/udp_wrapper.hpp \
    Drone_Interface/Daemon_Interface/controlthread.h \
    Drone_Interface/droneinterface.h

FORMS    += proudwingapp.ui
