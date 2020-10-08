// Esse segmento de código é resposanvel pela inicialização das estruturas utilizadas.

#include "../includes/initialization.hpp"

/* 
	função que inicializa a estrutura de um determinado Alfabeto
	parâmetro (void) - sem parâmetros
	return (AlphabetStructure) - inicializada
*/
AlphabetStructure initializeAlphabet () {
	AlphabetStructure alphabetStructure;
	alphabetStructure.alphabet = "";
	alphabetStructure.alphabetSize = 0;
	return alphabetStructure;
}

/* 
	função que inicializa a estrutura de uma unica transição
	parâmetro (void) - sem parâmetros
	return (TransitionStructure) - inicializada
*/
TransitionStructure initializeTransition () {
	TransitionStructure transitionStructure;
	transitionStructure.endTransition = "";
	transitionStructure.inputCharacter = 0;
	transitionStructure.outputCharacters = "";
	return transitionStructure;
}

/* 
	função que inicializa a estrutura de um unico estado
	parâmetro (void) - sem parâmetros
	return (StateStructure) - inicializada
*/
StateStructure initializeState () {
	StateStructure stateStructure;
	stateStructure.numberOfTransitions = 0;
	stateStructure.stateName = "";
	for (int i = 0; i < MAX_TRANSITIONS; i++) {
		stateStructure.transitions[i] = initializeTransition();
	}
	return stateStructure;
}

/* 
	função que inicializa a estrutura que representa os conjuntos de estados
	parâmetro (void) - sem parâmetros
	return (StatesStructure) - inicializada
*/
StatesStructure initializeStates () {
	StatesStructure statesStructure;
	statesStructure.numberOfStates = 0;
	for (int i = 0; i < MAX_STATES; i++) {
		statesStructure.states[i] = initializeState();
	}
	return statesStructure;
}

/* 
	função que inicializa a estrutura da lista de estados finais
	parâmetro (void) - sem parâmetros
	return (EndStatesStructure) - inicializada
*/
EndStatesStructure initializeEndStates () {
	EndStatesStructure endStatesStructure;
	endStatesStructure.numberOfEndStates = 0;
	for (int i = 0; i < MAX_STATES; i++) {
		endStatesStructure.states[i] = "";
	}
	return endStatesStructure;
}

/* 
	função que inicializa a estrutura de um autômato
	parâmetro (void) - sem parâmetros
	return (AutomatonStructure) - inicializada
*/
AutomatonStructure initialize () {
	AutomatonStructure automatonStructure;
	automatonStructure.initState = "";
	automatonStructure.inputAlphabet = initializeAlphabet();
	automatonStructure.outputAlphabet = initializeAlphabet();
	automatonStructure.endStates = initializeEndStates();
	automatonStructure.states = initializeStates();
	return automatonStructure;
}

/* 
	função que inicializa a estrutura que representa um autômato em funcionamento
	parâmetro (void) - sem parâmetros
	return (AutomatonStatusStructure) - inicializada
*/
AutomatonStatusStructure initializeAutomatonController () {
	AutomatonStatusStructure automatonStatusStructure;
	automatonStatusStructure.thisState = initializeState();
	automatonStatusStructure.transition = initializeTransition();
	automatonStatusStructure.word = "";
	automatonStatusStructure.exitWord = "";
	automatonStatusStructure.stateName = "";
	automatonStatusStructure.transitionNumber = 0;
	automatonStatusStructure.stateNumber = 0;
	automatonStatusStructure.step = 0;
	return automatonStatusStructure;
}
