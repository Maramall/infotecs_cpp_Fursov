#include "../../include/Sockets/ListenSocket.h"

ListenSocket::ListenSocket() {
   if( (bind(adr_socket, (struct sockaddr*)&serverAddress, sizeof(serverAddress))) == -1){
    std::cout << "error in bind\n";
    return;
   }
   listen(adr_socket, 5);
}

int ListenSocket::l_connect()
{
    clientSocket = accept(adr_socket, nullptr, nullptr);
    return clientSocket;
}
std::string ListenSocket::listen_s()
{
    char buffer[1024] = { 0 };
    int s = recv(clientSocket, &buffer, sizeof(buffer), 0);
    return buffer;
    if(s == -1){
        std::cout << "not accept\n";
        return "\0";
    }
}

ListenSocket::~ListenSocket(){

}