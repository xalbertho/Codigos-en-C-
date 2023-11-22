#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>



int main() {
    srand(time(NULL)); // Inicializar el generador de números aleatorios
    int victoriasJugador = 0;
     int victoriasComputadora = 0;
      int empates = 0;
    std::string opciones[5] = {"piedra", "papel", "tijera", "lagarto", "spock"};

    while (victoriasJugador < 4 && victoriasComputadora < 4) {
        int opcionJugador;
       std:: cout << "Elige tu opción (0=piedra, 1=papel, 2=tijera, 3=lagarto, 4=spock): "<<std::endl;;
        std::cin >> opcionJugador;

        if (opcionJugador < 0 || opcionJugador > 4) {
            std::cout << "Opción inválida, intenta de nuevo." << std::endl;
            continue;
        }

        int opcionComputadora = rand() % 5;
        std::cout << "La computadora eligió " << opciones[opcionComputadora] << "." << std::endl;

        if (opcionJugador == opcionComputadora) {
            std::cout << "Empate!" << std::endl;
            empates++;
        } else if
                   ((opcionJugador == 0 && (opcionComputadora == 2 || opcionComputadora == 3)) ||
                   (opcionJugador == 1 && (opcionComputadora == 0 || opcionComputadora == 4)) ||
                   (opcionJugador == 2 && (opcionComputadora == 1 || opcionComputadora == 3)) ||
                   (opcionJugador == 3 && (opcionComputadora == 1 || opcionComputadora == 4)) ||
                   (opcionJugador == 4 && (opcionComputadora == 0 || opcionComputadora == 2))) {
            std::cout << "¡Ganaste!" <<std:: endl;
            victoriasJugador++;
        } else {
            std::cout << "¡Perdiste!" << std::endl;
            victoriasComputadora++;
        }
    }

    if (victoriasJugador > victoriasComputadora) {
        std::cout << "¡Felicidades, ganaste la partida!" <<std:: endl;
    } else {
        std::cout << "Lo siento, perdiste la partida." <<std:: endl;
    }

    std::cout << "Resumen de la partida:" <<std:: endl;
    std::cout << "Victorias del jugador: " << victoriasJugador <<std:: endl;
    std::cout << "Victorias de la computadora: " << victoriasComputadora << std::endl;
    std::cout << "Empates: " << empates <<std:: endl;

    return 0;
}
