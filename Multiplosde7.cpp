#include<iostream>

int main(){

 int n{};
 std::cout<<"Introduce un numero"<<std::endl;
 std::cin>>n;

 for(int i{0}; i<=n; i++){

    if(i%7!=0){
        continue;
    }
    std::cout<<i<<std::endl;

 }






return 0;
}
