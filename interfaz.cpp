#include <iostream>
#include <string>

int main() {
    std::cout << "Iniciando interfaz..." << std::endl;

    while (true) {
        std::string input;
        std::cout << "Ingrese un valor le�do del amper�metro ('x' para detener): ";
        std::getline(std::cin, input);

        if (input == "x") {
            break;
        }

        int sensorValue = std::stoi(input);
        std::cout << "Valor le�do del amper�metro: " << sensorValue << std::endl;
        // Aqu� puedes agregar cualquier l�gica adicional que desees realizar con los datos

        std::cout << std::endl;
    }

    std::cout << "Interfaz finalizada." << std::endl;
    return 0;
}
