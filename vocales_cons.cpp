#include <iostream>



int main(){

    std::cout<<"Introduce una letra del abecedario en mayuscula "<<std::endl;
 char opcion{};
 std::cin>>opcion;

 switch (opcion){
    case 'A':std::cout<<opcion <<"A es una vocal"<< std::endl;

              break;

        case 'i':std::cout<<opcion <<"i es una vocal"<< std::endl;

              break;

         case 'O':std::cout<<opcion <<"O es una vocal"<< std::endl;

              break;
           case 'U':std::cout<<opcion <<"U es una vocal"<< std::endl;

              break;

           case 'E':std::cout<<opcion <<"E es una vocal"<< std::endl;

              break;

           default:
        std::cout<<opcion<<" es una consonante"<<std::endl;

 };







}
