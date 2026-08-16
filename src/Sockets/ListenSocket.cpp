#include "../../include/Sockets/ListenSocket.h"

ListenSocket::ListenSocket() {
   
    bind(adr_socket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
    
}

std::string  ListenSocket::listen_s(){
   int l = listen(adr_socket, 5);
   //std::cout << "res of listen: " << l << "\n"; 
   int clientSocket = accept(adr_socket, nullptr, nullptr);
    if(clientSocket != -1){
      //  std::cout << "start listening in " << clientSocket << "\n";
        char buffer[1024] = { 0 };
        int s= recv(clientSocket, &buffer, sizeof(buffer), 0);
        //std::cout << "res: " << s << "\nMessage from client: " << buffer << "\n";
        //std::cout << buffer << "\n";
        close(clientSocket);
        return buffer;
    }
    else{
        std::cout << "not accept\n";
        return "\0";
    }
}

ListenSocket::~ListenSocket(){

}