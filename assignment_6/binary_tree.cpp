#include <iostream>
using std::cout;
using std::endl;


struct node {
    int key;
    node* left = nullptr;
    node* right = nullptr;
    node* parent = nullptr;
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

    // void repoint(node* curr, node* parent, node* del_node=nullptr) {// rearranges pointers if the node is a right child of the 
    //     if (del_node=nullptr) {del_node = curr;}
    //     if(del_node->key > parent->key) {//
    //         parent->right = del_node->left;

    //     }
       
    // }
    
    node* findParent(int value, node* curr=nullptr) {// returns the node pointer to the value specified or returns nullptr if it does not exist
        if(curr == nullptr) {curr = top;}//initializes current
        if (value == curr->left->key | value == curr->right->key){// returns parent if a child equals the value
            return curr;
        }
        if (value < curr->key) {// walks down the left
            cout << "left" << endl;
            if (curr->left != nullptr) {findParent(value, curr->left);}
        }
        cout << "what" << endl;
        if (value > curr->key) {// walks down the right
            cout << "right" << endl;
            if (curr->right != nullptr) {findParent(value, curr->right);}
        }
        // if (curr->left == nullptr & curr->right == nullptr) {
        //     return nullptr;
        // }
    }

    bool find(int value) {// returns true if the value is stored in the tree
        node* parent = findParent(value);
        if (findParent(value) != nullptr && top != nullptr) {
            return true;
        }
        return false;
    }


    int remove(int value) {
        node* parent=findParent(value);
        node* del_node;
        if (value == parent->left->key){del_node = parent->left;}
        if (value == parent->right->key){del_node = parent->right;}
        node* curr = del_node;
        if (del_node->key > parent->key) {
            parent->right = del_node->left;
            curr = curr->left;
            while (curr->right != nullptr){
                curr = curr->right;
            }
            curr->right = del_node->right;
            delete del_node;
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
    cout << "findParent test: " << myTree.findParent(40) << endl;
    cout << "remove(40) test: " << myTree.remove(40) << endl;
    myTree.inOrder();

    cout << "end program" << endl;
    return 0;
}
