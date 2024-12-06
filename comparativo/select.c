#include <stdio.h>
#include <time.h>

void selection_sort(int vetor[], int n) {
    int menor, aux, temp, troca, i;
    unsigned long int trocas = 0, comp = 0;

    for(aux=0; aux < n-1; aux++) {
        menor = aux; // Menor valor recebe a posi��o que est� passando;

        for (temp=aux+1; temp < n; temp++) { // Percorre o vetor da posi��o aux+1 at� o final;
          comp++;
            if (vetor[temp] < vetor[menor]) { // Testa se a posi��o que est� passando � menor que o menor valor;
                menor = temp; // menor recebe a posi��o do menor valor;
            }
        }

        if (menor != aux) { // Se a posi��o for diferente da que est� passando, ocorre a troca;
            troca = vetor[aux];
            vetor[aux] = vetor[menor];
            vetor[menor] = troca;
            trocas++;
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
	selection_sort(a, tam_a);
  t = clock() - t; //tempo final - tempo inicial

  printf("Tempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));
	
	return 1;
}

