#include "../../include/Sockets/ListenSocket.h"


ListenSocket::ListenSocket() {
    const int reuse_adress = 1;
    if(setsockopt(adr_socket, SOL_SOCKET, SO_REUSEADDR, &reuse_adress, sizeof(reuse_adress)) == -1)
        throw std::logic_error("setsockopt");
   if( (bind(adr_socket, (struct sockaddr*)&serverAddress, sizeof(serverAddress))) == -1){
    throw std::logic_error("error in bind");
   }
  
   if(listen(adr_socket, 5) == -1)
    throw std::logic_error("listen"); 
}

void ListenSocket::l_connect()
{   
    while(clientSocket == -1){
        
        clientSocket = accept(adr_socket, nullptr, nullptr);
        if(clientSocket == -1 && errno != EINTR){
            throw std::logic_error("accept");
        }
    }
}
void ListenSocket::closing_sock() {
    if(clientSocket != -1){
        close(clientSocket);
        clientSocket = -1;
    }

}
std::string ListenSocket::listen_s()
{

    while(true){
        std::size_t end_of_message = recieve.find('\n');
        if(end_of_message != std::string::npos){
            std::string message = recieve.substr(0, end_of_message);            
            recieve.erase(0, end_of_message+1);
            return message;
        }
        if(clientSocket == -1){
            l_connect();
        }
        char buffer[1024] = {0};
        ssize_t s = recv(clientSocket, &buffer, sizeof(buffer), 0);
        if(s > 0){
            recieve.append(buffer, static_cast<std::size_t>(s));
            continue;
        }

        if(s == -1 && errno == EINTR){
            continue;
        }
        
        closing_sock();
        
    }
}
bool ListenSocket::send_OK(){
    char ok[] = "OK\n";
    std::size_t sent = 0;
    while(sent < sizeof(ok)-1){
        ssize_t result = send(clientSocket, ok + sent, sizeof(ok) - 1 - sent, MSG_NOSIGNAL);
        if(result == -1){
            if (errno == EINTR){
                continue;
            }
            
            closing_sock();
            return false;
        }
        if(!result){
            closing_sock();
            return false;
        }
        sent += static_cast<std::size_t>(result);
        
    }
    return true;
}
ListenSocket::~ListenSocket(){

}