#include <iostream>
#include "LibreriaUsuarios.h"
#include "LibreriaCanciones.h"
#include "LibreriaHistorial.h"
#include "validaciones.h"
#include "carlosArchivos.h"
using namespace std;

void GenericMsg(int a);
PtrCanciones ListaCanciones= NULL;
PtrUsuarios ListaUsuarios = NULL;

int main(){
    PtrUsuarios Datos;
    PtrCanciones DatosCanciones;
    string ValidarOpcion, Seleccion1, Seleccion2;
    do{
        do{
            GenericMsg(1);
            cin>>ValidarOpcion;
            MsgdeError(1, ValidarOpcion);
        }while(!esNumero(ValidarOpcion));
        
        switch (stoi(ValidarOpcion))
        {
        case 1:
            do{
                do{
                    GenericMsg(2);
                    cin>>ValidarOpcion;
                    MsgdeError(1, ValidarOpcion);
                }while(!esNumero(ValidarOpcion));
                
                switch (stoi(ValidarOpcion))
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
                case 3: //Gestion de historial de usuarios
                    do{
                        do{
                            GenericMsg(9);
                            cin>>ValidarOpcion;
                            MsgdeError(1, ValidarOpcion);
                        }while(!esNumero(ValidarOpcion));

                        switch (stoi(ValidarOpcion))
                        {
                        case 1:
                            do{
                                cout<<"Seleccione el usuario al cual desea revisarle el culo:\n";
                                ImprimirListaUsuarios(ListaUsuarios);
                                cin>>ValidarOpcion;
                                MsgdeError(1, ValidarOpcion);
                            }while(!esNumero(ValidarOpcion));
                            ImprimirHistorial(ListaUsuarios, stoi(ValidarOpcion));
                            system("pause");
                            break;
                        case 2:
                            do{
                                GenericMsg(10);
                                cin>>ValidarOpcion;
                                MsgdeError(1, ValidarOpcion);
                            }while(!esNumero(ValidarOpcion));

                            switch (stoi(ValidarOpcion))
                            {
                            case 1:
                                do{
                                    cout<<"Seleccione el usuario al cual le desea eliminar un dato del historial\n";
                                    ImprimirListaUsuarios(ListaUsuarios);
                                    cin>>Seleccion1;
                                    MsgdeError(1, Seleccion1);
                                }while(!esNumero(Seleccion1));

                                
                                do{
                                    cout<<"Seleccione el dato que desea eliminar del usario "<<BuscarUsuario(ListaUsuarios, stoi(Seleccion1))->Nombre_Usuario<<"\n";
                                    ImprimirHistorial(ListaUsuarios, stoi(Seleccion1));
                                    cin>>Seleccion2;
                                    MsgdeError(1, Seleccion2);
                                }while(!esNumero(Seleccion2));
                                EliminarHistorial(ListaUsuarios, stoi(Seleccion1), stoi(Seleccion2));
                                break;
                            case 2:
                                do{
                                    cout<<"Seleccione el usuario al cual le desea eliminar un dato del historial\n";
                                    ImprimirListaUsuarios(ListaUsuarios);
                                    cin>>Seleccion1;
                                    MsgdeError(1, Seleccion1);
                                }while(!esNumero(Seleccion1));
                                
                                while(BuscarUsuario(ListaUsuarios, stoi(Seleccion1))->ContadorHistorial!=0)
                                    if(BuscarUsuario(ListaUsuarios, stoi(Seleccion1))->ContadorHistorial==0)
                                        break;
                                    else    
                                        EliminarHistorial(ListaUsuarios, stoi(Seleccion1), 1);
                                break;
                            default:
                                break;
                            }
                        default:
                            break;
                        }
                    }while(stoi(ValidarOpcion)!=3);
                    break;
                case 4://Reproducir canciones
                    if(ListaUsuarios==NULL)
                        cout<<"la lista esta vacia\n";
                    else
                        ImprimirListaUsuarios(ListaUsuarios);
                    
                    system("pause");
                    break;
                default:

                    break;
                }
            }while(stoi(ValidarOpcion)!=5);
            break;
        case 2:
            do{
                do{
                    GenericMsg(3);
                    cin>>ValidarOpcion;
                    MsgdeError(1, ValidarOpcion);
                }while(!esNumero(ValidarOpcion));
                switch (stoi(ValidarOpcion))
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
                case 3://Imprimir lista de canciones
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
            }while(stoi(ValidarOpcion)!=4);
            break;
        case 3: //Reproducir canciones
            if((ListaCanciones==NULL) && (ListaUsuarios==NULL)){
                GenericMsg(5);
                GenericMsg(8);
                break;
            }else{
                if(ListaCanciones == NULL){
                    GenericMsg(6);
                    GenericMsg(8);
                    break;
                }
                if(ListaUsuarios==NULL){
                    GenericMsg(7);
                    GenericMsg(8);
                    break;
                }
            }

            GenericMsg(4);
            ImprimirListaUsuarios(ListaUsuarios);
            cin>>Seleccion1;

            ImprimirListaCanciones(ListaCanciones);
            cin>>Seleccion2;

            AgregarHistorial(ListaUsuarios, ListaCanciones,stoi(Seleccion1), stoi(Seleccion2));
            break;
        default:
            break;
        }
    }while(stoi(ValidarOpcion)!= 0);
}




void GenericMsg(int a){
    switch (a)
    {
    case 1:
        system("cls");
        cout<<"\t\t MENU PRINCIPAL\n\n";
        cout<<"( 1 ) Gestion de usuarios\n";
        cout<<"( 2 ) Gestion de Canciones\n";
        cout<<"( 3 ) Escuchar Musica\n";
        cout<<"( 0 ) SALIR\n";
        break;
    case 2:
        system("cls");
        cout<<"\t\t Bienvenido al menu de gestion de usuarios\n\n";
        cout<<"( 1 ) Agregar Usuario\n";
        cout<<"( 2 ) Eliminar Usuario\n";
        cout<<"( 3 ) Gestionar historial de usuario\n";
        cout<<"( 4 ) Imprimir Lista de usuarios\n";
        cout<<"( 5 ) Volver al menu anterior\n";
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
    case 5:
        cout<<"No hay canciones disponibles; ni usuarios registrados en UCABIFY\n";
        break;
    case 6:
        cout<<"No hay canciones disponibles en UCABIFY\n";
        break;
    case 7:
        cout<<"No hay usuarios registrados en UCABIFY\n";
        break;
    case 8:
        cout<<"intente de nuevo mas tarde\n";
        system("pause");
        break;
    case 9:
        cout<<"Menu para gestionar el historial de los usuarios\n\n";
        cout<<"( 1 ) Ver historial de usuario\n";
        cout<<"( 2 ) Limpiar Historial\n";
        cout<<"( 3 ) Volver al menu anterior\n";
        break;
    case 10:
        cout<<"\t\tMenu para limpiar el historial, seleccione una opcion: \n";
        cout<<"( 1 ) Borrar un elemento del historial de un usuario\n";
        cout<<"( 2 ) Borrar todo el historial de un usuario\n";
        cout<<"( 3 ) Volver al menu anterior\n";
        break;
    default:
        break;
    }
}