#ifndef STRUCTURES
#define STRUCTURES
// este arquivo contem a definição de todas as estruturas utilizadas

#include "call_libs.h"

// estrutura de um determinado alfabeto
struct AlphabetStructure {
    string alphabet;
    int alphabetSize;
};

// estrutura de uma única transição
struct TransitionStructure {
    string endTransition;
    char inputCharacter;
    string outputCharacters;
};

// estrutura de um único estado
struct StateStructure {
    string stateName;
    TransitionStructure transitions[MAX_TRANSITIONS];
    int numberOfTransitions;
};

// estrutura do conjunto de estados
struct StatesStructure {
    StateStructure states[MAX_STATES];
    int numberOfStates;
};

// estrutura da lista de estados finais
struct EndStatesStructure {
    string states[MAX_STATES];
    int numberOfEndStates;
};

// estrutura de um autômato
struct AutomatonStructure {
    AlphabetStructure inputAlphabet;
    AlphabetStructure outputAlphabet;
    StatesStructure states;
    string initState;
    EndStatesStructure endStates;
};

// estrutura de um automômato em funvionamento
struct AutomatonStatusStructure {
    StateStructure thisState;
    TransitionStructure transition;
    string word;
    string exitWord;
    string stateName;
    int transitionNumber;
    int stateNumber;
    int step;
};

#endif
