/**
 * @file main.cpp
 * @brief Programa para calcular el valor total de venta de productos en un almac�n de pedidos por correo.
 * @author TuNombre
 * @date 2023-04-10
 */

#include <iostream>
#include <iomanip>

using namespace std;

/**
 * @brief Punto de entrada principal del programa.
 *
 * Este programa lee una serie de pares de n�meros (n�mero del producto y cantidad vendida)
 * y utiliza una instrucci�n switch para determinar el precio de venta de cada producto.
 * Calcula el valor total de venta de todos los productos vendidos y muestra el resultado
 * cuando el usuario ingresa -1.
 *
 * @return int C�digo de salida del programa (0 para �xito).
 */
int main() {
    int producto, cantidad;
    double total = 0.0, precio;

    cout << "Introduzca el n�mero del producto y la cantidad vendida (use -1 para terminar):" << endl;

    while (true) {
        cin >> producto;
        if (producto == -1) break;
        cin >> cantidad;

        switch (producto) {
            case 1:
                precio = 2.98;
                break;
            case 2:
                precio = 4.50;
                break;
            case 3:
                precio = 9.98;
                break;
            case 4:
                precio = 4.49;
                break;
            case 5:
                precio = 6.87;
                break;
            default:
                cout << "N�mero de producto no v�lido. Int�ntalo de nuevo." << endl;
                continue;
        }

        total += precio * cantidad;
        cout << "Introduzca otro n�mero de producto y cantidad vendida (use -1 para terminar):" << endl;
    }

    cout << fixed << setprecision(2);
    cout << "El valor total de venta de todos los productos vendidos es: $" << total << endl;

    return 0;
}

