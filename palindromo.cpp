#include <iostream>
#include <string>
#include <algorithm>



bool es_palindromo(std::string palabra) {
    std::string palabra_invertida = palabra;
    std::reverse(palabra_invertida.begin(), palabra_invertida.end());
    return palabra == palabra_invertida;
}

int main() {
    std::string palabra{};
    std::cout << "Ingrese una palabra: ";
    std::cin >> palabra;
    if (es_palindromo(palabra)) {
        std::cout << "La palabra es un palindromo." <<std:: endl;
    } else {
        std::cout << "La palabra no es un palindromo." <<std:: endl;
    }
    return 0;
}

