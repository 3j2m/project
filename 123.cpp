#include <iostream>
#include <array>


int getArraySize(){
    int x;
    std::cin >> x;

    return x;
}



void MaxHeapify(int arr[], int start, int arraySize){
    int leftchildIndex = (2 * start) + 1;
    int rightchildIndex = (2 * start) + 2;
    int maxIndex = start;
    if ((leftchildIndex >= (arraySize)) && (rightchildIndex >= (arraySize))){
        return; 
    }

            
    if (leftchildIndex < arraySize && arr[leftchildIndex] > arr[maxIndex]){
        maxIndex = leftchildIndex;
    }
    if(rightchildIndex < arraySize && arr[rightchildIndex] > arr[maxIndex]){
        maxIndex = rightchildIndex;
    }
            
    if (maxIndex != start){
        std::swap(arr[start], arr[maxIndex]);
        
        MaxHeapify(arr, maxIndex, arraySize);
        }
}

void BuildMaxHeap(int arr[], int arraySize){
    for (int i = ((arraySize / 2) - 1); i >= 0; i--){
        MaxHeapify(arr, i, arraySize);
    }
}



void HeapSort(int arr[], int arraySize){
    BuildMaxHeap(arr, arraySize);
    for (int i = arraySize - 1; i >= 1; i--){
        std::swap(arr[0], arr[i]);
        MaxHeapify(arr, 0, i);
    }
}

int main(){

    int arraySize = getArraySize();
    int A[arraySize];


    for (int i = 0; i < arraySize; i++){
        int x;
        std::cin >> x;
        A[i] = x;
    }

    HeapSort(A, arraySize);

    for (int i = 0; i < arraySize; i++){
        std::cout << A[i] << ";";
    }


 
    return 0;
}