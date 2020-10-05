#include "../includes/initialization.hpp"

AlphabetStructure initializeAlphabet () {
	AlphabetStructure aux;
	aux.alphabet = "";
	aux.alphabetSize = 0;
	return aux;
}

TransitionStructure initializeTransition () {
	TransitionStructure aux;
	aux.endTransition = "";
	aux.inputCharacter = 0;
	aux.outputCharacters = "";
	return aux;
}

StateStructure initializeState () {
	StateStructure aux;
	aux.numberOfTransitions = 0;
	aux.stateName = "";
	for (int i = 0; i < MAX_TRANSITIONS; i++) {
		aux.transitions[i] = initializeTransition();
	}
	return aux;
}

StatesStructure initializeStates () {
	StatesStructure aux;
	aux.numberOfStates = 0;
	for (int i = 0; i < MAX_STATES; i++) {
		aux.states[i] = initializeState();
	}
	return aux;
}

EndStatesStructure initializeEndStates () {
	EndStatesStructure aux;
	aux.numberOfEndStates = 0;
	for (int i = 0; i < MAX_STATES; i++) {
		aux.states[i] = "";
	}
	return aux;
}

AutomatonStructure initialize () {
	AutomatonStructure aux;
	aux.initState = "";
	aux.inputAlphabet = initializeAlphabet();
	aux.outputAlphabet = initializeAlphabet();
	aux.endStates = initializeEndStates();
	aux.states = initializeStates();
	return aux;
}


