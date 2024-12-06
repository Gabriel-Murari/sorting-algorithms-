#include <stdio.h>
#include <time.h>

void insertion_sort(int vetor[], int n) {
    int aux, temp, troca, i;
    unsigned long int trocas = 0, comp = 0;

    for (aux=1; aux < n; aux++) {
        temp = aux; // temp recebe a posi��o que est� passando no "for";
        comp++;
        while (vetor[temp] < vetor[temp-1]) { // Enquanto o valor que est� passando na posi��o "temp" for menor que a posi��o "temp" menos 1, ocorre a troca;
         	// Ocorre a troca;
            troca = vetor[temp];
            vetor[temp] = vetor[temp-1];
            vetor[temp-1] = troca;
            temp--;
            trocas++;

            if (temp == 0) // Quando "temp" chegar na posi��o 0, primeira posi��o do vetor, o la�o while para;
                break;
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
	insertion_sort(a, tam_a);
  t = clock() - t; //tempo final - tempo inicial

  printf("Tempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));
	
	return 1;
}

