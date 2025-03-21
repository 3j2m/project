#include <stdio.h>
#include <stdlib.h>
int** matMult(int **a, int **b, int size) {
    int **result = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++){
        *(result + i) = (int*)malloc(size * sizeof(int));
    }
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            *(*(result + i) + j) = 0;
            for (int r = 0; r < size; r++){
                *(*(result + i) + j) += *(*(a + i) + r) * *(*(b + r) + j);

            }

        }
    }
    return result;
}
void printArray(int **arr, int n) {
    for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", *(*(arr + i) + j));
            }
            printf("\n");
        }

}
int main() {
    int n = 3;
    int **matA = (int**)malloc(n * sizeof(int*));
    int **matB = (int**)malloc(n * sizeof(int*));
    int **matC = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++){
        *(matA + i) = (int*)malloc(n * sizeof(int));
        *(matB + i) = (int*)malloc(n * sizeof(int));
        *(matC + i) = (int*)malloc(n * sizeof(int));
    }

    //Entering in values for Matrix A 
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int x;
            scanf("%d", &x);
            *(*(matA + i) + j) = x;
        }
    }

    //Entering in values for Matrix B
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int x;
            scanf("%d", &x);
            *(*(matB + i) + j) = x;
        }
    }

    //Initializing values for Matrix B
    
    matC = matMult(matA, matB, n);
    printArray(matA, n);
    printf("\n");
    printArray(matB, n);
    printf("\n");
    printArray(matC, n);

    for (int i = 0; i < n; i++) {
        free(*(matA + i));
        free(*(matB + i));
        free(*(matC + i));
    }
    free(matA);
    free(matB);
    free(matC);
// (1) Define 2 (n x n) arrays (matrices).
// (3) Call printArray to print out the 2 arrays here.
// (5) Call matMult to multiply the 2 arrays here.
// (6) Call printArray to print out resulting array here.
return 0;
}
