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

int ehdirecao(char direcao){
	return direcao == 'a' || direcao == 'd' || direcao == 'w' || direcao == 's';
}

void move(char direcao){	
	if(!ehdirecao(direcao)) return; //tratando entradas invalidas	
	
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
	if(!ehvalida(&mp, prox_x, prox_y)) return; // não atravesa os limites do mapa
	if(!ehvazia(&mp, prox_x, prox_y)) return; // não se move para espaços não vazios
	
	// movenvo o pacman p/ um posicao valida no mapa
	andando_no_mapa(&mp, pacman.x, pacman.y, prox_x, prox_y);
	
	// atualizando a posicao atual no pacman
	pacman.x = prox_x;
	pacman.y =  prox_y;
}

