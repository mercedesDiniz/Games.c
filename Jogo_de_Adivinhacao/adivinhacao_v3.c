/* Formação C - Fundamentos da linguagem
 * Curso: C: conhecendo a Linguagem das Linguagens
 * Jogo de Adivinhação
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	// Decrarando variaveis
	int seg = time(0); // o EPOCH é a semente
	srand(seg); // passando a semente
	int num_secreto = rand() % 100; // numero aleatorio entre 0 e 99
		
	int chute;
	int num_tentativa = 1;
	double pontos = 1000;
	int acertou = 0;
	int nivel;
	int chances;	
	
	// Cabeçalho Inicial:
	printf("\n\n");
	printf("          P  /_\\  P                               \n");
	printf("         /_\\_|_|_/_\\                             \n");
	printf("     n_n | ||. .|| | n_n         Bem vindo ao      \n");
	printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhação!  \n");
	printf("    |" "  |  |_|  |"  " |                          \n");
	printf("    |_____| ' _ ' |_____|                          \n");
	printf("          \\__|_|__/                               \n\n\n");
	
	//printf("O %d é o numero secreto. Não conta pra ninguem!\n", num_secreto);
	
	printf("Qual o nível de dificuldade?\n(1) Fácil\t(2) Médio\t(3) Difícil\n\n");
	printf("Escolha: ");
	scanf("%d",&nivel);
	switch(nivel){
		case 1:
			chances = 20;
			break;
		case 2:
			chances = 10;
			break;
		case 3:
			chances = 5;
			break;
		default:
			chances = 5;
			break;	
	}

	
	for(int i = 1; i <= chances; i++){ // Numero de tentativas limitado
		// Recebendo o chute do usuario:
		printf("Tentativa %d.\n", num_tentativa);
		
		printf("Qual o seu chute? ");
		scanf("%d", &chute);
		
		if(chute < 0){
			printf("Números negativos são invalidos\n");
			continue; // Vai direto para a proxima iteração (Faz o loop continuar sem executar o resto do bloco de codigo, mas sem mata o loop)
		}
		
		// Avaliando o resultado
		acertou = (chute == num_secreto); // 0 - falso | 1 - verdadeiro
		int maior = chute > num_secreto;
		
		if(acertou){
			break; // Saindo do loop 
		}else if(maior){
			printf("Você errou!\n");
			printf("Seu chute foi MAIOR que o número secreto.\n");
		}else{
			printf("Você errou!\n");
			printf("Seu chute foi MENOR que o número secreto.\n");
		}
		
		num_tentativa++;
		double pontosperdidos = abs(chute - num_secreto) / (double)2; // valor descontado da pontuacao total
		pontos = pontos - pontosperdidos;
	
	}
	
	printf("Fim de Jogo.\n\n");
	if(acertou){
		printf("             OOOOOOOOOOO               \n");
        		printf("         OOOOOOOOOOOOOOOOOOO           \n");
	          printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
	        	printf("    OOOOOO      OOOOO      OOOOOO      \n");
	        	printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
	        	printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
	        	printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
	       	printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
	        	printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
	        	printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
	        	printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
	        	printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
	        	printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
	        	printf("         OOOOOO         OOOOOO         \n");
	        	printf("             OOOOOOOOOOOO              \n");
	        	printf("\n\n");
	
		printf("Parabéns! Você acertou!\n");
		printf("Você acertou em %d tentativas.\n", num_tentativa);
		printf("Total de pontos %.1f\n", pontos);
	}else{
		printf("Você perdeu! Tente de novo!\n");
		printf("       \\|/ ____ \\|/    \n");
 	          printf("        @~/ ,. \\~@      \n");
        		printf("       /_( \\__/ )_\\    \n");
        		printf("          \\__U_/        \n");
		
	}
		
	return 0;
}
