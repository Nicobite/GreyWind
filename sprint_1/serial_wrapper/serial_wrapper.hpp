/**********************************************************************
     Author:   Grey Wind
     Date:     31/10/2014
     Version:  v0.1.0
     Details:
               31/10-v0.1.0: Created basic outline for Serial devices.
**********************************************************************/
#ifndef SERIAL_WRAPPER_HPP
#define SERIAL_WRAPPER_HPP

//TODO: Check ces librairies
#include <cstdio>
#include <string>
#include <sstream>
#include <errno.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdexcept>

class SerialDevice{
private:
    std::string m_portname;
    int         m_baudrate;
    int         m_parity;
    int         m_blocking;
    int         m_fd;

    int         set_interface_attribs (int fd, int speed, int parity);
    void        set_blocking (int fd, int should_block);
public:
    SerialDevice(const std::string portname, int baudrate=B57600, int parity=0,int blocking=0);
    ~SerialDevice();
    void    writeChar(char c);
    char    readChar();
};

#endif // SERIAL_WRAPPER_HPP
