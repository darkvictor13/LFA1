#ifndef AUTOMATON_CONTROLLER
#define AUTOMATON_CONTROLLER

#include "structures_library.hpp"
#include "print_stdio.hpp"
#include "read_file.hpp"
#include "read_stdio.hpp"

/*
   este arquivo contém as principais funções que simulam o ciclo de vida do autômato
*/

AlphabetStructure initializeAlphabet ();

TransitionStructure initializeTransition ();

StateStructure initializeState ();

StatesStructure initializeStates ();

EndStatesStructure initializeEndStates ();

AutomatonStructure initialize ();

// função que verifica se um determinado estado é estado final do autômato
bool verifyValidEndState(EndStatesStructure endStatesStructure, string endState);

// função que realiza uma dada transição do autômato definido no arquivo de entrada
AutomatonStatusStructure makeTransition(AutomatonStatusStructure runningAutomaton, AutomatonStructure automaton);

// função que realiza uma verificação previa da palavra entrada pelo usuário
bool preVerifyWord(string word);

// função que verifica se a palavra entrada pelo usuário é composta pelo alfabeto de entrada
bool verifyWordIfInAlphabet(AlphabetStructure alphabet, string word);

// função que verifica se a palavra entrada pelo usuário é válida para o autômato carregado
void runAutomaton(AutomatonStatusStructure runningAutomaton, AutomatonStructure automaton);

// função que permite a entrada varias palavras pelo usuário
void enterWords(AutomatonStructure automaton);

#endif
