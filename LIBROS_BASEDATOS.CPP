#include <iostream>
#include <string>
#include <SQLiteCpp/SQLiteCpp.h>

// Definición del tipo enumerado 'clase' para distinguir entre libros y revistas
enum clase
{
    libro, revista
};

// Definición de la estructura 'tficha' para almacenar los datos de libros y revistas
struct tficha
{
    unsigned int numref;
    std::string titulo;
    std::string autor;
    std::string editorial;
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
void crearTablaLibros(SQLite::Database&);
void agregarLibro(SQLite::Database&, const tficha&);
void mostrarLibros(SQLite::Database&);

int main()
{
    SQLite::Database database("biblioteca.db", SQLite::OPEN_CREATE | SQLite::OPEN_READWRITE);

    crearTablaLibros(database);

    char resp = 's';
    while (tolower(resp) == 's')
    {
        tficha ficha;

        std::cout << "\nNúmero de refer. ";
        std::cin >> ficha.numref;
        std::cin.ignore();

        std::cout << "Título ";
        std::getline(std::cin, ficha.titulo);

        std::cout << "Autor ";
        std::getline(std::cin, ficha.autor);

        std::cout << "Editorial ";
        std::getline(std::cin, ficha.editorial);

        unsigned int clase;
        do
        {
            std::cout << "Libro o revista (0 = libro, 1 = revista) ";
            std::cin >> clase;
        } while (clase != 0 && clase != 1);

        if (clase == libro)
        {
            ficha.libro_revista = libro;

            std::cout << "Edición ";
            std::cin >> ficha.lr.libros.edicion;

            std::cout << "Año de public. ";
            std::cin >> ficha.lr.libros.anyo;
        }
        else
        {
            ficha.libro_revista = revista;

            std::cout << "Nombre revista ";
            std::cin.ignore();
            std::cin.getline(ficha.lr.nomrev, 30);
        }

        agregarLibro(database, ficha);

        std::cout << "\n¿Más datos a introducir? s/n ";
        std::cin >> resp;
        std::cin.ignore();
    }

    std::cout << "\n\nListado de libros y revistas\n";
    mostrarLibros(database);

    return 0;
}

void crearTablaLibros(SQLite::Database& database)
{
    database.exec("CREATE TABLE IF NOT EXISTS libros ("
                  "numref INTEGER PRIMARY KEY, "
                  "titulo TEXT, "
                  "autor TEXT, "
                  "editorial TEXT, "
                  "libro_revista INTEGER, "
                  "edicion INTEGER, "
                  "anyo INTEGER, "
                  "nombre_revista TEXT"
                  ")");
}

void agregarLibro(SQLite::Database& database, const tficha& ficha)
{
    SQLite::Statement query(database, "INSERT INTO libros VALUES (?, ?, ?, ?, ?, ?, ?, ?)");

    query.bind(1, ficha.numref);
    query.bind(2, ficha.titulo);
    query.bind(3, ficha.autor);
    query.bind(4, ficha.editorial);
    query.bind(5, static_cast<int>(ficha.libro_revista));

    if (ficha.libro_revista == libro)
    {
        query.bind(6, ficha.lr.libros.edicion);
        query.bind(7, ficha.lr.libros.anyo);
        query.bind(8);
    }
    else
    {
        query.bind(6);
        query.bind(7);
        query.bind(8, ficha.lr.nomrev);
    }

    query.exec();
}

void mostrarLibros(SQLite::Database& database)
{
    SQLite::Statement query(database, "SELECT * FROM libros");

    while (query.executeStep())
    {
        int numref = query.getColumn(0);
        std::string titulo = query.getColumn(1);
        std::string autor = query.getColumn(2);
        std::string editorial = query.getColumn(3);
        int libro_revista = query.getColumn(4);

        std::cout << "\n" << numref << " " << titulo << "\n";
        std::cout << autor << " — Ed. " << editorial << "\n";

        if (libro_revista == libro)
        {
            int edicion = query.getColumn(5);
            int anyo = query.getColumn(6);

            std::cout << "Edición " << edicion << " - año " << anyo << "\n";
        }
        else
        {
            std::string nombre_revista = query.getColumn(7);
            std::cout << nombre_revista << "\n";
        }

        std::cout << "\nPulse <Entrar> para continuar ";
        std::cin.get();
    }
}
