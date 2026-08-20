#include "../../include/Sockets/SenderSocket.h"

SenderSocket::SenderSocket() {
   
}

bool SenderSocket::connect_s()
{
    if(connected)
        return true;

    if (adr_socket == -1) {
        adr_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (adr_socket == -1) {
            std::cout << "socket creation failed\n";
            return false;
        }
    }
    const timeval receive_timeout{2,0};
    

    if (setsockopt(adr_socket, SOL_SOCKET, SO_RCVTIMEO,
                   &receive_timeout, sizeof(receive_timeout)) == -1) {
        std::cout << "not sockopt\n";
                    disconnect();
        return false;
    }
    if (connect(adr_socket, reinterpret_cast<sockaddr*>(&serverAddress), sizeof(serverAddress)) == -1) {
        std::cout << "not connect\n";
        disconnect();
        return false;
    }
        
    std::cout << (connected = true) << "\n";
    return true;
}

void SenderSocket::disconnect(){
    connected = false;
    close(adr_socket);
    adr_socket = -1;

}

bool SenderSocket::send_s(int to_send){
    if(!connected)
        return false;

        std::string message = std::to_string(to_send) + '\n';
        std::size_t sent = 0;
         
        while(sent < message.size()){
            const ssize_t res = send(adr_socket, message.data() + sent, message.size() - sent, MSG_NOSIGNAL);
            
            if(res == -1){
                if(errno == EINTR){
                    continue;
                }    
                disconnect();
                return false;
            }
            if(!res){
                disconnect();
                return false;
            }
            sent += static_cast<std::size_t>(res);
        }
        std::string ok;
        char buf[32];
        while(ok.find('\n') == std::string::npos){
            const ssize_t res = recv(adr_socket, buf, sizeof(buf),0);
            if(res > 0){
                ok.append(buf, static_cast<std::size_t>(res));
                continue;
            }
            if(res == -1 && errno == EINTR){
                continue;
            }
            disconnect();
            return false;
        }
        if(ok.substr(0, ok.find('\n')) != "OK"){
            disconnect();
            return false;
        }
       
        return true;
    }

SenderSocket::~SenderSocket(){
    
}