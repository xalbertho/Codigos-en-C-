//funcion que calcula el area de un triangulo???


#include <iostream>
#include <cmath>

double areaTriangulo(double,double);

int main(){

double base{7.8};
double altura{3.7};




double area{areaTriangulo(base,altura)};

std::cout<<area<<std::endl;

return 0;
}

double areaTriangulo(double xbase, double xaltura){
    double areat{(xbase*xaltura/2)};
    return areat;


}
