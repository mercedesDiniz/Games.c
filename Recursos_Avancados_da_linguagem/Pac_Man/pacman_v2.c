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
	mp.matriz[pacman.x][pacman.y] = '.'; // apagando o pacman da posicao anterior
	 
	 switch(direcao){
	 	case 'a': // vai p/ esquerda
	 		mp.matriz[pacman.x][pacman.y-1] = '@';
	 		pacman.y--; // atualiando a localizacao do pacman no mapa
	 		break;
	 	case 'd': // vai p/ direita
	 		mp.matriz[pacman.x][pacman.y+1] = '@';
	 		pacman.y++; // atualiando a localizacao do pacman no mapa
	 		break;
	 	case 'w': // vai p/ cima
	 		mp.matriz[pacman.x-1][pacman.y] = '@';
	 		pacman.x--; // atualiando a localizacao do pacman no mapa
	 		break;
	 	case 's': // vai p/ baixo
	 		mp.matriz[pacman.x+1][pacman.y] = '@';
	 		pacman.x++; // atualiando a localizacao do pacman no mapa
	 		break;
	 }  
	 
}

