#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"
#include "mapa.h"

// Declarando Variaveis Globais
MAPA mp;
POSICAO pacman; // posição atual do pacman


// MAIN
int main(){	
	le_mapa(&mp); // Inicializa o mapa
	 encontrar_no_mapa(&mp, &pacman, '@'); // localizando posicao inicial do pacman no mapa
	
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
	if(direcao != 'a' && direcao != 'd' && direcao != 'w' && direcao != 's') return; //tratando entradas invalidas	
		 
	 // verificar o que temos no mapa na posicao que o pacman deseja ir
	int prox_x = pacman.x; // posicao atual de x
	int prox_y = pacman.y; // posicao atual de y
	switch(direcao){
		case 'a': // vai p/ esquerda
	 		prox_y--; // atualiando a localizacao em que o pacman deseja ir no mapa
	 		break;
	 	case 'd': // vai p/ direita
	 		prox_y++; // atualiando a localizacao em que o pacman deseja ir no mapa
	 		break;
	 	case 'w': // vai p/ cima
	 		prox_x--; // atualiando a localizacao em que o pacman deseja ir no mapa
	 		break;
	 	case 's': // vai p/ baixo
	 		prox_x++; // atualiando a localizacao em que o pacman deseja ir no mapa
	 		break;
	}  
	//tratrando a validacao do movimento
	if(prox_x >= mp.linhas) return; // limite vertical do mapa
	if(prox_y >= mp.colunas) return; // limite horizontal do mapa
	if(mp.matriz[prox_x][prox_y] != '.') return; // não se move para espaços não vazios
		 
	mp.matriz[prox_x][prox_y] = '@'; // movendo o pacman p/ uma posicao valida
	mp.matriz[pacman.x][pacman.y] = '.'; // apagando o pacman da posicao anterior
	
	// atualizando a posicao atual do pacman
	pacman.x = prox_x; 
	pacman.y = prox_y;	
}

