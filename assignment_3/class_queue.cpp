#include <iostream>

using std::cout;
using std::endl;
// using namespace::std;
struct node { // nodes for the linked queue
    int data;
    struct node* next;
};

class Queue{ // linked queue data structure
private:
    /* data */
    node *front = nullptr;
    node *back = nullptr;
    int count = 0;
public:
    
    void enqueue(int x) { // adds an element to the back of the queue
        // create a new node (current) and assign it new values
        node* current = new node();
        current->data = x;
        current->next = nullptr;
        // checks for empty list and sets values = to each other to initialize
        if(front == nullptr && back == nullptr) {
            front = back = current;
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
        // removes the element from the queue
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
};


int main() {
    Queue myQueue;
    // empty list dequeue and peek
    cout << "empty queue" << endl;
    cout << "dequeue empty: " << myQueue.dequeue() << endl;
    cout << "peekBack empty: " << myQueue.peekFront() << endl;
    // enqueue items test
    cout << "enqueue: " << endl;
    myQueue.enqueue(30);
    cout << "enqueue: " << endl;
    myQueue.enqueue(31);
    cout << "enqueue: " << endl;
    myQueue.enqueue(32);
    cout << "enqueue: " << endl;
    myQueue.enqueue(33);
    cout << "enqueue: " << endl;
    myQueue.enqueue(34);
    
    // cout << "enqueue success: " << endl;
    cout << "peekBack: " << myQueue.peekFront() << endl;

    cout << "dequeue: " << myQueue.dequeue() << endl;
    cout << "dequeue: " << myQueue.dequeue() << endl;
    cout << "dequeue: " << myQueue.dequeue() << endl;

    cout << "peekBack: " << myQueue.peekFront() << endl;
    
    // dequeue through the back of the list
    cout << "dequeue: " << myQueue.dequeue() << endl;
    cout << "dequeue: " << myQueue.dequeue() << endl;
    cout << "dequeue: " << myQueue.dequeue() << endl;
    
    cout << "peekBack: " << myQueue.peekFront() << endl;
    
    // add another element to the emptied queue to check for back ptr correctness
    // cout << "enqueue: " << endl;
    // myQueue.enqueue(34);
    cout << "enqueue: " << endl;
    myQueue.enqueue(34);
    cout << "peekBack: " << myQueue.peekFront() << endl;



    // cout << "peek: " << myQueue.peek() << endl;

    // cout << "end program" << endl;
    return 0;
}