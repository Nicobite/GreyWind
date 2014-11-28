#ifndef PROTOCOLWRAPPER_H
#define PROTOCOLWRAPPER_H

#include <iostream>
#include <string>
#include <queue>
#include "udp_wrapper.hpp"


typedef struct {
   uint8_t id_number;
   uint8_t type;
   uint8_t host_address;
   uint8_t dest_address;
   uint8_t length;
   uint8_t data1;
   uint8_t data2;
   uint8_t data3;
   uint8_t data4;

   uint8_t status;
}SensorFrame;



class ProtocolWrapper
{
private:
    char m_recv_buff;
    std::queue<int> m_tx_buff ;
    UDPClient *m_client_socket;

public:
    ProtocolWrapper();
    ~ProtocolWrapper();

    const int DISTANCE_TRANSMISSION_REQUEST = 1;
    const int SWITCH_ON_LASER_ORDER         = 2;
    const int SWITCH_OFF_LASER_ORDER        = 3;

    const int NB_OCTET_INFO = 5;    //id, type, host, dest, length
    const int DELAY_MAX_RECEPTION_ACK = 200; //ms

    //Addresses
    const uint8_t STM_ADDRESS = 0;
    const uint8_t DRONE_ADDRESS = 1;
    const uint8_t HOST_PC_ADDRESS = 2;

    //Types
    const uint8_t STM = 0;
    const uint8_t ULTRASONIC_SENSOR = 1;
    const uint8_t LASER = 2;
    const uint8_t ID_OTHER = 3;

    //???
    const uint8_t REQUEST = 1;
    const uint8_t ORDER = 2;
    const uint8_t DISTANCE_ANSWER = 3;
    const uint8_t OTHER_ANSWER = 4;

    //Protocol messages
    const char SOF = 0xFF;
    const char MSG_ACKNOWLEDGEMENT[4] = "ACK";
    const char MSG_NON_ACKNOWLEDGEMENT[4] = "NAK";
};

#endif // PROTOCOLWRAPPER_H
