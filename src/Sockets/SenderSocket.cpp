#include "../../include/Sockets/SenderSocket.h"

SenderSocket::SenderSocket() {
    if(connect(adr_socket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1){
        throw std::logic_error("not connect");
    }
}


void SenderSocket::send_s(int to_send){

    std::string tos = std::to_string(to_send);
    const char* message = tos.data();
    auto ms = send(adr_socket, message, strlen(message), 0);
    std::cout << "sended: " << message << " in ms: " << ms << "\n"; 
}

SenderSocket::~SenderSocket(){
    
}