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
        cout << "Biblioteca: Libros y Revistas Cient�ficas\n";
        cout << "1. Agregar libro\n";
        cout << "2. Agregar revista\n";
        cout << "3. Mostrar todos los libros y revistas\n";
        cout << "4. Salir\n";
        cout << "Ingrese su opci�n: ";
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
                cout << "�Hasta luego!\n";
                break;
            default:
                cout << "Opci�n inv�lida. Intente nuevamente.\n";
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
        cout << "Entrada inv�lida. Ingrese nuevamente: ";
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

    cout << "\nN�mero de referencia: ";
    libro.numref = leerDato();

    cout << "T�tulo: ";
    cin.ignore();
    getline(cin, libro.titulo);

    cout << "Autor: ";
    getline(cin, libro.autor);

    cout << "Editorial: ";
    getline(cin, libro.editorial);

    cout << "Edici�n: ";
    libro.libro_revista = libro;
    libro.lr.libros.edicion = leerDato();

    cout << "A�o de publicaci�n: ";
    libro.lr.libros.anyo = leerDato();

    biblioteca.push_back(libro);

    cout << "Libro agregado correctamente.\n";
}

void agregarRevista(vector<tficha>& biblioteca)
{
    tficha revista;

    cout << "\nN�mero de referencia: ";
    revista.numref = leerDato();

    cout << "T�tulo: ";
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
        cout << "La biblioteca est� vac�a.\n";
        return;
    }

    cout << "\nListado de libros y revistas:\n";
    for (const auto& ficha : biblioteca)
    {
        cout << "\nN�mero de referencia: " << ficha.numref << endl;
        cout << "T�tulo: " << ficha.titulo << endl;
        cout << "Autor: " << ficha.autor << endl;
        cout << "Editorial: " << ficha.editorial << endl;

        if (ficha.libro_revista == libro)
        {
            cout << "Edici�n: " << ficha.lr.libros.edicion << endl;
            cout << "A�o de publicaci�n: " << ficha.lr.libros.anyo << endl;
        }
        else if (ficha.libro_revista == revista)
        {
            cout << "Nombre de la revista: " << ficha.lr.nomrev << endl;
        }

        cout << "--------------------------------\n";
    }
}
