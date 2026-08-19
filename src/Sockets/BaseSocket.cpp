#include "../../include/Sockets/BaseSocket.h"


Socket::Socket(){
    if((adr_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        std::cout << "error in creating socket\n";
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
   
}

Socket::~Socket(){
    close(adr_socket);
}

