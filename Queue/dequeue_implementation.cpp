#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next, *prev;

        Node(int data){
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
};


class deQueue{
    public:
        Node *rear, *front;

        deQueue(){
            rear = front = NULL;
        }

        void enqueueFront(int data);
        void enqueueRear(int data);
        void dequeueFront();
        void dequeueRear();
        bool isEmpty();
        int Front();
        int Rear();
};


void deQueue::enqueueFront(int data){

    Node* node = new Node(data);
    if(front == NULL){
        front = rear = node;
        return;
    }

    node->next = front;
    front->prev = node;
    front = node;
}

void deQueue::enqueueRear(int data){

    Node* node = new Node(data);
    if(rear == NULL){
        front = rear = node;
        return;
    }

    rear->next = node;
    node->prev = rear;
    rear = node;
}

void deQueue::dequeueFront(){

    if(front == NULL) return;

    Node* node = front;
    front = front->next;
    if(front == NULL) rear = NULL;  
    else front->prev = NULL;
    delete node;
}

void deQueue::dequeueRear(){

    if(rear == NULL) return;

    Node* node = rear;
    rear = rear->prev;
    if(rear == NULL) front = NULL;
    else rear->next = NULL;  
    delete node;
}


bool deQueue::isEmpty(){
    if(rear == NULL && front == NULL) return 1;
    return 0;  
}


int deQueue::Front(){
    return (front == NULL)? -1: front->data;
}

int deQueue::Rear(){
    return (rear == NULL)? -1: rear->data;
}

int main(){

    deQueue q;
    q.enqueueRear(5);
    q.enqueueRear(10);

    cout << "Queue Front: " << q.Front() << endl;
    cout << "Queue Rear: " << q.Rear() << endl; 
    
    q.dequeueRear();
    
    cout << "Queue Front: " << q.Front() << endl;
    cout << "Queue Rear: " << q.Rear() << endl; 
    
    q.enqueueFront(15);
    
    cout << "Queue Front: " << q.Front() << endl;
    cout << "Queue Rear: " << q.Rear() << endl; 

    q.enqueueFront(50);

    cout << "Queue Front: " << q.Front() << endl;
    cout << "Queue Rear: " << q.Rear() << endl;   

    return 0;
}
