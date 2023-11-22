#include <iostream>
#include <vector>

using namespace std;

const int FILAS = 100; // número de filas en la cuadrícula
const int COLUMNAS = 100; // número de columnas en la cuadrícula

// Definimos la estructura de una celda en la cuadrícula
struct Celda {
    bool estado; // estado de la celda (true = blanco, false = negro)
    int hormiga; // número de hormiga en la celda (0 = sin hormiga)
};

// Función para imprimir la cuadrícula
void imprimirCuadricula(vector<vector<Celda>>& cuadricula) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (cuadricula[i][j].estado) {
                cout << " "; // si la celda está en blanco, imprimimos un espacio en blanco
            } else {
                cout << "#"; // si la celda está en negro, imprimimos un símbolo #
            }
        }
        cout << endl;
    }
}

// Función para actualizar el estado de una celda según la regla "Ant"
void actualizarCelda(Celda& celda) {
    if (celda.estado) { // si la celda está en blanco
        celda.estado = false; // cambiamos su estado a negro
        switch (celda.hormiga) { // cambiamos la dirección de la hormiga según su número
            case 0:
                celda.hormiga = 3;
                break;
            case 1:
                celda.hormiga = 0;
                break;
            case 2:
                celda.hormiga = 1;
                break;
            case 3:
                celda.hormiga = 2;
                break;
        }
    } else { // si la celda está en negro
        celda.estado = true; // cambiamos su estado a blanco
        switch (celda.hormiga) { // cambiamos la dirección de la hormiga según su número
            case 0:
                celda.hormiga = 1;
                break;
            case 1:
                celda.hormiga = 2;
                break;
            case 2:
                celda.hormiga = 3;
                break;
            case 3:
                celda.hormiga = 0;
                break;
        }
    }
}

int main() {
    vector<vector<Celda>> cuadricula(FILAS, vector<Celda>(COLUMNAS)); // creamos una cuadrícula de celdas vacías

    // colocamos una hormiga en el centro de la cuadrícula
    int filaInicial = FILAS / 2;
    int columnaInicial = COLUMNAS / 2;
    cuadricula[filaInicial][columnaInicial].hormiga = 0;

    // simulamos el comportamiento de la hormiga durante un número determinado de pasos
    int numPasos = 10000;
    for (int i = 0; i < numPasos; i++) {
        Celda& celdaActual = cuadricula[filaInicial][columnaInicial]; // obtenemos la celda actual donde está la hormiga
        actualizarCelda(celdaActual); // actualizamos el estado de la celda según la regla "Ant"
        switch (celdaActual.hormiga) { // movemos la hormiga a la siguiente celda según su dirección
            case 0:
                filaInicial--;
                break;
            case 1:
                columnaInicial++;
                break;
            case 2:
                filaInicial++;
                break;
            case 3:
                columnaInicial--;
                break;
        }
        if (filaInicial < 0) filaInicial = FILAS - 1; // si la hormiga se sale de los límites de la cuadrícula, la hacemos aparecer por el otro lado
        if (filaInicial >= FILAS) filaInicial = 0;
        if (columnaInicial < 0) columnaInicial = COLUMNAS - 1;
        if (columnaInicial >= COLUMNAS) columnaInicial = 0;
    }

    imprimirCuadricula(cuadricula); // imprimimos la cuadrícula final
    return 0;
}


