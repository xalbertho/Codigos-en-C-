#include <iostream>
#include <math.h>


int main(){
float a{};
float b{};
float c{};
float *x1{};
float *x2{};


std::cout<<"ingresa el valor de a "<<std::endl; std::cin>>a;
std::cout<<"Ingrese el valor de b "<<std::endl; std::cin>>b;
std::cout<<"Ingrese el valor de b"<<std::endl; std::cin>>c;

bool chicharronera(a,b,c,*x1,*x2);{
     discriminante(pow(b,2)-4*a*c);
     if (discriminante<=0){ return false;}

     *x1=(-b+discriminante)/2*a
     *x2=(-b-discriminante)/2*a

}

return 0;
}
