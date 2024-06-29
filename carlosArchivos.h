#ifndef LIBRERIA_ARCHIVOS
#define LIBRERIA_ARCHIVOS
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include"LibreriaUsuarios.h"
#define NombreArchivo "ARCHIVO_PROYECTO.txt"
#include"LibreriaHistorial.h"
#include"LibreriaCanciones.h"


#define ComandoSalto "\r\n"
using namespace std;



void ArchivosEscribir(){
    ofstream archivo;

    archivo.open("archivo_proyecto.txt",ios::out);
    if(archivo.fail()) {
        cout<<"NO SE ABRIO ARCHIVO";}
    archivo.close();
}

string CopiarDato(string Linea, int &i){
    string datos;
    while((Linea[i]!='\t') && (i<=Linea.size())){
        datos+=Linea[i];
        i++;
    }
    i++;
    return datos;
}


void CargarArchivoCanciones(PtrCanciones &Lista){
    int Identificador;
    string NombreCancion;
    string Artista;
    string Genero;
    int Anio;
    int ContadorReproducciones;
    int ContadorLikes;
    string Linea;
    ifstream archivo("CancionesArchivo.txt");
    
    while(getline(archivo,Linea)){
        if(archivo.fail())
            break;
        int i=0;
        Identificador=stoi(CopiarDato(Linea,i));
        NombreCancion = CopiarDato(Linea,i);
        Artista = CopiarDato(Linea,i);
        Genero = CopiarDato(Linea,i);
        Anio = stoi(CopiarDato(Linea,i));
        ContadorReproducciones = stoi(CopiarDato(Linea,i));
        ContadorLikes = stoi(CopiarDato(Linea,i));

        AgregarCancion(Lista, CrearNodoCanciones(Identificador, NombreCancion, Artista, Genero, Anio,ContadorReproducciones, ContadorLikes,0));
    }
    archivo.close();
}

void CargarArchivoUsuarios(PtrUsuarios &Lista){
    int CodigoIdentificador;
    string NombreUsuario;
    string Correo;
    short Edad;
    string Contrasena;
    string Pais;
    string Linea;
    ifstream archivo("UsuarioArchivo.txt");
    
    while(getline(archivo,Linea)){
        if(archivo.fail())
            break;
        int i=0;
        CodigoIdentificador=stoi(CopiarDato(Linea,i));
        NombreUsuario= CopiarDato(Linea, i);
        Correo= CopiarDato(Linea,i);
        Edad=short(stoi(CopiarDato(Linea,i)));
        Contrasena = CopiarDato(Linea,i);
        Pais= CopiarDato(Linea, i);
        AgregarUsuario(Lista, CrearNodoUsuarios(CodigoIdentificador,NombreUsuario, Correo, Edad,Contrasena,Pais));
    }
    archivo.close();
}

void CargarArchivoHistorial(PtrUsuarios &Lista, PtrCanciones ListaCanciones){
    int codigoUS, CodigoCan,Reproduccion, like;
    ifstream archivo("UsuarioHistorialArchivo.txt");
    string Linea; 
    while(getline(archivo, Linea)){
        if(!Lista || !ListaCanciones)
            break;
        int i =0;
        codigoUS=BuscarPosicionDeUsuario(Lista, stoi(CopiarDato(Linea, i)));
        while(i<Linea.size()){
            if(i!=Linea.size()){
                CodigoCan = BuscarPosicionDeCancion(ListaCanciones, stoi(CopiarDato(Linea, i)));
                like= stoi(CopiarDato(Linea, i));
                Reproduccion = stoi(CopiarDato(Linea,i));
                AgregarHistorial(Lista, ListaCanciones,codigoUS, CodigoCan,Reproduccion,like);
            }
        }
    }
    archivo.close();
}

void ArchivoMeterEnArchivoCanciones(PtrCanciones Lista){
    ofstream archivo;
    archivo.open("CancionesArchivo.txt",ios::out);
    while (Lista){
        archivo<<Lista->Identificador<<"\t";
        archivo<<Lista->NombreCancion<<"\t";
        archivo<<Lista->Artista<<"\t";
        archivo<<Lista->Genero<<"\t";
        archivo<<Lista->Anio<<"\t";
        archivo<<Lista->ContadorReproducciones<<"\t";
        archivo<<Lista->ContadorLikes<<"\n";
        Lista=Lista->Next;
    }
    archivo.close();
}

void ArchivoMeterEnArchivoUsuario(PtrUsuarios Lista){
    ofstream archivo;
    archivo.open("UsuarioArchivo.txt",ios::out);

    while (Lista){
        archivo<<Lista->CodigoIdentificador<<"\t";
        archivo<<Lista->NombreUsuario<<"\t";
        archivo<<Lista->Correo<<"\t";
        archivo<<Lista->Edad<<"\t";
        archivo<<Lista->Contrasena<<"\t";
        archivo<<Lista->Pais<<"\n";
        
        Lista=Lista->Next;
    }
    archivo.close();
}

void ArchivoMeterEnHistorial(PtrUsuarios lista){
    ofstream archivo;
    PtrUsuarios UsuLista=lista;
    PtrCanciones CanLista;
    archivo.open("UsuarioHistorialArchivo.txt",ios::out);
    while(UsuLista){
        archivo<<UsuLista->CodigoIdentificador<<"\t";
        CanLista=UsuLista->PtrHistorial;
        while (CanLista){
            if(CanLista->Next!=NULL){
                archivo<<CanLista->Identificador<<"\t";
                archivo<<CanLista->Like<<"\t";
                archivo<<CanLista->ContadorReproducciones<<"\t";
            }else{
                archivo<<CanLista->Identificador<<"\t";
                archivo<<CanLista->Like<<"\t";
                archivo<<CanLista->ContadorReproducciones;
            }
            CanLista=CanLista->Next;
        }   
        archivo<<"\n";
        UsuLista=UsuLista->Next;
    }   
    archivo.close();
}


void fArchivoGuardadoUsuario(PtrUsuarios lista){
    string linea,linea2;
    PtrUsuarios UsuAux=lista;
    PtrCanciones CanAux;
    ofstream archivo("ArchivoHistorial.txt");
    archivo.open("ArchivoHistorial.txt");

    CanAux= UsuAux->PtrHistorial;
    linea= UsuAux->CodigoIdentificador + '/';

    while(UsuAux){
        while(CanAux){
            linea2=to_string(CanAux->Identificador);
            if(CanAux->Next)
                linea+= linea2+'-';
            else 
                linea+= linea2+'\n';
            CanAux=CanAux->Next;
        }
        UsuAux=UsuAux->Next;
    }
//
    archivo<<linea;
    archivo.close();
}
#endif


//carlosArchivos.h