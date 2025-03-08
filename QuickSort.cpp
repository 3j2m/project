#include <iostream>
#include <random>
#include <algorithm>


int getArraySize(){
    int x;
    std::cin >> x;

    return x;
}


void QuickSort(int arr[], int start, int end){
    if (start >= end){
        return;
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(start, (end));
    
    int p = dist(gen);
    int pivot = arr[p];
    int key = start - 1;
    for (int i = start; i <= end; i++){
        if (i == p){
            continue;
        }
        if (arr[i] < pivot){
            key++;
            std::swap(arr[key], arr[i]);
            if (key == p){
                p = i;
            }
        }
    }
    key++;
    std::swap(arr[p], arr[key]);
    QuickSort(arr, start, key - 1);
    QuickSort(arr, key + 1, end);
}
int main(){
    int arraySize = getArraySize();

    int arr[arraySize];

    for (int i = 0; i < arraySize; i++){
        int value;
        std::cin >> value;
        arr[i] = value;
    }
   
    QuickSort(arr, 0, arraySize - 1);
    for (int x = 0; x < arraySize; x++){
        std::cout << arr[x] << ";";
    }
    
    return 0;
}
