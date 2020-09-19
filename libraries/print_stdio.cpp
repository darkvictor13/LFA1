// este arquivo é responsáel por definir todas as funções encarregadas de imprimir na saída estandar

#include "print_stdio.h"

// função que escreve na saída estandar a mensafem de bienvenida au programa
void welcomeMessage() {
    
    cout << endl 
         << "-----------------------------------" << endl
         << "-----------------------------------" << endl 
         << "----- Mealy Machine Simulator -----" << endl
         << "-----------------------------------" << endl
         << "----------------------- Since 2020." << endl << endl;

}

// função que imprime na saída estandar um alfabeto
void printAlphabet(AlphabetStructure alphabet) {

    cout << alphabet.alphabet[0];

    for(int i = 1; i < alphabet.alphabetSize; i++) {
        cout << ", " << alphabet.alphabet[i];
    }
}

// função que imprime na saída estandar um alfabeto
void printInputAlphabet(AlphabetStructure inputAlphabet) {
    
    cout << " -> alfabeto_entrada = { ";
    
    printAlphabet(inputAlphabet);
    
    cout << " }" << endl;
}

// função que imprime na saída estandar um alfabeto
void printOutputAlphabet(AlphabetStructure outputAlphabet) {
    
    cout << " -> alfabeto_saida = { ";
    
    printAlphabet(outputAlphabet);
    
    cout << " }" << endl;
}

// função que imprime na saída estandar os estados de um autômato
void printStates(StatesStructure states) {
    
    cout << " -> estados = { ";

    cout << states.states[0].stateName;

    for(int i = 1; i < states.numberOfStates; i++) {
        cout << ", " << states.states[i].stateName;
    }

    cout << " }" << endl;
}

// função que imprime na saída estandar o estado inicial de um autômato
void printInitState(string initState) {
    
    cout << " -> inicial = " << initState << endl;

}

// função que imprime na saída estandar os estados finais de um autômato
void printEndStates(EndStatesStructure endStates) {
    
    cout << " -> finais = { ";

    cout << endStates.states[0];

    for(int i = 1; i < endStates.numberOfEndStates; i++) {
        cout << ", " << endStates.states[i];
    }

    cout << " }" << endl;
}

// função que imprime na saída estandar o conjunto de transições de um dado estado
void printStateTransitions(StateStructure state) {
    
    for(int i = 0; i < state.numberOfTransitions; i++) {
        
        cout << "     -> ( "
             << state.stateName
             << ", "
             << state.transitions[i].inputCharacter
             << " ) = ( "
             << state.transitions[i].endTransition
             << ", "
             << state.transitions[i].outputCharacters
             << " )"
             << endl;

    }
}

// função que imprime na saída estandar todas as transições
void printTransitions(StatesStructure states) {
    
    cout << " -> transição:" << endl;

    for(int i = 0; i < states.numberOfStates; i++) {
        printStateTransitions(states.states[i]);
    }
}

// função que imprime na saída estandar o autômato carregado apartir do arquivo inicial
void printAutomaton(AutomatonStructure automaton) {

    cout << "--------------------" << endl
         << "------------------------------" << endl
         << "Autômato:" << endl;

    printInputAlphabet(automaton.inputAlphabet);

    printOutputAlphabet(automaton.outputAlphabet);

    printStates(automaton.states);

    printInitState(automaton.initState);

    printEndStates(automaton.endStates);

    printTransitions(automaton.states);

    cout << "------------------------------" << endl
         << "--------------------" << endl << endl;

}

// função que imprime na saída estandar erro em caso da palavra de entrada conter carateres inválido para o autômato
void printWordInvalidMessage() {
    
    cout << "Palavra inválida: existem caráteres que não pertencem ao alfabeto inicial do autômato." << endl << endl;

}

// função que imprime o número de espaçõs em brancos necesssarios para completar a linha
void printBlankSpaces(int n) {
   
    for (int i = 0; i < n; i++) {
        cout << ' ';
    }
}

// função que imprime na saída estandar o inicio do ciclo de transição 
void printInitTransitionMessage(string stateName, string enterWord) {
   
    cout << endl << "[" << stateName << "]" << enterWord << endl;

}

// função que imprime na saída estandar o resultado de uma transição efetuada pelo autômato
void printTransitionMessage(string stateName, string word, string outputCharacters, int step) {

    cout << "[" << stateName << "]" << word;
        
    printBlankSpaces(MIN_BLANK_SPACES + step);
        
    cout << "saída: " << outputCharacters << endl;
}

// função que imprime na saída estandar a mensagem que declara que a palavar é inválida
void printValidWord() {

    cout << "ACEITA" << endl;

}

// função que imprime na saída estandar a mensagem que declara que a palavar não é inválida
void printInvalidWord() {

    cout << "REJEITA" << endl;

}

// função que imprime na saída a palavra obtida no final do processo do autômato
void printEndWordMessage(string word) {

    cout << "Palavra de saída: " 
         << word << endl << endl;

}

// função que imprime a mensagem de fechamento do progama
void printEndProgramMessage() {

    cout << endl 
         << "-----------------------------------" << endl 
         << "--------------- FIM ---------------" << endl
         << "-----------------------------------" << endl << endl;

}

// função que imprime mensagem pedindo a confirmação do usuário para encerrar o programa
void printExitConfirmationMessage() {

    cout << "Deseja finalizar o programa? [y/n] -> ";

}