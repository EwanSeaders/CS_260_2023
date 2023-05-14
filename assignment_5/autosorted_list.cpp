#include <iostream>

using std::cout;
using std::endl;
// using namespace::std;
struct node {
    int data;
    struct node* next;
};

class linkedList{
private:
    /* data */
    node *front = nullptr;
    node *back = nullptr;
    int count = 0;
public:
    

    void print() {
        node* curr = front;
        while (curr != nullptr) {
            cout << curr->data << ", ";
            curr = curr->next;
        }
        cout << endl;
    }
    
    int remove(int index) { // removes an element from a specified index
        node* curr = front;
        node* prev = front;
        if (index < count) {
            if (index == 0) {
                front = front->next;
                curr->next = nullptr;
                if (count == 0) {
                    free(front);
                    count -= 1;
                }
            }
            while (index > 0) {
                prev = curr;
                curr = curr->next;
                index -= 1;
            }
            count -= 1;
            prev->next = curr->next;
            curr->next = nullptr;
            return curr->data;  
        }
        return -999999;
    }

    void add0(int value) {
        node* curr = front;
        curr = new node();
        curr->next = front;
        curr->data = value;
        front = curr;
        count += 1;
    }
    
    node* iterate(int index) { // iterates throught the list and returns the pointer to the node at specified index
        node* current = front;
        try {
            if (index > 0) {
                while (index > 0) {
                        current = current->next;
                        index -= 1;
                }
            throw 10;
            }
        }
        catch(...) {
            cout << "invalid index" << endl; 
        }
        // if (0 > index | index > count) {
        //     cout << "invalid index";
        // }
        return current;
    }
        
    void add(int value, int index) {
        if (index == 0) {
            add0(value);
            return;
        }
        node* curr = iterate(index-1);
        node* prev = curr;
        curr = curr->next;
        node* insert = new node();
        insert->data = value;
        
        prev->next = insert;
        prev->next->next = curr;
        count += 1;
    }

    int get(int index) {
        if (count < index <= count) {
            return iterate(index)->data;
        }
        return -999999;
    }
    
    int list_len() {
        return count;
    }
};


int main() {
    linkedList myList;
    
    cout << "end program" << endl;
    return 0;
}