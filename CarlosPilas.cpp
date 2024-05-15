#include<iostream>
#include<stdlib.h>

using namespace std;

struct Node
{
    int dato;
    Node *next;
}   *LISTA;


//EXPLOTA EL ELEMENTO SUPERIOR EN LA PILA
void pop (Node *&Pila){

    Node *listaAux=Pila;
    Pila=Pila->next;
    delete listaAux;

}

//DEVUELVE EL VALOR DEL ELEMENTO SUPERIOR
int top(Node *&Pila){

    return Pila->dato;
    }

// AGREGA UN NUEVO NODO AL INICIO DE LA PILA
void AgregarPila(Node *&pila,int dato){
    Node *PilaNueva = new Node();
    PilaNueva->dato=dato;
    PilaNueva->next = pila;

    int x= top(pila);
    if(x==PilaNueva->dato)
        cout<<"ELEMENTO AGREGADO"<<endl;
    else
        cout<<"NO SE AGREGO EL ELEMENTO"<<endl;
    
}


//  NO ES OBVIO, IMPRIME LA LISTA XD (RECURSIVA)
void ImprimirLista(Node *&Pila){

    if(Pila->next){
        cout<<Pila->dato<<" -> ";
        int x = top(Pila);
        pop(Pila);

        ImprimirLista(Pila);

        AgregarPila(Pila,x);
        }

}

int main (){
    int opc,dato;


    cout<<"-------MENUU-------"<<endl;
    cout<<"1. (EMPILAR) Agregar elemento a pila"<<endl;
    cout<<"2.(IMPRIMIR) MOSTRAR LISTA"<<endl;
    cin>>opc;

while(opc!=0){ //CICLO DEL MENU

    switch (opc)
    {
    case 1:// AGREGAR O EMPILAR A LA LISTA
        cout<<endl<<"INGRESE DATO A PONER EN LA PILA";
        cin>>dato;
        AgregarPila(LISTA,dato);
        break;

    case 2:
        cout<<"";
        break;
    
    default:
        cout<<"OPCION NO VALIDA";
        break;
    }
}

    return 0;
}