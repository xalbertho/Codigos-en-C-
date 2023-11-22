#include <iostream>
#include <string>

int main() {
    std::cout << "Iniciando interfaz..." << std::endl;

    while (true) {
        std::string input;
        std::cout << "Ingrese un valor leído del amperímetro ('x' para detener): ";
        std::getline(std::cin, input);

        if (input == "x") {
            break;
        }

        int sensorValue = std::stoi(input);
        std::cout << "Valor leído del amperímetro: " << sensorValue << std::endl;
        // Aquí puedes agregar cualquier lógica adicional que desees realizar con los datos

        std::cout << std::endl;
    }

    std::cout << "Interfaz finalizada." << std::endl;
    return 0;
}
