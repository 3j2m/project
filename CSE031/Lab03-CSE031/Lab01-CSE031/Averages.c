#include <stdio.h>
void printing(int printIndex){
    if (printIndex >= 10 && printIndex <= 20){
        printf("Enter the %dth value: ", printIndex);
    }
    else if (printIndex % 10 == 1){
        printf("Enter the %dst value: ", printIndex);
    }
    else if(printIndex % 10 == 2){
        printf("Enter the %dnd value: ", printIndex);
    }
    else if (printIndex % 10 == 3){
        printf("Enter the %drd value: ", printIndex);
    }
    else{
        printf("Enter the %dth value: ", printIndex);
    }

}

int sum(int value){
    int sum = 0;
    int currentNumber = value;
    if (currentNumber < 0){
        currentNumber = -currentNumber;
    }
    while (currentNumber > 0){
        int modulo = currentNumber % 10;
        sum += modulo;
        currentNumber = currentNumber / 10;
    }

    return sum;
}

int main(){
    int x;
    int printIndex = 2;
    int oddArrayIndex = 0;
    int evenArrayIndex = 0;
    int oddArray[1000000];
    int evenArray[1000000];
    printf("Enter the 1st value: ");
    scanf("%d", &x);
    int test = sum(x);
    if (test % 2 == 0){
        evenArray[evenArrayIndex] = x;
        evenArrayIndex++;
    }
    else{
        oddArray[oddArrayIndex] = x;
        oddArrayIndex++;
    }
    if (x == 0){
        printf("\n");
        printf("There is no average value to compute.");
        return 0;
    }
    while(x != 0){
        printing(printIndex);
        scanf("%d", &x);
        if (x == 0){
            break;
        }
        int testing = sum(x);

        if (testing % 2 == 0){
        evenArray[evenArrayIndex] = x;
        evenArrayIndex++;
        }
        else{
        oddArray[oddArrayIndex] = x;
        oddArrayIndex++;
        }

        printIndex++;
    }

    float evenSum = 0;
    float oddSum = 0;
    for (int i = 0; i < (evenArrayIndex); i++){
        evenSum += evenArray[i];
        test = evenArray[i];

    }
    for (int j = 0; j < (oddArrayIndex); j++){
        oddSum += oddArray[j];
    }


    if (evenSum == 0){
        printf("\n");
    }
    else{
        float evenAverage = evenSum / (evenArrayIndex);
        printf("\n");
        printf("Average of input whose digits sum up to an even number: %0.2f\n", evenAverage);

    }
    if(oddSum == 0){
        int null;
    }
    else{
        float oddAverage = oddSum / (oddArrayIndex);
        printf("Average of input whose digits sum up to an odd number: %0.2f", oddAverage);
    }
 
        


}