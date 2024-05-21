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
    string Nombre_Cancion;
    string Artista;
    string Genero;
    int Year;
    int Contador_Reproducciones;
    int Contador_Likes;
    string Linea;
    ifstream archivo("CancionesArchivo.txt");
    
    while(getline(archivo,Linea)){
        int i=0;
        Identificador=stoi(CopiarDato(Linea,i));
        Nombre_Cancion = CopiarDato(Linea,i);
        Artista = CopiarDato(Linea,i);
        Genero = CopiarDato(Linea,i);
        Year = stoi(CopiarDato(Linea,i));

        AgregarCancion(Lista, CrearNodoCanciones(Identificador, Nombre_Cancion, Artista, Genero, Year));
    }
    archivo.close();
}

void CargarArchivoUsuarios(PtrUsuarios &Lista){
    int Codigo_Identificador;
    string Nombre_Usuario;
    string Correo;
    short Edad;
    string Password;
    string Pais;
    string Linea;
    ifstream archivo("UsuarioArchivo.txt");
    
    while(getline(archivo,Linea)){
        int i=0;
        Codigo_Identificador=stoi(CopiarDato(Linea,i));
        Nombre_Usuario= CopiarDato(Linea, i);
        Correo= CopiarDato(Linea,i);
        Edad=short(stoi(CopiarDato(Linea,i)));
        Password = CopiarDato(Linea,i);
        Pais= CopiarDato(Linea, i);
        AgregarUsuario(Lista, CrearNodoUsuarios(Codigo_Identificador,Nombre_Usuario, Correo, Edad,Password,Pais));
    }
    archivo.close();
}

void CargarArchivoHistorial(PtrUsuarios &Lista, PtrCanciones ListaCanciones){
    int codigoUS, CodigoCan;
    ifstream archivo("UsuarioHistorialArchivo.txt");
    string Linea; 
    while(getline(archivo, Linea)){
        int i =0;
        codigoUS=BuscarPosicionDeUsuario(Lista, stoi(CopiarDato(Linea, i)));
        while(i<Linea.size()){
            if(i!=Linea.size()){
                CodigoCan = BuscarPosicionDeCancion(ListaCanciones, stoi(CopiarDato(Linea, i)));
                AgregarHistorial(Lista, ListaCanciones,codigoUS, CodigoCan);
            }
        }
    }
    archivo.close();
}

void fArchivo_MeterEnArchivoCanciones(PtrCanciones Lista){
    ofstream archivo;
    archivo.open("CancionesArchivo.txt",ios::out);

    while (Lista){
        archivo<<Lista->Identificador<<"\t";
        archivo<<Lista->Nombre_Cancion<<"\t";
        archivo<<Lista->Artista<<"\t";
        archivo<<Lista->Genero<<"\t";
        archivo<<Lista->Year<<"\t";
        archivo<<Lista->Contador_Reproducciones<<"\t";
        archivo<<Lista->Contador_Likes<<"\n";
        Lista=Lista->Next;
    }
    archivo.close();
}

void fArchivo_MeterEnArchivoUsuario(PtrUsuarios Lista){
    ofstream archivo;
    archivo.open("UsuarioArchivo.txt",ios::out);

    while (Lista){
        archivo<<Lista->Codigo_Identificador<<"\t";
        archivo<<Lista->Nombre_Usuario<<"\t";
        archivo<<Lista->Correo<<"\t";
        archivo<<Lista->Edad<<"\t";
        archivo<<Lista->Password<<"\t";
        archivo<<Lista->Pais<<"\n";
        
        Lista=Lista->Next;
    }
    archivo.close();
}

void fArchivo_MeterEnHistorial(PtrUsuarios lista){
    ofstream archivo;
    PtrUsuarios UsuLista=lista;
    PtrCanciones CanLista;
    archivo.open("UsuarioHistorialArchivo.txt",ios::out);
    while(UsuLista){
        archivo<<UsuLista->Codigo_Identificador<<"\t";
        CanLista=UsuLista->PtrHistorial;
        while (CanLista){
            if(CanLista->Next!=NULL)
                archivo<<CanLista->Identificador<<"\t";
            else
                archivo<<CanLista->Identificador;
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
    linea= UsuAux->Codigo_Identificador + '/';

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