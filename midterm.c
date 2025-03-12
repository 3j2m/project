#include <stdio.h>
#include <stdlib.h>



int main(){
    
    int *array = (int *)malloc(10 * sizeof(int));
    int *temp = array; 
    int *freeAddress = array;
    for (int i = 0; i < 10; i++){
        printf("Please enter in array value: ");
        int x;
        scanf("%d\n", &x);
        *array = x;
        array++;
    }

    int *niggaPointer1 = array; //Pointer to 1st element
    int *niggaPointer2 = array + 3; //Pointer to 3rd element
    int niggaPointer3 = niggaPointer2 - niggaPointer1;
    /*
    printf("Contents of the array: ");
    for (int j = 0; j < 10; j++){
        printf("%d ", *temp);
        temp++;
    }
    printf("\n");
    */
    free(freeAddress);
    
    return 0;
}