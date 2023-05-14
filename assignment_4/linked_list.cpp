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
    // Queue() {
    //     node *front = nullptr;
    //     node *back = nullptr;
    // };
    
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