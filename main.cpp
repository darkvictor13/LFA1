// este arquivo serve de ponto de entrada do programa

// importando bibliotecas
#include "src/interface_library.h"

// ponto de entrada do programa
int main(int argc, char **argv) {
     if (argc == 1) {
         //como tem que fazer essa verificação para funcionar
         //da para separar em 2 funções melhores
         verifySelectFile("", argc);
     }else {
         verifySelectFile(argv[1], argc);
     }
     cout << "acabei\n";
     return 0;
}
