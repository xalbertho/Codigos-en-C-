#include <iostream>

int main(){

const double PI{3.1416};
// definimos la vvariable  del radio inicialmente definida en cero
double radio{};
// indtrudicimos la insercion de flujo
std:: cout<<"introduce el radio :";
// introducimos cin para guardar datos del teclado
std::cin>> radio;
// guardamos otra variable area donde se guarda la operacion del area
double area{PI*radio*radio};
// introducimos la cout con un salto de linea para devolver el area y cerramos con un endl
std::cout<<"\nEl area de un circulo es :"<< area<<std::endl;


return 0;

}
