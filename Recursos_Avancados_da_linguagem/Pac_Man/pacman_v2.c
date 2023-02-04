#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"
#include "mapa.h"

// Declarando Variaveis Globais
MAPA mp;

// MAIN
int main(){	
	le_mapa(&mp); // Inicializa o mapa
	
	// LOOP PRINCIPAL
	do{
		imprime_mapa(&mp);
		// Recebe novo comando
		char comando;
		scanf(" %c", &comando);
		
		move(comando); // executando o comando
			
	}while(!acabou());
	
	libera_mapa(&mp); // Fecha o mapa
}

// FUNÇÕES:
int acabou(){
	return 0; // nao acabou
}

void move(char direcao){
	// localizando o pacman no mapa
	 int x;
	 int y;
	 for(int i=0; i<(mp.linhas); i++){
	 	for(int j=0; j<(mp.colunas); j++){
	 		if(mp.matriz[i][j] == '@'){
	 			x = i;
	 			y = j;
	 			break;
	 		}
	 	}
	 }
	 
	 switch(direcao){
	 	case 'a': // vai p/ esquerda
	 		mp.matriz[x][y-1] = '@';
	 		break;
	 	case 'd': // vai p/ direita
	 		mp.matriz[x][y+1] = '@';
	 		break;
	 	case 'w': // vai p/ cima
	 		mp.matriz[x-1][y] = '@';
	 		break;
	 	case 's': // vai p/ baixo
	 		mp.matriz[x+1][y] = '@';
	 		break;
	 }  
	 
	 mp.matriz[x][y] = '.'; // apagando o pacman da posicao anterior
}

