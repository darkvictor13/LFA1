// este arquivo serve de ponto de entrada do programa

// importando bibliotecas
#include "src/interface_library.h"

// ponto de entrada do programa
int main(int argc, char **argv) {
    string fileName;
    if (argc == 1) {
        fileName = findNameFile();
    }else if (argc == 2){
       fileName = argv[1]; 
    }else {
        errorMensage();
    }
    cout << "o nome do arquivinhu é: " << fileName << endl;
    return 0;
}
