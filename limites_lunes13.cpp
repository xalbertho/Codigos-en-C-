#include <limits>
#include <iostream>

        int main(){
        std::cout<<"Short"<<std::numeric_limits<short>::max()<<std::endl;
        std::cout<<"Short"<<std::numeric_limits<short>::min()<<std::endl;
        std::cout<<"Long"<<std::numeric_limits<long>::max()<<std::endl;
        std::cout<<"Unsigned"<<std::numeric_limits<unsigned>::max()<<std::endl;
        std::cout<<"Unsigned"<<std::numeric_limits<unsigned>::min()<<std::endl;
        std::cout<<"Unsignedshort"<<std::numeric_limits<unsigned>::max()<<std::endl;
return 0;
}
