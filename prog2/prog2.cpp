#include "../include/lib.h"

#include "../include/Sockets/ListenSocket.h"

int main(){
   
ListenSocket server;
    std::string sr = "He12llo44";
    sort_and_replace(sr);
     while(1){
        std::string res = server.listen_s();
        if(res.size()){
            if(more_2_sym_and_32(res)){
                std::cout << res << "\n";
            }else{
                std::cout << "error\n";
            }
        }
    }
 //   std::cout << sum_elems(sr) << "\n" << sr;

}