#include <iostream>

using std::cout;
using std::endl;
// using namespace::std;
struct node {
    int data;
    struct node* next;
};

class autosortedList{
private:
    /* data */
    node *front = nullptr;
    node *back = nullptr;
    int count = 0;
public:

    // linked list helper functions
    void print() {// prints elements of the list to terminal
        node* curr = front;
        while (curr != nullptr) {
            cout << curr->data << ", ";
            curr = curr->next;
        }
        cout << endl;
    }
    
    int list_len() {// returns the number of values in the list based on the private count variable
        return count;
    }

    node* iterate(int index) { // iterates throught the list and returns the pointer to the node at specified index
        node* current = front;
        try {// starts code to check for errors
            if (index > 0) {// iterates through list
                while (index > 0) {
                        current = current->next;
                        index -= 1;
                }
            throw 10;
            }
        }
        catch(...) { // throws invalid index error to terminal and continues
            cout << "invalid index" << endl; 
        }
        return current;
    }
    bool insertFrontNull(int value) {
        if ((front != nullptr) && (value <= front->data)) {
            node* temp = new node();
            temp->data = value;
            temp->next = front;
            front = temp;
            count += 1;
            return true;
        }
        return false;
    }
    
    bool insertFront(int value) {// inserts element at front of the list
            
            if (front == nullptr) {// sets front if the list is empty
                front = new node();
                front->data = value;
                front->next = nullptr;
                count += 1;
                return true;
            }
            return false;
    }
    
    // void insert(int value) {// inserts a value into its position in the list from least to greatest
    //     if (insertFrontNull(value) | insertFront(value)){
    //         return;
    //     }
    //     node* current = front;
    //     // node* prev;
    //     while(value > current->data) {
    //         current = current->next;
    //         if (value >= current->data) {
    //             node* insert = new node();
    //             insert->data = value;
    //             if (current->next != nullptr){
    //                 current = current->next;
    //             }
    //             insert->next = current->next;
    //             current->next = insert;
                
    //             return;
    //         }
    //     }
        
    // }

    void insert(int value) {// inserts a value into its position in the list from least to greatest
        node* current = front;
        node* insert = new node();
        if (insertFrontNull(value) | insertFront(value)){
            return;
        }
        insert->data = value;
        while (current->next->data >= value) {
            if (current->next == nullptr){
                current->next = insert;
                insert->next = nullptr;
            }
            current = current->next;

        }
    }

};

int main() {
    autosortedList myList;
    myList.insert(4);
    myList.print();


    myList.insert(5);
    myList.print();
    myList.insert(3);
    myList.print();

    myList.insert(22);
    myList.print();

    myList.insert(22);
    myList.print();

    myList.insert(1);
    myList.print();

    myList.insert(7);
    myList.print();

    myList.insert(7);
    myList.print();

    myList.insert(8);
    myList.print();
    myList.insert(0);
    myList.print();
    
    cout << "end program" << endl;
    return 0;
}