#include <iostream>


int getArraySize(){
    int arraySize;
    std::cin >> arraySize;

    return arraySize;
}
int arrayCopy(){
    int x;
    std::cin >> x;
    return x;
}
void merge(int* array, int left, int middle, int right){
    
    int leftSize = middle - left + 1;
    int rightSize = right - middle;

    int leftArray[leftSize];
    int rightArray[rightSize];

    for (int i = 0; i < leftSize; i++){
        leftArray[i] = array[left + i];
    }
    for (int j = 0; j < rightSize; j++){
        rightArray[j] = array[j + middle + 1];
    }

    int rightIndex = 0;
    int leftIndex = 0; 
    int mergedIndex = left;

    while((rightIndex < rightSize) && (leftIndex < leftSize)){
        if (leftArray[leftIndex] <= rightArray[rightIndex]){
            array[mergedIndex] = leftArray[leftIndex];
            leftIndex++;
        }
        else if (rightArray[rightIndex] < leftArray[leftIndex]){
            array[mergedIndex] = rightArray[rightIndex];
            rightIndex++;
        }
        mergedIndex++;
    }

    while (leftIndex < leftSize){
        array[mergedIndex] = leftArray[leftIndex];
        leftIndex++;
        mergedIndex++;
    }
    while (rightIndex < rightSize){
        array[mergedIndex] = rightArray[rightIndex];
        rightIndex++;
        mergedIndex++;
    }

}


void mergeSort(int* array, int left, int right){
    if (left >= right){
        return;
    }
    int middle = left + (right - left) / 2;

    mergeSort(array, left, middle);
    mergeSort(array, middle + 1, right);

    merge(array, left, middle, right);
}





int main(){

    int arraySize = getArraySize();

    int array[arraySize];

    for (int i = 0; i < arraySize; i++){
        array[i] = arrayCopy();
    }

    mergeSort(array, 0, arraySize - 1);

    for (int i = 0; i < arraySize; i++){
        std::cout << array[i] << ";";
    }

    return 0;


} 