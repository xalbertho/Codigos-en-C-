#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int producto, cantidad;
    double total = 0.0, precio;

    cout << "Introduzca el número del producto y la cantidad vendida (use -1 para terminar):" << endl;

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
                cout << "Número de producto no válido. Inténtalo de nuevo." << endl;
                continue;
        }

        total += precio * cantidad;
        cout << "Introduzca otro número de producto y cantidad vendida (use -1 para terminar):" << endl;
    }

    cout << fixed << setprecision(2);
    cout << "El valor total de venta de todos los productos vendidos es: $" << total << endl;

    return 0;
}

