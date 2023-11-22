#include <iostream>
#include <cctype>
#include <iomanip>
int main(){
    size_t tabla{};
    const size_t tabla_min{2};
    const size_t tabla_max{12};
    char respuesta{};


    do{
        std::cout<<"De un numero("<<tabla_min<<"y"
        <<tabla_max<<")?";
        std::cin>>tabla;
        if(tabla<tabla_min||tabla>tabla_max){
                std::cout<<"Tamaño de tabla invalido. Programa terminado"<<std::endl;
                return 1;
        }
                std::cout<<"|";




                for(size_t i{1}; i<=tabla;i++){
                    std::cout<<" "<<i<<"|";

                }
                std::cout<<std::endl;
                for(size_t i{0}; i<=tabla;i++){
                    std::cout<<"----";

                }

                std::cout<<std::endl;

                for(size_t i{1};i<=10;i++){
                    std::cout<<i<<"|";
                    for(size_t j{1};j<=tabla;j++){
                        std::cout<<i*j<<"|";
                    }
                    std::cout<<std::endl;

                }

     std::cout<<"\nQuiere dar otro numero (s/n)?:";
     std::cin>>respuesta;

    }while(std::tolower(respuesta)=='s');















return 0;
}
