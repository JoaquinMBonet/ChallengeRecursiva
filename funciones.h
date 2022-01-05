#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

///PROTOTIPOS
void metodoBurburaDeMenorAMayor(int temporal, string temporalNombre[30], string temporalEquipo[40], int *edad, int tam, string nombre[][30], string equipo[][40]);
void listar(int *edad, int tam, string nombre[][30], string equipo[][40]);
void ordenarAlfabeticamente(int tam, string temporalNombre[30], string nombres[][30]);
void Cuenta(string* nombres, int tam, string* temporal[30], string* uno[30]);
void Elimina(string* nombres, int tam, string* temporal[30]);
void CuentaEquipos(string* equipos, int tam, string* temporalEquipo, string* uno);
void EliminaEquipos(string* equipos, int tam, string* temporalEquipo);

///DESARROLLO
void metodoBurbujaDeMenorAMayor(int temporal, string temporalNombre[30], string temporalEquipo[40], int *edades, int tam, string nombres[150][30], string equipos[150][40]){

    for(int i=1;i<tam;i++){
                for(int j=1;j<tam-1;j++){
                    if(edades[i]<edades[j]){
                        temporal = edades[i];
                        edades[i] = edades[j];
                        edades[j] = temporal;
                        temporalNombre[30] = nombres[i][30];
                        nombres[i][30] = nombres[j][30];
                        nombres[j][30] = temporalNombre[30];
                        temporalEquipo[40] = equipos[i][40];
                        equipos[i][40] = equipos[j][40];
                        equipos[j][40] = temporalEquipo[40];
                    }
                }
            }
}

void listar(int *edades, int tam, string nombres[150][30], string equipos[150][40]){
    for(int p=1;p<tam;p++){
            cout<<p<<". "<<nombres[p][30]<<";"<<edades[p]<<";"<<equipos[p][40]<<endl;
    }
}

void ordenarAlfabeticamente(int tam, string* temporalNombre[30], string* nombres){
    for(int i=1;i<tam;i++){
            for(int j=i;j<tam;j++){
                if(nombres[i]>nombres[j]){
                    *temporalNombre[30]=nombres[i];
                    nombres[i]=nombres[j];
                    nombres[j]=*temporalNombre[30];
                }
            }
        }
}

void Cuenta(string* nombres, int tam, string* temporal[30], string* uno[30]){
    int contador=0;

    for(int i=1;i<tam;i++){
        if(*temporal[30]==nombres[i]){
            contador++;
            *uno[30] = nombres[i];
        }
    }
    cout<<"EL NOMBRE: "<<setw(3)<<*uno[30]<<" SE REPITE "<<setw(2)<<contador<<" VECES"<<endl;
}

void Elimina(string* nombres, int tam, string* temporal[30]){
    string cero={"0"};
    for(int i=1;i<tam;i++){
        if(*temporal[30]==nombres[i]){
            nombres[i] = cero;
        }
    }
}

void CuentaEquipos(string* equipos, int tam, string* temporalEquipo, string* uno){
    int contador=0;

    for(int i=1;i<tam;i++){
        if(*temporalEquipo==equipos[i]){
            contador++;
            *uno = equipos[i];
        }
    }
    cout<<"EL EQUIPO: "<<setw(3)<<*uno<<" CUENTA CON "<<setw(2)<<contador<<" SOCIOS"<<endl;
}

void EliminaEquipos(string* equipos, int tam, string* temporalEquipo){
    string cero={"0"};
    for(int i=1;i<tam;i++){
        if(*temporalEquipo==equipos[i]){
            equipos[i] = cero;
        }
    }
}

#endif // FUNCIONES_H_INCLUDED
