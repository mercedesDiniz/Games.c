#include <stdio.h>
#include <stdlib.h>

// Declarando Variaveis Globais
int linhas;
int colunas;
char** mapa; // ponteiro de ponteiros

int main(){	
	// Declarando Variaveis

	// Fazendo o upload do .txt para iniciar o matriz mapa
	FILE* f;
	f = fopen("mapa.txt", "r");
	if(0 == f){
		printf("Erro na leitura do mapa\n");
		exit(1);
	}
	
	fscanf(f, "%d %d", &linhas, &colunas); // verificando as dimensoes do mapa
	printf("Dimensoes do mapa: %dx%d\n", linhas, colunas);
	
	// Alocação dinamica de memoria
	mapa = malloc(sizeof(char*) * linhas);
	for(int i = 0; i<linhas; i++){
		mapa[i] =  malloc(sizeof(char) * (colunas+1)); // +1 -> '\0'
	}
		
	// lendo e armazenando um linha
	for(int i = 0; i<linhas; i++){	
		fscanf(f, "%s", mapa[i]); // passando 1 dimensão de uma matriz, retona um array
	}
	
	fclose(f);
	
	// Exibindo o mapa
	for(int i = 0; i<linhas; i++){	
		printf("%s\n", mapa[i]);
	}
	
	// Liberando a memoria alocada	
	for(int i =0; i<linhas; i++){
		free(mapa[i]); // liberanoo linha-por-linha
	}
	free(mapa);
	
}
