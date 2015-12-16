#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../headers/node.h"
#include "../headers/hash1.h"
#include "../headers/hash2.h"
#include "../headers/hash3.h"

int main(int argc, char *argv[]){
	//Estrutura
	Hash2** hash2;
	Hash3** hash3;
	
	Lista* tab;
	tab = NULL;
	
	//Controle
	No *saida = NULL;
	char* string = NULL;
	int count = 0;
	
	//Parametros
	char* nameEntrada = argv[1];
	char* nameBusca = argv[2];
	char* nameSaida = argv[3];
	char nameAux[120]; //Tamanho max do caminho dos arquivos
	
	//Arquivo
	FILE *arq;
	FILE *write;
 	char info[200];
	
	//Controle do tempo
	float inst1= 0;
	float inst2=0;
	float maior=0;
	float aux = 0;
		
		
//==================== HASH TIPO 2 ================
	
	printf("\n ===> INICIANDO HASH DO TIPO 2\n");
	hash2 = TInit();

	//INSERINDO
	printf("Lendo entrada\n");
	 fopen_s(&arq,nameEntrada,"r");

	if(arq == NULL)
			printf("Erro, nao foi possivel abrir o arquivo\n");
	else
		while( (fgets(info, sizeof(info), arq))!=NULL )
			InsertType2(hash2,novoElem(info));
	fclose(arq);

	//BUSCANDO
	
	strcpy(nameAux,nameSaida);
	strcat(nameAux,"_2");

	printf("\nBUSCANDO\n");
	fopen_s(&arq,nameBusca,"r");
	if(arq == NULL)
			printf("Erro, nao foi possivel abrir o arquivo de leitura\n");
	else{
		fopen_s(&write,nameAux,"w");
		if(arq == NULL)
			printf("Erro, nao foi possivel abrir o arquivo de escrita\n");
		else
			while( (fgets(info, sizeof(info), arq))!=NULL ){
				inst1 = (float)clock()/(float)CLOCKS_PER_SEC;
				saida = BuscaType2(hash2,info);
				inst2 = (float)clock()/(float)CLOCKS_PER_SEC;
				aux =(inst2 - inst1)*1000; 
				if(aux > maior){
					maior = aux;
					string = getNodeVal(saida);
				}else if(aux == 0)
					count++;
				
				if(saida == NULL)
					fprintf(write,"%s %fms NAO\n",info,((inst2 - inst1)*1000));
				else
					fprintf(write,"%s %fms [%d] \n",getNodeVal(saida),((inst2 - inst1)*1000),getCollision(saida));
			}
	}
	fclose(arq);
	fclose(write);
	printf("Liberando memoria\n");
	Free2(hash2);

	printf("MAIOR TEMPO %fms Chave: %s \n",maior,string);
	printf("QUANTIDADE DE ZEROS %d \n",count);

//==================== HASH TIPO 3 ================

	maior = aux = count =0;

	printf("\n ===> INICIANDO HASH DO TIPO 3\n");
	hash3 = H3Init();

	//INSERINDO
	printf("Lendo entrada\n");
	 fopen_s(&arq,nameEntrada,"r");

	if(arq == NULL)
			printf("Erro, nao foi possivel abrir o arquivo\n");
	else
		while( (fgets(info, sizeof(info), arq))!=NULL )
			InsertType3(hash3,novoElem(info));
	fclose(arq);

	strcpy(nameAux,nameSaida);
	strcat(nameAux,"_3");

	printf("\nBUSCANDO\n");
	fopen_s(&arq,nameBusca,"r");
	if(arq == NULL)
			printf("Erro, nao foi possivel abrir o arquivo de leitura\n");
	else{
		fopen_s(&write,nameAux,"w");
		if(arq == NULL)
			printf("Erro, nao foi possivel abrir o arquivo de escrita\n");
		else
			while( (fgets(info, sizeof(info), arq))!=NULL ){
				inst1 = (float)clock()/(float)CLOCKS_PER_SEC;
				saida = BuscaType3(hash3,info);
				inst2 = (float)clock()/(float)CLOCKS_PER_SEC;
				aux =(inst2 - inst1)*1000; 
				if(aux > maior){
					maior = aux;
					string = getNodeVal(saida);
				}else if(aux == 0)
					count++;
					
				if(saida == NULL)
					fprintf(write,"%s %fms NAO\n",info,((inst2 - inst1)*1000));
				else
					fprintf(write,"%s %fms [%d] \n",getNodeVal(saida),((inst2 - inst1)*1000),getCollision(saida));
			}
	}
	fclose(arq);


printf("MAIOR TEMPO %fms Chave: %s \n",maior,string);
printf("QUANTIDADE DE ZEROS %d \n",count);
printf("Liberando memoria\n");
Free3(hash3);

/*
//==================== HASH TIPO 1 ================

	maior = aux = 0;
	
	printf("\n ===> INICIANDO HASH DO TIPO 1\n");

	//INSERINDO
	printf("Lendo entrada\n");
	 fopen_s(&arq,"k:/entrada2.txt","r");

	if(arq == NULL)
			printf("Erro, nao foi possivel abrir o arquivo\n");
	else
		while( (fgets(info, sizeof(info), arq))!=NULL )
		//			tab = insertList(tab,novoElem(info));
			InsertType3(hash3,novoElem(info));
	fclose(arq);


	printf("\nBUSCANDO\n");
	fopen_s(&arq,"k:/entrada2.txt","r");
	if(arq == NULL)
			printf("Erro, nao foi possivel abrir o arquivo\n");
	else
		while( (fgets(info, sizeof(info), arq))!=NULL ){
			saida = BuscaType3(hash3,info);
			inst2 = (float)clock()/(float)CLOCKS_PER_SEC;
			aux =(inst2 - inst1)*1000; 
			if(aux > maior){
				maior = aux;
				string = getNodeVal(saida);
			}else if(aux == 0)
				count++;
			
			if(saida == NULL)
				printf("TEMPO %fms Chave: NAO ENCONTRADA \n",((inst2 - inst1)*1000));
		//	else
		//		printf("TEMPO %fms Chave: %s \n",((inst2 - inst1)*1000),getNodeVal(saida));
		}
			
	fclose(arq);


printf("MAIOR TEMPO %fms Chave: %s \n",maior,string);
printf("QUANTIDADE DE ZEROS %d \n",count);
system("pause");
printf("Liberando memoria\n");
Free3(tab);
*/

}
