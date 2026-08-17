#include "../../include/Sockets/SenderSocket.h"

SenderSocket::SenderSocket() {
   
}

int SenderSocket::s_connect()
{
    return connect(adr_socket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
        
}
int SenderSocket::send_s(int to_send){

    std::string tos = std::to_string(to_send);
    const char* message = tos.data();
    auto ms = send(adr_socket, message, strlen(message), 0);
   // std::cout << "sended: " << message << " in ms: " << ms << "\n"; 
    close(adr_socket);
    return ms;
}

SenderSocket::~SenderSocket(){
    
}