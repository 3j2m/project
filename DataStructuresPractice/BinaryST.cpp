#include <iostream>

class BinaryST{
    private:
        struct Node{
            int data;
            Node* left;
            Node* right;    
            Node* parent;
        };

        Node* root;
    public:
        BinaryST(){
            root = nullptr;
        }

        void addValue(int value){
            Node* newNode = new Node;
            newNode->data = value;
            newNode->left = nullptr;
            newNode->right = nullptr;
            if (root == nullptr){
                root = newNode;
            }
            else{
                if (value > )
            }

        }

        void inOrderTraversal(){
            if (root == nullptr){
                std::cout << "Cannot in-order traverse an empty Binary ST" << std::endl;
            }
            else{
                Node* leftMostNode = root;
                Node* previousNode = nullptr;
                while (leftMostNode != nullptr){
                    previousNode = leftMostNode;
                    leftMostNode->left = leftMostNode;
                }
                std::cout << leftMostNode->data << " ";
                std::cout << previousNode->data << " ";
                std::cout << previousNode->right->data << " ";
                while (previousNode != nullptr){
                    leftMostNode = previousNode;

                }

                }
            
        }
};

int main(){
    BinaryST Binary;

}