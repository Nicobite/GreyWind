#include "sensorthread.h"

SensorThread::SensorThread(QObject *parent) :
    QThread(parent)
{
    m_client_socket = new UDPClient("192.168.1.1", 6666);
    //m_client_socket = new UDPClient("127.0.0.1", 6666);
    m_ready2receive = false;
}

SensorThread::~SensorThread(){
    delete m_client_socket;
}

void SensorThread::run(){
    while(true){
        transmission();
        reception();
        usleep(10000);
    }
}

uint8_t SensorThread::compute_checksum(SensorFrame *a_frame){
    int i=0;
    int checksum_int=0;
    uint8_t checksum=0;
    uint8_t *pnt_trame;
    pnt_trame=(uint8_t*) a_frame;
    int total_length = a_frame->length + NB_OCTET_INFO;

    /* Sum of the octet of the trame */
    for ( i=0; i<total_length; i++)
    {
        checksum_int += *pnt_trame;
        pnt_trame++;
    }

    /* Addition with 1 */
    checksum_int += 1;

    /* Modulo 256 */
    checksum= (uint8_t)(checksum_int%0xFF);

    return checksum;
}

void SensorThread::transmission(){
    while(!m_tx_buff.empty())
    {
        SensorFrame trame_tx ={0,0,0,0,0,0,0,0,0,0};
        int type;

        type  = m_tx_buff.front() ;
        m_tx_buff.pop();

        trame_tx.id_number    =  ID_OTHER;
        trame_tx.host_address =  ADDR_HOST_PC;
        trame_tx.dest_address =  ADDR_STM;
        trame_tx.length       =  4;


        if(type==CMD_DISTANCE_TRANSMISSION_REQUEST){
            trame_tx.type = TYPE_REQUEST;

            trame_tx.data1 = 'G' ;
            trame_tx.data2 = 'E' ;
            trame_tx.data3 = 'T' ;
            trame_tx.data4 = 'D' ;

            m_ready2receive = true;

        }else if(type==CMD_SWITCH_ON_LASER_ORDER){
            trame_tx.type = TYPE_ORDER;

            trame_tx.data1 = 'S' ;
            trame_tx.data2 = 'E' ;
            trame_tx.data3 = 'T' ;
            trame_tx.data4 = 'L' ;
        }else if(type==CMD_SWITCH_OFF_LASER_ORDER){
            trame_tx.type = TYPE_ORDER;

            trame_tx.data1 = 'R' ;
            trame_tx.data2 = 'S' ;
            trame_tx.data3 = 'T' ;
            trame_tx.data4 = 'L' ;
        }else{
            break;
        }

        trame_tx.status       =  compute_checksum(&trame_tx) ;

        char data = SOF;
        //printf("Sending : %i\n", data);
        m_client_socket->send(&data, 2) ;

        m_client_socket->send((char*)(&trame_tx), sizeof(trame_tx)+1);
    }
}

void SensorThread::reception(){

    if(m_ready2receive){
        SensorFrame trame_rx ={0,0,0,0,0,0,0,0,0,0};

        m_client_socket->recv(&m_recv_buff,2);

        if(m_recv_buff==SOF)
        {
            m_client_socket->recv((char*)(&trame_rx),sizeof(trame_rx) + 1);
            //DEBUG("[Client: RX] Received packet with id: %i, type: %i, ha: %i, da: %i, length: %i, data1: %i, data2: %i, data3: %i, data4: %i\n",trame_rx.id_number, trame_rx.type, trame_rx.host_address, trame_rx.dest_address, trame_rx.length, trame_rx.data1,trame_rx.data2,trame_rx.data3,trame_rx.data4);

            if(trame_rx.type==TYPE_DISTANCE_ANSWER){
                int dist = (trame_rx.data4)+(trame_rx.data3&0xF)*255;
                //DEBUG("[Client: RX] Distance = " + dist);
                emit newSonarData(dist);
            }
            m_ready2receive = false;
        }
    }
}

void SensorThread::setLaserState(bool state){
    if(state)
        m_tx_buff.push(CMD_SWITCH_ON_LASER_ORDER);
    else
        m_tx_buff.push(CMD_SWITCH_OFF_LASER_ORDER);
}

void SensorThread::requestSonarData(){
    m_tx_buff.push(CMD_DISTANCE_TRANSMISSION_REQUEST);
}

void SensorThread::requestFilteredSonarData(){

}
