/* 1. Faça um programa que imprima todos os números de 1 a 100 usando o laço de repetição for. 
 * 2. Faça o mesmo programa do exercício anterior, só que dessa vez usando um while.  */

# include<stdio.h>

int main(){
	/* 1- 
	for(int n = 1; n <= 100; n++){
		printf("%d\n", n);
	}	
	
	return 0;*/
	
	/* 2- */
	
	int n = 1;
	while(n <= 100){
		printf("%d\n", n);
		n++;
	}	
	
	return 0;
}
