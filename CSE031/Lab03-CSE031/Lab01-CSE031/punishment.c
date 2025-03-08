#include <stdio.h>

int main(){

    int punishmentCount;
    int typoLine;

    printf("Enter the repitition count for the punishment phrase: " );
    scanf("%d", &punishmentCount);
    while (punishmentCount <= 0){
        printf("You entered an invalid value for the repitition count! Please re-enter: ");
        scanf("%d", &punishmentCount);
    }
    printf("\n");
    printf("Enter the line where you want to insert the typo: ");
    scanf("%d", &typoLine);
    while (typoLine <= 0 || typoLine > punishmentCount){
        printf("You entered an invalid value for the typo placement! Please re-enter: ");
        scanf("%d", &typoLine);
    }
    printf("\n");
    int CorrectUpTo = punishmentCount - typoLine;
    for (int i = 1; i < typoLine; i++){
        printf("Coding with C is awesome!\n");
    }
    printf("Cading wiht is C awesome!\n");
    for (int i = typoLine; i < punishmentCount; i++){
        printf("Coding with C is awesome!\n");
    }

    
}