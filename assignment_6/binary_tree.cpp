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
    node* top;

    node* newNode(int key) {
        node* new_node = new node();
        new_node->key = key;
        new_node->left = new_node->right = nullptr;
        return new_node;
    }



public:
    binaryTree() {
        top = nullptr;
    }

    ~binaryTree() {
        killSwitch();
    }
    void killSwitch(node* del_ptr=nullptr) {
        if (del_ptr == nullptr) {del_ptr = top;}
        if (del_ptr->right != nullptr) {killSwitch(del_ptr->right);}
        if (del_ptr->left != nullptr) {killSwitch(del_ptr->left);}
        if (del_ptr->right == nullptr && del_ptr->left == nullptr) {delete del_ptr;}
        // delete[] top;
        delete top;
        return;
    }
    
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

    // void repointRight(node* curr, node* parent, node* del_node=nullptr) {// rearranges pointers if the node is a right child of the 
    //     if (del_node=nullptr) {del_node = curr;}
    //     if(del_node->key > parent->key) {//
    //         parent->right = del_node->left;

    //     }
       
    // }
    
    
    node* findParent(int value) {// returns the node pointer to the value specified or returns nullptr if it does not exist
        node* curr = top;
        node* parent = nullptr;
        if (value == curr->key) {return nullptr;}
        while (curr->key != value) {
            if (curr->right == nullptr && curr->left == nullptr) {break;}
            if (value > curr->key) {
                parent = curr;
                curr = curr->right;
            }
            if (value < curr->key) {
                parent = curr;
                curr = curr->left;
            }
        }
        if (value == curr->key) {return parent;}
        return nullptr;
    }
    // bool find(int value) {// returns true if the value is stored in the tree
    //     node* parent = findParent(value);
    //     if (findParent(value) != nullptr && top != nullptr) {
    //         return true;
    //     }
    //     return false;
    // }


    int remove(int value) {
        node* parent = findParent(value);
        node* del_node;
        if (value <= parent->left->key){del_node = parent->left;}
        if (value > parent->right->key){del_node = parent->right;}
        node* curr = del_node;
        node* temp = del_node;
        if (del_node->key > parent->key) {
            parent->right = del_node->left;
            curr = curr->left;
            while (curr->right != nullptr){
                curr = curr->right;
            }
            curr->right = del_node->right;
            delete del_node;
            // repointRight(curr, parent);
        }
        if (del_node->key < parent->key) {
            parent->left = del_node->left;
            curr = curr->left;
            while (curr->right != nullptr){
                curr = curr->right;
            }
            curr->right = del_node->right;
            delete del_node;
        }
        return temp->key;
    }

    void inOrder(node* curr=nullptr) {// prints out the nodes of the tree using an in order traversal
        if (curr == nullptr) {curr = top;}//initializes current
        if (curr->left != nullptr) {inOrder(curr->left);}// resurively walks to the left
        cout << curr->key << ", ";//prints out the key of the current node
        if (curr->right != nullptr) {inOrder(curr->right);}// resurively walks to the right
    }
    
    void postOrder(node* curr=nullptr) {// prints out the nodes of the tree using a post order traversal
        if (curr == nullptr) {curr = top;}//initializes current
        if (curr->left != nullptr) {postOrder(curr->left);}// resurively walks to the left
        if (curr->right != nullptr) {postOrder(curr->right);}// resurively walks to the right
        cout << curr->key << ", ";//prints out the key of the current node
    }
    
    void preOrder(node* curr=nullptr) {// prints out the nodes of the tree using a pre order traversal
        if (curr == nullptr) {curr = top;}//initializes current
        cout << curr->key << ", ";//prints out the key of the current node
        if (curr->left != nullptr) {preOrder(curr->left);}// resurively walks to the left
        if (curr->right != nullptr) {preOrder(curr->right);}// resurively walks to the right
    }
};


int main() {//runs tests written for
    binaryTree myTree;

    myTree.add(50);// add first(top) node
    myTree.add(50);// add duplicate
    myTree.add(30);// add smaller value
    myTree.add(40);// add another value()
    myTree.add(60);// add larger value
    myTree.add(60);// add its duplicate
    myTree.add(10);// adding values 
    myTree.add(20);
    myTree.add(5);
    myTree.add(80);
    myTree.add(100);




    cout << "add" << endl;
    myTree.inOrder();
    cout << endl;
    myTree.postOrder();
    cout << endl;
    myTree.preOrder();
    cout << endl;
    cout << "findParent(30): " << myTree.findParent(30)->key << endl;// should return 50
    cout << "findParent(5): " << myTree.findParent(5)->key << endl;// should return 10
    cout << "findParent(60): " << myTree.findParent(60)->key << endl;// should return 50
    cout << "findParent(100): " << myTree.findParent(100)->key << endl;// should return 80
    cout << "findParent(50): " << myTree.findParent(50) << endl;// should return nullptr (0)
    // myTree.killSwitch();
    
    cout << "remove(40): " << myTree.remove(80) << endl;
    myTree.inOrder();

    cout << "end program" << endl;
    return 0;
}
