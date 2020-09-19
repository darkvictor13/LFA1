#ifndef PRINT_STDIO 
#define PRINT_STDIO

#include "structures_library.h"

// este arquivo é responsável por definir todas as funções encarregadas de imprimir na saída padrão

// Imprime as mensagens que encerram o arquivo
void errorMessagesCode(int code, string message);

// função que escreve na saída padrão a mensagem de bem vindo ao programa
void welcomeMessage();

// função que imprime na saída padrão um alfabeto
void printAlphabet(AlphabetStructure alphabet);

// função que imprime na saída padrão um alfabeto
void printInputAlphabet(AlphabetStructure inputAlphabet);

// função que imprime na saída padrão um alfabeto
void printOutputAlphabet(AlphabetStructure outputAlphabet);

// função que imprime na saída padrão os estados de um autômato
void printStates(StatesStructure states);

// função que imprime na saída padrão o estado inicial de um autômato
void printInitState(string initState);

// função que imprime na saída padrão os estados finais de um autômato
void printEndStates(EndStatesStructure endStates);

// função que imprime na saída padrão o conjunto de transições de um dado estado
void printStateTransitions(StateStructure state);

// função que imprime na saída padrão todas as transições
void printTransitions(StatesStructure states);

// função que imprime na saída padrão o autômato carregado a partir do arquivo inicial
void printAutomaton(AutomatonStructure automaton);

// função que imprime na saída padrão erro em caso da palavra de entrada conter carácteres inválido para o autômato
void printWordInvalidMessage();

// função que imprime o número de espaços em brancos necessários para completar a linha
void printBlankSpaces(int n);
// função que imprime na saída padrão o inicio do ciclo de transição 
void printInitTransitionMessage(string stateName, string enterWord);

// função que imprime na saída padrão o resultado de uma transição efetuada pelo autômato
void printTransitionMessage(string stateName, string word, string outputCharacters, int step);

// função que imprime na saída padrão a mensagem que declara que a palavra é inválida
void printValidWord();

// função que imprime na saída padrão a mensagem que declara que a palavra não é inválida
void printInvalidWord();

// função que imprime na saída a palavra obtida no final do processo do autômato
void printEndWordMessage(string word);

// função que imprime a mensagem de fechamento do programa
void printEndProgramMessage();

// função que imprime mensagem pedindo a confirmação do usuário para encerrar o programa
void printExitConfirmationMessage();

#endif
