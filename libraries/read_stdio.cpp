#include"read_stdio.h"

/*
   este arquivo é responsável por definir todas as funções encarregadas de ler na saída padrão
*/

// função que realiza a leitura de uma palavra a ser testada no autômato a partir da entrada padrão
string readWord() {

    string word;

    cin >> word;

    return word;
}

// função que realiza a leitura da palavra que confirma a saída do programa
bool readExitConfirmationMessage() {

    string line;
    bool boolean = 1;

    cin >> line;

    line = removeStringSpaces(line);

    if ( line == "y" || line == "Y" || line == "yes" || line == "YES" || line == "Yes" )
        boolean = 0;
    

    return boolean;
}
