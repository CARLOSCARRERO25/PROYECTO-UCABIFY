#include <iostream>
#include "LibreriaUsuarios.h"
#include "LibreriaCanciones.h"
#include "LibreriaHistorial.h"
#include "validaciones.h"
#include "carlosArchivos.h"
using namespace std;

void MsgdeError(int a, string ValidarOpcion);
int GenerarCodigo();
void GenericMsg(int a);

PtrCanciones ListaCanciones= NULL;
PtrUsuarios ListaUsuarios = NULL;

int main(){
    CargarArchivoCanciones(ListaCanciones);
    CargarArchivoUsuarios(ListaUsuarios);
    CargarArchivoHistorial(ListaUsuarios, ListaCanciones);
    PtrUsuarios Datos;
    PtrCanciones DatosCanciones;
    string ValidarOpcion, Seleccion1, Seleccion2;
    int Codigo;

    do{
        do{
            GenericMsg(1);
            cout<<">> ";
            cin>>ValidarOpcion;
            MsgdeError(1, ValidarOpcion);
        }while(!EsNumero(ValidarOpcion));
        
        switch (stoi(ValidarOpcion))
        {
        case 1:
            do{
                do{
                    GenericMsg(2);
                    cin>>ValidarOpcion;
                    MsgdeError(1, ValidarOpcion);
                }while(!EsNumero(ValidarOpcion));
                
                switch (stoi(ValidarOpcion))
                {
                case 1: //Agregar Usuarios (Faltan validaciones y generar el codigo aleatorio)
                    system("cls");
                    Datos = SolicitarDatos();
                    do{
                        Codigo = GenerarCodigo();
                    }while(ValidarCodigoUs(ListaUsuarios, Codigo));

                    AgregarUsuario(ListaUsuarios,CrearNodoUsuarios(Codigo,Datos->NombreUsuario, Datos->Correo, Datos->Edad, Datos->Contrasena, Datos->Pais));
                    ArchivoMeterEnArchivoUsuario(ListaUsuarios);
                    break;
                case 2: //Eliminar Usuarios (Faltan validaciones mas especifcas)
                    if(ListaUsuarios==NULL){
                        cout<<"La lista esta vacia; no hay elementos para eliminarm\n";
                        delay(2);
                    }else{ 
                        do{
                            do{
                                ImprimirListaUsuarios(ListaUsuarios);
                                cout<<"Ingrese el N# de usuario que desea eliminar\n";
                                cin>>ValidarOpcion;
                                MsgdeError(1, ValidarOpcion);
                            }while(!EsNumero(ValidarOpcion));
                                MsgdeError(2, ValidarOpcion);
                        }while (((stoi(ValidarOpcion)<=0)||(stoi(ValidarOpcion)>ContadorUsuarios)));
                        EliminarUsuario(ListaUsuarios, stoi(ValidarOpcion));  
                        ArchivoMeterEnArchivoUsuario(ListaUsuarios);
                        ArchivoMeterEnHistorial(ListaUsuarios); 
                    }
                        
                    break;
                case 3: //Gestion de historial de usuarios
                    do{
                        do{
                            GenericMsg(9);
                            cout<<">> ";
                            cin>>ValidarOpcion;
                            MsgdeError(1, ValidarOpcion);
                        }while(!EsNumero(ValidarOpcion));

                        switch (stoi(ValidarOpcion))
                        {
                        case 1:
                            if(!ListaUsuarios){
                                GenericMsg(7);
                                GenericMsg(8);
                            }else{
                                do{
                                    do{  // IMPRIMIR HISTORIAL DE USUARIO SELECCIONADO
                                        system("cls");
                                        cout<<"Seleccione el usuario al cual desea revisarle el historial:\n";
                                        ImprimirListaUsuarios(ListaUsuarios);
                                        cout<<">> ";
                                        cin>>ValidarOpcion;
                                        MsgdeError(1, ValidarOpcion);
                                    }while(!EsNumero(ValidarOpcion));
                                }while(stoi(ValidarOpcion)<= 0 || stoi(ValidarOpcion)>ContadorUsuarios);
                                
                                if (BuscarUsuario(ListaUsuarios, stoi(ValidarOpcion))->ContadorHistorial==0)
                                {
                                    cout<<"El historial de este usuario esta vacio\n";
                                    delay(2);
                                }else{
                                    system("cls");
                                    ImprimirHistorial(ListaUsuarios, stoi(ValidarOpcion));
                                    system("pause");   
                                }
                            }
                            break;
                        case 2:
                            do{
                                GenericMsg(10);
                                cout<<">> ";
                                cin>>ValidarOpcion;
                                MsgdeError(1, ValidarOpcion);
                            }while(!EsNumero(ValidarOpcion));

                            switch (stoi(ValidarOpcion))
                            {
                            case 1:
                                do{//SELECCION 1 es el usuario buscado
                                    system("cls");
                                    cout<<"Seleccione el usuario al cual le desea eliminar un dato del historial\n";
                                    ImprimirListaUsuarios(ListaUsuarios);
                                    cout<<">> ";
                                    cin>>Seleccion1;
                                    MsgdeError(1, Seleccion1);
                                }while(!EsNumero(Seleccion1));
                
                                do{//SELECCION 2 ES LA CANCION QUE VOY A ELIMINAR
                                    system("cls");
                                    cout<<"Seleccione el dato que desea eliminar del usuario "<<BuscarUsuario(ListaUsuarios, stoi(Seleccion1))->NombreUsuario<<"\n";
                                    ImprimirHistorial(ListaUsuarios, stoi(Seleccion1));
                                    cout<<">> ";
                                    cin>>Seleccion2;
                                    MsgdeError(1, Seleccion2);
                                }while(!EsNumero(Seleccion2));

                                EliminarHistorial(ListaUsuarios, stoi(Seleccion1), stoi(Seleccion2));
                                ArchivoMeterEnHistorial(ListaUsuarios);
                                
                                break;
                            case 2:
                                do{//SELECCIONE UN USUARIO ELIMINA SU HISTORIAL COMPLETO (SELECCION)
                                    system("cls");
                                    cout<<"Seleccione el usuario al cual le desea eliminar un dato del historial\n";
                                    ImprimirListaUsuarios(ListaUsuarios);
                                    cout<<">> ";
                                    cin>>Seleccion1;
                                    MsgdeError(1, Seleccion1);               
                                }while(!EsNumero(Seleccion1));
                                //AUXILIAR COPIA EL USUARIO BUSCADO
                                Datos = BuscarUsuario(ListaUsuarios, stoi(Seleccion1));
                                while(Datos->ContadorHistorial!=0)
                                        EliminarHistorial(ListaUsuarios, stoi(Seleccion1), 1);
                                    ArchivoMeterEnHistorial(ListaUsuarios);/*c*/
                                break;
                            default:
                                break;
                            }
                        default:
                            break;
                        }
                    }while(stoi(ValidarOpcion)!=3);
                    break;
                case 4://Imprimir Lista de usuarios
                    if(ListaUsuarios==NULL)
                        cout<<"la lista esta vacia\n";
                    else
                        system("cls");
                        cout<<"La lista de usuarios de UCABIFY es: \n";
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
                    cout<<">> ";
                    cin>>ValidarOpcion;
                    MsgdeError(1, ValidarOpcion);
                }while(!EsNumero(ValidarOpcion));

                switch (stoi(ValidarOpcion))
                {
                case 1: //Agregar canciones (faltan validaciones y generar el codigo identificador)
                    system("cls");
                    DatosCanciones = SolicitarDatosCanciones();
                    do{
                        Codigo = GenerarCodigo();
                    }while(ValidarCodigoCanciones(ListaCanciones, Codigo));
                    
                    AgregarCancion(ListaCanciones, CrearNodoCanciones(Codigo,DatosCanciones->NombreCancion,DatosCanciones->Artista, DatosCanciones->Genero,DatosCanciones->Anio,0,0,0));
                    ArchivoMeterEnArchivoCanciones(ListaCanciones);
                    break;
                case 2: //Eliminar Canciones (Faltan validaciones mas especificas)
                    if(ListaCanciones==NULL){
                        cout<<"La lista esta vacia; no hay elementos para eliminar\n";
                        system("pause");
                    }else{
                        do{
                            do{
                                GenericMsg(14);
                                ImprimirListaCanciones(ListaCanciones);
                                cout<<"Ingrese el N° de la cancion que desea eliminar\n";
                                cout<<">> ";
                                cin>>ValidarOpcion;
                                MsgdeError(1, ValidarOpcion);
                            }while(!EsNumero(ValidarOpcion));
                        }while(stoi(ValidarOpcion)<=0 || stoi(ValidarOpcion)>ContadorCanciones);
                        EliminarCancion(ListaCanciones, stoi(ValidarOpcion));
                        ArchivoMeterEnArchivoCanciones(ListaCanciones);
                    }
                    break;
                case 3://Imprimir lista de canciones
                    if(ListaCanciones==NULL){
                        cout<<"La lista esta vacia\n";
                    }else{
                        GenericMsg(14);
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
            do{
                do{
                    GenericMsg(12);
                    cin>>ValidarOpcion;
                    MsgdeError(1, ValidarOpcion);
                }while(!EsNumero(ValidarOpcion));

                if(stoi(ValidarOpcion)==1){
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

                do{
                    do{
                        GenericMsg(4);
                        ImprimirListaUsuarios(ListaUsuarios);
                        cout<<">> ";
                        cin>>Seleccion1;
                        MsgdeError(1, Seleccion1);
                    }while(!EsNumero(Seleccion1));
                    MsgdeError(2, Seleccion1);
                }while(stoi(Seleccion1)<=0 || stoi(Seleccion1)>ContadorUsuarios);

                do{
                    do{
                        GenericMsg(14);
                        ImprimirListaCanciones(ListaCanciones);
                        cout<<">> ";
                        cin>>Seleccion2;
                        MsgdeError(1, Seleccion2);
                    }while(!EsNumero(Seleccion2));
                    MsgdeError(3, Seleccion2);
                }while((stoi(Seleccion2)<=0) || (stoi(Seleccion2)>ContadorCanciones));

                Codigo = BuscarCancion(ListaCanciones, stoi(Seleccion2))->Identificador;

                if(!EncontrarElementoHistorial(ListaUsuarios, stoi(Seleccion1), Codigo)){
                    AgregarHistorial(ListaUsuarios, ListaCanciones,stoi(Seleccion1), stoi(Seleccion2),0,0);
                }
            
                BuscarHistorial(ListaUsuarios, stoi(Seleccion1), Codigo)->ContadorReproducciones++;

                do{
                    do{
                        if(BuscarHistorial(ListaUsuarios, stoi(Seleccion1), Codigo)->Like==0){
                            cout<<"Que tal te pareci"<<char(162)<<" la cancion? Quisieras darle like?\n";
                            cout<<"( 1 ) Dar Like\n";
                            cout<<"( 2 ) No dar like\n";
                        }else{
                            cout<<"Que tal te pareci"<<char(162)<<" la cancion? Quisiera mantener su like?\n";
                            cout<<"( 1 ) Mantener like\n";
                            cout<<"( 2 ) Quitar Like\n";
                        }
                        cout<<">> ";
                        cin>>ValidarOpcion;
                        MsgdeError(1, ValidarOpcion);
                    }while(!EsNumero(ValidarOpcion));
                    MsgdeError(4, ValidarOpcion);
                }while(stoi(ValidarOpcion)<=0 || stoi(ValidarOpcion)>2);

                if(stoi(ValidarOpcion)==1){
                    BuscarHistorial(ListaUsuarios, stoi(Seleccion1), Codigo)->Like=1;
                    BuscarCancion(ListaCanciones, stoi(Seleccion2))->ContadorLikes++;
                }else{
                    BuscarHistorial(ListaUsuarios, stoi(Seleccion1), Codigo)->Like=0;
                    if(BuscarCancion(ListaCanciones, stoi(Seleccion2))->ContadorLikes>0)
                    BuscarCancion(ListaCanciones, stoi(Seleccion2))->ContadorLikes--;
                }

                BuscarCancion(ListaCanciones, stoi(Seleccion2))->ContadorReproducciones++;
                ArchivoMeterEnHistorial(ListaUsuarios);
                ArchivoMeterEnArchivoCanciones(ListaCanciones);
                }
            }while(stoi(ValidarOpcion)!=2);
            break;
        case 4:
            do{
                do{
                    do{
                        GenericMsg(11);
                        cin>>ValidarOpcion;
                        MsgdeError(1, ValidarOpcion);
                    }while(!EsNumero(ValidarOpcion));
                //MsgdeError(4, ValidarOpcion);
                }while(stoi(ValidarOpcion)<=0 || stoi(ValidarOpcion)>6);

            switch (stoi(ValidarOpcion))
            {
                case 1:
                    system("cls");
                    CancionesMasEscuchadas(ListaCanciones);
                    system("pause");
                    break;
                case 2:
                    do{
                        do{
                            system("cls");
                            cout<<"Lista de usuarios de UCABIFY: \n";
                            ImprimirListaUsuarios(ListaUsuarios);
                            cout<<">> ";
                            cin>>Seleccion1;
                            MsgdeError(1, Seleccion1);
                        }while(!EsNumero(Seleccion1));
                        MsgdeError(2, Seleccion1);
                    }while(stoi(Seleccion1)<=0 || stoi(Seleccion1)>ContadorUsuarios);
                    system("cls");
                    cout<<"La canciones mas escuchadas del usuario "<<BuscarUsuario(ListaUsuarios, stoi(Seleccion1))->NombreUsuario<<" son:\n";
                    CancionesMasEscuchadasUS(BuscarUsuario(ListaUsuarios, stoi(Seleccion1))->PtrHistorial);
                    system("pause");
                    break;
                case 3:
                    system("cls");
                    ArtistaMasEscuchado(ListaCanciones);
                    system("pause");
                    break;
                case 4:
                    do{
                        do{
                            system("cls");
                            cout<<"Seleccione el usuario al cual desee conocer sus canciones con likes:\n";
                            ImprimirListaUsuarios(ListaUsuarios);
                            cout<<">> ";
                            cin>>Seleccion1;
                            MsgdeError(1, Seleccion1);
                        }while(!EsNumero(Seleccion1));
                        MsgdeError(2, Seleccion1);
                    }while(stoi(Seleccion1)<=0 || stoi(Seleccion1)>ContadorUsuarios);
                    system("cls");
                    cout<<"Las canciones con likes del likes del usario "<<BuscarUsuario(ListaUsuarios, stoi(Seleccion1))->NombreUsuario<<" son: \n";
                    CancionesConlikesUS(BuscarUsuario(ListaUsuarios, stoi(Seleccion1))->PtrHistorial);
                    system("pause");
                    break;

                case 5:
                    //CompatibilidadUsuarios(ListaUsuarios);
                    do{
                        do{
                            GenericMsg(13);
                            cin>>ValidarOpcion;
                            MsgdeError(1, ValidarOpcion);
                        }while(!EsNumero(ValidarOpcion));

                        if(stoi(ValidarOpcion)==1){
                            do{
                                do{
                                    system("cls");
                                    cout<<"Seleccione el usuario al que desea conocer sus compatibilidad: \n";
                                    ImprimirListaUsuarios(ListaUsuarios);
                                    cout<<">> ";
                                    cin>>Seleccion1;
                                    MsgdeError(1, Seleccion1);
                                }while(!EsNumero(Seleccion1));
                                MsgdeError(2, Seleccion1);
                            }while(stoi(Seleccion1)<=0 || stoi(Seleccion1)>ContadorUsuarios);
                            cout<<"El usuario mas compatible con "<<BuscarUsuario(ListaUsuarios, stoi(Seleccion1))->NombreUsuario<<" es: "<<Compatibilidad(ListaUsuarios, stoi(Seleccion1))->NombreUsuario<<endl;
                            system("pause");
                        }
                    }while(stoi(ValidarOpcion)!= 2);
                    break;
                default:
                    break;
            }
        }while(stoi(ValidarOpcion)!=6);
            break;
        case 0:
            cout<<"MUCHAS GRACIAS POR USAR UCABIFY! VUELVA PRONTO."<<endl;
            delay(2);
            system("cls");
            break;
        default:

            break;
        }
    }while(stoi(ValidarOpcion)!= 0);
}




void GenericMsg(int A){
    switch (A)
    {
    case 1:
        system("cls");
        cout<<"\t\t MENU PRINCIPAL\n\n";
        cout<<"( 1 ) Gestion de usuarios\n";
        cout<<"( 2 ) Gestion de Canciones\n";
        cout<<"( 3 ) Reproductor de Musica\n";
        cout<<"( 4 ) Reportes\n";
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
        system("cls");
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
        delay(2);
        system("cls");
        break;
    case 9:
        system("cls");
        cout<<"\t\tMenu para gestionar el historial de los usuarios\n\n";
        cout<<"( 1 ) Ver historial de usuario\n";
        cout<<"( 2 ) Limpiar Historial\n";
        cout<<"( 3 ) Volver al menu anterior\n";
        break;
    case 10:
        system("cls");
        cout<<"\t\tMenu para limpiar el historial, seleccione una opcion: \n";
        cout<<"( 1 ) Borrar un elemento del historial de un usuario\n";
        cout<<"( 2 ) Borrar todo el historial de un usuario\n";
        cout<<"( 3 ) Volver al menu anterior\n";
        break;
    case 11:
        system("cls");
        cout<<"\t\tMenu para gestionar los reportes\n\n";
        cout<<"( 1 ) Top 5 canciones mas escuchadas en general\n";
        cout<<"( 2 ) Top 5 canciones mas escuchadas por usuario\n";
        cout<<"( 3 ) Top 3 Artistas mas escuchados\n";
        cout<<"( 4 ) Canciones con Likes por Usuario\n";
        cout<<"( 5 ) Compatibilidad entre usuarios\n";
        cout<<"( 6 ) Volver al menu anterior\n";
        cout<<">> ";
        break;
    case 12:
        system("cls");
        cout<<"\t\tMenu para el reproductor\n\n";
        cout<<"( 1 ) Reproducir Cancion\n";
        cout<<"( 2 ) Volver al menu anterior\n";
        cout<<">> ";
        break;
    case 13:
        system("cls");
        cout<<"\t\tMenu para la compatibilidad entre usuarios\n\n";
        cout<<"( 1 ) Buscar compatibilidad entre usuarios\n";
        cout<<"( 2 ) Volver al menu anterior\n";
        cout<<">> ";
        break;
    case 14:
        system("cls");
        cout<<"La lista de canciones de UCABIFY es: \n";
        break;
    default:
        break;
    }
}

void MsgdeError(int A, string ValidarOpcion){
    switch (A)
    {
    case (1):
        if (!EsNumero(ValidarOpcion)){
                cout<<"No puede ingresar un caracter, es una opcion invalida. Vuelva a intentar\n";
                delay(2);
                system("cls");
            }
        break;
    case(2):
        if((stoi(ValidarOpcion)<=0)||(stoi(ValidarOpcion)>ContadorUsuarios)){
            cout<<"La opcion que ingreso es invalida, vuelva a intentar\n";
            delay(2);
            system("cls");
        } 
        break;
    case(3):
        if((stoi(ValidarOpcion)<=0)||(stoi(ValidarOpcion)>ContadorCanciones)){
            cout<<"La opcion que ingreso es invalida, vuelva a intentar\n";
            delay(2);
            system("cls");
        }
    case (4):
        if((stoi(ValidarOpcion)<=0)||(stoi(ValidarOpcion)>2)){
            cout<<"La opcion que ingreso es invalida, vuelva a intentar\n";
            delay(2);
            system("cls");
        }
        break;
    default:
        break;
    }
} 

int GenerarCodigo(){
    srand(time(NULL));
    int num = (10000 + rand() % (99999 + 1 - 10000));
    return num;
}
