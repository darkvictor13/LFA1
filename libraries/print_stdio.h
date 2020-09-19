#ifndef print_stdio 
#define print_stdio

#include "structures_library.h"

// este arquivo é responsáel por definir todas as funções encarregadas de imprimir na saída estandar

// função que escreve na saída estandar a mensafem de bienvenida au programa
void welcomeMessage();

// função que imprime na saída estandar um alfabeto
void printAlphabet(AlphabetStructure alphabet);

// função que imprime na saída estandar um alfabeto
void printInputAlphabet(AlphabetStructure inputAlphabet);

// função que imprime na saída estandar um alfabeto
void printOutputAlphabet(AlphabetStructure outputAlphabet);

// função que imprime na saída estandar os estados de um autômato
void printStates(StatesStructure states) ;

// função que imprime na saída estandar o estado inicial de um autômato
void printInitState(string initState) ;

// função que imprime na saída estandar os estados finais de um autômato
void printEndStates(EndStatesStructure endStates) ;

// função que imprime na saída estandar o conjunto de transições de um dado estado
void printStateTransitions(StateStructure state) ;

// função que imprime na saída estandar todas as transições
void printTransitions(StatesStructure states) ;

// função que imprime na saída estandar o autômato carregado apartir do arquivo inicial
void printAutomaton(AutomatonStructure automaton) ;

// função que imprime na saída estandar erro em caso da palavra de entrada conter carateres inválido para o autômato
void printWordInvalidMessage() ;

// função que imprime o número de espaçõs em brancos necesssarios para completar a linha
void printBlankSpaces(int n) ;
// função que imprime na saída estandar o inicio do ciclo de transição 
void printInitTransitionMessage(string stateName, string enterWord) ;

// função que imprime na saída estandar o resultado de uma transição efetuada pelo autômato
void printTransitionMessage(string stateName, string word, string outputCharacters, int step) ;

// função que imprime na saída estandar a mensagem que declara que a palavar é inválida
void printValidWord();

// função que imprime na saída estandar a mensagem que declara que a palavar não é inválida
void printInvalidWord();

// função que imprime na saída a palavra obtida no final do processo do autômato
void printEndWordMessage(string word);

// função que imprime a mensagem de fechamento do progama
void printEndProgramMessage();

// função que imprime mensagem pedindo a confirmação do usuário para encerrar o programa
void printExitConfirmationMessage();

#endif