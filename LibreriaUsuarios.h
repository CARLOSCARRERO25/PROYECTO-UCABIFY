#ifndef LIBRERIA_USUARIOS
#define LIBRERIA_USUARIOS
#include "LibreriaCanciones.h"
#include "validaciones.h"
#include <iostream>
using namespace std;




struct Usuarios{
    int CodigoIdentificador;
    string NombreUsuario;
    string Correo;
    short Edad;
    string Contrasena;
    string Pais;
    Usuarios *Next;
    Canciones *PtrHistorial;
    int ContadorHistorial;
};

typedef Usuarios *PtrUsuarios;

int ContadorUsuarios=0; 

PtrUsuarios SolicitarDatos(){
    PtrUsuarios auxDatos = new Usuarios;
    string edad;
    cout<<"--------------------------------------------------------------- \n";

    cout<<"Ingrese los datos datos que le seran solicitados a continuacion\n\n";
    cout<<">> ";
    cin.ignore();
    cout<<"Ingrese su Nombre de usuario: \n";
    getline(cin,auxDatos->NombreUsuario);

    do{
        cout<<"Ingrese su edad:\n";
        cout<<">> ";
        cin>>edad;
        MsgdeErrorF(1, edad);
    }while(!EsNumero(edad));
    auxDatos->Edad=short(stoi(edad));
    
    cin.ignore();
    cout<<"\nIngrese su pais de origen\n";
    cout<<">> ";
    getline(cin,auxDatos->Pais);

    cout<<"\nIngrese el correo de su usuario\n";
    cout<<">> ";
    getline(cin, auxDatos->Correo);

    cout<<"\nIngrese una contrasena:\n";
    cout<<">> ";
    getline(cin,auxDatos->Contrasena);

    cout<<"--------------------------------------------------------------- \n";

    return auxDatos;
}


bool ValidarCodigoUs(PtrUsuarios Lista,int Codigo){
    PtrUsuarios aux = Lista;
    while(aux!=NULL){
        if(aux->CodigoIdentificador == Codigo)
            return 1;
        aux=aux->Next;
    }
    return 0;
}
    

PtrUsuarios CrearNodoUsuarios(int Codigo, string Nombre, string Correo, short Edad, string Contrasena, string Pais){
    PtrUsuarios Aux = new Usuarios;
    Aux->CodigoIdentificador= Codigo;
    Aux->NombreUsuario = Nombre;
    Aux->Correo = Correo;
    Aux->Edad = Edad;
    Aux->Contrasena = Contrasena;
    Aux->Pais= Pais;
    Aux->Next= NULL;
    Aux->PtrHistorial = NULL;
    Aux->ContadorHistorial= 0;
    return Aux;
}

void AgregarUsuario(PtrUsuarios &Lista, PtrUsuarios Nodo){ //Funcion para agregar Usuarios al final de la lista
    if(Lista==NULL)
        Lista=Nodo;
    else{
        PtrUsuarios aux=Lista;
        while(aux->Next!=NULL)
        {
            aux=aux->Next;
        }
        aux->Next = Nodo;
    }
    ContadorUsuarios++;
}

void EliminarUsuario(PtrUsuarios &Lista, int Posicion){// Funcion para eliminar Usuario por posicion
    PtrUsuarios aux = Lista;
    if (Posicion == 1){
        Lista= Lista->Next;
        delete aux;
    }else{
        for(int i=1; i!=Posicion-1; i++)
            aux=aux->Next;
        PtrUsuarios aux2 = aux->Next;
        aux->Next = aux2->Next;
        delete aux2;
    }
    ContadorUsuarios--;
}

PtrUsuarios BuscarUsuario(PtrUsuarios &lista, int Posicion){
    PtrUsuarios aux = lista;
    for(int i=1; i!=Posicion; i++){
        aux= aux->Next;
    }
    return aux;
}

int BuscarPosicionDeUsuario(PtrUsuarios Lista, int Codigo){
    int i=1;
    PtrUsuarios aux = Lista;
    while(aux->CodigoIdentificador != Codigo){
        i++;
        aux=aux->Next;
    }
    return i;
}

void ImprimirListaUsuarios(PtrUsuarios Lista){
    cout<<"La lista de usuarios de UCABIFY es: \n";
    cout<<"------------------------------------------------------------------------------------ \n";
    for(int i=1; i<=ContadorUsuarios; i++){
        cout<<i<<" )\t";
        cout<<Lista->CodigoIdentificador<<"\t";
        cout<<Lista->NombreUsuario<<"\t";
        cout<<Lista->Correo<<"\t";
        cout<<Lista->Contrasena<<"\t";
        cout<<Lista->Edad<<"\t";
        cout<<Lista->Pais<<"\n";
        Lista=Lista->Next;
    }
        cout<<"------------------------------------------------------------------------------------ ";
    cout<<endl;
}

void CancionesMasEscuchadasUS(PtrCanciones Lista){
    PtrCanciones Ranking = NULL;
    PtrCanciones Mayor = Lista;
    int i=1;
    while(i<=5){
        PtrCanciones aux = Lista;
        while(aux!=NULL){
            if((aux->ContadorReproducciones >= Mayor->ContadorReproducciones) && (!ValidarCodigoCanciones(Ranking, aux->Identificador)))
                Mayor=aux;

            aux=aux->Next;
        }
        AgregarCancion(Ranking, CrearNodoCanciones(Mayor->Identificador,Mayor->NombreCancion,Mayor->Artista,Mayor->Genero,Mayor->Anio, Mayor->ContadorReproducciones, Mayor->ContadorLikes,0));
        Mayor->ContadorReproducciones=0;
        ContadorCanciones--;
        i++;
    }
    ImprimirListaCanciones(Ranking);
    system("pause");
}

void CancionesConlikesUS(PtrCanciones Lista){
    PtrCanciones Ranking = NULL;
    PtrCanciones aux = Lista;
        while(aux!=NULL){
            if(aux->Like==1){
                AgregarCancion(Ranking, CrearNodoCanciones(aux->Identificador,aux->NombreCancion,aux->Artista,aux->Genero,aux->Anio, aux->ContadorReproducciones, aux->ContadorLikes,0));
                ContadorCanciones--;
            }
            aux=aux->Next;
        }
    ImprimirListaCanciones(Ranking);
    system("pause");
}
#endif

