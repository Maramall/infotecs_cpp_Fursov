#include "../../include/Sockets/BaseSocket.h"


Socket::Socket(){
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
   
}

Socket::~Socket(){

   
    close(adr_socket);
}

