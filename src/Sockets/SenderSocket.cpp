#include "../../include/Sockets/SenderSocket.h"

SenderSocket::SenderSocket() {
    connect(adr_socket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
}


void SenderSocket::send_s(){
    const char* message = "Hello, server!";
    send(adr_socket, message, strlen(message), 0);
}

SenderSocket::~SenderSocket(){
    
}