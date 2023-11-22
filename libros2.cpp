// Biblioteca: libros y revistas cient�ficas
#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

// Definici�n del tipo enumerado 'clase' para distinguir entre libros y revistas
enum clase
{
    libro, revista
};

// Definici�n de la estructura 'tficha' para almacenar los datos de libros y revistas
struct tficha
{
    unsigned int numref;
    string titulo;
    string autor;
    string editorial;
    enum clase libro_revista;
    union
    {
        struct
        {
            unsigned int edicion;
            unsigned int anyo;
        } libros;
        char nomrev[30];
    } lr;
};

// Prototipos de las funciones
void escribir(vector<tficha>&);
void leer(vector<tficha>&);
unsigned int leerDato();

int main() // funci�n principal
{
    vector<tficha> biblioteca; // matriz de estructuras
    cout << "Introducir datos.\n";
    leer(biblioteca); // Llamada a la funci�n 'leer' para ingresar los datos
    cout << "\n\nListado de libros y revistas\n";
    escribir(biblioteca); // Llamada a la funci�n 'escribir' para mostrar los datos
}

void leer(vector<tficha>& bibli)
{
    // Funci�n para leer los datos de los libros y revistas
    unsigned int clase;
    char resp = 's';

    tficha ficha;

    while (tolower(resp) == 's') // Bucle mientras el usuario ingrese 's'
    {
        cout << "\nN�mero de refer. ";
        ficha.numref = leerDato(); // Llamada a la funci�n 'leerDato' para ingresar un n�mero de referencia
        cout << "T�tulo ";
        getline(cin, ficha.titulo); // Lee una l�nea de texto para el t�tulo
        cout << "Autor ";
        getline(cin, ficha.autor); // Lee una l�nea de texto para el autor
        cout << "Editorial ";
        getline(cin, ficha.editorial); // Lee una l�nea de texto para la editorial

        do
        {
            cout << "Libro o revista (0 = libro, 1 = revista) ";
            clase = leerDato(); // Llamada a la funci�n 'leerDato' para ingresar 0 o 1
        } while (clase != 0 && clase != 1);

        if (clase == libro)
        {
            ficha.libro_revista = libro;
            cout << "Edici�n ";
            ficha.lr.libros.edicion = leerDato(); // Llamada a la funci�n 'leerDato' para ingresar el n�mero de edici�n
            cout << "A�o de public. ";
            ficha.lr.libros.anyo = leerDato(); // Llamada a la funci�n 'leerDato' para ingresar el a�o de publicaci�n
        }
        else
        {
            ficha.libro_revista = revista;
            cout << "Nombre revista ";
            cin.getline(ficha.lr.nomrev, 30); // Lee una l�nea de texto para el nombre de la revista
        }

        bibli.push_back(ficha); // Agrega la estructura 'ficha' al vector 'biblioteca'

        do
        {
            cout << "\n�M�s datos a introducir? s/n ";
            resp = cin.get(); cin.ignore(); // Lee un car�cter ('s' o 'n') y descarta el car�cter de nueva l�nea
        } while (tolower(resp) != 's' && tolower(resp) != 'n');
    }
}

void escribir(vector<tficha>& bibli)
{
    // Funci�n para listar todos los elementos de la matriz
    int n = bibli.size(); // Obtiene el n�mero de elementos del vector 'biblioteca'

    for (int k = 0; k < n; k++) // Itera sobre cada elemento del vector 'biblioteca'
    {
        cout << '\n' << bibli[k].numref << ' ' << bibli[k].titulo << '\n'; // Muestra el n�mero de referencia y el t�tulo
        cout << bibli[k].autor << " � Ed. " << bibli[k].editorial << '\n'; // Muestra el autor y la editorial

        switch (bibli[k].libro_revista)
        {
            case libro:
                cout << "Edici�n " << bibli[k].lr.libros.edicion << " - a�o " << bibli[k].lr.libros.anyo << '\n'; // Muestra los detalles del libro
                break;
            case revista:
                cout << bibli[k].lr.nomrev << '\n'; // Muestra el nombre de la revista
                break;
        }

        cout << "\nPulse <Entrar> para continuar ";
        cin.get(); // Espera a que el usuario presione la tecla "Enter" antes de continuar
    }
}

unsigned int leerDato()
{
    unsigned int dato = 0;
    cin >> dato; // Lee un n�mero entero ingresado por el usuario

    while (cin.fail()) // Si hay un error al leer el dato (por ejemplo, si se ingresa un car�cter en lugar de un n�mero)
    {
        cout << '\a'; // Muestra un sonido de alerta
        cin.clear(); // Limpia los indicadores de error
        cin.ignore(numeric_limits<int>::max(), '\n'); // Descarta el resto de la entrada en el b�fer
        cin >> dato; // Intenta leer nuevamente el dato
    }

    cin.ignore(numeric_limits<int>::max(), '\n'); // Descarta cualquier car�cter adicional en el b�fer

    return dato; // Devuelve el dato le�do
}
