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

        Node* inOrderTraversalHelper(Node* node, Node* target){
            while(node->value < target->value){
                if (node != nullptr){
                    if (node->value > target->value){
                        return node;
                    }
                    inOrderTraversal(node->left);
                    inOrderTraversal(node->right);
                }
            }
            return nullptr;
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
            if (node == nullptr){
                return nullptr;
            }
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
            if (node->right != nullptr){
                node = node->right;
                while (node->left != nullptr){
                    node = node->left;
                }
                return node;
            }
            Node* parent = parentSearch(head, node);
            while (parent != nullptr && parent->right == node){
                node = parent;
                parent = parentSearch(head, node);
            }
            return parent;
        }

        Node* parentSearch(Node* node, Node* target){
            if (target == head){
                return nullptr;
            }
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

        Node* parentSearch(Node* node){
            Node* parent = parentSearch(head, node); 
            return parent;
        }
        Node* SuccessorSearcher(Node* node){
                Node* successor = successorSearch(node);
                return successor; 
            }
        

        /*void deleteValue(int value){
            Node* deleteNode = search(value, head);
            if (deleteNode == nullptr){
                return;
            }
            if (deleteNode->left == nullptr && deleteNode->right == nullptr){
                if (deleteNode == head){
                    delete head;
                    head = nullptr;
                }
                else{
                    Node* parent = parentSearch(head, deleteNode);
                    if (parent->left == deleteNode){
                        parent->left = nullptr;
                    }
                    else if (parent->right == deleteNode){
                        parent->right = nullptr;
                    }
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
                else{
                    Node* parent = parentSearch(head, deleteNode);
                    if(parent->left == deleteNode){
                        parent->left = deleteNode->left;
                    }
                    else{
                        parent->right = deleteNode->left;
                    }
                }
                delete deleteNode;
            }
            else if (deleteNode->left != nullptr && deleteNode->right != nullptr){
                Node* successor = successorSearch(deleteNode->right);
                std::cout << "Value of successor is: " << successor->value << std::endl;
                deleteNode->value = successor->value;
                if (successor->left == nullptr && successor->right == nullptr){
                    Node* parent = parentSearch(successor);
                    if (parent->left == successor){
                        parent->left = nullptr;
                        delete successor;
                    }
                    else if (parent->right == successor){
                        parent->right = successor;
                        delete successor;
                    }
                }
                else if(successor->left == nullptr && successor->right != nullptr){
                    Node* parent = parentSearch(successor);
                    if (parent->left == successor){
                        parent->left = successor->left;
                        delete successor;
                    }
                    else{
                        parent->right = successor->right;
                        delete successor;
                    }
                }
                else if (successor->left != nullptr && successor->right == nullptr){
                    Node* parent = parentSearch(successor);
                    if (parent->left == successor){
                        parent->left = successor->left;
                        delete successor;
                    }
                    else{
                        parent->right = successor->left;
                        delete successor;
                    }
                }
            }   
        }

        */

       void deleteValue(int value){
            Node* deleteNode = search(value, head);
            if (deleteNode->left == nullptr && deleteNode->right == nullptr){
                if (head == deleteNode){
                    head = nullptr;
                    delete deleteNode;
                }
                Node* parent = parentSearch(deleteNode);
                if (parent->left == deleteNode){
                    delete parent->left;
                    parent->left = nullptr;
                }
                else{
                    delete parent->right;
                    parent->right = nullptr;
                }
            }
            else if (deleteNode->left == nullptr && deleteNode->right != nullptr){
                Node* temp = deleteNode->right;
                if (deleteNode == head){
                    delete head;
                    head = temp;
                }
                else{
                    Node* parent = parentSearch(deleteNode);
                    if (parent->left == deleteNode){
                        parent->left = temp;
                    }
                    else{
                        parent->right = temp;
                    }
                        delete deleteNode;
                    }
            }
            else if (deleteNode->left != nullptr && deleteNode->right == nullptr){
                Node* temp = deleteNode->left;
                if(deleteNode == head){
                    delete head;
                    head = temp;
                }
                else{
                    Node* parent = parentSearch(deleteNode);
                    if (parent->left == deleteNode){
                        parent->left = temp;
                    }
                    else{
                        parent->right = temp;
                    }
                    delete deleteNode;
                }
            }
            else if (deleteNode->left != nullptr && deleteNode->right != nullptr){
                Node* successor = successorSearch(deleteNode);
                deleteNode->value = successor->value;
                if (successor->left == nullptr && successor->right == nullptr){
                    Node* parent = parentSearch(successor);
                    if (parent->left == successor){
                        delete parent->left;
                        parent->left = nullptr;
                    }
                    else if (parent->right == successor){
                        delete parent->right;
                        parent->right = nullptr;
                    }
                }
                else if (successor->right != nullptr && successor->left == nullptr){
                    Node* temp = successor->right;
                    Node* parent = parentSearch(successor);
                    if (parent->left == successor){
                        parent->left = temp;
                    }
                    else{
                        parent->right = temp;
                    }
                    delete successor;
                }   
                else if (successor->right == nullptr && successor->left != nullptr){
                    Node* temp = successor->left;
                    Node* parent = parentSearch(successor);
                    if (parent->left == successor){
                        parent->left = temp;
                    }
                    else{
                        parent->right = temp;
                    }
                    delete successor;
                }
                if (deleteNode == head){
                    head = successor;
                    delete deleteNode;
                }
            }
       }

        ~BinarySearchTree(){
            deconstructorHelper(head);
        }


};

int main(){
    
    BinarySearchTree BST;
    std::string string;
    while (string != "e"){
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
                int value = std::stoi(string.substr(1));
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
            else if (string[0] == 's'){
                int value = string[1] - '0';

            }
            
        }
        
    }
    
    return 0;
}