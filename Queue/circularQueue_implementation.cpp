#include<iostream>

using namespace std;

class Queue{
    public:
        int rear, front;
        int size;
        int *arr;

        Queue(int s){
            rear = front = -1;
            size = s;
            arr = new int[s];
        }

        void enqueue(int data);
        void dequeue();
        int Front();
        bool isEmpty();
};

void Queue::enqueue(int data){

    if(front == 0 && rear == size-1) return;
    if(rear == front-1) return;

    rear = (rear+1)%size;
    if(front == -1) front = rear;
    arr[rear] = data;
}

void Queue::dequeue(){

    if(front == -1) return;

    int data = arr[front];
    arr[front] = -1;
    if(front == rear)
        front = rear = -1;
    else front = (front+1)%size;

    cout << "Deleted value is: " << data << endl;
}

int Queue::Front(){
    return (front == -1)? -1: arr[front];
}

bool Queue::isEmpty(){
    return (front == -1)? 1: 0;
}


int main(){

    Queue q(5);
    q.enqueue(14);
    q.enqueue(22);
    q.enqueue(13);
    q.enqueue(-6);

    cout << "Queue Front: " << q.Front() << endl;

    q.dequeue();

    cout << "Queue Front: " << q.Front() << endl;
    
    q.dequeue();

    cout << "Queue Front: " << q.Front() << endl;
    q.enqueue(30);
    q.enqueue(33);
    q.enqueue(44);
    q.enqueue(49);

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    cout << "Queue Front: " << q.Front() << endl;

    q.dequeue();
    q.dequeue();
    return 0;
}
