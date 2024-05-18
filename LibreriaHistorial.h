#ifndef LIBRERIA_HISTORIAL
#define LIBRERIA_HISTORIAL
#include <iostream>
#include "LibreriaUsuarios.h"
#include "LibreriaCanciones.h"
using namespace std;

void AgregarHistorial(PtrUsuarios &ListaUsuarios, PtrCanciones ListaCanciones, int PosUs, int PosCan){
    PtrUsuarios aux = BuscarUsuario(ListaUsuarios, PosUs);
    PtrCanciones aux2 = BuscarCancion(ListaCanciones, PosCan);

    if(aux->PtrHistorial==NULL){
        aux->PtrHistorial = CrearNodoCanciones(aux2->Identificador, aux2->Nombre_Cancion, aux2->Artista, aux2->Genero, aux2->Year);
    }else{
        PtrCanciones aux3 = aux->PtrHistorial;
        while(aux3->Next!=NULL)
            aux3=aux3->Next;
        aux3-> Next = CrearNodoCanciones(aux2->Identificador, aux2->Nombre_Cancion, aux2->Artista, aux2->Genero, aux2->Year);
    }
    aux->ContadorHistorial++;
}

void EliminarHistorial(PtrUsuarios &Lista, int PosicionUS, int PosicionHistorial){
    PtrUsuarios aux = BuscarUsuario(Lista, PosicionUS);
    PtrCanciones aux2 = aux->PtrHistorial;
    if(PosicionHistorial == 1){
        aux->PtrHistorial->Next = aux2->Next;
        delete aux2;
    }else{
        for(int i=1; i!=PosicionHistorial-1; i++)
            aux2=aux2->Next;
        PtrCanciones aux3 = aux2->Next;
        aux2->Next = aux3->Next;
        delete aux3;
    }
    aux->ContadorHistorial--;
}

void ImprimirHistorial(PtrUsuarios ListaUsuarios, int Posicion){
    PtrUsuarios aux = BuscarUsuario(ListaUsuarios, Posicion);
    PtrCanciones aux2 = aux->PtrHistorial;
    cout<<"El Historial del Usuario "<<aux->Nombre_Usuario<<" es: \n";
    for(int i=1; i<=aux->ContadorHistorial; i++){
        cout<<i<<" )\t";
        cout<<aux2->Identificador<<"\t";
        cout<<aux2->Nombre_Cancion<<"\t";
        cout<<aux2->Artista<<"\t";
        cout<<aux2->Genero<<"\t";
        cout<<aux2->Year<<"\n";
        aux2=aux2->Next;
    }
    cout<<endl;
}



#endif