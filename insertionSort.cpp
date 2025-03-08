#include <iostream>
#include <vector>

int gettingArraySize(){
    int arraySize;
    std::cin >> arraySize;
    return arraySize;
}

void insertionSort(int arraySize){
    int numberArray [arraySize];
    int* arr = new int[arraySize];
    for (int i = 0; i < arraySize; i++){
        int x;
        std::cin >> x;
        numberArray[i] = x;
    }
    int index = 0;
    int sortedArraySize = 1;
    int sortedArray[arraySize];
    sortedArray[0] = numberArray[0];
    for (int i = 1; i < arraySize; i++){
        int tempValue = numberArray[i];
        int j = i - 1;
    
        while (j >= 0 && numberArray[j] > tempValue){
            numberArray[j+1] = numberArray[j];
            j--;
        }
        numberArray[j+1] = tempValue;
        for (int z = 0; z <= i ; z++){
            std::cout << numberArray[z] << ";";
        }
        std::cout << std::endl;
    }
    delete[] arr;
}

int main(){
    int arraySize = gettingArraySize();

    insertionSort(arraySize);
    
    return 0; 

}   