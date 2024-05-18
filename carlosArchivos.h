#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<LibreriaUsuarios.h>
#define NombreArchivo "ARCHIVO_PROYECTO.txt"
#include<LibreriaHistorial.h>
#include<LibreriaCanciones.h>


#define ComandoSalto "\r\n"
using namespace std;

struct Canciones{
    int Identificador;
    string Nombre_Cancion;
    string Artista;
    string Genero;
    int Year;
    int Contador_Reproducciones;
    bool Like;
    Canciones *Next;

};
typedef Canciones *PtrCanciones;
Canciones Cancion;

struct Usuarios{
    int Codigo_Identificador;
    string Nombre_Usuario;
    string Correo;
    short Edad;
    string Password;
    string Pais;
    Canciones *PtrHistorial;
    int ContadorHistorial;
    Usuarios *Next;
    
};

typedef Usuarios *PtrUsuarios;



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
    Canciones *ptraux=lista;
    string texto,linea,linea2;
    int conteo=0;
    char letra;

    archivo.open("NombreArchivo");
    //mientras haya contenido en el archivo se tomara linea por linea el contenido
    while(getline(archivo,linea) ){


        for(char letra:linea){

            linea2= linea2+letra;

            if(letra == '\t'){
                conversor_campos_canciones(ptraux,conteo,linea2);
                conteo++;
                linea2="";
                ptraux = ptraux->Next;
            }
        }

        texto=texto+linea+"\n" ;
        ptraux=ptraux->Next;

    }

    cout<< texto << endl;
    archivo.close();
}


void fArchivo_MeterEnArchivoCanciones(PtrCanciones &Lista){
    ifstream archivo("NombreArchivo");
    archivo.open("NombreArchivo");
    string estrin;
    string linea;

    while (Lista)
    {

    estrin=to_string(Lista->Identificador);
    linea = linea + estrin;
    linea = linea + Lista->Nombre_Cancion;
    linea = linea + Lista->Artista;
    linea = linea + Lista->Genero;
    estrin = to_string	(Lista->Year);
    linea = linea + estrin;
    Lista=Lista->Next;

    }
        
        archivo>>linea;
        
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



