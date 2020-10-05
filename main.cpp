// este arquivo serve de ponto de entrada do programa

// importando bibliotecas
#include "libraries/includes/structures_library.hpp"
#include "libraries/includes/call_libs.hpp"
#include "libraries/includes/print_stdio.hpp"
#include "libraries/includes/automaton_controller.hpp"

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

	automaton = initialize();

    welcomeMessage();

    automaton = readInputFile(fileName);

    printAutomaton(automaton);

		EnterWordMensage();

    enterWords(automaton);

    printEndProgramMessage();

    return 0;
}
