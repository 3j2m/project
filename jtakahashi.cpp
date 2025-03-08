#include <iostream>

int gettingArraySize(){
    int x;
    std::cin >> x;

    return x;
}
int main(){

    int arraySize = gettingArraySize();

    int arr[arraySize][10];

    for (int i = 0; i < arraySize; i++){
        for (int j = 0; j < 10; j++){
            int y;
            std::cin >> y;
            arr[i][j] = y;
        }
    }
   
    
    for (int p = 9; p >= 0; p--){
    
        int countArr[4];
        for (int i = 0; i < 4; i++){
            countArr[i] = 0;
        }

        for (int i = 0; i < arraySize; i++){
            countArr[arr[i][p]]++;
        }

        for (int i = 1; i <= 3; i++){
            countArr[i] = countArr[i] + countArr[i - 1];
        }
        int output[arraySize][10];
        for (int j = arraySize - 1; j >= 0; j--){
            int correctIndex = countArr[arr[j][p]] - 1;
            for (int i = 0; i < 10; i++){
                output[correctIndex][i] = arr[j][i];
            }
            countArr[arr[j][p]]--;
        }

        for (int k = 0; k < arraySize; k++){
            for (int e = 0; e < 10; e++){
                arr[k][e] = output[k][e];
            }
        }
    }

        for (int i = 0; i < arraySize; i++){
            for (int j = 0; j < 10; j++){
                std::cout << arr[i][j] << ";";
            }
            std::cout << std::endl;
        }
    return 0;
}

