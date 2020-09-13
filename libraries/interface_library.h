// este arquivo á responsáel por definir todas as funções encarregadas de se comunicar com os dispositivos de entrada é saída

// importando bibliotecas
#include "structure_library.h"

// função para retirar os espaços vacios de uma string, linha
string removeStringSpaces(string line) {

    string newLine = "";
    for (int i = 0; i < (int)line.size(); i++) {
        if (line[i] != ' ') {
            newLine += line[i];
        }
    }
    
    return newLine;
}

// função que verifica o arquivo selecionado pelo usuário
string verifySelectFile(string fileName, int argumentsCounter) {
    
    // verificar o arquivinho selecionado
    
    return fileName;
}

// função que realiza a leitura do alfabeto de entrada a partir do arquivo entrada
AlphabetStructure readInputAlphabet(string line) {
    AlphabetStructure alphabet;

    line = removeStringSpaces(line);

    if( "alfabeto_entrada" != line.substr(0, 16) ) {
        cout << "Erro de formato: " << line.substr(0, 16) << " não identificado." << endl;
        exit(EXIT_FAILURE);
    }
    
    if( '=' != line[16] ) {
        cout << "Erro de formato: '=' separador não identificado." << endl;
        exit(EXIT_FAILURE);
    }
    
    if( '{' != line[17] && line.find("}") ) {
        cout << "Erro de formato: '{}' faltam chaves." << endl;
        exit(EXIT_FAILURE);
    }
    
    alphabet.alphabet = "";
    alphabet.alphabetSize = 0;

    for(int i = 18; line[i] != '}'; i++) {
        if(line[i] != ',') {
            alphabet.alphabet += line[i];
            alphabet.alphabetSize++;
        }
    }

    return alphabet;
}

// função que realiza a leitura do alfabeto de saída a partir do arquivo entrada
AlphabetStructure readOutputAlphabet(string line) {
    AlphabetStructure alphabet;

    line = removeStringSpaces(line);

    if( "alfabeto_saida" != line.substr(0, 14) ) {
        cout << "Erro de formato: " << line.substr(0, 14) << " não identificado." << endl;
        exit(EXIT_FAILURE);
    }
    
    if( '=' != line[14] ) {
        cout << "Erro de formato: '=' separador não identificado." << endl;
        exit(EXIT_FAILURE);
    }
    
    if( '{' != line[15] && line.find("}") ) {
        cout << "Erro de formato: '{}' faltam chaves." << endl;
        exit(EXIT_FAILURE);
    }
    
    alphabet.alphabet = "";
    alphabet.alphabetSize = 0;

    for(int i = 16; line[i] != '}'; i++) {
        if(line[i] != ',') {
            alphabet.alphabet += line[i];
            alphabet.alphabetSize++;
        }
    }

    return alphabet;
}

// função que realiza a leitura dos estados possíveis a partir do arquivo entrada
StatesStructure readStates(string line) {
    StatesStructure states;

    line = removeStringSpaces(line);

    if( "estados" != line.substr(0, 7) ) {
        cout << "Erro de formato: " << line.substr(0, 7) << " não identificado." << endl;
        exit(EXIT_FAILURE);
    }
    
    if( '=' != line[7] ) {
        cout << "Erro de formato: '=' separador não identificado." << endl;
        exit(EXIT_FAILURE);
    }
    
    if( '{' != line[8] && line.find("}") ) {
        cout << "Erro de formato: '{}' faltam chaves." << endl;
        exit(EXIT_FAILURE);
    }

    states.numberOfStates = 0;

    for(int i = 9, j = 0; line[i] != '}'; i++) {

        states.numberOfStates = j + 1;

        if(line[i] != ',') {
            states.states[j].stateName += line[i];
        }else{
            j++;
        }
    }

    return states;
}

// função que realiza a leitura estado inicial a partir do arquivo de entrada
string readInitState(string line) {
    string initState;

    line = removeStringSpaces(line);

    if( "inicial" != line.substr(0, 7) ) {
        cout << "Erro de formato: " << line.substr(0, 7) << " não identificado." << endl;
        exit(EXIT_FAILURE);
    }
    
    if( '=' != line[7] ) {
        cout << "Erro de formato: '=' separador não identificado." << endl;
        exit(EXIT_FAILURE);
    }

    initState = line.substr(8, line.size());

    return initState;
}

// função que realiza a leitura estado final a partir do arquivo de entrada
EndStatesStructure readEndStates(string line) {
    EndStatesStructure endStates;

    line = removeStringSpaces(line);

    if( "finais" != line.substr(0, 6) ) {
        cout << "Erro de formato: " << line.substr(0, 6) << " não identificado." << endl;
        exit(EXIT_FAILURE);
    }
    
    if( '=' != line[6] ) {
        cout << "Erro de formato: '=' separador não identificado." << endl;
        exit(EXIT_FAILURE);
    }
    
    if( '{' != line[7] && line.find("}") ) {
        cout << "Erro de formato: '{}' faltam chaves." << endl;
        exit(EXIT_FAILURE);
    }

    endStates.numberOfEndStates = 0;

    for(int i = 8, j = 0; line[i] != '}'; i++) {

        endStates.numberOfEndStates = j + 1;

        if(line[i] != ',') {
            endStates.states[j] += line[i];
        }else{
            j++;
        }
    }

    return endStates;
}

// função que verifica se uma linha de transição esta formatada da forma correta
void verifyTransitionLine(string line) {
    int position = 0;
    int stringLengh = line.size();
    
    if( '(' != line[position++] ) {
        cout << "Erro de formato: '(' não encontrado." << endl;
        exit(EXIT_FAILURE);
    }
    
    for(; position < stringLengh && line[position] != ',' && line[position] != '='; position++);

    if( position == stringLengh ) {
        cout << "Erro de formato: ',' não encontrado." << endl;
        exit(EXIT_FAILURE);
    }

    position++;

    for(; position < stringLengh && line[position] != ')'; position++);

    if( position == stringLengh ) {
        cout << "Erro de formato: ')' não encontrado." << endl;
        exit(EXIT_FAILURE);
    }

    position++;

    if( '=' != line[position++] ) {
        cout << "Erro de formato: '=' não encontrado." << endl;
        exit(EXIT_FAILURE);
    }

    if( '(' != line[position++] ) {
        cout << "Erro de formato: '(' não encontrado." << endl;
        exit(EXIT_FAILURE);
    }
    for(; position < stringLengh && line[position] != ','; position++);

    if( position == stringLengh ) {
        cout << "Erro de formato: ',' não encontrado." << endl;
        exit(EXIT_FAILURE);
    }

    position++;

    for(; position < stringLengh && line[position] != ')'; position++);

    if( position == stringLengh ) {
        cout << "Erro de formato: ')' não encontrado." << endl;
        exit(EXIT_FAILURE);
    }

    cout << line << endl;
}

// função que realiza a leitura de uma transição a partir do arquivo de entrada
TransitionStructure readTransition(string line) {
    TransitionStructure transition;

    return transition;
}

// função que realiza a leitura de um conjunto de transições a partir do arquivo de entrada
AutomatonStructure readTransitions(AutomatonStructure automaton, ifstream* inputFile) {
    string line;

    while( !( (*inputFile).eof() ) ) {

        getline(*inputFile, line);

        line = removeStringSpaces(line);
        verifyTransitionLine(line);

        // escolher o estado e enfiar a transição no estado
        //readTransition(line);
    }

    return automaton;
}

// função que realiza a leitura do arquivo de entrada
AutomatonStructure readAutomaton(ifstream* inputFile) {
    AutomatonStructure automaton;
    string line;
    
    getline(*inputFile, line);
    automaton.inputAlphabet = readInputAlphabet(line);

    getline(*inputFile, line);
    automaton.outputAlphabet = readOutputAlphabet(line);

    getline(*inputFile, line);
    automaton.states = readStates(line);

    getline(*inputFile, line);
    automaton.initState = readInitState(line);

    getline(*inputFile, line);
    automaton.endStates = readEndStates(line);

    return readTransitions(automaton, inputFile);
}

// função que realiza o manejo do arquivo de entrada
AutomatonStructure readInputFile() {
    AutomatonStructure automaton;
    ifstream inputFile;

    inputFile.open( verifySelectFile("init_file_t2", 0) );

    automaton = readAutomaton(&inputFile);
    
    inputFile.close();

    return automaton;
}

// função que realiza a leitura de uma palavra a ser testada no autômato a partir da entrada estandar
string readWord() {
    string word;

    cin >> word;

    return word;
}

// função qeu imprime na saída estandor uma mensagem de biembenida para o usuário 
void welcomeMessage() {
    cout << "Mealy Machine Simulator" << endl;
    cout << "Since 2020." << endl;
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
    cout << "alfabeto_entrada = { ";
    printAlphabet(inputAlphabet);
    cout << " }" << endl;
}

// função que imprime na saída estandar um alfabeto
void printOutputAlphabet(AlphabetStructure outputAlphabet) {
    cout << "alfabeto_saida = { ";
    printAlphabet(outputAlphabet);
    cout << " }" << endl;
}

// função que imprime na saída estandar os estados de um autômato
void printStates(StatesStructure states) {
    cout << "estados = { ";

    cout << states.states[0].stateName;

    for(int i = 1; i < states.numberOfStates; i++) {
        cout << ", " << states.states[i].stateName;
    }

    cout << " }" << endl;
}

// função que imprime na saída estandar o estado inicial de um autômato
void printInitState(string initState) {
    cout << "inicial = " << initState << endl;
}

// função que imprime na saída estandar os estados finais de um autômato
void printEndStates(EndStatesStructure endStates) {
    cout << "finais = { ";

    cout << endStates.states[0];

    for(int i = 1; i < endStates.numberOfEndStates; i++) {
        cout << ", " << endStates.states[i];
    }

    cout << " }" << endl;
}

// função que imprime na saída estandar uma transições
void printTransition() {

}

// função que imprime na saída estandar todas as transições
void printTransitions(StatesStructure states) {

}

// função que imprime na saída estandar o autômato carregado apartir do arquivo inicial
void printAutomaton(AutomatonStructure automaton) {

    cout << "Autômato:" << endl;

    printInputAlphabet(automaton.inputAlphabet);

    printOutputAlphabet(automaton.inputAlphabet);

    printStates(automaton.states);

    printInitState(automaton.initState);

    printEndStates(automaton.endStates);

    printTransitions(automaton.states);

}

// função que imprime na saída estandar o resultado de uma transição efetuada pelo autômato
void printTransitionMessage() {

}

// função que imprime a mensagem final de cada palavra lida, validando-a ou não
void printEndMessage() {

}
