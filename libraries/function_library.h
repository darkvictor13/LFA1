// este arquivo contem as principais funções que simulam o ciclo de vido do autômato

#include "structure_library.h"

// função que realiza uma dada transição do autômato definido no arquivo de entrada
bool makeTransition();

// função que verifica se um determinado estado do autômato é válido
bool verifyValidState();

// função que realiza todas as transições de uma dada palavra no automato definido a partir do arquivo de entrada
bool makeTransitions();

// função que verifica se uma dada palavra é válida ou não
bool verifyWord();