#include <iostream>

int main(){


    int columnas{};
    int filas{};
    std::cout<<"Introduce un numero"<<std::endl;
    std::cin>>columnas;

    filas=columnas/2;


    for  (int inicio{0};inicio<filas;inicio++){
     for (int de{0};de<columnas;de++){
            std::cout<<'*';

      }
      std::cout<<std::endl;

          }



return 0;
}
