#include "../../include/Sockets/ListenSocket.h"

ListenSocket::ListenSocket() {
   
    bind(adr_socket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
    
}

void ListenSocket::listen_s(){
    listen(adr_socket, 5);
    int clientSocket = accept(adr_socket, nullptr, nullptr);
    char buffer[1024] = { 0 };
    recv(clientSocket, buffer, sizeof(buffer), 0);
    std::cout << "Message from client: " << buffer << "\n";
}

ListenSocket::~ListenSocket(){

}