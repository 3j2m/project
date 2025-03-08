#include <iostream>

class LinkedList{

    private:
        struct node{
            node* next;
            int value;
        };

        node* head;

    public:
        LinkedList(){
            head = nullptr;
        }

        void addValue(int value){
            node* newNode = new node;
            newNode->value = value;
            newNode->next = nullptr;
            if (head == nullptr){
                head = newNode;
            }
            else{
                node* current = head;
                while (current->next != nullptr){
                    current = current->next;
                }

                current->next = newNode;
            }
        }

        void printLinkedList(){
            node* current = head;
            while (current != nullptr){
                std::cout << current->value << " ";
                current = current->next;
            }
            std::cout << std::endl;
        }

        ~LinkedList(){
            node* current = head;
            while(!(current == nullptr)){
                node* temp = current;
                current = current->next;
                delete temp;
            }
        }

};

int main(){

    LinkedList bootyLinkedList;
    bootyLinkedList.addValue(5);
    bootyLinkedList.addValue(6);
    bootyLinkedList.addValue(8);
    bootyLinkedList.printLinkedList();
    return 0;
}