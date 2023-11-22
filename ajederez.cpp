#include <iostream>
#include <string>

using namespace std;
const int MAX_GASTOS = 100;

struct gasto {
    string fecha;
    string descripcion;
    string categoria;
    float monto;
};

void agregarGasto(gasto [], int &);
void mostrarGastos(gasto [], int);
void mostrarGastosPorCategoria(gasto [], int);
void mostrarGastosPorMes(gasto [], int);
void mostrarPresupuesto(gasto [], int);

int main() {
    const int MAX_GASTOS = 100;
    gasto gastos[MAX_GASTOS];
    int numGastos = 0;

    int opcion;
    do {
        cout << "Bienvenido al programa de registro de gastos" << endl;
        cout << "1. Agregar un gasto" << endl;
        cout << "2. Mostrar todos los gastos" << endl;
        cout << "3. Mostrar gastos por categoría" << endl;
        cout << "4. Mostrar gastos por mes" << endl;
        cout << "5. Mostrar presupuesto" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese la opción deseada: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarGasto(gastos, numGastos);
                break;
            case 2:
                mostrarGastos(gastos, numGastos);
                break;
            case 3:
                mostrarGastosPorCategoria(gastos, numGastos);
                break;
            case 4:
                mostrarGastosPorMes(gastos, numGastos);
                break;
            case 5:
                mostrarPresupuesto(gastos, numGastos);
                break;
            case 0:
                cout << "Gracias por usar el programa" << endl;
                break;
            default:
                cout << "Opción inválida" << endl;
                break;
        }
    } while (opcion != 0);

    return 0;
}

void agregarGasto(gasto gastos[], int &numGastos) {
    if (numGastos == MAX_GASTOS) {
        cout << "No se pueden agregar más gastos" << endl;
        return;
    }

    gasto nuevoGasto;

    cout << "Ingrese la fecha (formato dd/mm/aaaa): ";
    cin >> nuevoGasto.fecha;

    cout << "Ingrese la descripción: ";
    cin.ignore();
    getline(cin, nuevoGasto.descripcion);

    cout << "Ingrese la categoría: ";
    getline(cin, nuevoGasto.categoria);

    cout << "Ingrese el monto: ";
    cin >> nuevoGasto.monto;

    gastos[numGastos] = nuevoGasto;
    numGastos++;

    cout << "El gasto ha sido agregado exitosamente" << endl;
}

void mostrarGastos(gasto gastos[], int numGastos) {
    if (numGastos == 0) {
        cout << "No hay gastos registrados" << endl;
        return;
    }

    cout << "Fecha\t\tDescripción\tCategoría\tMonto" << endl;
    for (int i = 0; i < numGastos; i++) {
        cout << gastos[i].fecha << "\t";
        cout << gastos[i].descripcion << "\t";
        cout << gastos[i].categoria << "\t";
        cout << gastos[i].monto << endl;
    }
}

void mostrarGastosPorCategoria(gasto gastos[], int numGastos) {
    if (numGastos == 0) {
        cout << "No hay gastos registrados" << endl;
        return;
    }

    string categoriaBuscada;

    cout << "Ingrese la categoría a buscar: ";
    cin.ignore();
    getline(cin, categoriaBuscada);

    float totalCategoria = 0;

    cout << "Fecha\t\tDescripción\tMonto" << endl;
    for (int i = 0; i < numGastos; i++) {
        if (gastos[i].categoria == categoriaBuscada) {
            cout << gastos[i].fecha << "\t";
            cout << gastos[i].descripcion << "\t";
            cout << gastos[i].monto << endl;

            totalCategoria += gastos[i].monto;
        }
    }

    cout << "Total de la categoría " << categoriaBuscada << ": " << totalCategoria << endl;
}

void mostrarGastosPorMes(gasto gastos[], int numGastos) {
    if (numGastos == 0) {
        cout << "No hay gastos registrados" << endl;

        //
            return ;
    }

    string mesBuscado;

    cout << "Ingrese el mes a buscar (formato mm/aaaa): ";
    cin >> mesBuscado;

    float totalMes = 0;

    cout << "Fecha\t\tDescripción\tCategoría\tMonto" << endl;
    for (int i = 0; i < numGastos; i++) {
        if (gastos[i].fecha.substr(3) == mesBuscado) {
            cout << gastos[i].fecha << "\t";
            cout << gastos[i].descripcion << "\t";
            cout << gastos[i].categoria << "\t";
            cout << gastos[i].monto << endl;

            totalMes += gastos[i].monto;
        }
    }

    cout << "Total del mes " << mesBuscado << ": " << totalMes << endl;
}

void mostrarPresupuesto(gasto gastos[], int numGastos) {
    if (numGastos == 0) {
        cout << "No hay gastos registrados" << endl;
        return;
    }

    float presupuestoComida, presupuestoTransporte, presupuestoEntretenimiento;

    cout << "Ingrese el presupuesto para comida: ";
    cin >> presupuestoComida;

    cout << "Ingrese el presupuesto para transporte: ";
    cin >> presupuestoTransporte;

    cout << "Ingrese el presupuesto para entretenimiento: ";
    cin >> presupuestoEntretenimiento;

    float totalComida = 0, totalTransporte = 0, totalEntretenimiento = 0;

    for (int i = 0; i < numGastos; i++) {
        if (gastos[i].categoria == "Comida") {
            totalComida += gastos[i].monto;
        } else if (gastos[i].categoria == "Transporte") {
            totalTransporte += gastos[i].monto;
        } else if (gastos[i].categoria == "Entretenimiento") {
            totalEntretenimiento += gastos[i].monto;
        }
    }

    cout << "Presupuesto para comida: " << presupuestoComida << endl;
    cout << "Total gastado en comida: " << totalComida << endl;
    if (totalComida > presupuestoComida) {
        cout << "¡Ha excedido el presupuesto para comida!" << endl;
    }

    cout << "Presupuesto para transporte: " << presupuestoTransporte << endl;
    cout << "Total gastado en transporte: " << totalTransporte << endl;
    if (totalTransporte > presupuestoTransporte) {
        cout << "¡Ha excedido el presupuesto para transporte!" << endl;
    }

    cout << "Presupuesto para entretenimiento: " << presupuestoEntretenimiento << endl;
    cout << "Total gastado en entretenimiento: " << totalEntretenimiento << endl;
    if (totalEntretenimiento > presupuestoEntretenimiento) {
        cout << "¡Ha excedido el presupuesto para entretenimiento!" << endl;
    }
}
