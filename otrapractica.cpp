#include <iostream>
#include <string>
int main(){
std::string nombre{""};
std::cout<<"capture su nombre=>";
std::getline(std::cin,nombre);

std::cout<<"Bienvenido(a)"<<nombre<<std::endl;





return 0;
}
