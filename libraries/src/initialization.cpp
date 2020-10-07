// Esse segmento de código é resposanvel pela inicialização das estruturas utilizadas.

#include "../includes/initialization.hpp"

// Função que inicializa a estrutura de um determinado Alfabeto
AlphabetStructure initializeAlphabet () {
	AlphabetStructure aux;
	aux.alphabet = "";
	aux.alphabetSize = 0;
	return aux;
}

// Função que inicializa a estrutura de uma unica transição
TransitionStructure initializeTransition () {
	TransitionStructure aux;
	aux.endTransition = "";
	aux.inputCharacter = 0;
	aux.outputCharacters = "";
	return aux;
}

// Função que inicializa a estrutura de um unico estado
StateStructure initializeState () {
	StateStructure aux;
	aux.numberOfTransitions = 0;
	aux.stateName = "";
	for (int i = 0; i < MAX_TRANSITIONS; i++) {
		aux.transitions[i] = initializeTransition();
	}
	return aux;
}

// Função que inicializa a estrutura que representa os conjuntos de estados
StatesStructure initializeStates () {
	StatesStructure aux;
	aux.numberOfStates = 0;
	for (int i = 0; i < MAX_STATES; i++) {
		aux.states[i] = initializeState();
	}
	return aux;
}

// Função que inicializa a estrutura da lista de estados finais
EndStatesStructure initializeEndStates () {
	EndStatesStructure aux;
	aux.numberOfEndStates = 0;
	for (int i = 0; i < MAX_STATES; i++) {
		aux.states[i] = "";
	}
	return aux;
}

// Função que inicializa a estrutura de um autômato
AutomatonStructure initialize () {
	AutomatonStructure aux;
	aux.initState = "";
	aux.inputAlphabet = initializeAlphabet();
	aux.outputAlphabet = initializeAlphabet();
	aux.endStates = initializeEndStates();
	aux.states = initializeStates();
	return aux;
}

// Função que inicializa a estrutura que representa um autômato em funcionamento
AutomatonStatusStructure initializeAutomatonController () {
	AutomatonStatusStructure aux;
	aux.thisState = initializeState();
	aux.transition = initializeTransition();
	aux.word = "";
	aux.exitWord = "";
	aux.stateName = "";
	aux.transitionNumber = 0;
	aux.stateNumber = 0;
	aux.step = 0;
	return aux;
}
