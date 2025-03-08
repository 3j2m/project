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
            arrayCapacity = 10;
            array = new std::string[arrayCapacity];
        }

        void inflate(){
            arrayCapacity = arrayCapacity * 2;
            std::string* temp = new std::string[arrayCapacity];
        }

        void append(const std::string& string){
            array[arrayCount] = string;
            arrayCount++;
        }


        void printArray(){
            std::cout << "Contents of array: ";
            for (int i = 0; i < arrayCount; i++){
                std::cout << array[i];
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
    array.printArray();
    return 0;
}