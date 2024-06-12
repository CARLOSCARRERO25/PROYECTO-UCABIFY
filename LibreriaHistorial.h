#ifndef LIBRERIA_HISTORIAL
#define LIBRERIA_HISTORIAL
#include <iostream>
#include "LibreriaUsuarios.h"
#include "LibreriaCanciones.h"
using namespace std;

void AgregarHistorial(PtrUsuarios &ListaUsuarios, PtrCanciones ListaCanciones, int PosUs, int PosCan){
    PtrUsuarios Aux = BuscarUsuario(ListaUsuarios, PosUs);
    PtrCanciones Aux2 = BuscarCancion(ListaCanciones, PosCan);

    if(Aux->PtrHistorial==NULL){
        Aux->PtrHistorial = CrearNodoCanciones(Aux2->Identificador, Aux2->NombreCancion, Aux2->Artista, Aux2->Genero, Aux2->Anio);
    }else{
        PtrCanciones Aux3 = Aux->PtrHistorial;
        while(Aux3->Next!=NULL)
            Aux3=Aux3->Next;
        Aux3-> Next = CrearNodoCanciones(Aux2->Identificador, Aux2->NombreCancion, Aux2->Artista, Aux2->Genero, Aux2->Anio);
    }
    Aux->ContadorHistorial++;
}


void EliminarHistorial(PtrUsuarios &Lista, int PosicionUsu, int PosicionHistorial){
    PtrUsuarios Aux = BuscarUsuario(Lista, PosicionUsu);
    PtrCanciones Aux2 = Aux->PtrHistorial;
    if(PosicionHistorial == 1){
        Aux->PtrHistorial= Aux2->Next;
        delete Aux2;
    }else{
        for(int i=1; i!=PosicionHistorial-1; i++)
            Aux2=Aux2->Next;
        PtrCanciones Aux3 = Aux2->Next;
        Aux2->Next = Aux3->Next;
        delete Aux3;
    }
    Aux->ContadorHistorial--;
}

void ImprimirHistorial(PtrUsuarios ListaUsuarios, int Posicion){
    PtrUsuarios Aux = BuscarUsuario(ListaUsuarios, Posicion);
    PtrCanciones Aux2 = Aux->PtrHistorial;
    cout<<"El Historial del Usuario "<<Aux->NombreUsuario<<" es: \n";
    cout<<" ID Usuario \t ID \t NOMBRE \t ARTISTA \t GENERO \t Anio "<<endl;
    for(int i=1; i<=Aux->ContadorHistorial; i++){
        cout<<i<<" )\t";
        cout<<Aux2->Identificador<<"\t";
        cout<<Aux2->NombreCancion<<"\t";
        cout<<Aux2->Artista<<"\t";
        cout<<Aux2->Genero<<"\t";
        cout<<Aux2->Anio<<"\n";
        Aux2=Aux2->Next;
    }
    cout<<endl;
}

bool BuscarHistorial(PtrUsuarios ListaUsuarios,int PosicionUs ,int CodigoCancion){
    PtrUsuarios Aux=BuscarUsuario(ListaUsuarios, PosicionUs);
    PtrCanciones Aux2 = Aux->PtrHistorial;
    while (Aux2->Next != NULL || Aux2->Identificador != CodigoCancion){
        Aux2=Aux2->Next;
    }
    
}

#endif