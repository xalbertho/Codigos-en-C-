#include <iostream>

int main(){
    char letra{'A'};
    char *pl{nullptr};

    pl=&letra;

    std::cout<<"Direccion de letra es: "<<std::hex<<(long)&letra
             <<"\n El valor de pl es : "<<(long) pl<<std::endl;

    std::cout<<"Valor de letra es: "<<letra
             <<"\n El valor de *pl es : "<< *pl<<std::endl;







return 0;
}
