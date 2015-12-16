#include "../headers/hash2.h"

// ====== ESTRUTURAS =======
//No da lista
typedef struct no{
  char* chave;
  unsigned short collision;
} No;

//Hash2 da lista encadeada
typedef struct hash2 {
  No* elem;
  unsigned long int indice;
  struct hash2 * prox;
} Hash2;

// ========= CONTROLE DAS ESTRUTURAS ===========

//Inicializa tabela
Hash2** TInit(){
  Hash2** tab;
  int t;
  tab = malloc(M * sizeof(Hash2));
  for(t=0;t<M;t++)
    tab[t] = NULL;
  return tab;
}

// ========= CALCULO DE HASH ========

//Calculo da hash
unsigned long int preHash(int seed,char* key){
  int tam, inverso;
  //tam = strlen(key);
  long int hash = 0;
  inverso = 200;
  tam = 0;

  while(key[tam] != '\0')
    hash += key[tam]*tam++ + (seed*inverso--);

  hash = (hash*seed)+(inverso-seed);
  return hash;
}


// =========== FUNCOES PARA CONTROLE DA HASH TIPO 2 ==============

//Insere ordenado na lista [MELHORAR]
Hash2* InsertionSort(Hash2* lista, Hash2* novoElem){
  //lista vazia
  if(lista == NULL)
    return novoElem;
  
  Hash2* atual = lista->prox;
  Hash2* anterior = lista;
  
 //Verifica imediatamente o primeiro
  if(novoElem->indice <= anterior->indice){
    novoElem->prox = anterior;
    lista = novoElem;
    lista->elem->collision = anterior->elem->collision+1;
    return lista;
  }

  //Contabiliza colisao
  anterior->elem->collision++;
 	
  //Verifica o meio
  while(atual != NULL){
  if(novoElem->indice <= atual->indice){
      anterior->prox = novoElem;
      novoElem->prox = atual;
      return lista;
    }
    anterior = atual;
    atual = atual->prox;
  }

  //Se saiu e pq e o ultimo
  anterior->prox = novoElem;
  return lista;
}

//Insere na tabela
void InsertType2(Hash2 * tab[],No* no){
  unsigned long int h;
  h = preHash(SEED,no->chave);
  Hash2 *novo = (Hash2*) malloc(sizeof(Hash2));
  novo->indice = h;
  h = hash(h,M);
  novo->elem = no;
  novo->prox = NULL;
  tab[h] = InsertionSort(tab[h],novo);
}

//Busca
No* BuscaType2(Hash2 * tab[],char* chave){
  unsigned long int h;
  unsigned short col = 0;
  Hash2* no;
  h = preHash(SEED,chave);
  h = hash(h,M);
  col = tab[h]->elem->collision;
  for(no=tab[h];no!=NULL;no = no->prox)
    if(strcmp(no->elem->chave, chave) == 0){
      	no->elem->collision = col;
		return no->elem;
	}

    return NULL;
}

// =================== LIBERAR MEMORIA ==================

//Libera memoria alocada pela hash2
void Free2(Hash2* tab[]){
  int h;
  Hash2* no;
  Hash2* aux;
  for(h=0;h<M;h++)
    if(tab[h] != NULL)
      for(no=tab[h];no!=NULL;no = aux){
        aux = no->prox;
        free(no->elem);
        free(no);
      }
  free(tab);
}
