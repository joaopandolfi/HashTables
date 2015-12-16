#include "../headers/hash1.h"

// ====== Estruturas =======
//No da lista
typedef struct no{
  char* chave;
} No;

//Lista
typedef struct list{
	No* elem;
	struct list* prox;
}Lista;

//Hash
typedef struct hash1{
	No* elem;
	struct hash1* hash;
}Hash1;

// ====== Variaveis globais =======
long int lenList = 0;
int seedHash1 = 0;

// ====== Inicializadores =======

//inicializa Hash1
Hash1** H1Init(){
	Hash1** tab;
	int t;
	tab = malloc(lenList * sizeof(Hash1*));
	for(t=0;t<lenList;t++)
		tab[t] = NULL;
	return tab;
}

//Limpa hash
Hash1** H1Clean(Hash1* tab[]){
	int t;
	for(t=0;t<lenList;t++)
		if(tab[t] != NULL){
			free(tab[t]);
			tab[t] = NULL;
		}
	return tab;
}

// ====== Lista comum =======

//Insere na lista comum
Lista* insertList(Lista* list, No* elem1){
	Lista* novo = (Lista*) malloc(sizeof(Lista*));
	novo->elem = elem1;
	novo->prox = list;
	lenList++;
	list = novo;
	return list;
}

void imprime(Lista* l){
	Lista* aux = l;
	while(aux !=NULL){
		printf("%s\n",aux->elem->chave);
		aux = aux->prox;
	}
}

// ========= CALCULO DE HASH ========
/*
	O mesmo usado na hash do tipo 2
	implementando uma prehash e depois o ajustamento
	para dentro da nova hash
	long int preHash(int seed,char* key);
	hash1(h);
*/

// ========= CCONTROLE DE CALIBRAGEM DA HASH ========

//Calibra e retorna a hash
Hash1** calibra(Lista* list){
	Hash1** tab = H1Init();
	Hash1* novo;
	Lista* auxLista;
	unsigned long int h;
	unsigned short int haveCollision;
	do{
		tab = H1Clean(tab);
		auxLista = list;
		seedIncrement();
		haveCollision = 0;
		h = 0;
		printf("===> Recalibrando %d\n",seedHash1);
		while(auxLista != NULL){
			h = preHash(seedHash1,auxLista->elem->chave);
			h = hash1(h);
			if(tab[h] != NULL){
				printf("\n==>Colidiu \n");
				haveCollision = 1;
				break;
			}
			novo = (Hash1*) malloc(sizeof(Hash1*));
			novo->elem = auxLista->elem;
			tab[h] = novo;
			auxLista = auxLista->prox;
		}
		printf("SAIU\n");
	}while(haveCollision);
	return tab;	
}

void InsertType1(Hash1* hash[], No* elem){
	
}
