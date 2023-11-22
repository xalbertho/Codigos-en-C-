#include <iostream>
#include <vector>

using namespace std;

const int FILAS = 100; // n�mero de filas en la cuadr�cula
const int COLUMNAS = 100; // n�mero de columnas en la cuadr�cula

// Definimos la estructura de una celda en la cuadr�cula
struct Celda {
    bool estado; // estado de la celda (true = blanco, false = negro)
    int hormiga; // n�mero de hormiga en la celda (0 = sin hormiga)
};

// Funci�n para imprimir la cuadr�cula
void imprimirCuadricula(vector<vector<Celda>>& cuadricula) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (cuadricula[i][j].estado) {
                cout << " "; // si la celda est� en blanco, imprimimos un espacio en blanco
            } else {
                cout << "#"; // si la celda est� en negro, imprimimos un s�mbolo #
            }
        }
        cout << endl;
    }
}

// Funci�n para actualizar el estado de una celda seg�n la regla "Ant"
void actualizarCelda(Celda& celda) {
    if (celda.estado) { // si la celda est� en blanco
        celda.estado = false; // cambiamos su estado a negro
        switch (celda.hormiga) { // cambiamos la direcci�n de la hormiga seg�n su n�mero
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
    } else { // si la celda est� en negro
        celda.estado = true; // cambiamos su estado a blanco
        switch (celda.hormiga) { // cambiamos la direcci�n de la hormiga seg�n su n�mero
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
    vector<vector<Celda>> cuadricula(FILAS, vector<Celda>(COLUMNAS)); // creamos una cuadr�cula de celdas vac�as

    // colocamos una hormiga en el centro de la cuadr�cula
    int filaInicial = FILAS / 2;
    int columnaInicial = COLUMNAS / 2;
    cuadricula[filaInicial][columnaInicial].hormiga = 0;

    // simulamos el comportamiento de la hormiga durante un n�mero determinado de pasos
    int numPasos = 10000;
    for (int i = 0; i < numPasos; i++) {
        Celda& celdaActual = cuadricula[filaInicial][columnaInicial]; // obtenemos la celda actual donde est� la hormiga
        actualizarCelda(celdaActual); // actualizamos el estado de la celda seg�n la regla "Ant"
        switch (celdaActual.hormiga) { // movemos la hormiga a la siguiente celda seg�n su direcci�n
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
        if (filaInicial < 0) filaInicial = FILAS - 1; // si la hormiga se sale de los l�mites de la cuadr�cula, la hacemos aparecer por el otro lado
        if (filaInicial >= FILAS) filaInicial = 0;
        if (columnaInicial < 0) columnaInicial = COLUMNAS - 1;
        if (columnaInicial >= COLUMNAS) columnaInicial = 0;
    }

    imprimirCuadricula(cuadricula); // imprimimos la cuadr�cula final
    return 0;
}


