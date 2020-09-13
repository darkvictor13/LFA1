// este arquivo serve de ponto de entrada do programa

// importando bibliotecas
#include "src/interface_library.h"

// ponto de entrada do programa
int main(int argc, char **argv) {
     verifySelectFile(argv[1], argc);
     cout << "acabei\n";
     return 0;
}
