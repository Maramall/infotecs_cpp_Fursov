#include "lib.h"

void sort_and_replace(std::string & str){
sort(str.rbegin(), str.rend());
{int b = str.size();
for(int i = 1; i < b; i+=2){
    str.erase(str.begin()+i);
}

for(int i = 1; i < b; i+=2){
    str.append("KB", i);
}

}

}
int64_t sum_elems(const std::string &str){
    bool start_digit = false;
    int64_t sum = 0;
    int64_t cur_num = 0;
    for(char e : str){
        if(e >= '0' && e <= '9'){
            if(!start_digit){
                start_digit = true;
            }else{
                cur_num *= 10;
            }
            cur_num += e - '0';
                
        }else{
            start_digit = false;
            sum += cur_num;
            cur_num = 0;
        }
    }
    return sum;
}
bool more_2_sym_and_32(const std::string &str){
    if(str.size() > 2){
        if(sum_elems(str) % 32 == 0){
            return true;
        }
    }

    return false;
}