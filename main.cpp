// este arquivo serve de ponto de entrada do programa

// importando bibliotecas
#include "libraries/structures_library.h"
#include "libraries/call_libs.h"
#include "libraries/print_stdio.h"
#include "libraries/automaton_controller.h"

using namespace std;

// ponto de entrada do programa
int main(int argc, char **argv) {

    string fileName;

    if( argc == 1 ) {
        fileName = findNameFile();
    }else if( argc == 2 ) {
        fileName = argv[1];
    }else{
        errorMessagesCode( 0, "");
    }
    
    AutomatonStructure automaton;

    welcomeMessage();

    automaton = readInputFile(fileName);

    printAutomaton(automaton);

    enterWords(automaton);

    printEndProgramMessage();

    return 0;
}
