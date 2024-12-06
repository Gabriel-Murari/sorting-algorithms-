#include <stdio.h>
#include <time.h>

void improvedBubbleSort(int arr[], int n) {
    int i, j, temp;
    int swapped;
    unsigned long int trocas = 0, comp = 0;
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - 1 - i; j++) {
            comp++;
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
                trocas++;
            }
        }
        if (swapped == 0) {
            break;
        }
    }

    printf("\n");
		printf("Trocas: %lu \n", trocas);
    printf("\n");
    printf("Comparacoes: %lu \n", comp);
    printf("\n");
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    clock_t t;
    int a[] = {};
    int tam_a = 100000;

    t = clock(); //armazena tempo
    improvedBubbleSort(a, tam_a);
    t = clock() - t; //tempo final - tempo inicial

  printf("Tempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));

    return 0;
}