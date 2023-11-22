//calcular el numero de aprobados y suspendidos

#include <iostream>
#include<iomanip>
#include <string>
#include <vector>

using namespace std;

struct tficha{
    string nombre;
    float nota;
};  //Estructura de datos tficha

int main(){
    vector<tficha> alumno; //matriz de estructura o registro vacio
    //Entrada de datos
    cout<<"Introducir datos: ";
    cout<<"Para finalizar teclee la marca de fichero\n\n";

    tficha un_alumno;
    cout <<"nombre: "; getline(cin,un_alumno.nombre);

    while (!cin.eof())
    {
        cout<<"Nota:     ";cin>> un_alumno.nota;
        cin.ignore(); //eliminar el caracter \n
        alumno.push_back(un_alumno); //añadimos un alumno a la matriz

        //Para el siguiente alumno

        cout<<"Nombre: "; getline(cin,un_alumno.nombre);
    }

    //contar los aprobados y los suspendidos

    int aprobados=0, suspendidos=0;
    size_t n=0, i=0;
    n=alumno.size();

    for (i=0; i<n; i++)
        if (alumno[i].nota>=5)
        aprobados++;
        else
        suspendidos++;


    //escribir los resultados
    cout<<setprecision(4);
    cout<<"Aprobados: "<<static_cast<float>(suspendidos)/n*100<<"%";






return 0;
}
