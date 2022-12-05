#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
  
void merge(float *array, int ini, int meio, int fim) {

	int i = ini, j = meio + 1, k = 0;
	
	int n = fim - ini + 1;
	float aux[n];

	while( (i <= meio) && (j <= fim)) {
		if(array[i] <= array[j]) {
			aux[k] = array[i];
			i++;
		} else {
			aux[k] = array[j];
			j++;
		}
		k++;
	}

	while (j <= fim) {
		aux[k] = array[j];
		k++;
		j++;
	}

	while (i <= meio) {
		aux[k] = array[i];
		k++;
		i++;
	}

	for (i = 0; i < n; i++) {
		array[ini+i] = aux[i];
	}
}

void mergeSort(float *array, int ini, int fim) {
	if (ini >= fim) // caso base
		return;

	int meio = (ini+fim)/2;
	mergeSort(array, ini, meio);
	mergeSort(array, meio+1, fim);
	merge(array, ini, meio, fim);
}

int main() {
    float *array;
    int n_elems;

    //leitura da quantidade de elementos e numero de buckets
    scanf("%d %*d %*d", &n_elems);
    array = (float*) malloc (n_elems * sizeof(float));

    //leitura dos valores
    for(int i = 0; i < n_elems; i++)
        scanf(" %f", &array[i]);  
    
    //ordenação
    mergeSort(array, 0, n_elems - 1);

    //impressão do vetor ordenado
    for (int i = 0; i < n_elems; i++)
        printf("%.2f ", array[i]);
    cout << "\n";
    
    //finalização
    free(array);
    return EXIT_SUCCESS;
}