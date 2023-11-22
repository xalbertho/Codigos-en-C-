#include <iostream>

using namespace std;

int main(){

    double arreglo[]{1.1,1.2,1.3,1.4,1.5};
    double *arrPtr{nullptr};
    arrPtr = arreglo;                      //el arreglo lo podemos ver como un apuntador al primer elemento
    cout<<"Arreglo recorrido con el indice: "<<endl;

    for(size_t i{0};i<5;i++){
        cout<<"Arreglo["<<i<<"]="<<arreglo[i]<<endl;
    }

    cout<<"Arrar recorrido con un offset: "<<endl;
    for(size_t offset{0};offset<5; offset++){
        cout<<"*(arrPtr+"<<offset<<")= " << *(arrPtr+offset)<<endl;
    }


    //apuntador
     cout<<"Arreglo recorrido con un apuntador e indice: "<<endl;
    for(size_t j{0};j<5;j++){
        cout<<"arrPtr["<<j<<"]="<<arreglo[j]<<endl;
    }


     cout<<"Arrar recorrido con un arreglo como apuntador: "<<endl;
    for(size_t offset{0};offset<5; offset++){
        cout<<"*(arrPtr+"<<offset<<")= " << *(arreglo+offset)<<endl;
    }


return 0;
}
