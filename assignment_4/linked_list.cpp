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
    // queue functions
    void enqueue(int x) { // adds an element to the back of the queue
        // create a new node (current) and assign it new values
        node* current = new node();
        current->data = x;
        current->next = nullptr;
        // checks for empty list and sets values = to each other to initialize
        if(front == nullptr && back == nullptr) {
            front = back = current;
            count += 1;
            return;
        }
        back->next = current;
        back = current;
        count += 1;
    }

    int dequeue() { // removes an element from the front of the queue
        if(front == nullptr) {
            back = nullptr;
            return -9999999;
        }
        count -= 1;
        node* temp = front;
        front = front->next;
        return temp->data;
        free(temp);
    }

    int peekFront() { // returns element at the front of the queue
        if (front == nullptr && back == nullptr) {
            
            return -9999999;
        }
        return front->data;
    }

    int peekBack() {// returns element at the back of the queue
        if (back == nullptr && back == nullptr) {
            return -9999999;
        }
        return back->data;
    }
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

    void add0(int value) {// helper for main add finction.  adds a value to index 0
        node* curr = front;
        curr = new node();
        curr->next = front;
        curr->data = value;
        front = curr;
        count += 1;
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
    // required linked list functions
    int remove(int index) { // removes an element from a specified index and returns the value
        node* curr = front;
        node* prev = front;
        if (index < count) { // ensures index is within range of list
            if (index == 0) { //executes case for if index is 0
                front = front->next;
                curr->next = nullptr;
                if (count == 0) {// removes the first element
                    free(front);
                    count -= 1;
                }
            }
            while (index > 0) { // iterates throuth the list until reaches desired index
                prev = curr;
                curr = curr->next;
                index -= 1;
            }
            // removes the element from the list by moveing pointers
            count -= 1;
            prev->next = curr->next;
            curr->next = nullptr;
            return curr->data;
        }
        return -999999;
    }

    void add(int value, int index) {// adds an element to any point of the linked list
        if (index == 0) {// executes code to insert element at the front of the list if index is zero
            add0(value);
            return;
        }
        // sets current and previous to the proper values using iterate function
        node* curr = iterate(index-1);
        node* prev = curr;
        curr = curr->next;
        node* insert = new node();// creates the new node to be inserted
        insert->data = value;
        //resets pointers to the proper elements
        prev->next = insert;
        prev->next->next = curr;
        count += 1;
    }

    int get(int index) {// gets a specified element from an index
        if (count < index <= count) {// ensures index is within existing range
            return iterate(index)->data;
        }
        return -999999;
    }
};


int main() {
    linkedList myList;
    
    myList.enqueue(5);
    cout << "iterate function: " << myList.iterate(0)->data << endl;

    myList.enqueue(4);
    myList.enqueue(3);
    myList.enqueue(2);
    myList.enqueue(1);
    myList.print();
    // cout << "remove(0): " << myList.remove(0) << endl;
    cout << "remove(1): " << myList.remove(1) << endl;
    myList.print();
    cout << "list length: " << myList.list_len() << endl;

    cout << "remove(2): " << myList.remove(2) << endl;
    myList.print();
    cout << "list length: " << myList.list_len() << endl;

    cout << "remove(3): " << myList.remove(3) << endl;
    myList.print();
    cout << "list length: " << myList.list_len() << endl;

    cout << "remove(0): " << myList.remove(0) << endl;
    myList.print();
    cout << "list length: " << myList.list_len() << endl;

    cout << "remove(3): " << myList.remove(3) << endl;
    myList.print();
    cout << "list length: " << myList.list_len() << endl;

    cout << "remove(0): " << myList.remove(0) << endl;
    myList.print();
    cout << "list length: " << myList.list_len() << endl;

    cout << "remove(0): " << myList.remove(0) << endl;
    myList.print();
    cout << "list length: " << myList.list_len() << endl;

    cout << "remove(0): " << myList.remove(0) << endl;
    myList.print();
    cout << "list length: " << myList.list_len() << endl;

    cout << "iterate function: " << myList.get(3) << endl;
    
    
    myList.add0(42);
    myList.add0(41);
    myList.add0(40);
    myList.add0(39);
    myList.print();
    cout << "list length: " << myList.list_len() << endl;

    cout << "iterate function: " << myList.get(3) << endl;

    myList.add(99, 2);
    myList.add(20,0);
    myList.print();
    cout << "list length: " << myList.list_len() << endl;


    cout << "end program" << endl;
    return 0;
}