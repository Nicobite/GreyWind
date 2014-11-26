/**********************************************************************
     Author:   Grey Wind
     Date:     31/10/2014
     Version:  v0.1.0
     Details:
               31/10-v0.1.0: Created basic outline for Serial devices.
**********************************************************************/
#include "serial_wrapper.hpp"
#include <cstdlib>
#include <cstring>

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
    set_interface_attribs(m_fd,baudrate,parity);
    set_blocking(m_fd, blocking);
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

int SerialDevice::set_interface_attribs(int fd, int speed, int parity){
        struct termios tty;
        memset (&tty, 0, sizeof tty);
        if (tcgetattr (fd, &tty) != 0)
        {
                printf ("error %d from tcgetattr", errno);
                return -1;
        }

        cfsetospeed (&tty, speed);
        cfsetispeed (&tty, speed);

        tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;     // 8-bit chars
        // disable IGNBRK for mismatched speed tests; otherwise receive break
        // as \000 chars
        tty.c_iflag &= ~IGNBRK;         // disable break processing
        tty.c_lflag = 0;                // no signaling chars, no echo,
                                        // no canonical processing
        tty.c_oflag = 0;                // no remapping, no delays
        tty.c_cc[VMIN]  = 0;            // read doesn't block
        tty.c_cc[VTIME] = 5;            // 0.5 seconds read timeout

        tty.c_iflag &= ~(IXON | IXOFF | IXANY); // shut off xon/xoff ctrl

        tty.c_cflag |= (CLOCAL | CREAD);// ignore modem controls,
                                        // enable reading
        tty.c_cflag &= ~(PARENB | PARODD);      // shut off parity
        tty.c_cflag |= parity;
        tty.c_cflag &= ~CSTOPB;
        tty.c_cflag &= ~CRTSCTS;

        if (tcsetattr (fd, TCSANOW, &tty) != 0)
        {
                printf ("error %d from tcsetattr", errno);
                return -1;
        }
        return 0;
}

void SerialDevice::set_blocking (int fd, int should_block){
        struct termios tty;
        memset(&tty, 0, sizeof tty);
        if (tcgetattr (fd, &tty) != 0)
        {
                printf("error %d from tggetattr", errno);
                return;
        }

        tty.c_cc[VMIN]  = should_block ? 1 : 0;
        tty.c_cc[VTIME] = 5;            // 0.5 seconds read timeout

        if (tcsetattr (fd, TCSANOW, &tty) != 0)
                printf ("error %d setting term attributes", errno);
}

//void SerialDevice::get_fd() const{
//        return m_fd;
//}
