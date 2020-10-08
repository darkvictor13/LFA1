#include"../includes/read_stdio.hpp"

/*
		este arquivo é responsável por definir todas as funções encarregadas de ler na saída padrão
*/

/*
		função que realiza a leitura de uma palavra a ser testada no autômato a partir da entrada padrão
		parâmetro (void) - sem parâmetros
		return (string) - string lida do teclado
*/
string readWord() {

    string word = "";

    cin >> word;

    return word;
}


/*
		função que realiza a leitura da palavra que confirma a saída do programa
		parâmetro (void) - sem parâmetros
		return (bool) - verdadeiro caso o usuário queira encerrar o programa
					  - falso caso ele não deseje encerrar o programa
*/
bool readExitConfirmationMessage() {

    string line = "";

    cin >> line;

    line = removeStringSpaces(line);

    if ( line[0] == 'y' || line[0] == 'Y') {
        return false;
		}

    return true;
}
