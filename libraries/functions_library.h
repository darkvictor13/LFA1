// importando bibliotecas
#include "structures_library.h"

//
// segmento de código responsavél pela declaração dos erros
//

// função qeu imprime na saída estandor uma mensagem de biembenida para o usuário 
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

//
// este segmento de código á responsáel por definir todas as funções encarregadas de ler o arquivo de entrada
//

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

// função que pergunta ao usuário o nome do arquivo
string findNameFile () {

    string fileName;

    cout << "Você não informou o nome do arquivo contendo os dados\n";
    cout << "Por favor insira o nome arquivo -> ";
    
    cin >> fileName;

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    if ( fileName.find('.') == - 1 ) {
        
        string aux = "";

        cout << "O arquivo possui extenção? [Y/n] -> ";

        aux[0] = getchar();

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        if( aux[0] == '\n' || aux[0] == 'Y' || aux[0] == 'y' ) {  

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

    if( "alfabeto_saida" != line.substr(0, 14) ) {
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

// função que a partir de um carater de entrada retorna a posição da transição correspondente dentro do estado
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

//
// este segmento de código é responsáel por definir todas as funções encarregadas de imprimir na saída estandar
//

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
    
    cout << " -> transiçãoe:" << endl;

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
    
    cout << "Palavra inválida: existem carateres que não pertencem ao alfabeto inicial do autômato." << endl << endl;

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

//
// este segmento de código é responsáel por definir todas as funções encarregadas de ler na saída estandar
//

// função que realiza a leitura de uma palavra a ser testada no autômato a partir da entrada estandar
string readWord() {

    string word;

    cin >> word;

    return word;
}

bool readExitConfirmationMessage() {

    string line;
    bool boolean = 1;

    cin >> line;

    line = removeStringSpaces(line);

    if ( line == "y" || line == "Y" || line == "yes" || line == "YES" || line == "Yes" )
        boolean = 0;
    

    return boolean;
}

//
// este segmento de código contem as principais funções que simulam o ciclo de vida do autômato
//

// função que verifica se um determinado estado do autômato é válido
bool verifyValidState() {

    bool boolean = 1;

    return boolean;
}

// função que realiza uma dada transição do autômato definido no arquivo de entrada
AutomatonStatusStructure makeTransition(AutomatonStatusStructure runningAutomaton, AutomatonStructure automaton) {
    
    runningAutomaton.transitionNumber = selectTransition(runningAutomaton.thisState, runningAutomaton.word[0]);

    if(runningAutomaton.transitionNumber == - 1 ) {

        return runningAutomaton;
    }
    
    runningAutomaton.transition = automaton.states.states[runningAutomaton.stateNumber].transitions[runningAutomaton.transitionNumber];

    runningAutomaton.exitWord += runningAutomaton.transition.outputCharacters != "@" ? runningAutomaton.transition.outputCharacters : "";

    runningAutomaton.stateName = runningAutomaton.transition.endTransition;

    runningAutomaton.stateNumber = selectState(automaton.states, runningAutomaton.stateName);

    runningAutomaton.thisState = automaton.states.states[runningAutomaton.stateNumber];

    runningAutomaton.word = runningAutomaton.word.substr(1);

    runningAutomaton.step++;

    printTransitionMessage(runningAutomaton.stateName, runningAutomaton.word, runningAutomaton.transition.outputCharacters, runningAutomaton.step);

    if( runningAutomaton.word.size() == 0 || runningAutomaton.transitionNumber < 0 || !verifyValidState() ) {
        return runningAutomaton;
    }
    
    return makeTransition(runningAutomaton, automaton);
}

// função que realiza uma verificação previa da palavra entrada pelo usuário
bool preVerifyWord(string word) {

    bool boolean = 1;

    if( word == "exit" ) {

        printExitConfirmationMessage();

        boolean = readExitConfirmationMessage();

    }

    return boolean;
}

// função que verifica se a palavra entrada pelo usuário é composta pelo alfabeto de entrada
bool verifyWordIfInAlphabet(AlphabetStructure alphabet, string word) {

    for(int i = 0; i < word.size(); i++) {
        if( alphabet.alphabet.find(word[i]) == -1 ) {    
            return false;
        }
    }

    return true;    
}

// função que verifica se a palavra entrada pelo usuário é válida para o autômato carregado
void runAutomaton(AutomatonStatusStructure runningAutomaton, AutomatonStructure automaton) {

    printInitTransitionMessage(runningAutomaton.thisState.stateName, runningAutomaton.word);
    
    runningAutomaton = makeTransition(runningAutomaton, automaton);

    if( runningAutomaton.transitionNumber != - 1 ) {
        printValidWord();
    }else{
        printInvalidWord();
    }
    
    printEndWordMessage(runningAutomaton.exitWord);
   
}

// função que permite a entrada varias palavras pelo usuário
void enterWords(AutomatonStructure automaton) {
    
    string word;
    
    word = removeStringSpaces( readWord() );

    while( preVerifyWord(word) ) {
        
        if( verifyWordIfInAlphabet(automaton.inputAlphabet, word) ) {
            
            AutomatonStatusStructure runningAutomaton;

            runningAutomaton.word = word;
            runningAutomaton.stateNumber = selectState(automaton.states, automaton.initState);
            runningAutomaton.thisState = automaton.states.states[runningAutomaton.stateNumber];
            runningAutomaton.exitWord = "";
            runningAutomaton.step = 0;

            runAutomaton(runningAutomaton, automaton);

        }else{
            printWordInvalidMessage();
        }

        word = removeStringSpaces( readWord() );
    }   
}