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
        while(aux->PtrHistorial->Next!=NULL)
            aux->PtrHistorial=aux->PtrHistorial->Next;
        aux->PtrHistorial-> Next = CrearNodoCanciones(aux2->Identificador, aux2->Nombre_Cancion, aux2->Artista, aux2->Genero, aux2->Year);
    }
    aux->ContadorHistorial++;
}

void ImprimirHistorial(PtrUsuarios ListaUsuarios, int Posicion){
    PtrUsuarios aux = BuscarUsuario(ListaUsuarios, Posicion);
    PtrCanciones aux2 = aux->PtrHistorial;
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