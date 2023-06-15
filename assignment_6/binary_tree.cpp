/*

tests:
    add():
        1.  test it with add the first node
        2. add a node that will go to the bottom left and right:
        3. add several nodes to be in the middle, some with only one child and some with 2
        4. add a duplicate node


    remove():
        1.  remove a node that has
            - 1 child
            - 2 children
            - no children
        2. remove top node
        3. remove last node in the list
        4. remove a node that is a right child
        5. remove a node that is a left child
        6. remove a node with a duplicate

*/









#include <iostream>
using std::cout;
using std::endl;


struct node {
    int key;
    node* left = nullptr;
    node* right = nullptr;
    // node* parent = nullptr;
};

class binaryTree{
private:
    node* top;

    node* newNode(int key) {
        node* new_node = new node();
        new_node->key = key;
        new_node->left = nullptr;
        new_node->right = nullptr;
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
        // if (del_ptr == nullptr) {del_ptr = top;}
        // if (del_ptr->right != nullptr) {killSwitch(del_ptr->right);}
        // if (del_ptr->left != nullptr) {killSwitch(del_ptr->left);}
        // if (del_ptr->right == nullptr && del_ptr->left == nullptr) {delete del_ptr;}
        // // delete[] top;
        // killSwitch(del_ptr->left), killSwitch
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
    
    // finds the first with a null right child: returns parent of null node
    node* findNullChild(node* startNode) {
        node* curr = startNode;
        // if (curr->left != nullptr && curr->right != nullptr) {
        //     curr = curr->left;
        while (curr->right != nullptr){curr = curr->right;}
        // }
        // else if (curr->right != nullptr) {return curr->right;}
        // // return curr;
        return curr;
    }
    
    // rearranges pointers if the node is a right child of the parent
    bool repointRight(node* curr, node* parent, node* del_node=nullptr) {
        bool myBool = false;
        if (del_node->left != nullptr) {
            curr = del_node->left;
            // cout << "A\n\n";
            myBool = true;
            parent->right = del_node->left;// poits the parents right node to the left subtree of delnode
            // cout << "right child 1\n\n";
            if (del_node->right != nullptr){
            // cout << "B\n\n";
                curr = findNullChild(curr);// finds the first right node in delnodes left subtree that is null
                curr->right = del_node->right;
            }
        }
        else if (del_node->right != nullptr){// if del node left was null but not right
            // cout << "C\n\n";
            myBool = true;
            parent->right = del_node->right;
        }
            // cout << "D\n\n";
        
        return myBool;
    }
// rearranges pointers if the node is a left child of the parent
bool repointLeft(node* curr, node* parent, node* del_node=nullptr) {
        bool myBool = false;
        if (del_node->left != nullptr) {// if the left child of del_node exists
            curr = del_node->left;
            // cout << "A\n";
            myBool = true;
            parent->left = del_node->left;// poits the parents right node to the left subtree of delnode
            // cout << "right child 1\n\n";
            if (del_node->right != nullptr){
            // cout << "B\n";
                curr = findNullChild(curr);// finds the first right node in delnodes left subtree that is null
                curr->right = del_node->right;
            }
        }
        else if (del_node->right != nullptr){// if del node left was null but not right
            // cout << "C\n\n";
            myBool = true;
            parent->left = del_node->right;
        }
            // cout << "D\n\n";
        
        return myBool;
    }
    
    int remove(int value) {
        node* parent;
        if (value != top->key){parent = findParent(value);}
        node* del_node;
        node* curr = del_node;
        node* temp;
        if (value == top->key) {// if the value is the top node
            del_node = top;
            temp = del_node;
            if (top->left != nullptr) {top = top->left;}
            else if (top->right != nullptr) {top = top->right;}
            else {top = nullptr;}
            delete del_node;
            return temp->key;
        }
        if (value <= parent->key){del_node = parent->left;}// set delnode to proper value
        if (value > parent->key){del_node = parent->right;}
        temp = del_node;
        if (del_node->key > parent->key) {// if the node to be deleted is a right child
            // cout << "right child in\n\n";
            if (repointRight(curr, parent, del_node) == false) {
                parent->right = nullptr;
            }
        }
        if (del_node->key <= parent->key) {// if the node to be deleted is a left child
            // cout << "left child in\n\n";
            if (repointLeft(curr, parent, del_node) == false) {
                parent->left = nullptr;
            }
        }
        delete del_node;
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
    myTree.add(90);




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
    
    myTree.inOrder();
    
    cout << "\nremove(80): " << myTree.remove(80) << endl;
    myTree.inOrder();
    cout << "\nremove(60): " << myTree.remove(60) << endl;
    myTree.inOrder();
    // cout << "\nremove(60): " << myTree.remove(60) << endl;
    // myTree.inOrder();
    cout << "\nremove(100): " << myTree.remove(100) << endl;
    myTree.inOrder();
    cout << "\nremove(50): " << myTree.remove(50) << endl;
    myTree.inOrder();
    cout << "\nremove(50): " << myTree.remove(50) << endl;
    myTree.inOrder();
    
    cout << "\nremove(40): " << myTree.remove(40) << endl;
    myTree.inOrder();
    cout << "\nremove(10): " << myTree.remove(10) << endl;
    myTree.inOrder();
    cout << "\nremove(20): " << myTree.remove(20) << endl;
    myTree.inOrder();
    cout << "\nremove(30): " << myTree.remove(30) << endl;
    myTree.inOrder();
    // cout << "\nremove(5): " << myTree.remove(5) << endl;
    // myTree.inOrder();


    cout << "\nend program" << endl;
    return 0;
}
