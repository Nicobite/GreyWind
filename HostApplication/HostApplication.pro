    #-------------------------------------------------
#
# Project created by QtCreator 2014-11-14T13:19:13
#
#-------------------------------------------------

QT += core gui opengl
QT += webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HostApplication
TEMPLATE = app


SOURCES += main.cpp\
    Detection/laserdetect.cpp \
    Drone_Interface/droneinterface.cpp \
    Drone_Interface/Daemon_Interface/controlthread.cpp \
    Drone_Interface/Daemon_Interface/daemoninterface.cpp \
    Drone_Interface/Daemon_Interface/navdatathread.cpp \
    Drone_Interface/Sensor_Interface/udp_wrapper.cpp	\
    control.cpp \
    Detection/detectionalgo.cpp \
    Detection/haarfacedetectionalgo.cpp \
#    Detection/surfdetectionalgo.cpp \
    GUI/help.cpp \
    GUI/mainwindow.cpp \
    GUI/videoview.cpp \
    Video/videothread.cpp \
    Drone_Interface/Sensor_Interface/sensorthread.cpp \
    GUI/painterthread.cpp \
    Detection/detectthread.cpp \
    localizationfunctions.cpp \
    GUI/threedview.cpp \
    Tracking/trackingalgo.cpp \
    Tracking/pmtrackingalgo.cpp \
    GUI/detection.cpp \
    Detection/pcmdetectionalgo.cpp \
    GUI/helpdetect.cpp \
    Tracking/collimator.cpp \
    GUI/glwidget.cpp \
    GUI/webview.cpp

LIBS += `pkg-config opencv --libs`

HEADERS  += Detection/laserdetect.hpp \
    includes.h \
    Drone_Interface/droneinterface.h \
    Drone_Interface/Daemon_Interface/control_states.h \
    Drone_Interface/Daemon_Interface/controlthread.h \
    Drone_Interface/Daemon_Interface/daemoninterface.h \
    Drone_Interface/Daemon_Interface/daemoninterface.h.autosave \
    Drone_Interface/Daemon_Interface/navdatathread.h \
    Drone_Interface/Sensor_Interface/udp_wrapper.hpp \
    control.h \
    Detection/detectionalgo.h \
    Detection/haarfacedetectionalgo.h \
#    Detection/surfdetectionalgo.h \
    GUI/help.h \
    GUI/mainwindow.h \
    GUI/videoview.h \
    Video/videothread.hpp \
    Drone_Interface/Sensor_Interface/sensorthread.h \
    GUI/painterthread.h \
    Detection/detectthread.h \
    localizationfunctions.h \
    GUI/threedview.h \
    Tracking/trackingalgo.h \
    Tracking/pmtrackingalgo.h \
    GUI/detection.h \
    Detection/pcmdetectionalgo.h \
    GUI/helpdetect.h \
    Tracking/collimator.h \
    GUI/glwidget.h \
    GUI/webview.h

FORMS    += GUI/help.ui \
    GUI/mainwindow.ui \
    GUI/videoview.ui \
    GUI/threedview.ui \
    GUI/detection.ui \
    GUI/helpdetect.ui \
    GUI/webview.ui

RESOURCES += \
    HostApplication.qrc
