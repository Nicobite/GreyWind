#ifndef SENSORTHREAD_H
#define SENSORTHREAD_H

#include <QThread>
#include "includes.h"
#include "Drone_Interface/Sensor_Interface/udp_wrapper.hpp"
#include <queue>
#include <string>
#include <stdint.h>

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


class SensorThread: public QThread
{
    Q_OBJECT

private:
    char m_recv_buff;
    bool m_ready2receive;
    std::queue<int> m_tx_buff;
    UDPClient *m_client_socket;

    const int CMD_DISTANCE_TRANSMISSION_REQUEST = 1;
    const int CMD_SWITCH_ON_LASER_ORDER         = 2;
    const int CMD_SWITCH_OFF_LASER_ORDER        = 3;

    static const int NB_OCTET_INFO = 5;    //id, type, host, dest, length
    static const int DELAY_MAX_RECEPTION_ACK = 200; //ms

    //Addresses
    static const uint8_t ADDR_STM = 0;
    static const uint8_t ADDR_DRONE = 1;
    static const uint8_t ADDR_HOST_PC = 2;

    //Types
    static const uint8_t ID_STM = 0;
    static const uint8_t ID_SONAR = 1;
    static const uint8_t ID__LASER = 2;
    static const uint8_t ID_OTHER = 3;

    //???
    static const uint8_t TYPE_REQUEST = 0;
    static const uint8_t TYPE_ORDER = 1;
    static const uint8_t TYPE_DISTANCE_ANSWER = 2;
    static const uint8_t TYPE_OTHER_ANSWER = 3;

    //Protocol messages
    static const char SOF = 0xFF;
    const std::string MSG_ACKNOWLEDGEMENT = "ACK";
    const std::string MSG_NON_ACKNOWLEDGEMENT = "NAK";

    uint8_t compute_checksum(SensorFrame *a_frame);
    void transmission();
    void reception();

public:
     explicit SensorThread(QObject *parent = 0);
    ~SensorThread();

protected:
    void run();

public slots:
    void setLaserState(bool state);
    void requestSonarData();
    void requestFilteredSonarData();

signals:
    void newSonarData(int distance);

};

#endif // SENSORTHREAD_H
