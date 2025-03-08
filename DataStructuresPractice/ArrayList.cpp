#include <iostream>

class ArrayList{
    private:
        int* Array;
        int arrayCount;
        int arrayCapacity;
    public:
        ArrayList(){
            int arrayCapacity = 10;
            int arrayCount = 0;
            Array = new int[arrayCapacity];
        }

        void addElementEnd(int value){
            if (arrayCount == arrayCapacity){
                expand();
            }
            int* temp = new int[arrayCapacity];
            for (int i = 0; i < arrayCount; i++){
                temp[i] = Array[i];
            }
            delete[] Array;
            Array = temp; 
            Array[arrayCount] = value;
            arrayCount++;
        }

        void addElementBeginning(int value){
            if (arrayCount == arrayCapacity){
                expand();
            }
            for (int i = (arrayCount); i > 0; i--){
                Array[i + 1] = Array[i];
            }
            Array[0] = value;
            arrayCount++;
        }

        void deleteValue(int value){
            for (int i = 0; i < arrayCount; i++){
                if (value == Array[i]){
                    for (int j = (i + 1); j < arrayCount;j++){
                        Array[j - 1] = Array[j];
                    }
                    arrayCount--;
                    i--;
                }
            }
        }

        void deleteEnd(){
            for (int i = 0; i < arrayCount; i++){
                Array[i - 1] = Array[i];
            }
            arrayCount--;
        }

        void expand(){
            arrayCapacity = arrayCapacity * 2;
            int* temporary = new int[arrayCapacity];
            for (int i = 0; i < arrayCount; i++){
                temporary[i] = Array[i];
            }
            delete[] Array;
            Array = temporary;
        }
        void printArray(){
            for (int i = 0; i < arrayCount; i++){
                std::cout << Array[i] << " ";
            }
            std::cout << std::endl;
        }

        void reverseArray(){
            int tempValue = arrayCount - 1;
                for (int i = 0; i < (arrayCount / 2); i++){
                    int tempBeginning = Array[i];
                    int tempEnd = Array[tempValue];
                    Array[i] = tempEnd;
                    Array[tempValue] = tempBeginning;
                    tempValue--;
                }
        }



        
        
    ~ArrayList(){
        delete[] Array;
    }
};

int main(){
   ArrayList list;
   list.addElementEnd(3);
   list.addElementEnd(4);
   list.addElementEnd(5);
   list.addElementEnd(5);
   list.addElementEnd(5);
   list.addElementEnd(5);
   list.addElementEnd(6);
   list.addElementEnd(7);
   list.addElementEnd(8)
   //list.addElementEnd(10);
   //list.addElementEnd(6);
   list.printArray();

}
