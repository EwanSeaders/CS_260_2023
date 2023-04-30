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
    node *front, *back;
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
        // cout << "front node data: " << frontNode->data << endl;
        // cout << "front node address: " << frontNode << endl;
        // cout << "front node pointer: " << frontNode->next << endl;

    }

    int dequeue() {
        node *current;
        // node *previous;
        current = front;
        // removes an element from the back of the queue
        // node *backNode;
        while(current->next != nullptr) {
            // if(current == nullptr) {
            //     backNode = current;
            // current = current->next;
            
            cout << "current: " << current->data << endl;
            // previous = current;
            current = current->next;
            }
        // return current->data;
        back = current;
        // if (current == front) {
        //     return -1;
        // }
        if(back->next == nullptr) {
            return back->data;
            
            // previous->next = nullptr;
            
            
        }
        return -1;
        // }
    }

    int peek() {
        return 0;
    }
};


int main() {
    Queue myQueue;
    
    cout << "empty queue" << endl;
    cout << "enqueue" << endl;
    myQueue.enqueue(30);
    myQueue.enqueue(31);
    myQueue.enqueue(32);
    myQueue.enqueue(33);

    cout << "dequeue: " << myQueue.dequeue() << endl;
    cout << "dequeue: " << myQueue.dequeue() << endl;
    cout << "dequeue: " << myQueue.dequeue() << endl;
    cout << "end program" << endl;
    return 0;
}