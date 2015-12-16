#include "../headers/hash3.h"

// ====== Estruturas =======
//No da lista
typedef struct no{
  char* chave;
  unsigned short collision;
} No;

// Estrutura da hash de hash
typedef struct hash3{
	No* elem;
	struct hash3** hash;
	unsigned short int flag;
	unsigned int seed;
} Hash3;

//inicializa Hash3
Hash3** H3Init(){
	Hash3** tab;
	int t;
	tab = malloc(M * sizeof(Hash3));
	for(t=0;t<M;t++)
		tab[t] = NULL;
	return tab;
}

//Inicializa hash interna do tipo 3
Hash3** H3InitInternal(int tam){
	Hash3** tab;
	int t;
	tab = malloc(tam * sizeof(Hash3));
	for(t=0;t<tam;t++)
		tab[t] = NULL;
	return tab;	
}

// ========= CALCULO DE HASH ========
/*
	O mesmo usado na hash do tipo 2
	implementando uma prehash e depois o ajustamento
	para dentro da nova hash
*/

// =========== FUNCOES PARA CONTROLE DA HASH TIPO 3 ==============

// ==> Intenos

//Insere na hash interna
Hash3** InsertType3Internal(Hash3* hash[], No* elem,int seed, int T){
	unsigned long int h;
	h = preHash(seed,elem->chave);
	h = hash3(h,T);
	if(hash[h] == NULL){
		Hash3 *novo = (Hash3*) malloc(sizeof(Hash3));
		novo->elem = elem;
		novo->flag = FLAG_DATA;
		novo->seed = seed;
		novo->elem->collision = (seed)/ GAP_SEED;
		novo->hash = NULL;
		hash[h] = novo;
	}else if(hash[h]->flag == FLAG_DATA){
		Hash3 *aux;
		aux = hash[h];
		aux->hash = H3InitInternal(INTERNALM);
		aux->flag = FLAG_HASH;
		aux->seed += GAP_SEED;
		aux->hash = InsertType3Internal(aux->hash,elem,aux->seed,INTERNALM);
	}else
		InsertType3Internal(hash[h]->hash,elem,hash[h]->seed,INTERNALM);
	return hash;
}

//Busca na hash Interna 
No* BuscaType3Internal(Hash3* hash[], char* chave,int seed, int T){
	if(hash == NULL)
		return NULL;
	unsigned long int h;
	h = preHash(seed,chave);
	h = hash3(h,T);
	if(hash[h] == NULL)
		return NULL;

	if(strcmp(hash[h]->elem->chave,chave) == 0)
		return hash[h]->elem;

	return BuscaType3Internal(hash[h]->hash,chave,hash[h]->seed,INTERNALM);
}

// ==> Externos

//Insere na hash
void InsertType3(Hash3* hash[], No* elem){
	InsertType3Internal(hash,elem,SEED,M);
}

//Busca na hash
No* BuscaType3(Hash3* hash[],char* chave){
	return BuscaType3Internal(hash,chave,SEED,M);
}

// =================== LIBERAR MEMORIA ==================
//Recursiva do sistema para liberar memoria
Hash3** Free3Internal(Hash3* hash[],int tam){
	while(tam){
		if(hash[tam] == NULL){
			tam--;
			continue;
		}
		else if(hash[tam]->flag == FLAG_DATA){
			free(hash[tam]->elem);
			free(hash[tam]);
		}
		else{
			hash[tam]->hash = Free3Internal(hash[tam]->hash,INTERNALM-1);
			free(hash[tam]->elem);
			free(hash[tam]);
		}
		tam--;
	}
	free(hash);
	return hash;
}


//Liberar memoria da hash3
void Free3(Hash3* hash[]){
	Free3Internal(hash,M-1);
}
