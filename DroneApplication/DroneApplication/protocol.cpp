#include "protocol.hpp"

using namespace std;

std::queue<int> Tx_buff ;

SerialDevice USB_Device("/dev/ttyACM0", B57600, 0, 1);


#ifdef DRONE
UDPServer my_server("192.168.1.1", 6666);
#else
UDPServer my_server("127.0.0.1", 6666);
#endif


UDPServer* get_server(){
    return &my_server;
}

uint8_t Checksum_Compute(Trame *a_trame)
        {
            int i=0;
            int checksum_int=0;
            uint8_t checksum=0;
            uint8_t *pnt_trame;
            pnt_trame=(uint8_t*) a_trame;
            int total_length = a_trame->length + NB_OCTET_INFO;


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


void Send_ACK_to_HOST_PC()
        {
            std::string msg ;
            msg = MSG_ACKNOWLEDGEMENT;
            my_server.send(msg.c_str(), msg.length());
        }

void Send_NAK_to_HOST_PC()
        {
             std::string msg ;
             msg = MSG_NON_ACKNOWLEDGEMENT;
             my_server.send(msg.c_str(), msg.length());
        }


void Send_ACK_to_STM32()
        {
            std::string msg ;
            msg = MSG_ACKNOWLEDGEMENT;
            char toSend;
            int i=0;
            for (i=0;i<3;i++)
            {
            toSend=msg[i];
            USB_Device.writeChar(toSend);
            }
        }

void Send_NAK_to_STM32()
        {
             std::string msg ;
             msg = MSG_NON_ACKNOWLEDGEMENT;
             char toSend;
             int i=0;
             for (i=0;i<3;i++)
             {
             toSend=msg[i];
             USB_Device.writeChar(toSend);
             }
        }


void Send_Trame_USB(Trame *tr)
{
    uint8_t *pnt_trame;
    pnt_trame=(uint8_t*)tr;
    char toSend;
    int total_length=tr->length+NB_OCTET_INFO+NB_OCTET_CRC;
    int i=0;
    for (i=0; i<total_length;i++)
    {
        toSend=*pnt_trame;
        USB_Device.writeChar(toSend);
        pnt_trame++;
        printf("[USB SEND TRAME] Writechar: toSend=%i\n", toSend);
    }
}



Trame Reception_from_STM32()
{
    Trame trame_from_stm32 ={226,226,226,226,0,0,0,0,0,0};

     char ret;
     cout << "Dans reception \n"<<endl;

     /* We do the reception until we receive a SOF */
     do{
     ret = USB_Device.readChar();
     printf("[USB RX]RAW Data: 0x%x, <=> %c\n",ret, ret);
     }
     while (ret!=SOF && ret!='A' && ret!='N');

     if ( ret==SOF)
     {
         /* We have received the SOF, we can fill in the trame */
         usleep(200);
         /* Fill the id_number */
         ret = USB_Device.readChar();
         trame_from_stm32.id_number=ret;
         printf("[USB RECV TRAME] char=%i\n", ret);

         /* Fill the type */
         ret = USB_Device.readChar();
         trame_from_stm32.type=ret;
         printf("[USB RECV TRAME] char=%i\n", ret);

         /* Fill the host address */
         ret = USB_Device.readChar();
         trame_from_stm32.host_address=ret;
         printf("[USB RECV TRAME] char=%i\n", ret);

         /* Fill the dest address */
         ret = USB_Device.readChar();
         trame_from_stm32.dest_address=ret;
         printf("[USB RECV TRAME] char=%i\n", ret);

         /* Fill the length */
         ret = USB_Device.readChar();
         trame_from_stm32.length=ret;
         printf("[USB RECV TRAME] char=%i\n", ret);

         /* Fill the data */
         ret = USB_Device.readChar();
         trame_from_stm32.data1=ret;
         printf("[USB RECV TRAME] char=%i\n", ret);

         ret = USB_Device.readChar();
         trame_from_stm32.data2=ret;
         printf("[USB RECV TRAME] char=%i\n", ret);

         ret = USB_Device.readChar();
         trame_from_stm32.data3=ret;
         printf("[USB RECV TRAME] char=%i\n", ret);

         ret = USB_Device.readChar();
         trame_from_stm32.data4=ret;
         printf("[USB RECV TRAME] char=%i\n", ret);

         /* Fill the status */
         ret = USB_Device.readChar();
         trame_from_stm32.status=ret;
         printf("[USB RECV TRAME] char=%i\n", ret);

         /* Before to put it into the drone buffer, we have to test the checksum */
         uint8_t checksum_computed=0x00;
         checksum_computed=Checksum_Compute(&trame_from_stm32);
         if (checksum_computed==trame_from_stm32.status)
         {
             /* The checksum is valid */
             Send_ACK_to_STM32();
             cout<<"ACK sent to STM32"<<endl;

             /* The data can be put into the drone buffer */
             cout<<"Trame from STM32 sent"<<endl;

         }
         else
         {
            /* There is a mistake in the trame */
             Send_NAK_to_STM32();
              cout<<"NAK sent to STM32"<<endl;
         }
     } else if(ret=='A'){
         ret = USB_Device.readChar();
         ret = USB_Device.readChar();
         printf("[USB RX] Received ACK!\n");

     } else if(ret=='N'){
         ret = USB_Device.readChar();
         ret = USB_Device.readChar();
         printf("[USB RX] Received NAK!\n");

     }
     return trame_from_stm32;
}



void Transmission_to_STM32(Trame* trame_to_STM32)
{
   /* We start by writing the SOF for STM32 */

   printf("[USB TX] Sending SOF \n");

   char toSend;
   toSend=SOF;
   USB_Device.writeChar(toSend);

   printf("[USB TX] Sending data: \n");
   printf("[USB TX] data1 : %i, data2 :%i , data3 :%i , data4:%i \n",trame_to_STM32->data1,trame_to_STM32->data2,trame_to_STM32->data3,trame_to_STM32->data4);

   /* We send the trame */
   Send_Trame_USB(trame_to_STM32);
}


Trame Reception_from_HOST_PC()
{    Trame trame_from_hostPc ={226,226,226,226,0,0,0,0,0,0};
     char recv_buff;
    do{
      my_server.recv(&recv_buff,2);
    }while(recv_buff!= SOF && recv_buff!='A' && recv_buff!='N');

        if(recv_buff == SOF)
        {
            printf("[UDP RX]Received  SOF\n");
            my_server.recv((char*)(&trame_from_hostPc),sizeof(trame_from_hostPc) + 1);
            printf("[UDP RX]data1 : %i, data2 :%i , data3 :%i , data4:%i \n",trame_from_hostPc.data1,trame_from_hostPc.data2,trame_from_hostPc.data3,trame_from_hostPc.data4);

            /* The data can be put into the drone buffer */
            uint8_t checksum_computed=0x00;
            checksum_computed=Checksum_Compute(&trame_from_hostPc);
            if (checksum_computed==trame_from_hostPc.status)
            {
                //Send_ACK_to_HOST_PC();
                printf("[UDP RX]Checksum cool blo.\n");

            }
            else
            {
                printf("[UDP RX]Checksum parti en couille: calcule %i, on voulait %i.\n", checksum_computed, trame_from_hostPc.status);

                //Send_NAK_to_HOST_PC();

            }
        }
        return trame_from_hostPc;

}


void Transmission_to_HOST_PC(Trame* trame_tx)
{
   char data = SOF;
   printf("[UDP TX] Je balance tout au pc ouech. \n");
   my_server.send(&data, sizeof(uint8_t)) ;
   my_server.send((char*)(trame_tx), sizeof(Trame)+1);
   printf("[UDP TX] Send data1 : %i, data2 :%i , data3 :%i , data4:%i \n",trame_tx->data1,trame_tx->data2,trame_tx->data3,trame_tx->data4);

}




void Routage(Trame *trame)
{
    switch(trame->dest_address){
    case STM_ADDRESS:
        printf("[Router] Je route au USB!\n");
        Transmission_to_STM32(trame);
        break;
    case HOST_PC_ADDRESS:
    case DRONE_ADDRESS:
        printf("[Router] Je route au UDP!\n");
        if(my_server.is_client_known()){
            Transmission_to_HOST_PC(trame);

        }

        break;
    default:
        //perte du data
        break;
    }
}
