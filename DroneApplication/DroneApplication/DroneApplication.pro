TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    USB_Wrapper/serial_wrapper.cpp \
    UDP_Wrapper/udp_wrapper.cpp \
    protocol.cpp

QMAKE_CXXFLAGS += -std=c++0x -pthread
LIBS += -pthread

HEADERS += \
    USB_Wrapper/serial_wrapper.hpp \
    UDP_Wrapper/udp_wrapper.hpp \
    protocol.hpp
