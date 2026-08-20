#include "../include/lib.h"

#include "../include/Sockets/ListenSocket.h"

int main(){
   
ListenSocket server;
    std::string sr = "\0";
    sort_and_replace(sr);
    int con = 0; 
    server.l_connect();
    while(1){

            std::string res = server.listen_s();
            server.send_OK();
            std::cout << res << "\n";
            if(res.size()){
                if(more_2_sym_and_32(res)){
                    std::cout << res << "\n";
                }else{
                    std::cout << "error\n";
                }
            }
        
    }

}