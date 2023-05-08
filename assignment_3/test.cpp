#include <iostream>

using namespace::std;

struct node {
    int data;
    node* next;
};

struct node* front = NULL;
struct node* back = NULL;

void enqueue(int x) {
    node* current = new node();
    current->data = x;
    current->next = NULL;
    if(front == NULL && back == NULL) {
        front = back = current;
        return;
    }
    back->next = current;
    back = current;
}
int peek() {
    if (front == NULL) {
        return -9999999;
    }
    return front->data;
    
}

int dequeue() {
    node* temp = front;
    front = front->next;
    return temp->data;
    free(temp);

}

int main() {
    cout << "empty queue" << endl;
    cout << "enqueue" << endl;
    enqueue(30);
    enqueue(31);
    // cout << "enqueue success: " << endl;

    enqueue(32);
    enqueue(33);
    
    // cout << "enqueue success: " << endl;
    // cout << "peekBack: " << myQueue.peekBack() << endl;

    cout << "dequeue: " << dequeue() << endl;
    cout << "dequeue: " << dequeue() << endl;
    // cout << "dequeue: " << dequeue() << endl;

    cout << "peek: " << peek() << endl;

    // cout << "end program" << endl;
    return 0;
}