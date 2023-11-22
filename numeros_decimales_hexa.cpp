#include <iostream>
#include <iomanip>
#include <cctype>
#include <limits>

int main(){

  std::cout<<std::setw(11)<<"Caracter"
        <<std::setw(11)<<"hexadecimal"
           <<std::setw(11)<<"decimal"<<std::endl;

   unsigned char ch{};
   do{
        if(!std::isprint(ch)){
                continue;
        }


       std::cout<<std::setw(6)<<ch
                <<std::hex<<std::setw(12)<<(int)ch
                <<std::dec <<std::setw(12)<<(int)ch
                <<std::endl;
   }while(ch++<std::numeric_limits<unsigned char>::max());






return 0;
}
