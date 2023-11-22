#include <iostream>

int main (){

    int numero{};
    std::cout<<"Introduce tu numero"<<std::endl;
    std::cin >>numero;

    for(size_t contador{1};contador<=10; contador++){

            int f{numero*contador};
            std::cout<<numero<<"x"<<contador
            <<"="<<numero*contador<<std::endl;

    }





return 0;
}
