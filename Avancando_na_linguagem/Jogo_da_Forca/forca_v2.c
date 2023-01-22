/* Formação C - Fundamentos da linguagem
 * Curso de C: avançando na linguagem
 * Jogo da Forca
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "forca.h"

// Declaração de Variaveis Globais
char palavra_secreta[20]; // um array de char pode ser visto como um string (como ultimo caracter = \0)
char chutes[26];
int chutes_dados = 0;


// MAIN
int main(){
	escolhe_palavra(); // Atribuindo o valor a variavel palavra_secreta
	//printf("A palavra secreta é %s.\n", palavra_secreta);
	
	abertura(); // Cabeçalho
	
	// Rotina principal 
	do{
		print_forca(); // Imprime a palavra secretas
		chuta(); // Solicitando um novo chute
		
	} while(!acertou() && !enforcou()); // enquanto o jogador não acertou nem foi enforcado
	
	add_palavra();
	return 0;
}


// Definição das funções
void abertura(){
	printf("/****************/\n");
	printf("/ Jogo de Forca */\n");
	printf("/****************/\n\n");
}

void chuta(){
	// Solicitando um novo chute
	char chute;
	printf("Chute uma letra: ");
	scanf(" %c", &chute); // o espaço é para ignorar o enter		
	chutes[chutes_dados] = chute;
	chutes_dados++;
}

int jachutou(char letra){
	int achou = 0;
	// Varrendo o array de chutes
	for(int j=0; j <chutes_dados; j++){
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

void print_forca(){
	// Varrendo o array palavra_secreta
	for(int i=0; i < strlen(palavra_secreta); i++){
		//printf("Estouvendo a letra secreta %d = %c\n", i,  palavra_secreta[i]);
			
		// a letra ja foi chutada?
		int achou = jachutou(palavra_secreta[i]);
			
		// Exibindo o resultado da jogada
		if(achou){
			printf("%c ", palavra_secreta[i]);
		}else{
			printf("_ ");	
		}		
	}
	printf("\n\n");
}

void add_palavra(){
	char quer;
	printf("Adicionar nova palavra? (S/N) ");
	scanf(" %c",&quer);
	
	// Adicionando  a nova palavra ao arquivo .txt
	if(quer == 'S'){
		char nova_palavra[20];
		printf("Insira a nova palavra: ");
		scanf("%s", nova_palavra);
		
		FILE* f;
		f = fopen("palavras.txt", "r+"); // abri com permissão de leitura e escrita
		
		// se o ponteiro for nulo, houve falha ao abrir o arquivo
		if(f == 0){
			printf("Desculpe, banco de dados não disponevel.\n\n");
			exit(1); // mata o programa
		}
		
		// alterando o valor que indica o total de palavra existentes no arquivo
		int qtd_palavras;
		fscanf(f, "%d", &qtd_palavras); // lendo a linha 1
		qtd_palavras++; 
		
		fseek(f, 0, SEEK_SET); //posicionando o ponteiro para a primeira lilha do arquivo
		fprintf(f, "%d", qtd_palavras); // sobreescrevendo o valor 
		
		fseek(f, 0, SEEK_END); //posicionando o ponteiro para a ultima lilha do arquivo
		fprintf(f, "%s", nova_palavra); // \n
		
		fclose(f);	
	}
}

void escolhe_palavra(){
	FILE* f;
	f = fopen("palavras.txt", "r"); // abri com permissão de leitura
	
	// se o ponteiro for nulo, houve falha ao abrir o arquivo
	if(f == 0){
		printf("Desculpe, banco de dados não disponevel.\n\n");
		exit(1); // mata o programa
	}
	// primeia linha do arq é o valor referente a quantidade de palavras
	int qtd_palavras;
	fscanf(f, "%d", &qtd_palavras); // lendo a linha 1
	
	// selecionando uma das palavras do arq aleatoriamente
	srand(time(0)); // semente
	int randomico = rand() % qtd_palavras; // gerando um numero randomico
	// le sequencialmente até chegar na palavra do indice especificado
	for(int i=0; i<=randomico; i++){
		fscanf(f, "%s", palavra_secreta); 
	}
	
	fclose(f);
}

int acertou(){
	for(int i=0; i < strlen(palavra_secreta); i++){
		if(!jachutou(palavra_secreta[i])){ 
			return 0; // caso falte chutar alguma letra da palavra secreta, é pq n ganhou
		}
	}
	return 1;	// caso todas as letras da palavra secreta tenham cido chutadas, é pq ganhou
}

int enforcou(){
	int erros = 0;
	for(int i=0; i <chutes_dados; i++){
		int existe = 0;
		for(int j=0; j<strlen(palavra_secreta); j++){
			if (chutes[i] == palavra_secreta[j]){
				 existe = 1;
				 break;
			}
		}	
		
		if(!existe) erros++;	
	}	
	return erros >= 5; // retorn 0 se falso ou 1 se verdadeiro
}
