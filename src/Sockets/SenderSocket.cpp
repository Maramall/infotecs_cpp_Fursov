#include "../../include/Sockets/SenderSocket.h"

SenderSocket::SenderSocket() {
   
}

int SenderSocket::connect_s()
{
    if(!connected){
        if( (connect(adr_socket, (struct sockaddr*)&serverAddress, sizeof(serverAddress))) == -1){
            std::cout << "error in connect\n";
            return -1;
        }else{
            std::cout << "connected\n";
            connected = true;
            return 0;
        }
    }
    std::cout << "already connected\n";
    return 0;
    
}

int SenderSocket::send_s(int to_send){
    if(connected){
        std::string tos = std::to_string(to_send);
        const char* message = tos.data();
        int sended = send(adr_socket, message, strlen(message), 0);
        if(sended == -1){
            connected = false; 
            close(adr_socket);
            std::cout << "not sended\n";
        }else{
            std::cout << "sended: " << message << "\n";
        }
            return sended;

    }else{
        return -1;
    }
}
SenderSocket::~SenderSocket(){
    
}