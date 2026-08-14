#include "../include/to_socket.h"
Socket::Socket(bool is_client){
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    if(is_client){
        connect(inf_socket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
    }else{
        bind(inf_socket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
    }
}

void Socket::listen_s(){
    listen(inf_socket, 5);
    int clientSocket = accept(inf_socket, nullptr, nullptr);
    char buffer[1024] = { 0 };
    recv(clientSocket, buffer, sizeof(buffer), 0);
    std::cout << "Message from client: " << buffer << "\n";
}

void Socket::send_s(){
    const char* message = "Hello, server!";
    send(inf_socket, message, strlen(message), 0);
}
Socket::~Socket(){
    close(inf_socket);
}