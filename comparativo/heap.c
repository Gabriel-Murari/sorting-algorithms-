#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

void heapify (int vetor[], int n, int i, unsigned long int* trocas, unsigned long int* comp) {
	int maior = i;
	int esq = 2*i+1;
	int dir = 2*i+2;
	int troca;
	
	if (esq < n && vetor[esq] > vetor[maior]) 
		maior = esq;
		*comp=*comp+1;
	if (dir < n && vetor[dir] > vetor[maior]) 
		maior = dir;
		*comp=*comp+1;
	if (maior != i) {
		*comp=*comp+1;
		troca = vetor[i];
		vetor[i] = vetor[maior];
    vetor[maior] = troca;
		*trocas=*trocas+1;
    heapify(vetor, n, maior,trocas, comp);
	}
}

void heap_sort (int vetor[], int n, unsigned long int* trocas, unsigned long int* comp) {
    int i, troca;
	
	for(i = n/2-1; i>=0; i--) {
		heapify(vetor, n, i, trocas, comp);
	}
	
	for(i = n-1; i>0; i--) {
		troca = vetor[0];
		vetor[0] = vetor[i];
    vetor[i] = troca; 
		*trocas= *trocas+1; 
		heapify(vetor, i, 0, trocas, comp);
	}
	
}

int main () {

	clock_t t;
	int a[] = {};
	int tam_a = 1000;
	unsigned long int trocas = 0, comp = 0;

	t = clock(); //armazena tempo
	heap_sort(a, tam_a, &trocas, &comp);
	t = clock() - t; //tempo final - tempo inicial

	printf("\n");
	printf("Trocas: %lu \n", trocas);
	printf("\n");
	printf("Comparacoes: %lu \n", comp);
	printf("\n");

	printf("Tempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));
			
	return 0;
}

