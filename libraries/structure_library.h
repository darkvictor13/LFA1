// este arquivo contem a definição de todas as estruturas utilizadas

// definindo constantes
#define MAX_STATES 50
#define MAX_TRANSITIONS 50

// importando bibliotecas
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// estrutura de um determinado alfabeto
struct AlphabetStructure {
    string alphabet;
    int alphabetSize;
};

// estrutura de uma única transição
struct TransitionStructure {
    string endTransition;
    string inputCharacter;
    string outputCharacters;
};

// estrutura de um conjunto de transições
struct TransitionsStructure {
    TransitionStructure transitionStructure[MAX_TRANSITIONS];
    int numberOfTransitions;
};

// estrutura de um único estado
struct StateStructure {
    string stateName;
    TransitionsStructure transitionsStructure;
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