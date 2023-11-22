// Biblioteca: libros y revistas científicas
#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

// Definición del tipo enumerado 'clase' para distinguir entre libros y revistas
enum clase
{
    libro, revista
};

// Definición de la estructura 'tficha' para almacenar los datos de libros y revistas
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

int main() // función principal
{
    vector<tficha> biblioteca; // matriz de estructuras
    cout << "Introducir datos.\n";
    leer(biblioteca); // Llamada a la función 'leer' para ingresar los datos
    cout << "\n\nListado de libros y revistas\n";
    escribir(biblioteca); // Llamada a la función 'escribir' para mostrar los datos
}

void leer(vector<tficha>& bibli)
{
    // Función para leer los datos de los libros y revistas
    unsigned int clase;
    char resp = 's';

    tficha ficha;

    while (tolower(resp) == 's') // Bucle mientras el usuario ingrese 's'
    {
        cout << "\nNúmero de refer. ";
        ficha.numref = leerDato(); // Llamada a la función 'leerDato' para ingresar un número de referencia
        cout << "Título ";
        getline(cin, ficha.titulo); // Lee una línea de texto para el título
        cout << "Autor ";
        getline(cin, ficha.autor); // Lee una línea de texto para el autor
        cout << "Editorial ";
        getline(cin, ficha.editorial); // Lee una línea de texto para la editorial

        do
        {
            cout << "Libro o revista (0 = libro, 1 = revista) ";
            clase = leerDato(); // Llamada a la función 'leerDato' para ingresar 0 o 1
        } while (clase != 0 && clase != 1);

        if (clase == libro)
        {
            ficha.libro_revista = libro;
            cout << "Edición ";
            ficha.lr.libros.edicion = leerDato(); // Llamada a la función 'leerDato' para ingresar el número de edición
            cout << "Año de public. ";
            ficha.lr.libros.anyo = leerDato(); // Llamada a la función 'leerDato' para ingresar el año de publicación
        }
        else
        {
            ficha.libro_revista = revista;
            cout << "Nombre revista ";
            cin.getline(ficha.lr.nomrev, 30); // Lee una línea de texto para el nombre de la revista
        }

        bibli.push_back(ficha); // Agrega la estructura 'ficha' al vector 'biblioteca'

        do
        {
            cout << "\n¿Más datos a introducir? s/n ";
            resp = cin.get(); cin.ignore(); // Lee un carácter ('s' o 'n') y descarta el carácter de nueva línea
        } while (tolower(resp) != 's' && tolower(resp) != 'n');
    }
}

void escribir(vector<tficha>& bibli)
{
    // Función para listar todos los elementos de la matriz
    int n = bibli.size(); // Obtiene el número de elementos del vector 'biblioteca'

    for (int k = 0; k < n; k++) // Itera sobre cada elemento del vector 'biblioteca'
    {
        cout << '\n' << bibli[k].numref << ' ' << bibli[k].titulo << '\n'; // Muestra el número de referencia y el título
        cout << bibli[k].autor << " — Ed. " << bibli[k].editorial << '\n'; // Muestra el autor y la editorial

        switch (bibli[k].libro_revista)
        {
            case libro:
                cout << "Edición " << bibli[k].lr.libros.edicion << " - año " << bibli[k].lr.libros.anyo << '\n'; // Muestra los detalles del libro
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
    cin >> dato; // Lee un número entero ingresado por el usuario

    while (cin.fail()) // Si hay un error al leer el dato (por ejemplo, si se ingresa un carácter en lugar de un número)
    {
        cout << '\a'; // Muestra un sonido de alerta
        cin.clear(); // Limpia los indicadores de error
        cin.ignore(numeric_limits<int>::max(), '\n'); // Descarta el resto de la entrada en el búfer
        cin >> dato; // Intenta leer nuevamente el dato
    }

    cin.ignore(numeric_limits<int>::max(), '\n'); // Descarta cualquier carácter adicional en el búfer

    return dato; // Devuelve el dato leído
}
