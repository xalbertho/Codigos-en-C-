
//pongame 6:(

#include <iostream>
#include <bitset>

// Función para aplicar una regla a una célula y sus vecinas
bool aplicarRegla(bool izquierda, bool centro, bool derecha, std::bitset<8> regla) {
    int indice = (izquierda << 2) | (centro << 1) | derecha;
    return regla.test(indice);
}

// Función para mostrar la evolución de un autómata celular dado una regla
void ejecutarAutomata(std::bitset<8> regla, int iteraciones) {
    std::string estadoActual = "0";
    std::cout << estadoActual << std::endl;

    for (int i = 0; i < iteraciones; i++) {
        std::string siguienteEstado;
        int tamano = estadoActual.size();

        for (int j = 0; j < tamano; j++) {
            bool izquierda = (j > 0) ? (estadoActual[j - 1] - '0') : (estadoActual[tamano - 1] - '0');
            bool centro = estadoActual[j] - '0';
            bool derecha = (j < tamano - 1) ? (estadoActual[j + 1] - '0') : (estadoActual[0] - '0');

            siguienteEstado += aplicarRegla(izquierda, centro, derecha, regla) ? '1' : '0';
        }

        std::cout << siguienteEstado << std::endl;
        estadoActual = siguienteEstado;
    }
}

int main() {
    int iteraciones = 10;
    int numeroRegla;

    bool continuarPrograma = true;

    while (continuarPrograma) {
        std::cout << "Ingrese el número de regla (0-255): ";
        std::cin >> numeroRegla;

        if (numeroRegla < 0 || numeroRegla > 255) {
            std::cout << "Número de regla inválido. Debe estar entre 0 y 255." << std::endl;
            continue;
        }

        std::bitset<8> regla(numeroRegla);
        std::string reglaBinaria = regla.to_string();

        std::cout << "Regla " << numeroRegla << " (binario: " << reglaBinaria << "):" << std::endl;
        ejecutarAutomata(regla, iteraciones);

        char eleccion;
        std::cout << "¿Desea ingresar otra regla? (s/n): ";
        std::cin >> eleccion;

        if (eleccion != 's' && eleccion != 'S') {
            continuarPrograma = false;
        }
    }

    return 0;
}
