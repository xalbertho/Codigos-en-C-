#include <iostream>
#include <string>
#include <clocale>

// la mayoria de edad ahora es = 21 antes 18
// Minoria de edad son = 14 antes 15
//Edad de 2 horas..15 y20

int main(){
std::setlocale(LC_ALL,"spanish");
short edad{};

std::string nombre{""};
std::cout<<"¿Cúal es su nombre?";
std::getline(std::cin,nombre);


std::cout<<"¿Cuantos años tienes?"<<std::endl;
std::cin>>edad;
// numeros magicos edad<15


    if (edad<=15){
        std::cout<<" Vete a tu casa "<<nombre<<std::endl;
     }

    else if (edad==16||edad==17){
        std::cout<<" Puedes entrar 2 horas "<<nombre<<std::endl;
    }
    else {

        std::cout<<nombre<<" Bienvenido puedes pasar "<<std::endl;
    }




return 0;
}
