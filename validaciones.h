#ifndef VALIDACIONES_LIB
#define VALIDACIONES_LIB

#include <iostream>
#include <string>
#include <time.h>
#include "LibreriaUsuarios.h"
using namespace std;

void delay(int secs) {
    for(int i = (time(NULL) + secs); time(NULL) != i; time(NULL));
}

bool EsNumero(string numeroString)
{
    if (numeroString.empty()){
        return false;  
    }else{
    try
        {   
            stoi(numeroString);
            return 1;
            /* code */
        }
        catch(const std::exception& e)
        {
    //        std::cerr << e.what() << '\n';
            return 0;
        }
    }
}

void MsgdeErrorF(int a, string op){
    switch (a)
    {
    case (1):
        if (!EsNumero(op)){
                cout<<"No puede ingresar un caracter, es una opcion invalida. Vuelva a intentar\n";
                delay(2);
                system("cls");
            }
        break;
    default:
        break;
    }
} 



#endif
