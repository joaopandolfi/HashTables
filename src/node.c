#include <string.h>
#include "../headers/node.h"
//No da lista
typedef struct no{
  char* chave;
  unsigned short collision;
} No;

//Cria novo elemento
No* novoElem(char* chave){
  No* novo = (No*) malloc(sizeof(No));
  novo->chave = malloc(strlen(chave)+1);
  strcpy_s(novo->chave,strlen(chave)+1,chave);
  novo->collision = 0;
  return novo;
}

//retorna valor
char* getNodeVal(No* elem){
	char* val;
	int tam;
	if(elem == NULL)
		return "vazio";
	tam = strlen(elem->chave);
	val = malloc(tam+1);
  	strcpy_s(val,tam+1,elem->chave);
  	val[tam-1] = '\0';
	return val;
}

//Retorna a quantidade de colisao
unsigned short getCollision(No* elem){
	return elem->collision;
}

//Verifica se o no esta vazio
int checkNullNode(No* elem){
	return elem == NULL;
}

