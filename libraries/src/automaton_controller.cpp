#include "../includes/automaton_controller.hpp"

/*
    função que verifica se um determinado estado é estado final do autômato
    parâmetro (EndStatesStructure) - estrutura contendo todos os estados finais do autômato
    parâmetro (string) - cadeia de caracteres contendo o nome do estado atual 
	return (AlphabetStructure) - valor booleano indicando se o estado atual é ou não um estado final
*/
bool verifyValidEndState(EndStatesStructure endStatesStructure, string endState) {
    
    for (int  i = 0; i < endStatesStructure.numberOfEndStates; i++) {
        if( endStatesStructure.states[i] == endState ) {
            return 1;
        }
    }

    return 0;
}

/*
    função que realiza uma dada transição do autômato definido no arquivo de entrada
    parâmetro (AutomatonStatusStructure) - estrutura contendo todos os dados que definen em que momento da execução se encontra o autômato
    parâmetro (AutomatonStructure) - estrutura contendo todos os dados do autômato
	return (AutomatonStatusStructure) - estrutura contendo todos os dados que definen do autômato que definem como ele se enconra após a execução da transição
*/
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

    if( runningAutomaton.word.size() == 0 || runningAutomaton.transitionNumber < 0 ) {
        return runningAutomaton;
    }
    
    return makeTransition(runningAutomaton, automaton);
}

/*
    função que realiza uma verificação previa da palavra entrada pelo usuário
    parâmetro (string) - contendo a palavra entrada pelo usuário 
	return (bool) - valor booleano que indica se a palavra entrada corresponde ou não com a instrução de saída
*/
bool preVerifyWord(string word) {

    if( word == "exit" ) {

        printExitConfirmationMessage();

        return readExitConfirmationMessage();

    }

    return 1;
}

/*
    função que verifica se a palavra entrada pelo usuário é composta pelo alfabeto de entrada
    parâmetro (AlphabetStructure) - estrutura de um dos alfabetos do autômato
    parâmetro (string) - cadeia de caracteres que representa a entrada completa do usuário a ser colocado no autômato
	return (bool) - valor booleano indicando se a palavra de entrada contem ou não carateres inválidos
*/
bool verifyWordIfInAlphabet(AlphabetStructure alphabet, string word) {

    for(int i = 0; i < word.size(); i++) {
        if( alphabet.alphabet.find(word[i]) == -1 ) {    
            return false;
        }
    }

    return true;    
}

/*
    função que verifica se a palavra entrada pelo usuário é válida para o autômato carregado
    parâmetro (AutomatonStatusStructure) - estrutura contendo todos os dados que definen em que momento da execução se encontra o autômato
    parâmetro (AutomatonStructure) - estrutura contendo todos os dados do autômato
	return (void)
*/
void runAutomaton(AutomatonStatusStructure runningAutomaton, AutomatonStructure automaton) {

    printInitTransitionMessage(runningAutomaton.thisState.stateName, runningAutomaton.word);
    
    runningAutomaton = makeTransition(runningAutomaton, automaton);

    if( runningAutomaton.transitionNumber != - 1 && verifyValidEndState(automaton.endStates, runningAutomaton.thisState.stateName ) ) {
        printValidWord();
    }else{
        printInvalidWord();
    }
    
    printEndWordMessage(runningAutomaton.exitWord);
   
}

/*
    função que permite a entrada varias palavras pelo usuário
    parâmetro (AutomatonStructure) - estrutura contendo todos os dados do autômato
	return (void)
*/
void enterWords(AutomatonStructure automaton) {
    
    string word = "";
    
	cout << "-> ";
    word = removeStringSpaces( readWord() );

    while( preVerifyWord(word) ) {
        
        if( verifyWordIfInAlphabet(automaton.inputAlphabet, word) ) {
            
            AutomatonStatusStructure runningAutomaton = initializeAutomatonController();

            runningAutomaton.word = word;
            runningAutomaton.stateNumber = selectState(automaton.states, automaton.initState);
            runningAutomaton.thisState = automaton.states.states[runningAutomaton.stateNumber];
            runningAutomaton.exitWord = "";
            runningAutomaton.step = 0;

            runAutomaton(runningAutomaton, automaton);

        }else{
            printWordInvalidMessage();
        }

				cout << "-> ";
        word = removeStringSpaces( readWord() );
    }   
}
