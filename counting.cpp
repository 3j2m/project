#include <iostream>

int gettingArraySize(){
    int x;
    std::cin >> x;

    return x;
}

int findingMaximum(int* arr, int arraySize){
    int max = 0;
    for (int i = 0; i < arraySize; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }

    return max;
}
int main(){

    int arraySize = gettingArraySize(); 

    int arr[arraySize];
    for (int i = 0; i < arraySize; i++){
        int y;
        std::cin >> y;
        arr[i] = y;
    }

    int maximum = findingMaximum(arr, arraySize);
    
    int countingArr[maximum + 1];
    for (int j = 0; j < maximum + 1; j++){
        countingArr[j] = 0;
    }

    for (int q = 0; q < arraySize; q++){
        countingArr[arr[q]]++;
    }
    
    for (int r = 1; r <= maximum; r++){
        countingArr[r] = countingArr[r] + countingArr[r - 1];
    }
    int output[arraySize];

    for (int o = arraySize - 1; o >= 0; o--){
        int correctIndex = countingArr[arr[o]] - 1;
        output[correctIndex] = arr[o];
        countingArr[arr[o]]--;
    }

    std::cout << "array contents: ";
    for (int c = 0; c < arraySize; c++){
        std::cout << output[c] << " ";
    }
    std::cout << std::endl;

}