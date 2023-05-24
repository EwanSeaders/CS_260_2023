#include <iostream>
using std::cout;
using std::endl;


struct node {
    int key;
    node* left = nullptr;
    node* right = nullptr;
};

class binaryTree{
private:
    node* top = nullptr;

    node* newNode(int key) {
        node* new_node = new node();
        new_node->key = key;
        new_node->left = new_node->right = nullptr;
        return new_node;
    }

public:
    
    
    
    void add(int value, node* curr=nullptr) {// adds a value to the binary tree
        if (top == nullptr) {// creates first node of the tree if it is empty
            top = newNode(value);
            return;
        }
        if(curr == nullptr) {curr = top;}//initializes current
        if (value <= curr->key) {// walks down and adds values to the left
            if (curr->left != nullptr) {add(value, curr->left);}
            if (curr->left == nullptr) {curr->left = newNode(value);}
        }
        if (value > curr->key) {// walks down and adds values to the right
            if (curr->right != nullptr) {add(value, curr->right);}
            if (curr->right == nullptr) {curr->right = newNode(value);}
        }
    }

    int remove(int value, node* curr=nullptr) {
        if (top == nullptr) {return -999999;}
            if(curr == nullptr) {curr = top;}//initializes current
            if (value < curr->key) {// walks down the left
                if (curr->left != nullptr) {remove(value, curr->left);}
                
            }
            if (value > curr->key) {// walks down the right
                if (curr->right != nullptr) {remove(value, curr->right);}
            }
            if (value == curr->key) {
                
            }
    }

    void inOrder(node* curr=nullptr) {// prints out the nodes of the tree using an in order traversal
        if (curr == nullptr) {curr = top;}//initializes current
        if (curr->left != nullptr) {inOrder(curr->left);}// resurively walks to the left
        cout << curr->key << ", ";//prints out the key of the current node
        if (curr->right != nullptr) {inOrder(curr->right);}// resurively walks to the right
    }
    
    void postOrder(node* curr=nullptr) {// prints out the nodes of the tree using a post order traversal
        if (curr == nullptr) {curr = top;}//initializes current
        if (curr->left != nullptr) {inOrder(curr->left);}// resurively walks to the left
        if (curr->right != nullptr) {inOrder(curr->right);}// resurively walks to the right
        cout << curr->key << ", ";//prints out the key of the current node
    }
    
    void preOrder(node* curr=nullptr) {// prints out the nodes of the tree using a pre order traversal
        if (curr == nullptr) {curr = top;}//initializes current
        cout << curr->key << ", ";//prints out the key of the current node
        if (curr->left != nullptr) {inOrder(curr->left);}// resurively walks to the left
        if (curr->right != nullptr) {inOrder(curr->right);}// resurively walks to the right
    }
};


int main() {//runs tests written for 
    binaryTree myTree;

    myTree.add(50);
    myTree.add(50);
    myTree.add(30);
    myTree.add(40);
    myTree.add(60);
    myTree.add(60);
    myTree.add(10);
    myTree.add(20);
    myTree.add(5);



    cout << "add" << endl;
    myTree.inOrder();
    cout << endl;
    myTree.postOrder();
    cout << endl;
    myTree.preOrder();
    cout << endl;

    cout << "end program" << endl;
    return 0;
}
