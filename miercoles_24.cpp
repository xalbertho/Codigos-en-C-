#include <iostream>
#include <cctype>
#include <string>
#include <random>
#include <chrono>

using namespace std;

const size_t MAXIMO{10};

void dibujarTablero(char tablero[]);
char pideLetraJugador();
string defineComienzo(); //Define comienzo para saber quien lo hace si la pc o el jugador
bool jugarDeNuevo();
void hacerJugada(char tablero[], char letra, int jugada);
bool esGanador(char tablero[], char letra);
void obtenerDuplicadoTablero(char tablero[], char copia[]);
bool hayEspacioLibre(char tablero[], int jugada);
int obtenerJugadaJugador(char tablero[]);
bool tableroCompleto(char tablero[]);
int obtenerJugadaComputadora(char tablero[], char letraComputadora);
int elegirJugadaArreglo(char tablero[], int arrJugadas[], int tamAJ);
void juegaGato();

int main(){

    while(true){
        cout<<"Bienvenido al juego del gato "<<endl;
        juegaGato();
        if(!jugarDeNuevo()){
            break;
        }

    }

    return 0;
}


void dibujarTablero(char tablero[]){
    cout << tablero [7] << " |  " << tablero[8] << " | "<< tablero[9]<<endl;
    cout << "--------------"<<endl;
    cout << tablero [4] << " |  " << tablero[5] << " | "<< tablero[6]<<endl;
    cout << "--------------"<<endl;
    cout << tablero [1] << " |  " << tablero[2] << " | "<< tablero[3]<<endl;
}


char pideLetraJugador(){
    char letra{};
    do{
        cout << "Quieres ser X u O ? : ";
        cin >> letra;
        letra = toupper(letra);
    }while(letra!='X' && letra!='O');
    return letra;
}

string defineComienzo(){
    unsigned int semilla = chrono::steady_clock::now().time_since_epoch().count();
    default_random_engine motor(semilla);
    uniform_int_distribution<int> distribucion(0,1);

    int aleatorio = distribucion(motor);
    if(aleatorio==0){
        return "PC";
    }else{
        return "JUGADOR";
    }
}

bool jugarDeNuevo(){
    char opcion{};
    cout<<"\nQuieres jugar de nuevo ? (s/n) : ";
    cin >> opcion;

    return toupper(opcion)=='S';
}

void hacerJugada(char tablero[], char letra, int jugada){
    tablero[jugada]=letra;
}

bool esGanador(char tablero[], char letra){
   return ((tablero[7]==letra && tablero[8]==letra && tablero[9]==letra) ||
    (tablero[4]==letra && tablero[5]==letra && tablero[6]==letra) ||
    (tablero[1]==letra && tablero[2]==letra && tablero[3]==letra) ||
    (tablero[1]==letra && tablero[4]==letra && tablero[7]==letra) ||
    (tablero[2]==letra && tablero[5]==letra && tablero[8]==letra) ||
    (tablero[3]==letra && tablero[6]==letra && tablero[9]==letra) ||
    (tablero[1]==letra && tablero[5]==letra && tablero[9]==letra) ||
    (tablero[7]==letra && tablero[5]==letra && tablero[3]==letra));
}


void obtenerDuplicadoTablero(char tablero[], char copia[]){
    for(size_t i{0}; i<MAXIMO; i++){
        copia[i]= tablero[i];
    }
}


bool hayEspacioLibre(char tablero[], int jugada){
    return (tablero[jugada] == ' ');
}


int obtenerJugadaJugador(char tablero[]){
    int jugada{};
    do{
        cout << "\nCuál es tu próxima jugada (1-9)? : ";
        cin >> jugada;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            jugada=0;
        }
    }while((jugada<1 || jugada>9) || !hayEspacioLibre(tablero,jugada));
    return jugada;
}

bool tableroCompleto(char tablero[]){
    for(size_t i{1}; i<MAXIMO;i++){
        if(hayEspacioLibre(tablero,i)){
            return false;
        }
    }
    return true;
}


int obtenerJugadaComputadora(char tablero[], char letraComputadora){
    char letraJugador{letraComputadora=='X'?'0':'X'};
    for(size_t i{1}; i<MAXIMO;i++){
        char copiaTablero[MAXIMO];
        obtenerDuplicadoTablero(tablero,copiaTablero);
        if(hayEspacioLibre(copiaTablero,i)){
            hacerJugada(copiaTablero,letraComputadora,i);
            if(esGanador(copiaTablero, letraComputadora)){
                return i;
            }
        }

    }
    //Jugada Bloquedora
    for(size_t i{1}; i<MAXIMO;i++){
        char copiaTablero[MAXIMO];
        obtenerDuplicadoTablero(tablero,copiaTablero);
        if(hayEspacioLibre(copiaTablero,i)){
            hacerJugada(copiaTablero,letraJugador,i);
            if(esGanador(copiaTablero, letraJugador)){
                return i;
            }
        }

    }
    //Jugar en las esquinas
    int jugadas[]{1,3,7,9};
    int jugada{elegirJugadaArreglo(tablero,jugadas,4)};
    if(jugada!=0){
        return jugada;

    }
    if(hayEspacioLibre(tablero,5)){
        return 5;
    }
    int jugadasPares[]{2,4,6,8};
    jugada=elegirJugadaArreglo(tablero,jugadasPares,4);
    return jugada;

}


int elegirJugadaArreglo(char tablero[], int arrJugadas[],int tamAJ){
    unsigned int semilla = chrono::steady_clock::now().time_since_epoch().count();
    default_random_engine motor(semilla);

    size_t cuentaJugadas{0};
    for(size_t i{0}; i<static_cast<size_t>(tamAJ);i++){
       if(hayEspacioLibre(tablero,arrJugadas[i])){
       cuentaJugadas++;
       }

    }

    if(cuentaJugadas!=0){
        int jugadasPosibles[cuentaJugadas];
        for(size_t i{0},j{0} ; i<static_cast<size_t>(tamAJ) &&
                               j<cuentaJugadas ; i++){
            if(hayEspacioLibre(tablero,arrJugadas[i])){
                jugadasPosibles[j]=arrJugadas[i];
                j++;
            }
        }
        uniform_int_distribution<int> distribucion(0,cuentaJugadas-1);
        int opcion = distribucion(motor);
        return jugadasPosibles[opcion];
    }else{
        return 0;
    }
}

void juegaGato(){
    char tablero[MAXIMO]{' ',' ',' ',' ',' ',' ' ,' ' ,' ',' ',' '};
    char letraJugador{pideLetraJugador()};
    char letraComputadora{letraJugador=='X'?'O':'X'};
    string turno{defineComienzo()};

    cout<<"\n"<<turno<<"Juega primero."<<endl;
    bool juegoEnCurso{true};

    while(juegoEnCurso){
        dibujarTablero(tablero);
            if (turno.compare("JUGADOR")==0){
            cout<<"Turno del jugador"<<endl;
        int jugada{obtenerJugadaJugador(tablero)};
        hacerJugada(tablero, letraJugador, jugada);
                   if(esGanador(tablero,letraJugador)){
                dibujarTablero(tablero);
                 cout<<"Felicidades has ganado!!"<<endl;
                juegoEnCurso=false;


                   }else{
        if(tableroCompleto(tablero)){
            dibujarTablero(tablero);
            cout<<"es un empate!!"<<endl;
            juegoEnCurso=false;
        }else{
        turno="PC";
        }
                   }
                   } else{
    cout<<"Es turno de la computadora"<<endl;
    int jugada{obtenerJugadaComputadora(tablero,letraComputadora)};

        hacerJugada(tablero,letraComputadora,jugada);
        if(esGanador(tablero,letraComputadora)){
            dibujarTablero(tablero);
            cout<<"La pc ha ganado, losser!!"<<endl;
            juegoEnCurso=false;
        }else{
            if(tableroCompleto(tablero)){
                    dibujarTablero(tablero);
            cout<<"Es un empate!!"<<endl;
            juegoEnCurso=false;


            }else{

        turno="JUGADOR";
                }

           }
        }


   }

}
















