#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <Windows.h>
#include <stdlib.h>
#include <sstream>
using namespace std;
string caracteres, caracteres_impreso;
int color, coincidencia=0, salto_linea=0;
int main(int argc, char** argv){
   if(argc>3){
    cout<<"Solo puede ingresar dos [2] argumentos";
    return 0;
   }
    cout<<"Elija el color que quiera que se resalte su palabra a buscar\n[1-Negro. 2-Azul. 3-Verde. 4-Aguamarina. 5-Rojo. 6-Purpura. 7-Amarillo. 8-Blanco. 9-Gris. 10-Celeste]\nIngrese la opcion: "; cin>>color;
    ifstream in_file (argv[2], fstream::in);
    if(!in_file.is_open()){
        cout<<"Archivo no encontrado"<<endl;
        return 0;
    }while(getline(in_file, caracteres)){
        caracteres_impreso=caracteres;
        cout<<caracteres_impreso[0]<<endl;
    }
    /*do{
        in_file>>caracteres;
        strcpy(caracteres_impreso, caracteres);
        for(int i=0; i<strlen(caracteres); i++){
            caracteres[i]= tolower(caracteres[i]);
        }for(int i=0; i<strlen(argv[1]); i++){
            argv[1][i]= tolower(argv[1][i]);
        }if(strcmp(argv[1], caracteres)==0){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color-1);
            cout<<caracteres_impreso<<endl;
            coincidencia++;
            salto_linea++;
        }else{
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
            cout<<caracteres_impreso<<endl;
            salto_linea++;
        }
    }while(in_file.good());
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    cout<<coincidencia<<" coincidencias en "<<salto_linea<<" lineas";*/
    in_file.close();
    return 0;
}