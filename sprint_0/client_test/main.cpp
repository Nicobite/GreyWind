#include <stdexcept>
#include <iostream>
#include <string>
#include "../udp_wrapper/udp_wrapper.hpp"

int main(int argc, char *argv[]){
  try{

    std::cout << "Creating a client to communicate with the localhost..."  << std::endl;    

    UDPClient my_client("127.0.0.1", 6666);
    std::string sent_mess, recv_mess;
    char recv_buff[128];
 
    std::cout << "Sending a message..."  << std::endl;       
    if(argc > 1){
        sent_mess = argv[1];
    } else{
        sent_mess = "Plop plop mofo, I am the client!";
    }

    my_client.send(sent_mess.c_str(), sent_mess.length());
    std::cout << "Sent message: " << sent_mess << std::endl;


    std::cout << "Receiveing a message..."  << std::endl;    
    my_client.recv(recv_buff, 128);
    recv_mess = recv_buff;
    std::cout << "Received message: " << recv_mess << std::endl;

  }
  catch(std::exception e){
    std::cout << e.what() << std::endl;
  }

  return 0;
}
