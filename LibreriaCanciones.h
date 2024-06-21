#ifndef LIBRERIA_CANCIONES
#define LIBRERIA_CANCIONES
#include <iostream>
#include "validaciones.h"

using namespace std;

int ContadorCanciones=0;

struct Canciones{
    int Identificador;
    string NombreCancion;
    string Artista;
    string Genero;
    int Anio;
    int ContadorReproducciones;
    int ContadorLikes;
    bool Like;
    Canciones *Next;
};
typedef Canciones *PtrCanciones;



PtrCanciones SolicitarDatosCanciones(){
    PtrCanciones auxDatos = new Canciones;
    string ano;
    cin.ignore();
    cout<<"------------------------------------------------------------------- \n";

    cout<<"Ingrese los datos datos que le seran solicitados a continuacion\n\n";
    cout<<"Ingrese su Nombre de la cancion: \n";
    cout<<">>";
    getline(cin,auxDatos->NombreCancion);

    cout<<"\nIngrese el nombre del artista:\n";
    cout<<">>";
    getline(cin,auxDatos->Artista);

    cout<<"\nIngrese el genero de la cancion\n";
    cout<<">>";
    getline(cin,auxDatos->Genero);

    do{
        cout<<"\nIngrese el ano de lanzamiento\n";
        cout<<">>";
        getline(cin,ano);
        MsgdeErrorF(1, ano);
    }while(!EsNumero(ano));
    auxDatos->Anio=stoi(ano);
    cout<<"--------------------------------------------------------------- \n";

    return auxDatos;
}

bool ValidarCodigoCanciones(PtrCanciones Lista, int Codigo){
    PtrCanciones aux = Lista;
    while(aux!=NULL){
        if(Codigo==aux->Identificador)
            return 1;
        aux=aux->Next;
    }
    return 0;
}

PtrCanciones BuscarCancion(PtrCanciones Lista, int Posicion){
    PtrCanciones aux = Lista;
    for(int i=1; i!=Posicion; i++)
        aux=aux->Next;
    return aux;
}

int BuscarPosicionDeCancion(PtrCanciones Lista, int Codigo){
    int i=1;
    PtrCanciones aux = Lista;
    while((aux->Identificador!= Codigo) && (aux->Next!=NULL)){
        i++;
        aux=aux->Next;
    }
    return i;
}

PtrCanciones CrearNodoCanciones(int identificador, string nombre, string artista, string genero, int anio,int reproducciones, int likes, int Darlike){
    PtrCanciones aux= new Canciones;
    aux->Identificador = identificador;
    aux->NombreCancion= nombre;
    aux->Artista= artista;
    aux->Genero = genero;
    aux->Anio= anio;
    aux-> ContadorReproducciones = reproducciones;
    aux->ContadorLikes=likes;
    aux->Like = Darlike;
    aux->Next = NULL;
    return aux;
}

void AgregarCancion(PtrCanciones &lista, PtrCanciones Nodo){
    if(lista==NULL)
        lista=Nodo;
    else{
        PtrCanciones aux = lista;
        while(aux->Next != NULL)
            aux=aux->Next;
        aux->Next=Nodo;
    }
    ContadorCanciones++;
}

void EliminarCancion(PtrCanciones &lista, int Posicion){
    PtrCanciones aux= lista;
    if(Posicion == 1){
        lista=lista->Next;
        delete aux;
    }else{
        for(int i=1; i!=Posicion-1; i++)
            aux= aux->Next;
        PtrCanciones aux2 = aux->Next;
        aux->Next = aux2->Next;
        delete aux2;
    }
    ContadorCanciones--;
}

void ImprimirListaCanciones(PtrCanciones Lista){
    cout<<"La lista de canciones de UCABIFY es: \n";

    cout<<" ID \t NOMBRE \t ARTISTA \t GENERO \t >Anio "<<endl;
    cout<<"--------------------------------------------------------------- \n";
    int i=1;

    while(Lista!=NULL){
        cout<<i<<" )\t";
        cout<<Lista->Identificador<<"\t";
        cout<<Lista->NombreCancion<<"\t";
        cout<<Lista->Artista<<"\t";
        cout<<Lista->Genero<<"\t";
        cout<<Lista->Anio<<"\n";
        Lista=Lista->Next;
        i++;
    }
            cout<<"--------------------------------------------------------------- \n";

    cout<<endl;
}

void CancionesMasEscuchadas(PtrCanciones Lista){
    PtrCanciones Ranking = NULL;
    PtrCanciones Mayor;
    int i=1;
    while(i<=5){
        Mayor = Lista;
        PtrCanciones aux = Lista;
        while(aux!=NULL){
            if((aux->ContadorReproducciones >= Mayor->ContadorReproducciones) && (!ValidarCodigoCanciones(Ranking, aux->Identificador)))
                Mayor=aux;
            aux=aux->Next;
        }
        AgregarCancion(Ranking, CrearNodoCanciones(Mayor->Identificador,Mayor->NombreCancion,Mayor->Artista,Mayor->Genero,Mayor->Anio, Mayor->ContadorReproducciones, Mayor->ContadorLikes,0));
        ContadorCanciones--;
        Mayor->ContadorReproducciones = 0;
        i++;
    }
    ImprimirListaCanciones(Ranking);
    system("pause");
}

#endif