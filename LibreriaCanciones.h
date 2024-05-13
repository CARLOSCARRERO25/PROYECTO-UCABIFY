#ifndef LIBRERIA_CANCIONES
#define LIBRERIA_CANCIONES
#include <iostream>

using namespace std;

int contadorCanciones=0;

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

PtrCanciones SolicitarDatosCanciones(){
    PtrCanciones auxDatos = new Canciones;

    cout<<"Ingrese los datos datos que le seran solicitados a continuacion\n";
    cout<<"Ingrese su Nombre de la cancion: \n";
    cin>>auxDatos->Nombre_Cancion;

    cout<<"\nIngrese el nombre del artista:\n";
    cin>>auxDatos->Artista;

    cout<<"\nIngrese el genero de la cancion\n";
    cin>>auxDatos->Genero;

    cout<<"\nIngrese el ano de lanzamiento\n";
    cin>>auxDatos->Year;
    return auxDatos;
}

PtrCanciones BuscarCancion(PtrCanciones Lista, int Posicion){
    PtrCanciones aux = Lista;
    for(int i=1; i!=Posicion; i++)
        aux=aux->Next;
    return aux;
}

PtrCanciones CrearNodoCanciones(int identificador, string nombre, string artista, string genero, int ano){
    PtrCanciones aux= new Canciones;
    aux->Identificador = identificador;
    aux->Nombre_Cancion= nombre;
    aux->Artista= artista;
    aux->Genero = genero;
    aux->Year= ano;
    aux->Contador_Reproducciones = 0;
    aux->Like = 0;
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
    contadorCanciones++;
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
    contadorCanciones--;
}

void ImprimirListaCanciones(PtrCanciones Lista){
    for(int i=1; i<=contadorCanciones; i++){
        cout<<i<<" )\t";
        cout<<Lista->Identificador<<"\t";
        cout<<Lista->Nombre_Cancion<<"\t";
        cout<<Lista->Artista<<"\t";
        cout<<Lista->Genero<<"\t";
        cout<<Lista->Year<<"\n";
        Lista=Lista->Next;
    }
    cout<<endl;
}

#endif