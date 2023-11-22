#include <iostream>
#include <string>
#include <random>

//using namespace std;
void imprimealeatorios(std::default_random_engine);

int main(){

    int usuario_ganados = 0;
    int computadora_ganados = 0;


    // Inicializar la semilla aleatoria

    std::default_random_engine generador;

    // Declarar las opciones del juego en forma de arreglo de valor 5
    std::string opciones[5] = {"Piedra", "Papel", "Tijera", "Lagarto", "Spock"};

    // Declarar las reglas del juego para la opcion seleccionada
    std::string reglas[5][5] = {
        {"Empate", "Gana Papel", "Gana Piedra", "Gana Piedra", "Gana Spock"},
        {"Gana Papel", "Empate", "Gana Tijera", "Gana Lagarto", "Gana Papel"},
        {"Gana Piedra", "Gana Tijera", "Empate", "Gana Lagarto", "Gana Spock"},
        {"Gana Piedra", "Gana Lagarto", "Gana Lagarto", "Empate", "Gana Tijera"},
        {"Gana Spock", "Gana Papel", "Gana Spock", "Gana Tijera", "Empate"}
    };


    // Jugar hasta que alguien gane 4 veces
    while (usuario_ganados < 4 && computadora_ganados < 4)
    {
        // Mostrar las opciones del juego
        std::cout << "Opciones: " <<std::endl;;
        for (int i = 0; i < 5; i++)
        {
            std::cout << i + 1 << ". " << opciones[i] << " ";
        }
        std::cout <<std:: endl;

        // Pedir al usuario que elija una opción entre 1 y 5
        int opcion_usuario;
        std::cout << "Elija una opcion (1-5): ";
        std::cin >> opcion_usuario;
        opcion_usuario--;

        // Generar la opción de la computadora aleatoriament entre las 5 posibles opciones
        int opcion_computadora = generador()%5;

        // Mostrar las opciones elegidas
        std::cout << "Usuario eligio: " << opciones[opcion_usuario] <<std:: endl;
        std::cout << "Computadora eligio: " << opciones[opcion_computadora] << std::endl;

        // Determinar el ganador y mostrar el resultado
        std::string resultado = reglas[opcion_usuario][opcion_computadora];
        if (resultado == "Empate")
        {
            std::cout << "Empate" <<std:: endl;
        }
        else if (resultado.substr(0, 4) == "Gana")
        {
            std::cout << "Usuario gana" <<std:: endl;
            usuario_ganados++;
        }

        else
        {
            std::cout << "Computadora gana" <<std:: endl;
            computadora_ganados++;
        }

        // Mostrar los juegos ganados hasta el momento
        std::cout << "Usuario: " << usuario_ganados << ", Computadora: " << computadora_ganados <<std:: endl;
    }

    // Determinar el ganador final y mostrar el resultado
    if (usuario_ganados >= 4)
    {
        std::cout << "Usuario gana el juego" <<std:: endl;
    }
    else
    {
        std::cout << "Computadora gana el juego" <<std:: endl;
    }


    return 0;
}


