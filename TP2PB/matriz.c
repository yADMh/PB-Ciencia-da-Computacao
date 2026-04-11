#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    int n = 1000;
    int **mat = malloc(n * sizeof(int*));

    for(int i = 0; i < n; i++){
        mat[i] = malloc(n * sizeof(int));
        for(int j = 0; j < n; j++)
            mat[i][j] = rand() % 256;
    }

    double inicio = omp_get_wtime();

    #pragma omp parallel for
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            mat[i][j] += 10;

    double fim = omp_get_wtime();

    printf("Tempo: %f\n", fim - inicio);

    for(int i = 0; i < n; i++)
        free(mat[i]);
    free(mat);

    return 0;
}