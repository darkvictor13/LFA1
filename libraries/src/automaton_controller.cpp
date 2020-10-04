#include "../includes/automaton_controller.hpp"


bool verifyValidEndState(EndStatesStructure endStatesStructure, string endState) {
    
    for (int  i = 0; i < endStatesStructure.numberOfEndStates; i++) {
        if( endStatesStructure.states[i] == endState ) {
            return 1;
        }
    }

    return 0;
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

    if( runningAutomaton.word.size() == 0 || runningAutomaton.transitionNumber < 0 ) {
        return runningAutomaton;
    }
    
    return makeTransition(runningAutomaton, automaton);
}

// função que realiza uma verificação previa da palavra entrada pelo usuário
bool preVerifyWord(string word) {

    if( word == "exit" ) {

        printExitConfirmationMessage();

        return readExitConfirmationMessage();

    }

    return 1;
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

    if( runningAutomaton.transitionNumber != - 1 && verifyValidEndState(automaton.endStates, runningAutomaton.thisState.stateName ) ) {
        printValidWord();
    }else{
        printInvalidWord();
    }
    
    printEndWordMessage(runningAutomaton.exitWord);
   
}

// função que permite a entrada varias palavras pelo usuário
void enterWords(AutomatonStructure automaton) {
    
    string word;
    
		cout << "-> ";
    word = removeStringSpaces( readWord() );

    while( preVerifyWord(word) ) {

        /*if( word == "@" ) {
            if( verifyValidEndState(automaton.endStates, automaton.initState ) ) {
                printValidWord();
            }else{
                printInvalidWord();
            }
            word = removeStringSpaces( readWord() );
            continue;
        }*/
        
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

				cout << "-> ";
        word = removeStringSpaces( readWord() );
    }   
}
