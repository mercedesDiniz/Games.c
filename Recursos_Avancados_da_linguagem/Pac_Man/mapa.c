#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"

void le_mapa(MAPA* mp){
	// Fazendo o upload do .txt para iniciar o matriz mapa
	FILE* f;
	f = fopen("mapa.txt", "r");
	if(0 == f){
		printf("Erro na leitura do mapa\n");
		exit(1);
	}
	
	fscanf(f, "%d %d", &(mp->linhas), &(mp->colunas)); // verificando as dimensoes do mapa
	//printf("Dimensoes do mapa: %dx%d\n", linhas, colunas);
	
	malloc_mapa(mp);
		
	// lendo e armazenando um linha
	for(int i = 0; i<mp->linhas; i++){	
		fscanf(f, "%s", mp->matriz[i]); // passando 1 dimensão de uma matriz, retona um array
	}
	
	fclose(f);
}

void malloc_mapa(MAPA* mp){
	// Alocação dinamica de memoria
	mp->matriz = malloc(sizeof(char*) * mp->linhas);
	for(int i = 0; i<mp->linhas; i++){
		mp->matriz[i] =  malloc(sizeof(char) * (mp->colunas+1)); // +1 -> '\0'
	}
}
void libera_mapa(MAPA* mp){
	// Liberando a memoria alocada	
	for(int i =0; i<mp->linhas; i++){
		free(mp->matriz[i]); // liberanoo linha-por-linha
	}
	free(mp->matriz);
}

void imprime_mapa(MAPA* mp){
	// Exibindo o mapa
	for(int i = 0; i<mp->linhas; i++){	
		printf("%s\n", mp->matriz[i]);
	}
}
