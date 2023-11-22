
#include <iostream>
using namespace std;

struct Nodo{
    int dato;
    Nodo *next;


};

struct Pila{
    Nodo *top;

};

Pila* creaPila(){
    Pila* nueva{new Pila};
    nueva->top=nullptr;
    return nueva;

}

Nodo* creaNodo(int dato){
    Nodo*nuevo{new Nodo};
    nuevo->dato=dato;
    nuevo->next=nullptr;

}

bool pilaVacia(Pila*pl){
    return pl->top==nullptr;
}

void push(Pila*pl, int dato){
    cout<<"Agregando dato a la pila: "<<dato<<endl;
    Nodo *nuevo{creaNodo(dato)};
    if(!pilaVacia(pl)){
       nuevo->next=pl->top;
    }
    pl->top=nuevo;
}

int cima(Pila *pl){
    if(!pilaVacia(pl)){
        return pl->top->dato;
    }
    else{
        exit(1);
    }
}

int pop(Pila *pl){
    if (pilaVacia(pl)){
        cout<<"Imposible sacar dato de pila(vacia)"<<endl;
        exit(1);
    }

    cout<<"Removiendo dato de pila: "<<cima(pl)<<endl;
    Nodo *auxiliar=pl->top;
    pl->top=pl->top->next;
    int datoPop=auxiliar->dato;
    delete auxiliar;
    return datoPop;

}


void printPila(Pila *pl){
    if(!pilaVacia(pl)){
            Nodo *Auxiliar{pl->top};
        while(Auxiliar!=nullptr){
            cout<<Auxiliar->dato<<" : ";
            Auxiliar=Auxiliar->next;
        }
        cout<<endl;
    }

}
int main(){
    Pila *pila{creaPila()};
    push(pila,5);
    push(pila,6);
    push(pila,7);
    printPila(pila);
    pop(pila);
    printPila(pila);
    pop(pila);
    pop(pila);
    printPila(pila);
    return 0;


    }







