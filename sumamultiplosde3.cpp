#include <iostream>

int main(){

    long numinicial{};
    long numfinal{};

    std::cin>>numinicial>>numfinal;
    if (numfinal<numinicial) {
        long auxiliar{numfinal};
        numfinal=numinicial;
        numinicial=auxiliar;



                            }

    long suma{0L};
      for(long step{numinicial};step<=numfinal;step++){
        if(step % 3==0){
            suma +=step;

        }


      }
std::cout<<suma<<std::endl;



return 0;
}
