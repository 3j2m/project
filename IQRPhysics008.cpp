#include <iostream>
#include <vector>
#include <cstdlib> // For std::rand
#include <ctime>   // For std::time

void partition(std::vector<int>& arr, int start, int end) {
    int p = 7;  // You specified that p = 5 (for pivot index)
    int pivot = arr[p];  // Store the pivot value
    int key = start - 1;

    std::cout << "Pivot is: " << arr[p] << std::endl;

    // Partition loop
    for (int i = start; i < end; i++) {
        if (arr[i] < pivot) {
            key++;
            std::swap(arr[key], arr[i]);
        }

        // Print the current array state
        std::cout << "Iteration " << i << ": ";
        for (int j = start; j < end; j++) {
            std::cout << arr[j] << " ";
        }
        
        // Print the pivot value (pivot doesn't change)
        std::cout << "  Also! Pivot value: " << pivot << std::endl;
    }

    // Place the pivot in its correct position
    std::swap(arr[p], arr[key + 1]);
}

int main() {
    std::vector<int> arr = {7, 6, 5, 4, 3, 2, 1};  // Example array
    partition(arr, 0, arr.size());

    // Output the array after partitioning
    std::cout << "Array after partitioning: ";
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}