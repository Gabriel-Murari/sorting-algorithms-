#include <stdio.h>
#include <stdlib.h> // srand, rand
#include <time.h> // time


// função que realiza a troca entre dois elementos
void troca(int vet[], int i, int j)
{
	int aux = vet[i];
	vet[i] = vet[j];
	vet[j] = aux;
}

// particiona e retorna o índice do pivô
int particiona(int vet[], int inicio, int fim, unsigned long int* comp)
{
	int pivo, pivo_indice, i;
	
	pivo = vet[fim]; // o pivô é sempre o último elemento
	pivo_indice = inicio;
	
	for(i = inicio; i < fim; i++)
	{
		// verifica se o elemento é <= ao pivô
		if(vet[i] <= pivo)
		{
      *comp= *comp+1;
			// realiza a troca
			troca(vet, i, pivo_indice);
			// incrementa o pivo_indice
			pivo_indice++;
		}
	}
	
	// troca o pivô
	troca(vet, pivo_indice, fim);
	
	// retorna o índice do pivô
	return pivo_indice;
}

// escolhe um pivô aleatório para evitar o pior caso do quicksort
int particiona_random(int vet[], int inicio, int fim, unsigned long int* trocas, unsigned long int* comp)
{
	// seleciona um número entre fim (inclusive) e inicio (inclusive)
	int pivo_indice = (rand() % (fim - inicio + 1)) + inicio;
	
	// faz a troca para colocar o pivô no fim
	troca(vet, pivo_indice, fim);
  *trocas= *trocas+1;
	// chama a particiona
	return particiona(vet, inicio, fim, comp);
}

void quick_sort(int vet[], int inicio, int fim, unsigned long int* trocas, unsigned long int* comp)
{
	if(inicio < fim)
	{
		// função particionar retorna o índice do pivô
		int pivo_indice = particiona_random(vet, inicio, fim, trocas, comp);
		
		// chamadas recursivas quick_sort
		quick_sort(vet, inicio, pivo_indice - 1, trocas, comp);
		quick_sort(vet, pivo_indice + 1, fim, trocas, comp);
	}
}

int main()
{

  clock_t t;
  int a[] = {};
  int tam_a = 1000;
  unsigned long int trocas = 0, comp = 0;

	t = clock(); //armazena tempo
  quick_sort(a, 0, tam_a - 1, &trocas, &comp);
  t = clock() - t; //tempo final - tempo inicial

  printf("\n");
  printf("Trocas: %lu \n", trocas);
  printf("\n");
  printf("Comparacoes: %lu \n", comp);
  printf("\n");

  printf("Tempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));
        
  return 0;
}