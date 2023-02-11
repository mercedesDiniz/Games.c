/* Formação C - Fundamentos da linguagem
 * Curso de C: avançando na linguagem
 * Jogo da Forca
 */
 
#include <stdio.h>
#include <string.h>

// Funções
void abertura(){
	printf("/****************/\n");
	printf("/ Jogo de Forca */\n");
	printf("/****************/\n\n");
}

void chuta(char chutes[26], int* tentativas){
	// Solicitando um novo chute
	char chute;
	printf("Chute uma letra: ");
	scanf(" %c", &chute); // o espaço é para ignorar o enter		
	chutes[(*tentativas)] = chute;
	(*tentativas)++;
}

int jachutou(char letra, char chutes[26], int tentativas){
	int achou = 0;
	// Varrendo o array de chutes
	for(int j=0; j <tentativas; j++){
		//printf("--> Chute %d = %c\n", j, chutes[j]);
			
		// Verificando se o jogador acertou o chute
		if(chutes[j] == letra){
			//printf("---> Chute correto : %c\n", chutes[j]);
			achou = 1;
			break;		
		}
	}
	return achou;
}

void print_forca(char palavra_secreta[20], char chutes[26], int tentativas){
	// Varrendo o array palavra_secreta
	for(int i=0; i < strlen(palavra_secreta); i++){
		//printf("Estouvendo a letra secreta %d = %c\n", i,  palavra_secreta[i]);
			
		// a letra ja foi chutada?
		int achou = jachutou(palavra_secreta[i], chutes, tentativas);
			
		// Exibindo o resultado da jogada
		if(achou){
			printf("%c ", palavra_secreta[i]);
		}else{
			printf("_ ");	
		}		
	}
	printf("\n\n");
}

void escolhe_palavra(char palavra_secreta[20]){
		sprintf(palavra_secreta, "MELANCIA"); 
}

// MAIN
int main(){
	// Declaração de Variaveis
	char palavra_secreta[20]; // um array de char pode ser visto como um string (como ultimo caracter = \0)
	char chutes[26];
	int tentativas = 0; 
	int acertou = 0; 
	int enforcou = 0;
	
	escolhe_palavra(palavra_secreta); // Atribuindo o valor a variavel palavra_secreta
	//printf("A palavra secreta é %s.\n", palavra_secreta);
	
	abertura(); // Cabeçalho
	
	// Rotina principal 
	do{
		print_forca(palavra_secreta, chutes, tentativas); // Imprime a palavra secretas
		chuta(chutes, &tentativas); // Solicitando um novo chute
		
	} while(!acertou && !enforcou); // enquanto o jogador não acertou nem foi enforcado
	
	return 0;
}
