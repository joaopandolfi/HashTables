/*
	09-12-2015 (C) Joao Carlos Pandolfi Santana
	
	Lib para gerar Hash, Sem colisões
	
	Funcionamento: Insere todas as keys em uma lista comum
	- Cria uma tabela com tamanho de keys inseridas
	- Encontra um valor para a semente que não haja colisao
	- Insere os elementos
*/

// ====== Dependencias =======
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "hash2.h"

// ====== Definicoes =======
#define hash1(h) (h % lenList)
#define seedIncrement() seedHash1 += 1


// ====== Estruturas =======
typedef struct hash1 Hash1;
typedef struct list Lista;

void imprime(Lista* list);

Hash1** calibra(Lista* list);
Lista* insertList(Lista* list, No* elem);
