// este arquivo serve de ponto de entrada do programa

// importando bibliotecas
#include "libraries/interface_library.h"

// ponto de entrada do programa
int main(int argc, char **argv) {
    //linha adicionada pelo victor, para dar merge
    string fileName;
    if (argc == 1) {
        fileName = findNameFile();
    }else if (argc == 2){
        fileName = argv[1]; 
    }else {
        errorMensage();
    }
}
