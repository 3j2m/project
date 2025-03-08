#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int size; // Variable to record size of original array arr
int evenCount = 0, oddCount = 0; // Variables to record sizes of new arrays
//arr_even and arr_odd
int *arr; // Dynamically allocated original array with #elements = size
int *arr_even; // Dynamically allocated array with #elements = #even elements in
//arr (evenCount)
int *arr_odd; // Dynamically allocated array with #elements = #odd elements in
//arr (oddCount)
char *str1 = "Original array's contents: ";
char *str2 = "Contents of new array containing even elements from original: ";
char *str3 = "Contents of new array containing odd elements from original: ";
/*
* DO NOT change the definition of the printArr function when it comes to
* adding/removing/modifying the function parameters, or changing its return
* type.
*/
void printArr(int *a, int size, char *prompt){
    printf("%s", prompt);
    if (size == 0){
        printf("empty");
    }
    for (int *p = a; p < a + size; p++){
        printf("%d ", *p);
    }
    printf("\n");
}
/*
* DO NOT change the definition of the arrCopy function when it comes to
* adding/removing/modifying the function parameters, or changing its return
* type.
*/
void arrCopy(){
    int *even = arr_even;
    int *odd = arr_odd;
    for (int *p = arr; p < arr + size; p++){
        int x = *p;
        if (x % 2 == 0){
            *even = x;
            even++;
            evenCount++;
        }
        else{
            *odd = x;
            odd++;
            oddCount++;
        }
    }
}
int main(){
printf("Enter the size of array you wish to create: ");
scanf("%d", &size);
arr = (int*)malloc(size * sizeof(int));
int printIndex = 1;
for (int *p = arr; p < arr + size; p++){
    printf("Enter array element #%d: ", printIndex);
    printIndex++;
    scanf("%d", p);
}
printf("\n");
arr_even = (int*)malloc(size * sizeof(int));
arr_odd = (int*)malloc(size * sizeof(int));
/*************** YOU MUST NOT MAKE CHANGES BEYOND THIS LINE! ***********/
// Print original array
printArr(arr, size, str1);
/// Copy even elements of arr into arr_even and odd elements into arr_odd
arrCopy();
// Print new array containing even elements from arr
printArr(arr_even, evenCount, str2);
// Print new array containing odd elements from arr
printArr(arr_odd, oddCount, str3);

printf("\n");
}