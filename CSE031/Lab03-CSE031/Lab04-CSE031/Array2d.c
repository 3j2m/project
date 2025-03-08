#include <stdio.h>
#include <stdlib.h>
void printArray(int**, int);

int main() {
    int j = 0, n = 9;
    int **arr = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++){
        *(arr + i) = (int*)malloc(n * sizeof(int*));
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (j == i){
                *(*(arr + i) + j) = (i + 1);
            }
            else{
                *(*(arr + i) + j) = 0;
            }
        }
    }

    

    // (3) Add your code to complete allocating and initializing the 2-D array
    //here. The content should be all 0.
    // This will print out your array
    printArray(arr, n);
    return 0;
}
    void printArray(int ** array, int size) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                printf("%d ", *(*(array + i) + j));
            }
            printf("\n");
        }
// (5) Implement your printArr here:
}
