#include <stdlib.h>

typedef struct no No;
//Cria novo elemento
No* novoElem(char* chave);
//Recuperar valores
char* getNodeVal(No* elem);
unsigned short getCollision(No* elem);

//Checar
int checkNullNode(No* elem);
