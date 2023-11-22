#include <iostream>



int main(){

    std::cout<<"Introduce una letra del abecedario en mayuscula "<<std::endl;
 char letra{};
 std::cin>>letra;
 if (std::isalpha(letra)){
char mayuscula{std::tolower(static_cast<int>(letra))};
 switch (mayuscula){
     case'a' :

     case'e':
      case'i':
      case'o':
      case'u':
        std::cout<<letra<<" es una vocal"<<std::endl;
        break;
      default:
        std::cout<<letra<<" Es una consonate"<<std::endl;


 };
 }else{
      std::cout<<letra<<" Caracter no es alfabetico..FIN"<<std::endl;


 }
 return 0;
 }
