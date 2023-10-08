#include <iostream>
#include <fstream>
using namespace std;
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
            cout<<"Archivo encontrado"<<endl;
        }
   }
   return 0;
}