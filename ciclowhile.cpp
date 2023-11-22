#include <iostream>

int main(){
int dato{};
int contador{};
long suma{};
double promedio{};

std::cout<<"Intdroduzca un entero:(Una letra para terminar)"
          <<std::endl;

 while(std::cin>>dato){
    suma +=dato;
    contador++;


 }

 promedio=static_cast<double>(suma)/
            static_cast<double>(contador);

 std::cout<<"El promedio es:"<<promedio<<std::endl;






return 0;
}
