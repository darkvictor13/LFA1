#ifndef INITIALIZATION
#define INITIALIZATION

#include "structures_library.hpp"

// função que inicializa a estrutura de um determinado Alfabeto
AlphabetStructure initializeAlphabet ();

// função que inicializa a estrutura de uma unica transição
TransitionStructure initializeTransition ();

// função que inicializa a estrutura de um unico estado
StateStructure initializeState ();

// função que inicializa a estrutura que representa os conjuntos de estados
StatesStructure initializeStates ();

// função que inicializa a estrutura da lista de estados finais
EndStatesStructure initializeEndStates ();

// função que inicializa a estrutura de um autômato
AutomatonStructure initialize ();

// função que inicializa a estrutura que representa um autômato em funcionamento
AutomatonStatusStructure initializeAutomatonController ();

#endif
