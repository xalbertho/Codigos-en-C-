#include <iostream>


int main() {
    int n;
   std:: cout << "Ingrese un n�mero impar para el tama�o del rombo: ";
    std::cin >> n;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n - abs(n/2 - i); j++) {
            std::cout << "*";
        }
       std:: cout <<std:: endl;
    }
    return 0;
}
