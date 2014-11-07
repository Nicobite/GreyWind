TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    Sources/Navdata/navdata.c \
    Sources/UI/gui.c \
    Sources/Video/video_stage.c \
    Sources/ardrone_testing_tool.c

HEADERS += \
    Sources/Navdata/navdata.h \
    Sources/UI/gui.h \
    Sources/Video/video_stage.h \
    Sources/ardrone_testing_tool.h

OTHER_FILES += \
    Build/Makefile

