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
    includes.cpp

LIBS += `pkg-config opencv --libs`

HEADERS  += mainwindow.h \
    Detection/laserdetect.hpp \
    Detection/facedetection.hpp \
    videoview.h \
    Threads/facethread.h \
    includes.h \
    includes.h \
    Threads/videothread.hpp

FORMS    += mainwindow.ui \
    videoview.ui
