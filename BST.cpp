#include <iostream>
#include <string>

class BinarySearchTree{

    private:    
        struct Node{
            int value;
            Node* left;
            Node* right;

        };
        Node* head;

        void insert(int value, Node*& head){
            Node* newNode = new Node;
            newNode->value = value;
            newNode->left = nullptr;
            newNode->right = nullptr;
            if (head == nullptr){
                head = newNode;
            }
            else{
                if (value < head->value){
                    insert(value, head->left);
                }
                else{
                    insert(value, head->right);
                }
            }
        }

        void inOrderTraversal(Node* node){
            if (node != nullptr){
                inOrderTraversal(node->left);
                std::cout << node->value << std::endl;
                inOrderTraversal(node->right);
            }
        }

        void preOrderTraversal(Node* node){
            if (node != nullptr){
                std::cout << node->value << std::endl;
                preOrderTraversal(node->left);
                preOrderTraversal(node->right);
            }
        }

        void postOrderTraversal(Node* node){
            if (node != nullptr){
                postOrderTraversal(node->left);
                postOrderTraversal(node->right);
                std::cout << node->value << std::endl;
            }
        }

        void deconstructorHelper(Node* node){
            if (node != nullptr){
                deconstructorHelper(node->left);
                deconstructorHelper(node->right);
                delete node;
            }
        }

        Node* search(int value, Node* node){
            if (node->value == value){
                return node;
            }
            else{
                if (value < node->value){
                    return search(value, node->left);
                }
                else{
                    return search(value, node->right);
                }
            }

            return nullptr;
        }

        Node* successorSearch(Node* node){
            if (node->left == nullptr){
                return node;
            }
            while (node->left != nullptr){
                node = node->left;
            }
            std::cout << "In order successor found!" << std::endl;
            return node;
        }

        Node* parentSearch(Node* node, Node* target){
            if (node->left == target || node->right == target){
                return node;
            }
            else{
                if (target->value < node->value){
                    return parentSearch(node->left, target);
                }
                else{
                    return parentSearch(node->right, target);
                }
            }
        }

    public:
        BinarySearchTree(){
            head = nullptr;
        }

        void insert(int value){
            insert(value, head);
        }

        void inOrderTraversalPrint(){
            inOrderTraversal(head);
        }

        void preOrderTraversalPrint(){
            preOrderTraversal(head);
        }

        void postOrderTraversalPrint(){
            postOrderTraversal(head);
        }

        void parentSearch(int value){
            Node* node = search(value, head);
            Node* parent = parentSearch(head, node); 
            std::cout << "Value of parent is: " << parent->value << std::endl;
        }
        
        void deleteValue(int value){
            Node* deleteNode = search(value, head);
            std::cout << "Value of deleteNode: " << deleteNode->value << std::endl;
            if (deleteNode->left == nullptr && deleteNode->right == nullptr){
                if (deleteNode == head){
                    delete head;
                    head = nullptr;
                }
                else{
                    delete deleteNode;
                }
            }
    
            else if (deleteNode->left == nullptr && deleteNode->right != nullptr){
                if (deleteNode == head){
                    head = deleteNode->right;
                }
                else{
                    Node* parent = parentSearch(head, deleteNode);
                    if(parent->left == deleteNode){
                        parent->left = deleteNode->right;
                    }
                    else{
                        parent->right = deleteNode->right;
                    }
                }
                delete deleteNode;
            }
            else if (deleteNode->left != nullptr && deleteNode->right == nullptr){
                if (deleteNode == head){
                    head = deleteNode->left;
                }
                Node* parent = parentSearch(head, deleteNode);
                if (parent->left == deleteNode){
                    parent->left = deleteNode->left;
                }
                else{
                    parent->right = deleteNode->left;
                }
                delete deleteNode;

            }
            else if (deleteNode->left != nullptr && deleteNode->right != nullptr){
                Node* successor = successorSearch(deleteNode->right);
                std::cout << "Value of the successor: " << successor->value << std::endl;
            }
        }



        ~BinarySearchTree(){
            deconstructorHelper(head);
        }


};

int main(){
    
    BinarySearchTree BST;
    std::string string;
    /*while (string != "e"){
        std::cin >> string;
        if (string == "e"){
            break;
        }
        else{
            if (string[0] == 'i'){
                int value = std::stoi(string.substr(1));
                BST.insert(value);
            }
            else if(string[0] == 'd'){
                int value = string[1] - '0';
                BST.deleteValue(value);
            }
            else if(string.substr(1, 3) == "pre"){
                BST.preOrderTraversalPrint();
            }
            else if (string.substr(1, 4) == "post"){
                BST.postOrderTraversalPrint();
            }
            else if (string.substr(1, 2) == "in"){
                BST.inOrderTraversalPrint();
            }
            
        }
        
    }
    */

    BST.insert(1);
    BST.insert(2);
    BST.insert(3);
    return 0;
}