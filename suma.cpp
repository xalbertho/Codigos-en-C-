# include <iostream>
#include <clocale>

int main (){
  std::setlocale(LC_ALL,"spanish");




int edad{};
//int edad
size_t  tamShort{sizeof(edad)};
//size_t  tamshort{sizeof(edad)};
std:: cout<<"Tamaño en bytes de short :"
 <<tamShort <<std::endl;

long hols{};
size_t tamShort{sizeof(hols)};
std:: cout<<"Tamaño en bytes de long :"
  <<tamShort <<std::endl;

long long hola{};
size_t tamshort{sizeof(hola)};
 std::cout<<"Tamaño en bytes de longlong:"
  <<tamshort <<std::endl;



    return 0;
}




