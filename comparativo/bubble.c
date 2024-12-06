#include <stdio.h>
#include <time.h>

void bubble_sort (int vetor[], int n) {
    int k, j, i, aux;
    unsigned long int trocas = 0, comp = 0;

    for (k = n - 1; k > 0; k--) {
        for (j = 0; j < k; j++) {
            comp++;
            if (vetor[j] > vetor[j + 1]) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
								trocas++;
            }
        }
    }

    printf("\n");
		printf("Trocas: %lu \n", trocas);
    printf("\n");
    printf("Comparacoes: %lu \n", comp);
    printf("\n");
}

int main () {
	clock_t t;
	int a[] = {};
	int tam_a = 100000;

	t = clock(); //armazena tempo
	bubble_sort(a, tam_a);
  t = clock() - t; //tempo final - tempo inicial
 //imprime o tempo na tela
 printf("Tempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));
	
	return 1;
}

