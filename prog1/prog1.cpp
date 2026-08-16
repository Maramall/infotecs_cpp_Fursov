#include "../include/lib.h"
#include "../include/Sockets/SenderSocket.h"
#include <vector>
bool is_only_digit_and_len_less_64(const std::string &str){

    if(str.size() > 64)
        return false;
    for(auto &e : str){
        if(e < '0' || e > '9')
            return false;
    }
    return true;
}


int main(){
    

    std::string sr = "He12llo44";
    std::vector<std::string> buffer ;
     //thread1
    while(true){
        std::cin >> sr;
        if(is_only_digit_and_len_less_64(sr)){
            sort_and_replace(sr);
            buffer.push_back(sr);
        }
               if(buffer.size()){
            std::string from_buffer = buffer[buffer.size()-1]; 
           
            std::cout << from_buffer;
            int to_prog2 = sum_elems(from_buffer);
            try{
            SenderSocket client;
            client.send_s(to_prog2);
            buffer.pop_back();
          }
          catch(std::logic_error& msg){
            std::cout << msg.what() << '\n';
          }
        }

    }
    
    
    
    

    //thread2

}