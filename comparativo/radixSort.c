// Radix Sort in C Programming
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
// Function to get the maximum value in the array
int getMax(int array[], int n, unsigned long int* comp) {
    int max = array[0];
    for (int i = 1; i < n; i++) {
        *comp = *comp + 1;
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}
// Using counting sort to sort the elements based on significant places
void countingSort(int array[], int n, int place, unsigned long int* trocas, unsigned long int* comp) {
    int output[n];
    int count[10] = {0};
    // Calculate count of elements
    for (int i = 0; i < n; i++) {
        int index = (array[i] / place) % 10;
        count[index]++;
    }
    // Calculate cumulative count
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    // Place the elements in sorted order
    for (int i = n - 1; i >= 0; i--) {
        int index = (array[i] / place) % 10;
        output[count[index] - 1] = array[i];
        count[index]--;
        *trocas = *trocas + 1;
    }
    // Copy the sorted elements into original array
    for (int i = 0; i < n; i++) {
        array[i] = output[i];
    }
}
// Main function to implement radix sort
void radixSort(int array[], int n, unsigned long int* trocas, unsigned long int* comp) {
    // Get maximum element
    int maxElement = getMax(array, n, comp);
    // Apply counting sort to sort elements based on place value
    for (int place = 1; maxElement / place > 0; place *= 10) {
        countingSort(array, n, place, trocas, comp);
    }
}
int main() {

    clock_t t;
	int a[] = {}; 
    int tam_a = 1000;
	unsigned long int trocas = 0, comp = 0;

	t = clock(); //armazena tempo
    radixSort(a, tam_a, &trocas, &comp);
	t = clock() - t; //tempo final - tempo inicial

	printf("\n");
	printf("Trocas: %lu \n", trocas);
	printf("\n");
	printf("Comparacoes: %lu \n", comp);
	printf("\n");

	printf("Tempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));
			
	return 0;
}