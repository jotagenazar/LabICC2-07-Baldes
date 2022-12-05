#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
  
void bucket_sort(float *array, int n_elems, int n_buckets, int max){
    //criação de n buckets
    vector<float> bucket[n_buckets];
    float range = 1.0 * max / (n_buckets - 1);
    int b_ind;
    
    //divisão dos elementos do array em diferentes buckets
    for(int i = 0; i < n_elems; i++) {
        b_ind = array[i] / range;
        bucket[b_ind].push_back(array[i]);
    }

    //ordenação de cada bucket
    for(int i = 0; i < n_buckets; i++)
        sort(bucket[i].begin(), bucket[i].end());
    
    //concatenação dos buckets de volta no array
    int arr_ind = 0;
    for(int i = 0; i < n_buckets; i++) {
        for(int j = 0; j < (int) bucket[i].size(); j++) {
            array[arr_ind] = bucket[i][j];
            arr_ind++;
        }
    }
}

int main() {
    float *array;
    int n_elems, n_buckets, max;

    //leitura da quantidade de elementos e numero de buckets
    scanf("%d %d %d", &n_elems, &max, &n_buckets);
    array = (float*) malloc (n_elems * sizeof(float));

    //leitura dos valores
    for(int i = 0; i < n_elems; i++)
        scanf(" %f", &array[i]);  
    
    //ordenação
    bucket_sort(array, n_elems, n_buckets, max);

    //impressão do vetor ordenado
    for (int i = 0; i < n_elems; i++)
        printf("%.2f ", array[i]);
    cout << "\n";
    
    //finalização
    free(array);
    return EXIT_SUCCESS;
}