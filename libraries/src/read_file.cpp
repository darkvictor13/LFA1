// este segmento de código á responsável por definir todas as funções encarregadas de ler o arquivo de entrada

#include "../includes/read_file.hpp"

// função para retirar os espaços vazios de uma string, linha
string removeStringSpaces(string line) {

    string newLine = "";

    for (int i = 0; i < (int)line.size(); i++) {
        if (line[i] != ' ') {
            newLine += line[i];
        }
    }
    
    return newLine;
}

// função que pergunta ao usuário o nome do arquivo
string findNameFile () {

    string fileName;

    cout << "Você não informou o nome do arquivo contendo os dados\n";
    cout << "Por favor insira o nome arquivo -> ";
    
    cin >> fileName;

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    if ( (int)fileName.find('.') == - 1 ) {
        
        string aux = "";

        cout << "O arquivo possui extensão? [y/n] -> ";

        cin >> aux;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        if( aux[0] == 'Y' || aux[0] == 'y' ) {  

            cout << "Entre a extensão do arquivo -> ";

            cin >> aux;

            if (aux[0] != '.') {
                fileName += '.';
            }

            fileName += aux;
        }
    }

    return fileName;
}

// função que realiza a leitura do alfabeto de entrada a partir do arquivo entrada
AlphabetStructure readInputAlphabet(string line) {
    
    AlphabetStructure alphabet;

    line = removeStringSpaces(line);

    if( "alfabeto_entrada" != line.substr(0, 16) ) {
        errorMessagesCode( 1, line.substr(0, 16));
    }
    
    if( '=' != line[16] ) {
        errorMessagesCode( 2, "");
    }
    
    if( '{' != line[17] || ( line.find("}") != ( line.size() - 1 ) ) ) {
        errorMessagesCode( 3, "");
    }
    
    alphabet.alphabet = "";
    alphabet.alphabetSize = 0;

    for(int i = 18, j = line.size() - 1; i < j; i++) {
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

    if( "alfabeto_saída" != line.substr(0, 14)  && "alfabeto_saida" != line.substr(0, 14)) {
        errorMessagesCode( 1, line.substr(0, 14));
    }
    
    if( '=' != line[14] ) {
        errorMessagesCode( 2, "");
    }
    
    if( '{' != line[15] || ( line.find("}") != ( line.size() - 1 ) ) ) {
        errorMessagesCode( 3, "");
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
        errorMessagesCode( 1, line.substr(0, 7));
    }
    
    if( '=' != line[7] ) {
        errorMessagesCode( 2, "");
    }
    
    if( '{' != line[8] || ( line.find("}") != ( line.size() - 1 ) ) ) {
        errorMessagesCode( 3, "");
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
        errorMessagesCode( 1, line.substr(0, 7) );
    }
    
    if( '=' != line[7] ) {
        errorMessagesCode( 2, "");
    }

    initState = line.substr(8, line.size());

    return initState;
}

// função que realiza a leitura estado final a partir do arquivo de entrada
EndStatesStructure readEndStates(string line) {
    
    EndStatesStructure endStates;

    line = removeStringSpaces(line);

    if( "finais" != line.substr(0, 6) ) {
        errorMessagesCode( 1, line.substr(0, 6) );
    }
    
    if( '=' != line[6] ) {
        errorMessagesCode( 2, "");
    }
    
    if( '{' != line[7] || ( line.find("}") != ( line.size() - 1 ) ) ) {
        errorMessagesCode( 3, "");
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
    char verifyChar;
    
    if( '(' != line[position++] ) {
        errorMessagesCode( 4, "");
    }

    while( line[position] != ',' ) {
        verifyChar = line[position];
        
        if( '(' == verifyChar || '=' == verifyChar || ')' == verifyChar ) {
            errorMessagesCode( 5, "");
        }

        position++;
    }

    position++;

    while( line[position] != ')' ) {
        verifyChar = line[position];
        
        if( '(' == verifyChar || '=' == verifyChar || ',' == verifyChar ) {
            errorMessagesCode( 6, "");
        }

        position++;
    }

    if( '=' != line[++position] ) {
        errorMessagesCode( 2, "");
    }

    position++;

    if( '(' != line[position++] ) {
        errorMessagesCode( 4, "");
    }

    while( line[position] != ',' ) {
        verifyChar = line[position];
        
        if( '(' == verifyChar || '=' == verifyChar || ')' == verifyChar ) {
            errorMessagesCode( 5, "");
        }

        position++;
    }

    position++;

    while( line[position] != ')' ) {
        verifyChar = line[position];
        
        if( '(' == verifyChar || '=' == verifyChar || ',' == verifyChar ) {
            errorMessagesCode( 6, "");
        }

        position++;
    }

    position++;

    if( '\n' != line[position] && '\0' != line[position] ) {
        errorMessagesCode( 1, line.substr(position, stringLengh) );
    }
}

// função que a partir da linha do arquivo que declara uma transição retorna a posição do estado inicial
int selectState(StatesStructure states, string stateName) {
    
    for (int thisState = 0; thisState < states.numberOfStates; thisState++) {   
        if( states.states[thisState].stateName == stateName ) {
            return thisState;
        }
    }

    return -1;
}

// função que a partir de um carácter de entrada retorna a posição da transição correspondente dentro do estado
int selectTransition(StateStructure state, char inputLetter) {
    
    for (int thisTransition = 0; thisTransition < state.numberOfTransitions; thisTransition++) {
        if( state.transitions[thisTransition].inputCharacter == inputLetter ) {
            return thisTransition;
        }
    }
    
    return -1;
}

// função que realiza a leitura de uma transição a partir do arquivo de entrada
TransitionStructure readTransition(string line) {
    
    TransitionStructure transition;
    int position;
    int endPosition;

    position = line.find(',') + 1;
    
    transition.inputCharacter = line[position];

    position += 4;

    endPosition = line.substr(position).find(',');

    transition.endTransition = line.substr(position, endPosition);

    position += endPosition + 1;

    endPosition = line.substr(position).find(')');

    transition.outputCharacters = line.substr(position, endPosition);

    return transition;
}

// função que realiza a leitura de um conjunto de transições a partir do arquivo de entrada
StatesStructure readTransitions(StatesStructure states, ifstream* inputFile) {
    
    string line;
    string stateName;
    int stateNumber;
    int position;

    while( !( (*inputFile).eof() ) ) {

        getline(*inputFile, line);

        line = removeStringSpaces(line);

        verifyTransitionLine(line);

        for( position = 1; line[position] != ','; position++);

        stateName = line.substr(1, position - 1);

        stateNumber = selectState(states, stateName);

        states.states[stateNumber].transitions[states.states[stateNumber].numberOfTransitions++] = readTransition(line);
    }

    return states;
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

    automaton.states = readTransitions(automaton.states, inputFile);

    return automaton;
}

// função que realiza o manejo do arquivo de entrada
AutomatonStructure readInputFile(string fileName) {
    
    AutomatonStructure automaton;
    ifstream inputFile;

    inputFile.open(fileName);

    if( !inputFile.is_open() ) {
        errorMessagesCode( 7, "");
    }

    automaton = readAutomaton(&inputFile);
    
    inputFile.close();

    return automaton;
}
