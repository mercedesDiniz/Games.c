/* Formação C - Fundamentos da linguagem
 * Curso: C: conhecendo a Linguagem das Linguagens
 */

#include <stdio.h>

// Decrarando constantes
#define NUM_TENTATIVAS 5

int main(){
	// Decrarando variaveis e constantes
	int num_secreto = 42;
	int chute;
	
	// Cabeçalho Inicial:
	printf("************************************\n");
	printf("* Bem vindo ao Jogo de Advinhação *\n");
	printf("************************************\n");
	
	//printf("O %d é o numero secreto. Não conta pra ninguem!\n", num_secreto);
	
	for(int tentativa = 1; tentativa <= NUM_TENTATIVAS; tentativa++){ // Loop for
		// Recebendo o chute do usuario:
		printf("Tentativa %d de %d.\n", tentativa, NUM_TENTATIVAS);
		
		printf("Qual o seu chute? ");
		scanf("%d", &chute);
		printf("Seu chute foi %d.\n", chute);
		
		if(chute < 0){
			printf("Números negativos são invalidos\n");
			tentativa--; // Não contar essa tentativa
			continue; // Vai direto para a proxima iteração (Faz o loop continuar sem executar o resto do bloco de codigo, mas sem mata o loop)
		}
		
		// Avaliando o resultado
		int acertou = (chute == num_secreto); // 0 - falso | 1 - verdadeiro
		int maior = chute > num_secreto;
		//int menor = chute < num_secreto;
		
		//printf("valor de acertou: %d\n", acertou);
		if(acertou){
			printf("Parabéns! Você acertou!\n");
			break; // Saindo do loop 
		} 
			
		else if(maior){
			printf("Você errou!\n");
			printf("Seu chute foi maior que o número secreto.\n");
		}
		else{
			printf("Você errou!\n");
			printf("Seu chute foi menor que o número secreto.\n");
		}
	
	}
	
	printf("Fim de Jogo.\n");
	
	return 0;
}
