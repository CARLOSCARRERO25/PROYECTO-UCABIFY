#include<iostream>
using namespace std;

struct Node{
    int value;
    Node *next;

};

//CREA UN NODO
Node* LISTA_CrearNodo( int valor){
    Node *x = new Node;
    x->value=valor;
    x->next=NULL;
    return x;
}

Node* LISTA_Agregar_nodo(Node &lista,Node nodito){
    Node *listaAux = &lista;

    while(NodoLleno(listaAux)){
        if(!listaAux->next){
            listaAux->next = nodito;
            listaAux = listaAux->next;
        }
        listaAux=listaAux->next;
    }
    return listaAux;
}

//REVISA SI LA LISTA ESTA VACIA
bool NodoLleno(Node &p){
    if (p) return true;
    return false;
    
}


//RETORNA EL VALOR EN EL TOPE DE LA PILA
int top(Node *p){
    return p->value;
}



//TOMA EL VALOR EN CABEZA Y RETORNA EL VALOR PERO NO EL NODO Y BORRA EL NODO EN EL TOPE
int pop(Node **p){
    Node *aux = *p;
    *p=(*p) ->next;
    int value = aux->value;

    delete aux;
    return value;

}

 //PONE UN NUEVO NODO EN LA CABEZA DE LA PILA
void push (Node **p,int value){

Node *aux = new Node;
aux -> value=value;
aux ->next = *p;
*p = aux;
aux = NULL;
delete aux;

}

void imprimirPila(Node &p){
    Node *aux = *p;
    if (NodoLleno(aux)){
        cout<< aux->value <<endl;
        imprimirPila(&aux->next); }

}


void LISTA_OrdenamientoBurbuja(Node &Lista){
    //perdona tu pueblo señor
}

Node* LISTA_OrdenamientoDirecta(Node &lista){
Node *i,*j,*listaAux;
listaAux=lista;
j=listaAux;
while(NodoLleno(j)){
    i=listaAux;
    while(NodoLleno(i)){
        if(i->valor > j->valor){
            x=i->valor;
            i->valor=j->valor;
            j->valor=x;
        }}
    j=j->next;}

return listaAux;
}

/*Node* LISTA_OrdenamientoDirectaASC(Node *lista){
Node *i,*j,*listaAux;
listaAux=lista;
j=listaAux;
while(NodoLleno(j)){
    i=listaAux;
    while(NodoLleno(i)){
        if(i->valor > j->valor){
            x=i->valor;
            i->valor=j->valor;
            j->valor=x;
        }i=i->next;}
    j=j->next;}

return listaAux;
}*/


bool LISTA_Encontrar(Node &lista,int codigo){
    Node *listaAux=lista;

    while(NodoLleno(listaAux)){
        if(listaAux->valor = codigo){
            return true;}
        listaAux=listaAux->next;
    }

    return false;
}

bool LISTA_PrimerElemento(Node &lista;int codigo){
    Node *listaAux=lista;
    if(listaAux->valor=codigo)
        {return true;}
    else{return false;}
}

void LISTA_Eliminar1ro(Node &lista){
    Node *listaAux=lista;
    Node *listaAux2;

        listaAux2=listaAux;
        listaAux=listaAux->next;
        listaAux2->next=NULL;
        delete listaAux2;

    lista=listaAux;
}

void LISTA_EliminarElemento(Node &lista,int codigo){
    Node *listaAux=lista;
    Node *listaAux2;
    bool booleano;

    if(LISTA_Encontrar(listaAux,codigo)){

        while(NodoLleno && buleano){
            if(listaAux->next->valor==codigo){
                if(listaAux->next->next ==NULL){
                    listaAux2=listaAux->next;
                    listaAux->next=NULL;
                    delete listaAux2;
                    buleano= false;
                    }else{
                        listaAux=listaAux->next;
                        fLISTA_Eliminar1ro(listaAux);
                        buleano=false;}
            else{listaAux=listaAux->next;}
            }
        }
    }
}

void LISTA_Voltear(Node &lista){    
    Node *listaAux=lista;
    Node *listaAux2=lista;
    bool buleano=true;

   if(listaAux->next=NULL){

   }else{listaAux=listaAux->next;}

}