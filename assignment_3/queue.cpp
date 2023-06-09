#include <iostream>

// using std::cout;
// using std::endl;
using namespace::std;
struct node {
    int data;
    node *next;
};

class Queue{
private:
    /* data */
    node *front;
    node *back;
    int count = 0;
public:
    Queue() {
        node *front = nullptr;
        node *back = nullptr;
    };
    

    
    void enqueue(int newElem) {
        // adds an element to the front of the queue
        node *frontNode = new node{newElem, front};
        front = frontNode;
        count += 1;
        
        // checking if list is linked properly
        // cout << "back node data: " << backNode->data << endl;
        // cout << "back node address: " << backNode << endl;
        // cout << "back node pointer: " << backNode->next << endl;

    }

    int peek() { //peeks at element in the front of the queue
        node *current;
        current = front;
        
        while(current->next != nullptr) {
            
            cout << "current: " << current->data << endl;
            current = current->next;
            }
        back = current;
        if(back->next == nullptr) {
            return back->data;
        }
        return -1;
    }
    
    int dequeue() {
        node *current;
        node *previous;
        current = front;
        // removes an element from the back of the queue
        // node *backNode;
        while(current->next != nullptr) {
            // if(current == nullptr) {
            //     backNode = current;
            // current = current->next;
            
            previous = current;
            cout << "previous: " << previous->data << endl;
            current = current->next;
            cout << "current: " << current->data << endl;

            }
        // return current->data;
        back = current;
        // if (current == front) {
        //     return -1;
        // }
        if(back->next == nullptr) {
            return back->data;
            previous->next = nullptr;
            back = previous;
            free(current);
            
            // previous->next = nullptr;  
            
        }
        return -1;
        // }
    }

    // int dequeue() {
    //     node *current;
    //     current = front;
    //     // removes an element from the back of the queue
    //     // node *backNode;
    //     int temp = 0;
    //     while(temp < count) {
    //         // if(current == nullptr) {
    //         //     backNode = current;
    //         // current = current->next;
            
    //         previous = current;
    //         cout << "previous: " << previous->data << endl;
    //         current = current->next;
    //         cout << "current: " << current->data << endl;

    //         }
    //     // return current->data;
    //     back = current;
    //     // if (current == front) {
    //     //     return -1;
    //     // }
    //     if(back->next == nullptr) {
    //         return back->data;
    //         previous->next = nullptr;
    //         back = previous;
            
    //         // previous->next = nullptr;
            
            
    //     }
    //     return -1;
    //     // }
    // }
        
};


int main() {
    Queue myQueue;
    
    cout << "empty queue" << endl;
    cout << "enqueue" << endl;
    // myQueue.enqueue(30);
    myQueue.enqueue(31);
    myQueue.enqueue(32);
    myQueue.enqueue(33);
    cout << "peek: " << myQueue.peek() << endl;

    cout << "dequeue: " << myQueue.dequeue() << endl;
    cout << "dequeue: " << myQueue.dequeue() << endl;
    cout << "dequeue: " << myQueue.dequeue() << endl;

    cout << "peek: " << myQueue.peek() << endl;

    cout << "end program" << endl;
    return 0;
}