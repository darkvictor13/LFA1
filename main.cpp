// este arquivo serve de ponto de entrada do programa

// importando bibliotecas
//#include "libraries/function_library.h"
#include "libraries/interface_library.h"

// ponto de entrada do programa
int main() {
    AutomatonStructure automaton;

    automaton = readInputFile();

    printAutomaton(automaton);



    return 0;
}