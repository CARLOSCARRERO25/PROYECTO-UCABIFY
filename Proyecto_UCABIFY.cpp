#include <iostream>
#include "LibreriaUsuarios.h"
#include "LibreriaCanciones.h"
#include "LibreriaHistorial.h"
using namespace std;

void GenericMsg(int a);
PtrCanciones ListaCanciones= NULL;
PtrUsuarios ListaUsuarios = NULL;

int main(){
    PtrUsuarios Datos;
    PtrCanciones DatosCanciones;
    int Opcion, Seleccion1, Seleccion2;

    do{
        GenericMsg(1);
        cin>>Opcion;
        switch (Opcion)
        {
        case 1:
            do{
                GenericMsg(2);
                cin>>Opcion;
                switch (Opcion)
                {
                case 1: //Agregar Usuarios (Faltan validaciones y generar el codigo aleatorio)
                    Datos = SolicitarDatos();
                    AgregarUsuario(ListaUsuarios,CrearNodoUsuarios(0001,Datos->Nombre_Usuario, Datos->Correo, Datos->Edad, Datos->Password, Datos->Pais));
                    break;
                case 2: //Eliminar Usuarios (Faltan validaciones mas especifcas)
                    if(ListaUsuarios==NULL){
                        cout<<"La lista esta vacia; no hay elementos para eliminar\n";
                    }else{
                        cout<<"La lista de usuarios en UCABIFY es:\n";
                        ImprimirListaUsuarios(ListaUsuarios);
                        cout<<"Ingrese el N° de usuario que desea eliminar\n";
                        int eleccion;
                        cin>>eleccion;
                        EliminarUsuario(ListaUsuarios, eleccion);
                    }
                    break;
                case 3:
                    if(ListaUsuarios==NULL){
                        cout<<"la lista esta vacia\n";
                    }else{
                        cout<<"La lista de usuarios en UCABIFY es: \n";
                        ImprimirListaUsuarios(ListaUsuarios);
                    }
                    break;
                    system("pause");
                default:

                    break;
                }
            }while(Opcion!=4);
            break;
        case 2:
            do{
                GenericMsg(3);
                cin>>Opcion;
                switch (Opcion)
                {
                case 1: //Agregar canciones (faltan validaciones y generar el codigo identificador)
                    DatosCanciones = SolicitarDatosCanciones();
                    AgregarCancion(ListaCanciones, CrearNodoCanciones(12345,DatosCanciones->Nombre_Cancion,DatosCanciones->Artista, DatosCanciones->Genero,DatosCanciones->Year));
                    break;
                case 2: //Eliminar Canciones (Faltan validaciones mas especificas)
                    if(ListaCanciones==NULL){
                        cout<<"La lista esta vacia; no hay elementos para eliminar\n";
                        system("pause");
                    }else{
                        cout<<"La lista de canciones en UCABIFY es:\n";
                        ImprimirListaCanciones(ListaCanciones);
                        cout<<"Ingrese el N° de la cancion que desea eliminar\n";
                        int eleccion;
                        cin>>eleccion;
                        EliminarCancion(ListaCanciones, eleccion);
                    }
                    break;
                case 3:
                    if(ListaCanciones==NULL){
                        cout<<"La lista esta vacia\n";

                    }else{
                        cout<<"La lista de canciones en UCABIFY es:\n";
                        ImprimirListaCanciones(ListaCanciones);
                    }
                    system("pause");
                    break;
                default:
                    break;
                }
            }while(Opcion!=4);
            break;
        case 3:
            GenericMsg(4);
            ImprimirListaUsuarios(ListaUsuarios);
            cin>>Seleccion1;

            ImprimirListaCanciones(ListaCanciones);
            cin>>Seleccion2;

            AgregarHistorial(ListaUsuarios, ListaCanciones,Seleccion1, Seleccion2);

            cout<<"el historia del usuario que reprodujo musica es: \n\n";
            ImprimirHistorial(ListaUsuarios, Seleccion1);
            system("pause");
            break;
        default:
            break;
        }
    }while(Opcion != 0);



}




void GenericMsg(int a){
    switch (a)
    {
    case 1:
        system("cls");
        cout<<"\t\t MENU PRINCIPAL\n";
        cout<<"( 1 ) Gestion de usuarios\n";
        cout<<"( 2 ) Gestion de Canciones\n";
        cout<<"( 3 ) Escuchar Musica\n";
        cout<<"( 0 ) SALIR\n";
        break;
    case 2:
        system("cls");
        cout<<"\t\t Bienvenido al menu de gestion de usuarios\n";
        cout<<"( 1 ) Agregar Usuario\n";
        cout<<"( 2 ) Eliminar Usuario\n";
        cout<<"( 3 ) Imprimir Lista de usuarios\n";
        cout<<"( 4 ) Volver al menu anterior\n";
        break;
    case 3:
        system("cls");
        cout<<"\t\t Bienvenido al menu de gestion de canciones\n";
        cout<<"( 1 ) Agregar cancion\n";
        cout<<"( 2 ) Eliminar cancion\n";
        cout<<"( 3 ) Imprimir Lista de canciones\n";
        cout<<"( 4 ) Volver al menu anterior\n";
        break;
    case 4:
        cout<<"\t\tBienvenido a la lista de reproduccion de UCABIFY\n\n";
        cout<<"Seleccione el usuario que desea reproducir una cancion:\n";
        break;
    default:
        break;
    }
}