#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

enum clase
{
    libro, revista
};

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
unsigned int leerDato();
void agregarLibro(vector<tficha>& biblioteca);
void agregarRevista(vector<tficha>& biblioteca);
void mostrarDatos(const vector<tficha>& biblioteca);

int main()
{
    vector<tficha> biblioteca;
    char opcion;

    do
    {
        cout << "Biblioteca: Libros y Revistas Científicas\n";
        cout << "1. Agregar libro\n";
        cout << "2. Agregar revista\n";
        cout << "3. Mostrar todos los libros y revistas\n";
        cout << "4. Salir\n";
        cout << "Ingrese su opción: ";
        cin >> opcion;

        switch (opcion)
        {
            case '1':
                agregarLibro(biblioteca);
                break;
            case '2':
                agregarRevista(biblioteca);
                break;
            case '3':
                mostrarDatos(biblioteca);
                break;
            case '4':
                cout << "¡Hasta luego!\n";
                break;
            default:
                cout << "Opción inválida. Intente nuevamente.\n";
                break;
        }

        cout << endl;

    } while (opcion != '4');

    return 0;
}

unsigned int leerDato()
{
    unsigned int dato = 0;
    cin >> dato;

    while (cin.fail())
    {
        cout << "Entrada inválida. Ingrese nuevamente: ";
        cin.clear();
        cin.ignore(numeric_limits<int>::max(), '\n');
        cin >> dato;
    }

    cin.ignore(numeric_limits<int>::max(), '\n');

    return dato;
}

void agregarLibro(vector<tficha>& biblioteca)
{
    tficha libro;

    cout << "\nNúmero de referencia: ";
    libro.numref = leerDato();

    cout << "Título: ";
    cin.ignore();
    getline(cin, libro.titulo);

    cout << "Autor: ";
    getline(cin, libro.autor);

    cout << "Editorial: ";
    getline(cin, libro.editorial);

    cout << "Edición: ";
    libro.libro_revista = libro;
    libro.lr.libros.edicion = leerDato();

    cout << "Año de publicación: ";
    libro.lr.libros.anyo = leerDato();

    biblioteca.push_back(libro);

    cout << "Libro agregado correctamente.\n";
}

void agregarRevista(vector<tficha>& biblioteca)
{
    tficha revista;

    cout << "\nNúmero de referencia: ";
    revista.numref = leerDato();

    cout << "Título: ";
    cin.ignore();
    getline(cin, revista.titulo);

    cout << "Autor: ";
    getline(cin, revista.autor);

    cout << "Editorial: ";
    getline(cin, revista.editorial);

    cout << "Nombre de la revista: ";
    cin.getline(revista.lr.nomrev, 30);

    revista.libro_revista = revista;

    biblioteca.push_back(revista);

    cout << "Revista agregada correctamente.\n";
}

void mostrarDatos(const vector<tficha>& biblioteca)
{
    if (biblioteca.empty())
    {
        cout << "La biblioteca está vacía.\n";
        return;
    }

    cout << "\nListado de libros y revistas:\n";
    for (const auto& ficha : biblioteca)
    {
        cout << "\nNúmero de referencia: " << ficha.numref << endl;
        cout << "Título: " << ficha.titulo << endl;
        cout << "Autor: " << ficha.autor << endl;
        cout << "Editorial: " << ficha.editorial << endl;

        if (ficha.libro_revista == libro)
        {
            cout << "Edición: " << ficha.lr.libros.edicion << endl;
            cout << "Año de publicación: " << ficha.lr.libros.anyo << endl;
        }
        else if (ficha.libro_revista == revista)
        {
            cout << "Nombre de la revista: " << ficha.lr.nomrev << endl;
        }

        cout << "--------------------------------\n";
    }
}
