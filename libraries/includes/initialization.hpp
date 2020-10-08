#ifndef INITIALIZATION
#define INITIALIZATION

#include "structures_library.hpp"

//Função que inicializa a estrutura de um determinado Alfabeto
AlphabetStructure initializeAlphabet ();

//Função que inicializa a estrutura de uma unica transição
TransitionStructure initializeTransition ();

//Função que inicializa a estrutura de um unico estado
StateStructure initializeState ();

//Função que inicializa a estrutura que representa os conjuntos de estados
StatesStructure initializeStates ();

//Função que inicializa a estrutura da lista de estados finais
EndStatesStructure initializeEndStates ();

//Função que inicializa a estrutura de um autômato
AutomatonStructure initialize ();

//Função que inicializa a estrutura que representa um autômato em funcionamento
AutomatonStatusStructure initializeAutomatonController ();

#endif
