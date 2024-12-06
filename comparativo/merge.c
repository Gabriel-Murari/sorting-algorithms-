#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r, unsigned long int* trocas, unsigned long int* comp)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    
    int L[n1], R[n2];

    for (i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }
    
    for (j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j];
    }
    
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
        *trocas= *trocas+1;
        *comp= *comp+1;
    }

    
    while (i < n1) {
        arr[k] = L[i];
        *trocas= *trocas+1;
        *comp= *comp+1;
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        *trocas= *trocas+1;
        *comp= *comp+1;
        j++;
        k++;
    }
}


void mergeSort(int arr[], int l, int r, unsigned long int* trocas, unsigned long int* comp)
{
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m, trocas, comp);
        mergeSort(arr, m + 1, r, trocas, comp);

        merge(arr, l, m, r, trocas, comp);
    }
}

int main()
{
	clock_t t;
	int a[] = {};
	int tam_a = 1000;
  unsigned long int trocas = 0, comp = 0;

	t = clock(); //armazena tempo
  mergeSort(a, 0, tam_a - 1, &trocas, &comp);
  t = clock() - t; //tempo final - tempo inicial

  printf("\n");
  printf("Trocas: %lu \n", trocas);
  printf("\n");
  printf("Comparacoes: %lu \n", comp);
  printf("\n");

  printf("Tempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));
    
  return 0;
}
