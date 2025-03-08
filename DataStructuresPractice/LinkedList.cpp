#include <iostream>

class LinkedList{
    private:
        struct Node{
            int data;
            Node* next;
        };

        Node* head;

    public:
        LinkedList(){
            head = nullptr;
        }

        void addNodeEnd(int value){
            
            Node* newNode = new Node;
            newNode->data = value;
            newNode->next = nullptr;
            if (head == nullptr){
                head = newNode;
            }
            else{
                Node* current = head;
                while(current->next != nullptr){
                    current = current->next;
                }
                current->next = newNode;
            }
        }

        void addNodeBeginning(int value){
            Node* newNode = new Node;
            newNode->data = value;
            newNode->next = nullptr;
            if (head == nullptr){
                head = newNode;
            }
            else{
                newNode->next = head;
                head = newNode;
            }
        }

        void printLinkedList(){
            if (head == nullptr){
                std::cout << "Cannot print an empty Linked List" << std::endl;
            }
            else{
                Node* current = head; 
                while(!(current == nullptr)){
                    std::cout << current->data << " ";
                    current = current->next;
                }
            }
        }

        void deleteLast(){
            Node* current = head;
            if (current == nullptr){
                std::cout << "Cannot delete from an empty Linked List" << std::endl;
                return;
            }
            else if (head != nullptr && head->next == nullptr){
                delete head;
                head = nullptr;
                return;
            }
            while (current->next->next != nullptr){
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }

        void deleteFirst(){
            Node* nextPointer = head->next;
            head->next = nullptr;
            delete head;
            head = nextPointer;

        }

        void search(int value){
            if (head == nullptr){
                std::cout << "Cannot search from an empty linked list" << std::endl;
            }
            else if (head->data == value){
                std::cout << "The Linked List contains the specifcied value" << std::endl;
            }
            else{
                Node* current = head;
                while(current->next != nullptr){
                    current = current->next;
                    if (current->data == value){
                        std::cout << "The Linked List contains the specificed value" << std::endl;
                        break;
                    }
                }
            }
        }

        void reversingList(){
            if (head == nullptr){
                std::cout << "Cannot reverse an empty linked list" << std::endl;
            }
            else if(head != nullptr && head->next == nullptr){
                std::cout << "Cannot reverse a linked list of only one element" << std::endl;
            }
            else{
                Node* previous = nullptr;
                Node* current = head;
                Node* temp = nullptr;
                while(current != nullptr){
                    Node* temp = current->next;
                    current->next = previous;
                    previous = current;
                    current = temp;
                }
                head = previous;
            }
        }
    
    ~LinkedList(){
            Node* current = head;
            while(!(current == nullptr)){
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }



};


int main(){
    LinkedList list;
    list.addNodeEnd(7);
    list.addNodeEnd(8);
    list.addNodeEnd(9);
    list.addNodeEnd(10);
    list.addNodeBeginning(5);
    list.addNodeBeginning(5);
    list.printLinkedList();
}