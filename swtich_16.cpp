#include <iostream>

int main(){
char opcion{};



std::cin>>opcion;

switch(opcion){

      case 'S':std::cout<<"opcion S"<< std::endl;
              std::cout<<"linea de opcion S"<<std::endl;
              break;

      case 'N':std::cout<<"Opcion N"<<std::endl;
               std::cout<<"Linea de opcion N"<<std::endl;
               break;
     case 'a': std::cout<<"Opcion a"<<std::endl;
               std::cout<<"linea de opcion a"<<std::endl;
               break;
     default:
        std::cout<<"opcion no reconocida"<<std::endl;


};



return 0;
}
