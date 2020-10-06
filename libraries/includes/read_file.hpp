#ifndef READ_FILE 
#define READ_FILE

#include "structures_library.hpp"
#include "initialization.hpp"
#include "print_stdio.hpp"

// este arquivo é responsável por definir todas as funções encarregadas de ler o arquivo de entrada

// função para retirar os espaços vazios de uma string, linha
string removeStringSpaces(string line);

// função que pergunta ao usuário o nome do arquivo
string findNameFile ();

// função que realiza a leitura do alfabeto de entrada a partir do arquivo entrada
AlphabetStructure readInputAlphabet(string line);

// função que realiza a leitura do alfabeto de saída a partir do arquivo entrada
AlphabetStructure readOutputAlphabet(string line);

// função que realiza a leitura dos estados possíveis a partir do arquivo entrada
StatesStructure readStates(string line);

// função que realiza a leitura estado inicial a partir do arquivo de entrada
string readInitState(string line);

// função que realiza a leitura estado final a partir do arquivo de entrada
EndStatesStructure readEndStates(string line);

// função que verifica se uma linha de transição esta formatada da forma correta
void verifyTransitionLine(string line);

// função que a partir da linha do arquivo que declara uma transição retorna a posição do estado inicial
int selectState(StatesStructure states, string stateName);

// função que a partir de um carácter de entrada retorna a posição da transição correspondente dentro do estado
int selectTransition(StateStructure state, char inputLetter);

// função que realiza a leitura de uma transição a partir do arquivo de entrada
TransitionStructure readTransition(string line);

// função que realiza a leitura de um conjunto de transições a partir do arquivo de entrada
StatesStructure readTransitions(StatesStructure states, ifstream* inputFile);

// função que realiza a leitura do arquivo de entrada
AutomatonStructure readAutomaton(ifstream* inputFile);

// função que realiza o manejo do arquivo de entrada
AutomatonStructure readInputFile(string fileName);

#endif
