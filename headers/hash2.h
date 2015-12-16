/*
	09-12-2015 (C) Joao Carlos Pandolfi Santana
	
	Lib para gerar Hash, empilhando em uma lista as colisoes
*/

// ====== Dependencias =======
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

// ====== Definicoes =======

//Tamanho da tabela
#define M 110127
#define hash(h,M) (h % M)
#define SEED 3

// ====== ESTRUTURAS =======

//Hash2 da lista encadeada
typedef struct hash2 Hash2;

// ====== INICIALIZACOES =======
Hash2** TInit();

// ====== PRE CALCULO DE HASH =======
unsigned long int preHash(int seed,char* key);

// =========== FUNCOES PARA CONTROLE DA HASH TIPO 2 ==============
void InsertType2(Hash2 * tab[],No* no);
No* BuscaType2(Hash2 * tab[],char* chave);

// =================== LIBERAR MEMORIA ==================
void Free2(Hash2* tab[]);
