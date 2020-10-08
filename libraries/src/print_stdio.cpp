/* 
   este arquivo é responsável por definir todas as funções encarregadas de imprimir na saida padrão
*/

#include "../includes/print_stdio.hpp"

// Imprime as mensagens que encerram o arquivo
// parâmetro (int) code - Código do erro
// parâmetro (string) message - Mensagem de identificação do erro
// return - Não tem
void errorMessagesCode(int code, string message) {

    switch(code) {
        case 0:
            cout << "Voce esta usando o programa de forma errada!\n"
                 << "Por favor rode:\n"
                 << "[nome do programa] [nome do arquivo com os dados]\n";
            break;
        case 1:
            cout << "Erro de formato: " << message << " nao identificado." << endl;
            break;
        case 2:
            cout << "Erro de formato: '=' separador nao identificado." << endl;
            break;
        case 3:
            cout << "Erro de formato: '{}' erro de fechamento de chaves." << endl;
            break;
        case 4:
            cout << "Erro de formato: '(' nao encontrado." << endl;
            break;
        case 5:
            cout << "Erro de formato: ',' nao encontrado." << endl;
            break;
        case 6:
            cout << "Erro de formato: ')' nao encontrado." << endl;
            break;
        case 7:
            cout << "Erro de abertura de arquivo: arquivo nao encontrado." << endl;
            break;
    }

    exit(code);
}

// função que escreve na saida padrão a mensagem de bem vindo ao programa
// parâmetro (void) - sem parâmetros
// return - Não tem
void welcomeMessage() {
    
    cout << endl 
         << "-----------------------------------" << endl
         << "-----------------------------------" << endl 
         << "----- Mealy Machine Simulator -----" << endl
         << "-----------------------------------" << endl
         << "----------------------- Since 2020." << endl << endl;

}

// função que imprime na saida padrão um alfabeto
// parâmetro (alphabetStructure) alphabet - Alfabeto inicializado pelo arquivo
// pré-condição: Estrutura previamente inicializada
// return - Não tem
void printAlphabet(AlphabetStructure alphabet) {

    cout << alphabet.alphabet[0];

    for(int i = 1; i < alphabet.alphabetSize; i++) {
        cout << ", " << alphabet.alphabet[i];
    }
}

// função que imprime na saida padrão um alfabeto
// parâmetro (alphabetStructure) inputAlphabet - Alfabeto de entrada inicializado pelo arquivo
// pré-condição: Estrutura previamente inicializada
// return - Não tem
void printInputAlphabet(AlphabetStructure inputAlphabet) {

    cout << " -> alfabeto_entrada = { ";

    printAlphabet(inputAlphabet);

    cout << " }" << endl;
}

// função que imprime na saida padrão um alfabeto
// parâmetro (alphabetStructure) outputAlphabet - Alfabeto de saida inicializado pelo arquivo
// pré-condição: Estrutura previamente inicializada
// return - Não tem
void printOutputAlphabet(AlphabetStructure outputAlphabet) {

    cout << " -> alfabeto_saida = { ";

    printAlphabet(outputAlphabet);

    cout << " }" << endl;
}

// função que imprime na saida padrão os estados de um autômato
// parâmetro (StatesStructure) states - Estados inicializados pelo arquivo
// pré-condição: Estrutura previamente inicializada
// return - Não tem
void printStates(StatesStructure states) {

    cout << " -> estados = { ";

    cout << states.states[0].stateName;

    for(int i = 1; i < states.numberOfStates; i++) {
        cout << ", " << states.states[i].stateName;
    }

    cout << " }" << endl;
}

// função que imprime na saida padrão o estado inicial de um autômato
// parâmetro (string) initStates - Estado inicial inicializado pelo arquivo
// pré-condição: Estrutura previamente inicializada
// return - Não tem
void printInitState(string initState) {

    cout << " -> inicial = " << initState << endl;

}

// função que imprime na saida padrão os estados finais de um autômato
// parâmetro (EndStatesStructure) endStates - Estados finais inicializados pelo arquivo
// pré-condição: Estrutura previamente inicializada
// return - Não tem
void printEndStates(EndStatesStructure endStates) {

    cout << " -> finais = { ";

    cout << endStates.states[0];

    for(int i = 1; i < endStates.numberOfEndStates; i++) {
        cout << ", " << endStates.states[i];
    }

    cout << " }" << endl;
}

// função que imprime na saida padrão o conjunto de transições de um dado estado
// parâmetro (StateStructure) state - Estado inicializado pelo arquivo
// pré-condição: Estrutura previamente inicializada
// return - Não tem
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

// função que imprime na saida padrão todas as transições
// parâmetro (StatesStructure) states - Estados inicializados pelo arquivo
// pré-condição: Estrutura previamente inicializada
// return - Não tem
void printTransitions(StatesStructure states) {

    cout << " -> transicao:" << endl;

    for(int i = 0; i < states.numberOfStates; i++) {
        printStateTransitions(states.states[i]);
    }
}

// função que imprime na saida padrão o autômato carregado a partir do arquivo inicial
// parâmetro (AutomatonStructure) automaton - Estrutura do autômato inicializada pelo arquivo
// pré-condição: Estrutura previamente inicializada
// return - Não tem
void printAutomaton(AutomatonStructure automaton) {

    cout << "--------------------" << endl
         << "------------------------------" << endl
         << "Automato:" << endl;

    printInputAlphabet(automaton.inputAlphabet);

    printOutputAlphabet(automaton.outputAlphabet);

    printStates(automaton.states);

    printInitState(automaton.initState);

    printEndStates(automaton.endStates);

    printTransitions(automaton.states);

    cout << "------------------------------" << endl
         << "--------------------" << endl << endl;

}

// função que imprime na saida padrão mensagem de erro em caso da palavra de entrada conter carácteres inválidos para o autômato
// parâmetro (void) - sem parâmetros
// return - Não tem
void printWordInvalidMessage() {
    
    cout << "Palavra invalida: existem caracteres que nao pertencem ao alfabeto inicial do automato." << endl << endl;

}

// função que imprime o número de espaços em brancos necessários para completar a linha
// parâmetro (int) n - Número de espaços em branco
// return - Não tem
void printBlankSpaces(int n) {
   
    for (int i = 0; i < n; i++) {
        cout << ' ';
    }
}

// função que imprime na saida padrão o inicio do ciclo de transição
// parâmetro (string) stateName - Nome do Estado atual
// parâmetro (string) enterWord - Palavra inicial
// return - Não tem
void printInitTransitionMessage(string stateName, string enterWord) {

    cout << endl << "[" << stateName << "]" << enterWord << endl;

}

// função que imprime na saida padrão o resultado de uma transição efetuada pelo autômato
// parâmetro (string) stateName - Nome do Estado atual
// parâmetro (string) word - Palavra no estado atual
// parâmetro (string) outputCharacters - Letra de saida no estado atual
// parâmetro (int) step - Passo atual
// return - Não tem
void printTransitionMessage(string stateName, string word, string outputCharacters, int step) {

    cout << "[" << stateName << "]" << word;
        
    printBlankSpaces(MIN_BLANK_SPACES + step);
        
    cout << "saida: " << outputCharacters << endl;
}

// função que imprime na saida padrão a mensagem que declara que a palavra é inválida
// parâmetro (void) - sem parâmetros
// return - Não tem
void printValidWord() {

    cout << "ACEITA" << endl;

}

// função que imprime na saida padrão a mensagem que declara que a palavra não é inválida
// parâmetro (void) - sem parâmetros
// return - Não tem
void printInvalidWord() {

    cout << "REJEITA" << endl;

}

// função que imprime na saida a palavra obtida no final do processo do autômato
// parâmetro (string) word - Palavra de saida
// return - Não tem
void printEndWordMessage(string word) {

    cout << "Palavra de saida: " 
         << word << endl << endl;

}

// função que imprime a mensagem de fechamento do programa
// parâmetro (void) - sem parâmetros
// return - Não tem
void printEndProgramMessage() {

    cout << endl 
         << "-----------------------------------" << endl 
         << "--------------- FIM ---------------" << endl
         << "-----------------------------------" << endl << endl;

}

// função que imprime mensagem pedindo a confirmação do usuário para encerrar o programa
// parâmetro (void) - sem parâmetros
// return - Não tem
void printExitConfirmationMessage() {

    cout << "Deseja finalizar o programa? [y/n] -> ";

}

// função que imprime na tela mensagem sobre como entrar com a palavra
// parâmetro (void) - sem parâmetros
// return - Não tem
void EnterWordMensage() {
	
    cout << "Por favor insira uma palavra valida, ou [exit] para sair\n";

}
