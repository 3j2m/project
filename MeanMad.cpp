#include <iostream>
#include <cmath>

int main(){
    float arr[11];
    float sum = 0;
    for (int i = 0; i < 11; i++){
        float x;
        std::cin >> x;
        arr[i] = x;
        sum = sum + x;
    }

    float mean = sum / 11;

    float absD = 0;
    for (int j = 0; j < 11; j++){
        float temp = arr[j];
        float deviation = std::abs(temp - mean);
        absD = absD + deviation;
    }

    float MAD = absD / 11;


    std::cout << "Mean is: " << mean << std::endl;
    std::cout << "MAD is: " << MAD << std::endl;

}