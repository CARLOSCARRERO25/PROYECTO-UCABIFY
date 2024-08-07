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

//RETORNA EL PUNTERO DE UN USUARIO EN X POSICION
PtrUsuarios BuscarUsuario(PtrUsuarios &lista, int Posicion){
    PtrUsuarios aux = lista;
    for(int i=1; i!=Posicion; i++){
        aux= aux->Next;
    }
    return aux;
}

//RETORNA LA POSICION DEL USUARIO QUE BUSQUES (BUSQUEDAD POR IDENTIFICACION)
int BuscarPosicionDeUsuario(PtrUsuarios Lista, int Codigo){
    int i=1;
    PtrUsuarios aux = Lista;
    while(aux->CodigoIdentificador != Codigo){
        i++;
        aux=aux->Next;
    }
    return i;
}
//TA XD LAS FUNCIONES DE BUSQUEDAD, PARA ENCONTRAR UN USUARIO POR ID Y QUE TE RETORNE EL USUARIO (AMBAS SE LES PASA LA MISMA LISTA)
//PRIMERO BUSCAR POSICION USUARIO, LUEGO BUSCAR USUARIO PASANDOLE LA POSICION DE BUSCAR POSICION 



void ImprimirListaUsuarios(PtrUsuarios Lista){
    cout<<"#\t ID \t NOMBRE \t CORREO \t CONTRASENA \t EDAD \t PAIS"<<endl;
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
}

void CancionesConlikesUS(PtrCanciones Lista){
    PtrCanciones Ranking = NULL;
    PtrCanciones aux = Lista;
        while(aux!=NULL){
            if(aux->Like==1){
                AgregarCancion(Ranking, CrearNodoCanciones(aux->Identificador,aux->NombreCancion,aux->Artista,aux->Genero,aux->Anio, aux->ContadorReproducciones, aux->ContadorLikes,1));
                ContadorCanciones--;
            }
            aux=aux->Next;
        }
    ImprimirListaCanciones(Ranking);
}

PtrUsuarios Compatibilidad(PtrUsuarios Lista, int PosicionUsuario){
    PtrUsuarios CompatibilidadUS = BuscarUsuario(Lista, PosicionUsuario);
    PtrUsuarios AuxListaUsuarios = Lista;
    PtrUsuarios MayorCoincidencia;
    int Cuenta=0, CuentaAnterior=0;

    while(AuxListaUsuarios!=NULL){
        if(AuxListaUsuarios->CodigoIdentificador == CompatibilidadUS->CodigoIdentificador){
            if(AuxListaUsuarios->Next==NULL)
                break;
            AuxListaUsuarios= AuxListaUsuarios->Next;
        }
        PtrCanciones HistorialCompUS = CompatibilidadUS->PtrHistorial; //Apuntador auxiliar al inicio del Historial del usuario al cual se le busca su compatible
        while(HistorialCompUS!=NULL){
            PtrCanciones HistorialUsActual = AuxListaUsuarios->PtrHistorial; //Apuntador al inicio del historial del usuario actual
            while(HistorialUsActual!=NULL){
                if((HistorialCompUS->Identificador == HistorialUsActual->Identificador) && ((HistorialCompUS->Like==1) && (HistorialUsActual->Like==1))){
                    Cuenta++;
                    break;
                }
                HistorialUsActual=HistorialUsActual->Next;
            }
            HistorialCompUS=HistorialCompUS->Next;
        }
        
        if(Cuenta>CuentaAnterior){
            MayorCoincidencia = AuxListaUsuarios;
            CuentaAnterior = Cuenta;
            Cuenta = 0;
        }
        AuxListaUsuarios=AuxListaUsuarios->Next;
    }
    return MayorCoincidencia;
}

//

#endif
