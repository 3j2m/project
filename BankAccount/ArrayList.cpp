#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>
#include <string>
class arrayList{

    private:
        int arrayCount;
        int arrayCapacity;
        std::string* array;

    public:

        arrayList(){
            arrayCount = 0;
            arrayCapacity = 2;
            array = new std::string[arrayCapacity];
        }

        void inflate(){
            arrayCapacity = arrayCapacity * 2;
            std::string* temp = new std::string[arrayCapacity];
            for (int i = 0; i < arrayCount; i++){
                temp[i] = array[i];
            }
            delete[] array;
            array = temp;
        }

        void append(const std::string& string){
            array[arrayCount] = string;
            arrayCount++;
            if (arrayCount == arrayCapacity){
                inflate();
            }
        }


        void printArray(){
            std::cout << "Contents of array: ";
            for (int i = 0; i < arrayCount; i++){
                std::cout << array[i] << std::endl;
            }
            std::cout << std::endl;
        }

        ~arrayList(){
            delete[] array;
        }
};

int main(){

    arrayList array;
    array.append("Hello World!");
    array.append("ima touch you");
    array.append("ima touchy you");
    array.append("yo whats up");
    array.append("hey hey");
    array.append("nana");
    array.printArray();
    return 0;
}

#endif