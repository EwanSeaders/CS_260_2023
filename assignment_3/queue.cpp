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
        
        // checking if list is linked properly
        // cout << "front node data: " << frontNode->data << endl;
        // cout << "front node address: " << frontNode << endl;
        // cout << "front node pointer: " << frontNode->next << endl;

    }

    int dequeue() {
        node *current;
        current = front;
        // removes an element from the back of the queue
        // node *backNode;
        // for(current; current != nullptr; current->next) {
        //     // if(current == nullptr) {
        //     //     backNode = current;
        //     // current = current->next;
        //     cout << "current: " << current << endl;

        //     }
        while(current != nullptr) {
            // if(current == nullptr) {
            //     backNode = current;
            // current = current->next;
            
            // cout << "current: " << current << endl;
            current = current->next;
            }
        return current->data;
        // if(current == nullptr) {
        //     return current->data;
        //     delete current;
        // return -1;
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
    cout << "end program" << endl;
    return 0;
    
}