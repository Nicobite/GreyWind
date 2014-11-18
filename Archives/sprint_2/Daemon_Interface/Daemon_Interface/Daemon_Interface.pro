#-------------------------------------------------
#
# Project created by QtCreator 2014-11-14T17:57:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Daemon_Interface
TEMPLATE = app


SOURCES += main.cpp\
        droneinterfacetest.cpp \
    daemoninterface.cpp \
    navdatathread.cpp

HEADERS  += droneinterfacetest.h \
    daemoninterface.h \
    navdatathread.h

FORMS    += droneinterfacetest.ui

QMAKE_CXXFLAGS += -std=c++0x -pthread
LIBS += -pthread
