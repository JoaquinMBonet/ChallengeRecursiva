#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

#include "funciones.h"
#include "archivo.h"

int main()
{
    int opc;
    Socio obj;
    while(true){
        system("cls");
        cout<<"ELIJA UNA DE LAS SIGUIENTES OPCIONES"<<endl;
        cout<<"1. PUNTO 1"<<endl;
        cout<<"2. PUNTO 2"<<endl;
        cout<<"3. PUNTO 3"<<endl;
        cout<<"4. PUNTO 4"<<endl;
        cout<<"5. PUNTO 5"<<endl;
        cout<<"6. VER ARCHIVO COMPLETO"<<endl;
        cout<<"0. SALIR"<<endl;
        cout<<"\nOPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
        case 1: obj.punto1();
            break;
        case 2: obj.punto2();
            break;
        case 3: obj.punto3();
            break;
        case 4: obj.punto4();
            break;
        case 5: obj.punto5();
            break;
        default: cout<<"OPCION FUERA DE RANGO"<<endl;
            break;
        case 0: return 0;
            break;
        case 6: obj.Mostrar();
            break;
        }
       system("pause>nul");
    }
    return 0;
}
