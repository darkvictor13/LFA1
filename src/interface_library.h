// este arquivo é responsável por definir todas as funções encarregadas de se comunicar com os dispositivos de entrada é saída

// importando bibliotecas
#include "structure_library.h"

// função para retirar os espaços vacios de uma string, linha
string clearBlank(string line) {

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
    // quando a string é vazia buga o negócio
    if (argumentsCounter <= 0 || 3 <= argumentsCounter) {
        cout << "Você está usando o programa de forma errada!\n";
        cout << "Por favor rode:\n";
        cout << "[Nome do programa] [espaço em branco] [nome do arquivo com os dados]\n";
        exit(EXIT_FAILURE);
    }
    if (argumentsCounter == 1) {
        // fileName precisaria estar inicializada, porém não está
        cout << "Você não nos informou o nome do arquivo com os dados\n";
        cout << "Por favor insira o nome aqui -> ";
        cin >> fileName;
        if (!fileName.find(".")) {
            string aux;
            cout << "Qual a extensão desse aquivo que você me passou?\n"; 
            cout << "Ele é um txt? Um log? Ou o que?\n";
            cout << "Entre com a extensão do arquivo -> ";
            cin >> aux;

            if (aux[0] != '.') {
                fileName += '.';
            }
            fileName += aux;
        }
    }else {
        char test;
        cout << "Nome do arquivo: " << fileName << endl;
        cout << "Você tem certeza que esse arquivo existe? [s/n]\n";
        cin >> test;
        if (test == 'N' || test == 'n') {
            cout << "Então nos informe o nome correto\n->";
            cin >> fileName;
        }
        while(test != 's' && test != 'S') {
            cout << "carácter inválido, tente novamente\n" << "->";
            cin >> test;

            if (test == 'N' || test == 'n') {
                cout << "Então nos informe o nome correto\n->";
                cin >> fileName;
            }
        }
    }
    return fileName;
}

// função que realiza a leitura do alfabeto de entrada a partir do arquivo entrada
AlphabetStructure readInputAlphabet(string line) {
    AlphabetStructure alphabet;

    if( "alfabeto_entrada" != line.substr(0, 15) ) {
        cout << "Erro de formato: " << line.substr(0, 15) << " não identificado." << endl;
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

    if( "alfabeto_saida" != line.substr(0, 13) ) {
        cout << "Erro de formato: " << line.substr(0, 13) << " não identificado." << endl;
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

    return states;
}

// função que realiza a leitura estado inicial a partir do arquivo de entrada
string readInitState(string line) {
    string initState;

    return initState;
}

// função que realiza a leitura estado final a partir do arquivo de entrada
EndStatesStructure readEndStates(string line) {
    EndStatesStructure endStates;

    return endStates;
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

// função que realiza a leitura do arquivo de entrada
AutomatonStructure readInputFile() {
    AutomatonStructure automaton;
    ifstream inputFile;

    inputFile.open( verifySelectFile("init_file_t1", 0) );

    automaton = readAutomaton(&inputFile);
    
    inputFile.close();

    return automaton;
}

// função que realiza a leitura de uma palavra a ser testada no autômato a partir da entrada estandar
string readWord() {

}

// função que imprime na saída estandar o resultado de uma transição efetuada pelo autômato
void printTransitionMessage() {

}


// função que imprime a mensagem final de cada palavra lida, validando-a ou não
void printEndMessage() {

}
