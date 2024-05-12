#include<iostream>
#include<stdlib.h>
#include<time.h>


using namespace std;

int fCodigoGenerar(struct Nodo *lista,int digito){ 
    Nodo *aux=lista;
    
    if (CodigoVerificar(&aux,digito)==false)
    {
        srand(time(NULL));
        //numero desde 0 hasta 99999(novecientos noventa y nueve mil novecientos noventa y nueve)
        cout<<"el digito es: "<<x<<endl;
        int x = (rand % 100000);
        return x;

    }else {cout<<"codigo ya existe"<<endl;}
    
}

bool CodigoVerificar(struct Nodo *lista,int codigo){
    bool buleano=false;
        Nodo *aux=lista; 
    if(aux)
         while(aux->next){
            if (aux->codigo=codigo)
            {
                return buleano=true;
            }
        }
}


void VoltearLiata( Node *p){

if(p && p->next){Node *aux=VoltearLiata(p->next);
node aux2=aux;
while(aux2->next){aux2=aux2->next;}
aux2->next=p;
p->next = NULL;
return aux;

}
}