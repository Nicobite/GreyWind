#ifndef PROTOCOL_HPP
#define PROTOCOL_HPP

#include <stdexcept>
#include <iostream>
#include <string>
#include <queue>
#include "UDP_Wrapper/udp_wrapper.hpp"
#include "USB_Wrapper/serial_wrapper.hpp"

#define DISTANCE_TRANSMISSION_REQUEST 1
#define SWITCH_ON_LASER_ORDER 2
#define SWITCH_OFF_LASER_ORDER 3


#define NB_OCTET_INFO 5 // id,type, host, dest, length
#define NB_OCTET_CRC 1 // status
#define DELAY_MAX_RECEPTION_ACK  200  // ms


#define STM_ADDRESS (uint8_t) 0
#define DRONE_ADDRESS (uint8_t) 2
#define HOST_PC_ADDRESS (uint8_t) 1

//id
#define STM  (uint8_t) 0
#define ULTRASONIC_SENSOR  (uint8_t) 1
#define LASER (uint8_t)   2
#define ID_OTHER (uint8_t)3

//type
#define REQUEST (uint8_t) 0
#define ORDER (uint8_t) 1
#define DISTANCE_ANSWER (uint8_t) 2
#define OTHER_ANSWER (uint8_t) 3

#define MSG_ACKNOWLEDGEMENT "ACK"
#define MSG_NON_ACKNOWLEDGEMENT "NAK"

const char SOF=0xFF;

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
}Trame;

UDPServer* get_server();

uint8_t Checksum_Compute(Trame *a_trame);

void Send_ACK_to_STM32();

void Send_NAK_to_STM32();

void Send_ACK_to_HOST_PC();

void Send_NAK_to_HOST_PC();

void Send_Trame_USB(Trame *tr);


Trame Reception_from_STM32();

Trame Reception_from_HOST_PC();


void Transmission_to_STM32(Trame* trame_to_STM32);

void Transmission_to_HOST_PC(Trame *trame_tx);

void Routage(Trame *trame);

#endif // PROTOCOL_HPP
