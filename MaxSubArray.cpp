#include <iostream>
#include <climits>

int crossingMaxSubArray(int* arr, int left, int middle, int right){
    int leftsummation = 0;
    int leftSum = INT_MIN;
    for (int i = middle; i >= left; i--){
        leftsummation = leftsummation + arr[i];
        if (leftsummation > leftSum){
            leftSum = leftsummation;
        }
    }
    int rightsummation = 0;
    int rightSum = INT_MIN;
    for (int j = (middle + 1); j <= right; j++){
        rightsummation = rightsummation + arr[j];
        if (rightsummation > rightSum){
            rightSum = rightsummation;
        }
    }
    return (rightSum + leftSum);
}

int findMaxSubArray(int* arr, int left, int right){
    if (left == right){
        return arr[left];
    }
    int middle = (left + right) / 2;
    int leftMaxSubarray = findMaxSubArray(arr, left, middle);
    int rightMaxSubarray = findMaxSubArray(arr, (middle + 1), right);
    int crossingMaxSub = crossingMaxSubArray(arr, left, middle, right);
    int maximum;
    if ((leftMaxSubarray > rightMaxSubarray) && (leftMaxSubarray > crossingMaxSub)){
        maximum = leftMaxSubarray;
    }
    else if((rightMaxSubarray > leftMaxSubarray) && (rightMaxSubarray > crossingMaxSub)){
        maximum = rightMaxSubarray;
    }
    else if ((crossingMaxSub > leftMaxSubarray) && (crossingMaxSub > rightMaxSubarray)){
    maximum = crossingMaxSub;
    }
    return maximum;
}

int main(){
    int arraySize;
    std::cin >> arraySize;
    int arr[arraySize];

    for (int i = 0; i < arraySize; i++){
        int x;
        std::cin >> x;
        arr[i] = x;
    }

    int maxSub = findMaxSubArray(arr, 0, arraySize - 1);
    std::cout << maxSub;
}
