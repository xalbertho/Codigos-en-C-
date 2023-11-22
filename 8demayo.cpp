//programa que este leyendo los caracteres y los sume hvh

#include <iostream>
 #include <cctype>

int main(){
    unsigned int frecuencias[5]{0};
    char letra{};


    do{

        std::cout<<"Proporciona una letra";
        std::cin>>letra;
        letra =std::toupper(letra);

        switch(letra){
        case 'A':frecuencias[0]++;
        break;
        case 'E':frecuencias[1]++;
        break;
        case 'I':frecuencias[2]++;
        break;
        case 'O':frecuencias[3]++;
        break;
        case 'U': frecuencias[4]++;
        break;

        }

    }while(std::toupper(letra)!='x');


    std::cout<<"Frecuencias " <<std::endl;

    for(size_t i{0}; i<5; i++){
        char letraIndice{};
        letraIndice= i==0 ? 'A' : ;
        letraIndice= i==1 ? 'E' : ;
        letraIndice= i==2 ? 'I' : ;
        letraIndice= i==3 ? 'O' : ;
        letraIndice= i==4 ? 'U' : ;

    std::cout<<"Frecuencias "<<letraIndice<<":"<<frecuencias[i]<<std::endl;
    }









return 0;
}
