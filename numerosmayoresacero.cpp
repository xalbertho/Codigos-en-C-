#include <iostream>
#include <math.h>

int main(){
  int numero{};
  int contador{};

  do{
        std::cout<<"Digite un numero: "<<std::endl; std::cin>>numero;
        if(numero>0){
            contador++;
        }

  }while(numero!=0);

  std::cout<<"El total de numeros mayores a cero es: "<<contador<<std::endl;



return 0;
}
