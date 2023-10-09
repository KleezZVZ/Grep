#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <Windows.h>
#include <stdlib.h>
using namespace std;
char caracteres[100];
string caracteres_impreso;
int color=2, coincidencia=0, salto_linea=0;
int main(int argc, char** argv){
   if(argc>3){
    cout<<"Solo puede ingresar dos [2] argumentos";
    return 0;
   }else{
        ifstream in_file (argv[2], fstream::in|fstream::out|fstream::binary);
        if(!in_file.is_open()){
            cout<<"Archivo no encontrado"<<endl;
            return 0;
        }else{
            do{
                in_file>>caracteres;
                caracteres_impreso=caracteres;
                 for(int i=0; i<strlen(caracteres); i++){
                    caracteres[i]= tolower(caracteres[i]);
                }for(int i=0; i<strlen(argv[1]); i++){
                    argv[1][i]= tolower(argv[1][i]);
                }if(strcmp(argv[1], caracteres)==0){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
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
            cout<<coincidencia<<" coincidencias en "<<salto_linea<<" lineas";
        }
   }
   return 0;
}