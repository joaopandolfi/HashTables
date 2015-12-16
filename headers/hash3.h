/*
	09-12-2015 (C) Joao Carlos Pandolfi Santana
	
	Lib para gerar Hash, gerando uma nova hash em caso de colisao
*/

// ====== Dependencias =======
#include "node.h"
#include "hash2.h"

// ====== Definicoes =======
#define INTERNALM 144
#define FLAG_DATA 1
#define FLAG_HASH 2
#define GAP_SEED 3
#define hash3(h,T) (h % T)

// ====== Estruturas =======


// Estrutura da hash de hash
typedef struct hash3 Hash3;

// ====== Inicializacoes =======

//inicializa Hash3
Hash3** H3Init();

// ====== Manipulacao =======
//Insere na Hash3
void InsertType3(Hash3* hash[], No* elem);
//Busca na Hash3
No* BuscaType3(Hash3* hash[],char* chave);

// ====== Liberacao de memoria =======
//Liberar memoria da Hash3
void Free3(Hash3* hash[]);
