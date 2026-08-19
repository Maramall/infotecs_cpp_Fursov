#include "../include/lib.h"

#include "../include/Sockets/ListenSocket.h"

int main(){
   
ListenSocket server;
    std::string sr = "\0";
    sort_and_replace(sr);
    int con = 0; 
    bool con_is = true;
    con = server.l_connect();
      
        if(con == -1 && con_is){
            std::cout << con << "\n";
            con_is = false;
        }
    while(1){
        if(con != -1){
            con_is = true;
            std::string res = server.listen_s();
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
 //   std::cout << sum_elems(sr) << "\n" << sr;

}