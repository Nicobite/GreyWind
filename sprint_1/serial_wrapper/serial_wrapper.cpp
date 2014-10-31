/**********************************************************************
     Author:   Grey Wind
     Date:     31/10/2014
     Version:  v0.1.0
     Details:
               31/10-v0.1.0: Created basic outline for Serial devices.
**********************************************************************/
#include "serial_wrapper.hpp"

SerialDevice::SerialDevice(const std::string portname, int baudrate, int parity,int blocking):
    m_portname(portname),
    m_baudrate(baudrate),
    m_parity(parity),
    m_blocking(blocking)
{
    m_fd = open(portname.c_str(), O_RDWR | O_NOCTTY | O_SYNC);
    if (m_fd < 0) {
        //printf("[Error] %d opening %s: %d\n", errno, portname, errno);
        std::ostringstream os;
        os<<errno;
        throw std::runtime_error(("[Error] "+os.str()+" opening "+portname).c_str());
    }
    this->set_interface_attribs(m_fd,baudrate,parity);
    this->set_blocking(m_fd, blocking);
}

SerialDevice::~SerialDevice(){
    close(m_fd);
}

char SerialDevice::readChar(){
    char output;
    read(m_fd, &output, sizeof(char));
    return output;
}

void SerialDevice::writeChar(char c){
    write(m_fd, &c, 1);
}
