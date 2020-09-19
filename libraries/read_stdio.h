#ifndef READ_STDIO
#define READ_STDIO

#include "structures_library.h"

/*
   este arquivo é responsável por definir todas as funções encarregadas de ler na saída padrão
*/

// função que realiza a leitura de uma palavra a ser testada no autômato a partir da entrada padrão
string readWord();

// função que realiza a leitura da palavra que confirma a saída do programa
bool readExitConfirmationMessage();

#endif
