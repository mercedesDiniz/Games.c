/* Escreva um programa que imprima a soma de todos os números de 1 até 100. Ou seja, ele calculará o resultado de 1+2+3+4+...+100. */

#include<stdio.h>

int main(){
	int soma = 0;
	for(int n = 1; n <= 100; n++){
		soma = soma + n;
	}
	
	printf("Soma = %d\n", soma);
	return 0;
}
