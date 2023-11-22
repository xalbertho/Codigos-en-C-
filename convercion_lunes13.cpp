#include <iostream>

int main(){

int a{4};
int b{2};

//casting o cast
//static cast <tipo_a_convertir>(dato)
float division{static_cast<float>(b)/static_cast<float>(a)};

//float division{b/a};

std::cout<<division<<std::endl;



return 0;
}
