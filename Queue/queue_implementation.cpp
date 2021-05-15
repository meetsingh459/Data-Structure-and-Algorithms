#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};


class Queue{
    public:
        Node *rear, *front;

        Queue(){
            rear = front = NULL;
        }

        void enqueue(int data);
        void dequeue();
        bool isEmpty();
        int Front();
        int Rear();
};

void Queue::enqueue(int data){

    Node* node = new Node(data);
    if(rear == NULL){
        front = rear = node;
        return;
    }

    rear->next = node;
    rear = node;
}


void Queue::dequeue(){

    if(front == NULL) return;

    Node* node = front;
    front = front->next;
    if(front == NULL) rear = NULL;  

    delete node;
}


bool Queue::isEmpty(){
    if(rear == NULL && front == NULL) return 1;
    return 0;  
}


int Queue::Front(){
    return (front == NULL)? -1: front->data;
}

int Queue::Rear(){
    return (rear == NULL)? -1: rear->data;
}

int main(){

    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.dequeue();
    q.dequeue();
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.dequeue();

    cout << "Queue Front: " << q.Front() << endl;
    cout << "Queue Rear: " << q.Rear();   


    return 0;
}
