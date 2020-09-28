/* 
   este arquivo é responsável por definir todas as funções encarregadas de imprimir na saída padrão
*/

#include "../includes/print_stdio.h"

// função que escreve na saída padrão a mensagem de bem vindo ao programa

// Imprime as mensagens que encerram o arquivo
void errorMessagesCode(int code, string message) {

    switch(code) {
        case 0:
            cout << "Você está usando o programa de forma errada!\n"
                 << "Por favor rode:\n"
                 << "[nome do programa] [nome do arquivo com os dados]\n";
            break;
        case 1:
            cout << "Erro de formato: " << message << " não identificado." << endl;
            break;
        case 2:
            cout << "Erro de formato: '=' separador não identificado." << endl;
            break;
        case 3:
            cout << "Erro de formato: '{}' erro de fechamento de chaves." << endl;
            break;
        case 4:
            cout << "Erro de formato: '(' não encontrado." << endl;
            break;
        case 5:
            cout << "Erro de formato: ',' não encontrado." << endl;
            break;
        case 6:
            cout << "Erro de formato: ')' não encontrado." << endl;
            break;
        case 7:
            cout << "Erro de abertura de arquivo: arquivo não encontrado." << endl;
            break;
    }

    exit(code);
}


void welcomeMessage() {
    
    cout << endl 
         << "-----------------------------------" << endl
         << "-----------------------------------" << endl 
         << "----- Mealy Machine Simulator -----" << endl
         << "-----------------------------------" << endl
         << "----------------------- Since 2020." << endl << endl;

}

// função que imprime na saída padrão um alfabeto
// parâmetros: O alfabeto inicializado pelo arquivo
void printAlphabet(AlphabetStructure alphabet) {

    cout << alphabet.alphabet[0];

    for(int i = 1; i < alphabet.alphabetSize; i++) {
        cout << ", " << alphabet.alphabet[i];
    }
}

// função que imprime na saída padrão um alfabeto
// parâmetros: O alfabeto inicializado pelo arquivo
void printInputAlphabet(AlphabetStructure inputAlphabet) {
    
    cout << " -> alfabeto_entrada = { ";
    
    printAlphabet(inputAlphabet);
    
    cout << " }" << endl;
}

// função que imprime na saída padrão um alfabeto
// parâmetros: O alfabeto inicializado pelo arquivo
void printOutputAlphabet(AlphabetStructure outputAlphabet) {
    
    cout << " -> alfabeto_saída = { ";
    
    printAlphabet(outputAlphabet);
    
    cout << " }" << endl;
}

// função que imprime na saída padrão os estados de um autômato
void printStates(StatesStructure states) {
    
    cout << " -> estados = { ";

    cout << states.states[0].stateName;

    for(int i = 1; i < states.numberOfStates; i++) {
        cout << ", " << states.states[i].stateName;
    }

    cout << " }" << endl;
}

// função que imprime na saída padrão o estado inicial de um autômato
void printInitState(string initState) {
    
    cout << " -> inicial = " << initState << endl;

}

// função que imprime na saída padrão os estados finais de um autômato
void printEndStates(EndStatesStructure endStates) {
    
    cout << " -> finais = { ";

    cout << endStates.states[0];

    for(int i = 1; i < endStates.numberOfEndStates; i++) {
        cout << ", " << endStates.states[i];
    }

    cout << " }" << endl;
}

// função que imprime na saída padrão o conjunto de transições de um dado estado
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

// função que imprime na saída padrão todas as transições
void printTransitions(StatesStructure states) {
    
    cout << " -> transição:" << endl;

    for(int i = 0; i < states.numberOfStates; i++) {
        printStateTransitions(states.states[i]);
    }
}

// função que imprime na saída padrão o autômato carregado a partir do arquivo inicial
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

// função que imprime na saída padrão erro em caso da palavra de entrada conter carácteres inválido para o autômato
void printWordInvalidMessage() {
    
    cout << "Palavra inválida: existem caráteres que não pertencem ao alfabeto inicial do autômato." << endl << endl;

}

// função que imprime o número de espaços em brancos necessários para completar a linha
void printBlankSpaces(int n) {
   
    for (int i = 0; i < n; i++) {
        cout << ' ';
    }
}

// função que imprime na saída padrão o inicio do ciclo de transição 
void printInitTransitionMessage(string stateName, string enterWord) {
   
    cout << endl << "[" << stateName << "]" << enterWord << endl;

}

// função que imprime na saída padrão o resultado de uma transição efetuada pelo autômato
void printTransitionMessage(string stateName, string word, string outputCharacters, int step) {

    cout << "[" << stateName << "]" << word;
        
    printBlankSpaces(MIN_BLANK_SPACES + step);
        
    cout << "saída: " << outputCharacters << endl;
}

// função que imprime na saída padrão a mensagem que declara que a palavra é inválida
void printValidWord() {

    cout << "ACEITA" << endl;

}

// função que imprime na saída padrão a mensagem que declara que a palavra não é inválida
void printInvalidWord() {

    cout << "REJEITA" << endl;

}

// função que imprime na saída a palavra obtida no final do processo do autômato
void printEndWordMessage(string word) {

    cout << "Palavra de saída: " 
         << word << endl << endl;

}

// função que imprime a mensagem de fechamento do programa
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

void EnterWordMensage() {
	cout << "Por favor insira uma palavra válida, ou [exit] para sair\n";
}
