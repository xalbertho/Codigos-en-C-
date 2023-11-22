#include <iostream>
#include <sstream>

using namespace std;

struct punto{
    double x;
    double y;


};
double calculapendiente(punto,punto);
punto puntomedio(punto, punto);
string creacadena();


int main(){
    punto origen{1,1};
    punto destino{2,2};
    double pendiente{calculapendiente(origen, destino)};
    cout <<"La pendiente es: "<<pendiente<<endl;

    punto pm{puntomedio(origen,destino)};
    cout<<"el punto medio es ("<<pm.x<<","<<pm.y<<")"<<endl;
    string unacadena{creacadena()};
    cout<<unacadena<<endl;


return 0;
}

double calculapendiente(punto pa, punto pb){
    double pendiente{(pb.y-pa.y)/(pb.x-pa.x)};
    return pendiente;

};

punto puntomedio(punto a, punto b){
    double xm{(a.x+b.x)/2};
    double ym{(a.y+b.y)/2};
    punto medio{xm, ym};
    return medio;
}

string creacadena(){
    ostringstream flujo;
    flujo<< "Hola a todos tengo "<<19<<" "<<" y "<< 6 <<"meses";

    return flujo.str();


}
