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





void conversor_campos_canciones(PtrCanciones &lista,int conteo, string linea){
int x;
    switch (conteo)
    {
    case 1:
        x=stoi(linea);
        lista->Identificador=x;
        break;

    case 2:
        lista->Nombre_Cancion =linea;
        break;

    case 3:
        lista->Artista=linea;
        break;
    case 4:
    lista->Genero=linea;break;
    case 5:
        x=stoi(linea);
        lista->Year=x;
        break;
    default:
        break;
    }
}


void ArchivosEscribir(){
    ofstream archivo;

    archivo.open("archivo_proyecto.txt",ios::out);
    if(archivo.fail()) {
        cout<<"NO SE ABRIO ARCHIVO";}
    archivo.close();
}


void fArchivo_LeerCanciones(PtrCanciones &lista){
    ifstream archivo;
    PtrCanciones ptraux=lista;
    PtrCanciones ptraux2;
    string texto,linea,linea2,nombre,Genero, Artista;
    int conteo=0,x,Identificador,Year;
    char letra;


    archivo.open("NombreArchivo");
    //mientras haya contenido en el archivo se tomara linea por linea el contenido
    while(getline(archivo,linea) ){


        for(char letra:linea){

            linea2= linea2+letra;

            if(letra == '\t'){
                conteo++;
                int x;

            switch (conteo)
            {   case 1:
                    Identificador=stoi(linea2);
                    break;

                case 2:
                    nombre=linea2;
                    break;

                case 3:
                    Artista=linea2;
                    break;
                case 4:
                    Genero=linea2;break;
                case 5:
                    Year=stoi(linea2);
                    break;

                default:
                break;}

            linea2="";
            ptraux2 = CrearNodoCanciones(Identificador,nombre,Artista,Genero,Year);
                AgregarCancion(ptraux,ptraux2);
                ptraux = ptraux->Next;
            }
        }
    }

    archivo.close();
}


void fArchivo_MeterEnArchivoCanciones(PtrCanciones Lista){
    ofstream archivo;
    archivo.open("NombreArchivo",ios::out);

    while (Lista){
        archivo<<Lista->Identificador<<"\t";
        archivo<<Lista->Nombre_Cancion<<"\t";
        archivo<<Lista->Artista<<"\t";
        archivo<<Lista->Genero<<"\t";
        archivo<<Lista->Year<<"\t";
        archivo<<Lista->Contador_Reproducciones<<"\n";
        Lista=Lista->Next;
    }
    archivo.close();
}


void fArchivoLeerUsuario(PtrUsuarios &lista){
    string linea,linea2;
    PtrUsuarios UsuAux=lista;
    PtrCanciones CanAux;
    ifstream archivo("ArchivoHistorial.txt");
    archivo.open("ArchivoHistorial.txt");

    CanAux= UsuAux->PtrHistorial;
    linea= UsuAux->Codigo_Identificador + ' / ';

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
    archivo>>linea;
    archivo.close();
}
#endif


