#include <stdio.h>
    int main() {
    int i;
    int four_ints[4];
    char* four_c;
    for(i = 0; i < 4; i++){
        four_ints[i] = 2;
    }
    printf("%x\n", four_ints[0]);
    four_c = (char*)four_ints;
    for(i = 0; i < 4; i++){
        four_c[i] = 'A' + i;
    }

    printf("%x\n", four_ints[0]);
    printf("%x\n", four_ints[1]);
    int* ptr = four_ints;
    printf("Addresses of four_ints: ");
    for (int a = 0; a < 4; a++){
        printf("%p ", ptr);
        ptr++;
    }
    printf("\n");
    printf("Hex Contents of four_ints: ");
    for (int c = 0; c < 4; c++){
        printf("%x ", four_ints[c]);
    }
    printf("\n"); 
    printf("Contents of four_c: ");
    for (int b = 0; b < 4; b++){
        printf("%x ", four_c[b]);
    }
    printf("\n"); 

    printf("ADdresses of four_c: ");
    char* secondptr = four_c;
    for (int y = 0; y < 4; y++){
        printf("%p ", secondptr);
    }
    printf("\n");

    prin
 // ASCII value of 'A' is 65 or 0x41 in Hex.
// Add your code for the exercises here:
return 0;
    }