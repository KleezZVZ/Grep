#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <stdlib.h>
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
    system("cls");
    if(!in_file.is_open()){
        cout<<"Archivo no encontrado"<<endl;
        return 0;
    }while(getline(in_file, caracteres, '\n')){
        caracteres+="\n";
        caracteres_impreso=caracteres;
        for(int i=0; i<caracteres.length(); i++){
            caracteres[i]=tolower(caracteres[i]);
        }for(int i=0; i<strlen(argv[1]); i++){
            argv[1][i]=tolower(argv[1][i]);
        }for(int i=0; i<caracteres.length(); i++){
            if(caracteres.find(argv[1])!= string::npos && (caracteres.find(argv[1])<=i && (caracteres.find(argv[1])+strlen(argv[1]))>=i ) && strlen(argv[1])!=1){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color-1);
                cout<<caracteres_impreso[i];
            }else if(caracteres.find(argv[1])!= string::npos && (caracteres.find(argv[1])==i && strlen(argv[1])==1)){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color-1);
                cout<<caracteres_impreso[i];
            }else{
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
                cout<<caracteres_impreso[i];
            }if(caracteres.find(argv[1])+strlen(argv[1])==i && caracteres.find(argv[1])!= string::npos){
                coincidencia++;
            }if(i==0){
                salto_linea++;
            }
        }
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    cout<<coincidencia<<" coincidencias en "<<salto_linea<<" lineas"<<endl;
    in_file.close();
    system("pause");
    return 0;
}