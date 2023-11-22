#include <iostream>
#include <cctype>

int main(){

int temperatura{};
int contador{};
double suma{};
double promedio{};
char respuesta{};

do{
    std::cout<<"capture temperatura:";
    std::cin>>temperatura;
    suma +=temperatura;
    contador++;
    std::cout<<"Proporcionara otra temperatura(s/n):";
    std::cin>>respuesta;

}while(std::tolower(respuesta)=='s');

    promedio=suma/static_cast<double>(contador);
 std::cout<<"el promedio es:"<<promedio<<std::endl;




return 0;
}
