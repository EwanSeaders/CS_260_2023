#include <iostream>

// using std::cout;
// using std::endl;
using namespace::std;
struct node {
    int data;
    node *next;
};

class Queue
{
private:
    /* data */
    node *front;
    node *back;
    int count = 0;
public:
    Queue() {
        front = nullptr;
        back = nullptr;
    };
    

    
    void enqueue(int newElem) {
        // adds an element to the front of the queue
        node *frontNode = new node{newElem, front};
        front = frontNode;
        count += 1;

    }

    int dequeue() {
        node *current;
        current = front->next;
        // removes an element from the back of the queue
        node *backNode;
        for(current; current != nullptr; current->next) {
            if(current == nullptr) {
                backNode = current;
            }
        return backNode->data;
        delete backNode;
        }

        return -1;
    }

    int peek() {
        return 0;
    }
};


int main() {
    Queue myQueue;
    
    cout << "empty queue" << myQueue << endl;
    cout << "enqueue" << endl;
    myQueue.enqueue(30);
    cout << "dequeue: " << myQueue.dequeue() << endl;
    cout << "end program" << endl;
    return 0;
    
}