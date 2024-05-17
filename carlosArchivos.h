#include<iostream>
#include<stdlib.h>
#include<fstream>
//#include<carloslistas.h>
#define NombreArchivo "NOMBRE DEL ARCHIVO"

#define ComandoSalto "\r\n"

using namespace std;


void ArchivoVerificacion(){}

void ArchivosEscribir(){
    ofstream archivo;

    archivo.open("archivo_proyecto.txt",ios::out);
    if(archivo.fail()) {
        cout<<"NO SE ABRIO ARCHIVO";}
    archivo.close();
}

/*void fArchivo_LEERTexto(){
    ofstream archivo;
    string texto;

    archivo.open("NombreArchivo",ios::app);
    if(archivo.fail()) {
        cout<<"NO SE ABRIO ARCHIVO";}
//  cout<<"ingrese datos";
//  getline(cin,texto);
    archivo<<"PRUEBAAA TILIN AHHH";

    archivo.close();
}*/

void fArchivo_ImprimirContenido(){
    ifstream archivo;
    string texto,linea;
    archivo.open("NombreArchivo");
    //mientras haya contenido en el archivo se tomara linea por linea el contenido
    while(getline(archivo,linea));{
        

        texto=texto+linea"\n";
        lista = Lista
    }
    cout<< texto << endl;
    archivo.close();
}

void fArchivo_Guardar(string texto){
    ofstream archivo("NombreArchivo");
    archivo.open("NombreArchivo");

    archivo<< /*TEXTOO AHH*/ ;

    archivo.close;


}

void fArchivo_CopiarContenido(){
    ifstream archivo;
    string texto;
    archivo.open("NombreArchivo");
    //mientras haya contenido en el archivo se tomara linea por linea el contenido
    while(getline(archivo,texto));{

        /*copiar desde el archivo hasta la estructura de listas {canciones,historial,usuario}*/
        // \n (para salto de linea)

    }

    archivo.close();
}