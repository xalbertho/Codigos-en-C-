//clase miercoles 26 de abril
//UN programa que calcule el modulo de un vector

#include <iostream>
#include <cmath>

// prototipo de la funcion

double moduloVector(double, double, double);

int main(){
    double xe{3.0};
    double ye{-2.3};
    double ze{6.8};

    double modulo{moduloVector(xe,ye,ze)};

    std::cout<<modulo<<std::endl;
    std::cout<<moduloVector(xe,ye,ze)<<std::endl;



return 0;
}


double moduloVector(double cx, double cy, double cz){
    double moduloResultado{std::sqrt(cx*cx+cy*cy+cz*cz)};
    return moduloResultado;

}
