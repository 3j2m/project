#include <stdio.h>
int main() {
    int x, y, *px, *py;
    x = 5;
    y = 6;
    px = &x;
    py = &y;
    int arr[10];
    for (int i = 0; i < 10; i++){
        arr[i] = i;
    }


    printf("Value of x: %d\n", x);
    printf("Address of x: %p\n", &x);
    printf("Value of y: %d\n", y);
    printf("Address of y: %p\n", &y);
    printf("value of px: %p\n", px);
    printf("value stored in px: %d\n", *px);
    printf("Value of py: %p\n", py);
    printf("value stored in py: %d\n", *py);
    printf("Address of arr: %p", &arr);
    int *p = arr;
    for (int i = 0; i < 10; i++){
        printf("Value of element %d: %d\n", i, *p);
        p++;
    }
    return 0;
}