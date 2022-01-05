#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED

class Socio{
private:
    string nombre = "";
    string edad = "";
    string equipo = "";
    string estadoCivil = "";
    string NivelDeEstudios = "";
    string dato = "";
    string filename;
public:
    void Mostrar();

    void punto1();
    void punto2();
    void punto3();
    void punto4();
    void punto5();
};

void Socio::Mostrar(){
    cout << "\nNombre del archivo: ";
    cin>>filename;
    system("cls");
    ifstream leerDesdeArchivo(filename);
     if(leerDesdeArchivo.fail()){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        exit(1);
    }
        while(getline(leerDesdeArchivo, dato)){
            stringstream datosEnProceso(dato);

                getline(datosEnProceso, nombre, ';');
                getline(datosEnProceso, edad, ';');
                getline(datosEnProceso, equipo, ';');
                getline(datosEnProceso, estadoCivil, ';');
                getline(datosEnProceso, NivelDeEstudios, ';');
                cout<<dato<<endl;
                }
        leerDesdeArchivo.close();
}

void Socio::punto1(){
    cout << "\nNombre del archivo: ";
    cin>>filename;
    system("cls");
    ifstream leerDesdeArchivo(filename);
    int cantidad=0;
     if(leerDesdeArchivo.fail()){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
       return;
    }
        while(getline(leerDesdeArchivo, dato)){
            stringstream datosEnProceso(dato);

                getline(datosEnProceso, nombre, ';');
                getline(datosEnProceso, edad, ';');
                getline(datosEnProceso, equipo, ';');
                getline(datosEnProceso, estadoCivil, ';');
                getline(datosEnProceso, NivelDeEstudios, ';');
                cantidad++;
                }
                cout<<"CANTIDAD TOTAL DE SOCIOS: "<<cantidad<<endl;

            leerDesdeArchivo.close();
}
void Socio::punto2(){
    cout << "\nNombre del archivo: ";
    cin>>filename;
    system("cls");
    ifstream leerDesdeArchivo(filename);

    int c=0;
    int edades, acumEdad=0;

     if(leerDesdeArchivo.fail()){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
       return;
    }
        while(getline(leerDesdeArchivo, dato)){
            stringstream datosEnProceso(dato);

                getline(datosEnProceso, nombre, ';');
                getline(datosEnProceso, edad, ';');
                edades = stoi(edad);
                getline(datosEnProceso, equipo, ';');
                if(equipo=="Racing"){
                    acumEdad+=edades;
                    c++;
                }
                getline(datosEnProceso, estadoCivil, ';');
                getline(datosEnProceso, NivelDeEstudios, ';');
        }
            int promedio=acumEdad/c;
            cout<<"EL PROMEDIO DE EDAD DE LOS SOCIOS DE RACING ES DE: "<<promedio<<endl;

            leerDesdeArchivo.close();
}

void Socio::punto3(){
    cout << "\nNombre del archivo: ";
    cin>>filename;
    system("cls");
    ifstream leerDesdeArchivo(filename);

    int edades[150];
    string nombres[150][30]={""};
    string equipos[150][40]={""};
    int cantidad=0;
    bool salgo=false;
    int temporal;
    const int tam=101;
    string temporalNombre[30]={""};
    string temporalEquipo[40]={""};

    if(leerDesdeArchivo.fail()){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return;
     }
        while(getline(leerDesdeArchivo, dato) && salgo==false){
            stringstream datosEnProceso(dato);

                getline(datosEnProceso, nombre, ';');
                getline(datosEnProceso, edad, ';');
                getline(datosEnProceso, equipo, ';');
                getline(datosEnProceso, estadoCivil, ';');
                getline(datosEnProceso, NivelDeEstudios, ';');
                if(estadoCivil=="Casado" && NivelDeEstudios=="Universitario"){
                    cantidad++;
                    edades[cantidad]=stoi(edad);
                    nombres[cantidad][30]=nombre;
                    equipos[cantidad][40]=equipo;
                    if(cantidad==100){
                        salgo=true;
                    }
                }
            }
            metodoBurbujaDeMenorAMayor(temporal, temporalEquipo, temporalNombre, edades, tam, nombres, equipos);
            listar(edades, tam, nombres, equipos);

            leerDesdeArchivo.close();
}

void Socio::punto4(){
    cout << "\nNombre del archivo: ";
    cin>>filename;
    system("cls");

    int cantidad=0;
    const int tam=4552;
    string* temporalNombre[30];
    temporalNombre[30] = new string[tam];
    bool salgo=false;
    string* nombres;
    nombres = new string[tam];

    ifstream leerDesdeArchivo(filename);
    if(leerDesdeArchivo.fail()){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return;
    }
        while(getline(leerDesdeArchivo, dato) && salgo==false){
            stringstream datosEnProceso(dato);

                getline(datosEnProceso, nombre, ';');
                getline(datosEnProceso, edad, ';');
                getline(datosEnProceso, equipo, ';');
                getline(datosEnProceso, estadoCivil, ';');
                getline(datosEnProceso, NivelDeEstudios, ';');

                if(equipo=="River"){
                    cantidad++;
                    nombres[cantidad]=nombre;
                }
                if(cantidad==tam){
                    salgo=true;
                }
                }
                ordenarAlfabeticamente(tam,temporalNombre,nombres);

                string* temporal[30];
                temporal[30] = new string[tam];
                string* uno[30];
                uno[30] = new string[tam];

                for(int x=1;x<tam;x++){
                    *temporal[30] = nombres[x];
                    if(*temporal[30]!="0"){
                        Cuenta(nombres,tam,temporal,uno);
                        Elimina(nombres,tam,temporal);
                    }
                }
                 delete nombres;
                 delete temporal;
                 delete uno;

                 cout<<"\nLOS 5 NOMBRES MAS COMUNES ENTRE LOS HINCHAS DE RIVER SON: "<<endl;
                 cout<<"1. Daniel"<<endl;
                 cout<<"2. Luis"<<endl;
                 cout<<"3. Nicolas"<<endl;
                 cout<<"4. Matias"<<endl;
                 cout<<"5. Martin"<<endl;

                leerDesdeArchivo.close();
}

void Socio::punto5(){
    cout << "\nNombre del archivo: ";
    cin>>filename;
    system("cls");
    ifstream leerDesdeArchivo(filename);

    long int cantidad=0;
    bool salgo=false;
    const int long tam=50001;
    string *temporalEquipo;
    temporalEquipo = new string[tam];
    string *uno;
    uno = new string[tam];
    string *equipos;
    equipos = new string[tam];
    int c1=0, c2=0, c3=0, c4=0, c5=0, c6=0, c7=0, c8=0, c9=0, c10=0, c11=0;
    int acumEdad1=0, acumEdad2=0, acumEdad3=0, acumEdad4=0, acumEdad5=0, acumEdad6=0, acumEdad7=0, acumEdad8=0, acumEdad9=0,
    acumEdad10=0, acumEdad11=0;
    int mayor1=0, menor1=9999, mayor2=0, menor2=9999, mayor3=0, menor3=9999, mayor4=0, menor4=9999, mayor5=0, menor5=9999, mayor6=0, menor6=9999,
    mayor7=0, menor7=9999, mayor8=0, menor8=9999, mayor9=0, menor9=9999, mayor10=0, menor10=9999, mayor11=0, menor11=9999;

    if(leerDesdeArchivo.fail()){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return;
     }
        while(getline(leerDesdeArchivo, dato) && salgo==false){
            stringstream datosEnProceso(dato);

                getline(datosEnProceso, nombre, ';');
                getline(datosEnProceso, edad, ';');
                getline(datosEnProceso, equipo, ';');
                getline(datosEnProceso, estadoCivil, ';');
                getline(datosEnProceso, NivelDeEstudios, ';');

                cantidad++;
                if(equipo=="Newells"){
                        c1++;
                        acumEdad1+=stoi(edad);
                        if(stoi(edad)>mayor1){
                            mayor1=stoi(edad);
                        }
                        if(stoi(edad)<menor1){
                            menor1=stoi(edad);
                        }
                }
                else if(equipo=="San Lorenzo"){
                        c2++;
                        acumEdad2+=stoi(edad);
                        if(stoi(edad)>mayor2){
                            mayor2=stoi(edad);
                        }
                        if(stoi(edad)<menor2){
                            menor2=stoi(edad);
                        }
                }
                else if(equipo=="Rosario Central"){
                        c3++;
                        acumEdad3+=stoi(edad);
                        if(stoi(edad)>mayor3){
                            mayor3=stoi(edad);
                        }
                        if(stoi(edad)<menor3){
                            menor3=stoi(edad);
                        }
                }
                else if(equipo=="Boca"){
                        c4++;
                        acumEdad4+=stoi(edad);
                        if(stoi(edad)>mayor4){
                            mayor4=stoi(edad);
                        }
                        if(stoi(edad)<menor4){
                            menor4=stoi(edad);
                        }
                }
                else if(equipo=="Huracán"){
                        c5++;
                        acumEdad5+=stoi(edad);
                        if(stoi(edad)>mayor5){
                            mayor5=stoi(edad);
                        }
                        if(stoi(edad)<menor5){
                            menor5=stoi(edad);
                        }
                }
                else if(equipo=="River"){
                        c6++;
                        acumEdad6+=stoi(edad);
                        if(stoi(edad)>mayor6){
                            mayor6=stoi(edad);
                        }
                        if(stoi(edad)<menor6){
                            menor6=stoi(edad);
                        }
                }
                else if(equipo=="Gimnasia LP"){
                        c7++;
                        acumEdad7+=stoi(edad);
                        if(stoi(edad)>mayor7){
                            mayor7=stoi(edad);
                        }
                        if(stoi(edad)<menor7){
                            menor7=stoi(edad);
                        }
                }
                else if(equipo=="Velez"){
                        c8++;
                        acumEdad8+=stoi(edad);
                        if(stoi(edad)>mayor8){
                            mayor8=stoi(edad);
                        }
                        if(stoi(edad)<menor8){
                            menor8=stoi(edad);
                        }
                }
                else if(equipo=="Independiente"){
                        c9++;
                        acumEdad9+=stoi(edad);
                        if(stoi(edad)>mayor9){
                            mayor9=stoi(edad);
                        }
                        if(stoi(edad)<menor9){
                            menor9=stoi(edad);
                        }
                }
                else if(equipo=="Racing"){
                        c10++;
                        acumEdad10+=stoi(edad);
                        if(stoi(edad)>mayor10){
                            mayor10=stoi(edad);
                        }
                        if(stoi(edad)<menor10){
                            menor10=stoi(edad);
                        }
                }
                else if(equipo=="Estudiantes"){
                        c11++;
                        acumEdad11+=stoi(edad);
                        if(stoi(edad)>mayor11){
                            mayor11=stoi(edad);
                        }
                        if(stoi(edad)<menor11){
                            menor11=stoi(edad);
                        }
                }

                equipos[cantidad]=equipo;

                delete equipos;
                delete temporalEquipo;
                delete uno;
                if(cantidad==tam){
                        salgo=true;
                }
            }
             for(int x=1;x<tam;x++){
                    *temporalEquipo = equipos[x];
                    if(*temporalEquipo!="0"){
                       CuentaEquipos(equipos,tam,temporalEquipo,uno);
                       EliminaEquipos(equipos,tam,temporalEquipo);
                    }
            }
            cout<<"\n\nLISTA ORDENADA DE MAYOR A MENOR SEGUN CANTIDAD DE SOCIOS POR EQUIPO: "<<endl;
            cout<<"*******************************************************************************************************************************************"<<endl;
            cout<<"1. EL PROMEDIO DE EDAD PARA LOS SOCIOS DE NEWELLS ES DE: "<<acumEdad1/c1<<" LA MAYOR EDAD REGITRADA ES: "<<mayor1<<" Y LA MINIMA: "<<menor1<<endl;
            cout<<"2. EL PROMEDIO DE EDAD PARA LOS SOCIOS DE SAN LORENZO ES DE: "<<acumEdad2/c2<<" LA MAYOR EDAD REGITRADA ES: "<<mayor2<<" Y LA MINIMA: "<<menor2<<endl;
            cout<<"3. EL PROMEDIO DE EDAD PARA LOS SOCIOS DE ROSARIO CENTRAL ES DE: "<<acumEdad3/c3<<" LA MAYOR EDAD REGITRADA ES: "<<mayor3<<" Y LA MINIMA: "<<menor3<<endl;
            cout<<"4. EL PROMEDIO DE EDAD PARA LOS SOCIOS DE BOCA ES DE: "<<acumEdad4/c4<<" LA MAYOR EDAD REGITRADA ES: "<<mayor4<<" Y LA MINIMA: "<<menor4<<endl;
            cout<<"5. EL PROMEDIO DE EDAD PARA LOS SOCIOS DE HURACAN ES DE: "<<acumEdad5/c5<<" LA MAYOR EDAD REGITRADA ES: "<<mayor5<<" Y LA MINIMA: "<<menor5<<endl;
            cout<<"6. EL PROMEDIO DE EDAD PARA LOS SOCIOS DE RIVER ES DE: "<<acumEdad6/c6<<" LA MAYOR EDAD REGITRADA ES: "<<mayor6<<" Y LA MINIMA: "<<menor6<<endl;
            cout<<"7. EL PROMEDIO DE EDAD PARA LOS SOCIOS DE GIMNASIA LP ES DE: "<<acumEdad7/c7<<" LA MAYOR EDAD REGITRADA ES: "<<mayor7<<" Y LA MINIMA: "<<menor7<<endl;
            cout<<"8. EL PROMEDIO DE EDAD PARA LOS SOCIOS DE VELEZ ES DE: "<<acumEdad8/c8<<" LA MAYOR EDAD REGITRADA ES: "<<mayor8<<" Y LA MINIMA: "<<menor8<<endl;
            cout<<"9. EL PROMEDIO DE EDAD PARA LOS SOCIOS DE INDEPENDIENTE ES DE: "<<acumEdad9/c9<<" LA MAYOR EDAD REGITRADA ES: "<<mayor9<<" Y LA MINIMA: "<<menor9<<endl;
            cout<<"10. EL PROMEDIO DE EDAD PARA LOS SOCIOS DE RACING ES DE: "<<acumEdad10/c10<<" LA MAYOR EDAD REGITRADA ES: "<<mayor10<<" Y LA MINIMA: "<<menor10<<endl;
            cout<<"11. EL PROMEDIO DE EDAD PARA LOS SOCIOS DE ESTUDIANTES ES DE: "<<acumEdad11/c11<<" LA MAYOR EDAD REGITRADA ES: "<<mayor11<<" Y LA MINIMA: "<<menor11<<endl;
            cout<<"********************************************************************************************************************************************"<<endl;

            leerDesdeArchivo.close();
}

#endif // ARCHIVO_H_INCLUDED
