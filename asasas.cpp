/*4. Escriba un programa que tome cada 4 horas la temperatura exterior,
leyéndola durante un período de 24 horas. Es decir, debe leer 6 temperaturas.
Calcule la temperatura media del día, la temperatura más alta y la más baja.*/

#include <iostream>

int main(){
    float temperatura{};
    float temp_mayor{0};
    float temp_menor{9999};
    float suma{};


     for(int i=0;i<24;i+=4){
        std::cout<<"Ingrese la temperatura a las: "<<i<<std::endl; std::cin>>temperatura;

        suma+=temperatura;
        if(temperatura>temp_mayor){
            temp_mayor=temperatura;
        }
        if(temperatura<temp_menor){
            temp_menor=temperatura;
        }
    }
    float prom{suma/6};

    std::cout<<"La temperatura promedio es: "<<prom<<std::endl;
    std::cout<<"La temperatura mayot es: "<<temp_mayor<<std::endl;
    std::cout<<"La temperatura menor es: "<<temp_menor<<std::endl;
return 0;
}
