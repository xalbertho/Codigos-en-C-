#include <iostream>

int main() {
    int numero;

    std::cout << "Por favor ingrese un numero entre 2 y 12: ";
    std::cin >> numero;

    if (numero >= 2 && numero <= 12) {
        for (int inicio = 1; inicio <= numero; ++inicio) {

            std::cout << "Tabla del " << inicio << ":" << std::endl;
            for (int contador = 1; contador <= 10; ++contador) {
                std::cout << inicio << " x " << contador << " = " << inicio * contador << std::endl;
            }
            std::cout << std::endl;
        }
    } else {
        std::cout << "El numero ingresado no esta en el rango permitido (2-12)." << std::endl;
    }

    return 0;
}

