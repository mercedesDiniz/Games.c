/* Formação C - Fundamentos da linguagem
 * Curso: C: conhecendo a Linguagem das Linguagens
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
	printf("chute %d\n",chute);
	int num_tentativa = 1;
	double pontos = 1000;
		
	// Cabeçalho Inicial:
	printf("************************************\n");
	printf("* Bem vindo ao Jogo de Advinhação *\n");
	printf("************************************\n");
	
	//printf("O %d é o numero secreto. Não conta pra ninguem!\n", num_secreto);
	
	while(1){ // Loop enquanto , infinito
		// Recebendo o chute do usuario:
		printf("Tentativa %d.\n", num_tentativa);
		
		printf("Qual o seu chute? ");
		scanf("%d", &chute);
		
		if(chute < 0){
			printf("Números negativos são invalidos\n");
			continue; // Vai direto para a proxima iteração (Faz o loop continuar sem executar o resto do bloco de codigo, mas sem mata o loop)
		}
		
		// Avaliando o resultado
		int acertou = (chute == num_secreto); // 0 - falso | 1 - verdadeiro
		int maior = chute > num_secreto;
		
		if(acertou){
			printf("Parabéns! Você acertou!\n");
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
	
	printf("Fim de Jogo.\n");
	printf("Você acertou em %d tentativas.\n", num_tentativa);
	printf("Total de pontos %.1f\n", pontos);
	
	return 0;
}
