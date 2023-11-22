// Biblioteca: libros y revistas científicas
#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;
enum clase // tipo enumerado
{
 libro, revista
};
struct tficha // estructura variable
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
 leer(biblioteca);
 cout << "\n\nListado de libros y revistas\n";
 escribir(biblioteca); // listar todos los libros y revistas
}
void leer(vector<tficha>& bibli)
{
 // Función para leer los datos de los libros y revistas
 unsigned int clase;
 char resp = 's'; 
 
 tficha ficha;

 while( tolower(resp) == 's')
 {
 cout << "\nNúmero de refer. "; ficha.numref = leerDato();
 cout << "Título "; getline(cin, ficha.titulo);
 cout << "Autor "; getline(cin, ficha.autor);
 cout << "Editorial "; getline(cin, ficha.editorial);
 do
 {
 cout << "Libro o revista (0 = libro, 1 = revista) ";
 clase = leerDato();
 }
 while (clase != 0 && clase != 1);
 if (clase == libro)
 {
 ficha.libro_revista = libro;
 cout << "Edición ";
 ficha.lr.libros.edicion = leerDato();
 cout << "Año de public. ";
 ficha.lr.libros.anyo = leerDato();
 }
 else
 {
 ficha.libro_revista = revista;
 cout << "Nombre revista "; cin.getline(ficha.lr.nomrev, 30);
 }
 bibli.push_back(ficha);

 do
 {
 cout << "\n¿Más datos a introducir? s/n ";
 resp = cin.get(); cin.ignore();
 }
 while( tolower(resp) != 's' && tolower(resp) != 'n' );
 }
}
void escribir(vector<tficha>& bibli)
{
 // Función para listar todos los elementos de la matriz
 int n = bibli.size(); // número de elementos de la matriz
 for (int k = 0; k < n; k++)
 {
 cout << '\n' << bibli[k].numref << ' ' << bibli[k].titulo << '\n';
 cout << bibli[k].autor << " — Ed. " << bibli[k].editorial << '\n';
 switch (bibli[k].libro_revista)
 {
 case libro : 
 cout << "Edición " << bibli[k].lr.libros.edicion
 << " - año " << bibli[k].lr.libros.anyo << '\n';
 break;
 case revista :
 cout << bibli[k].lr.nomrev << '\n';
 }
 cout << "\nPulse <Entrar> para continuar ";
 cin.get();
 }
}
unsigned int leerDato()
{
 unsigned int dato = 0;
 cin >> dato;
 while (cin.fail()) // si el dato es incorrecto, limpiar el
 { // búfer y volverlo a leer
 cout << '\a'; // bip
 cin.clear(); // desactivar los indicadores de error
 cin.ignore(numeric_limits<int>::max(), '\n');
 cin >> dato;
 }
 // Eliminar posibles caracteres sobrantes
 cin.ignore(numeric_limits<int>::max(), '\n');
 return dato;
} 