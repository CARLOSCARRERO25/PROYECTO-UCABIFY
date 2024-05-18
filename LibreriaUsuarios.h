#ifndef LIBRERIA_USUARIOS
#define LIBRERIA_USUARIOS
#include "LibreriaCanciones.h"
#include "validaciones.h"
#include <iostream>
using namespace std;




struct Usuarios{
    int Codigo_Identificador;
    string Nombre_Usuario;
    string Correo;
    short Edad;
    string Password;
    string Pais;
    Usuarios *Next;
    Canciones *PtrHistorial;
    int ContadorHistorial;
};

typedef Usuarios *PtrUsuarios;

int contadorUsuarios=0; 

PtrUsuarios SolicitarDatos(){
    PtrUsuarios auxDatos = new Usuarios;
    string edad;

    cout<<"Ingrese los datos datos que le seran solicitados a continuacion\n\n";
    cin.ignore();
    cout<<"Ingrese su Nombre de usuario: \n";
    getline(cin,auxDatos->Nombre_Usuario);

    do{
        cout<<"Ingrese su edad:\n";
        cin>>edad;
        MsgdeError(1, edad);
    }while(!esNumero(edad));
    auxDatos->Edad=stoi(edad);
    
    cin.ignore();
    cout<<"\nIngrese su pais de origen\n";
    getline(cin,auxDatos->Pais);

    cout<<"\nIngrese el correo de su usuario\n";
    getline(cin, auxDatos->Correo);

    cout<<"\nIngrese una contrasena:\n";
    getline(cin,auxDatos->Password);

    return auxDatos;
}

PtrUsuarios CrearNodoUsuarios(int Codigo, string Nombre, string Correo, short Edad, string Pass, string Pais){
    PtrUsuarios Aux = new Usuarios;
    Aux->Codigo_Identificador= Codigo;
    Aux->Nombre_Usuario = Nombre;
    Aux->Correo = Correo;
    Aux->Edad = Edad;
    Aux->Password = Pass;
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
    contadorUsuarios++;
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
    contadorUsuarios--;
}

PtrUsuarios BuscarUsuario(PtrUsuarios &lista, int Posicion){
    PtrUsuarios aux = lista;
    for(int i=1; i!=Posicion; i++){
        aux= aux->Next;
    }
    return aux;
}

void ImprimirListaUsuarios(PtrUsuarios Lista){
    cout<<"La lista de usuarios de UCABIFY es: \n";
    for(int i=1; i<=contadorUsuarios; i++){
        cout<<i<<" )\t";
        cout<<Lista->Codigo_Identificador<<"\t";
        cout<<Lista->Nombre_Usuario<<"\t";
        cout<<Lista->Correo<<"\t";
        cout<<Lista->Password<<"\t";
        cout<<Lista->Edad<<"\t";
        cout<<Lista->Pais<<"\n";
        Lista=Lista->Next;
    }
    cout<<endl;
}
#endif

