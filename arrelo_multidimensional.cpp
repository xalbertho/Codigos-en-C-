#include <iostream>

using namespace std;

int main(){
    size_t nfilas{};
    size_t ncolumnas{};
    cout<<"Filas "<<endl;
    cin>>nfilas;
    cout<<"Columnas"<<endl;
    cin>>ncolumnas;

    int matriz[nfilas][ncolumnas]{};
    for(size_t i{};i<nfilas;i++){
        for(size_t j{}; j<ncolumnas;j++) {
            matriz[i][j]=i+j;
        }

    }

    for(size_t i{};i<nfilas;i++){
        for(size_t j{};j<ncolumnas;j++){
            cout<<" "<<matriz[i][j];

        }
        cout<<endl;
    }


return 0;
}
