//ejercicio de apuntadores lunees
//ejemplo de paso por referencia, cambiando el valor de la variable original


#include <iostream>
void funcion(char*);


int main(){
    char letra{'A'};
    char *pl{nullptr};

    pl=&letra;

    std::cout<<"Direccion de letra es: "<<std::hex<<(long)&letra
             <<"\n El valor de pl es : "<<(long) pl<<std::endl;

    std::cout<<"Valor de letra es: "<<letra
             <<"\n El valor de *pl es : "<< *pl<<std::endl;



             std::cout<<"Valor de char antes de funcion= "<<letra<<std::endl;

             funcion(pl);
             std::cout<<"Valor de char despues de funcion = "<<letra<<std::endl;

return 0;
}


    void funcion(char *puntero){
    *puntero='W';
    }
