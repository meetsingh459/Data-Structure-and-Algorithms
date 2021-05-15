#include<iostream>

using namespace std;

class kQueues{
    int n, k, free;
    int *arr, *front, *rear, *next;
    public:
        kQueues(int n, int k);
        void enqueue(int data, int qn);
        void dequeue(int qn);
        void Front(int qn);
        bool isfull() { return free == -1; }
        bool isEmpty(int qn) { return front[qn] == -1; }
};

kQueues::kQueues(int n, int k){

    this->n = n;
    this->k = k;
    free = 0;

    arr = new int[n];
    next = new int[n];
    front = new int[k];
    rear = new int[k];

    for(int i = 0; i < k; i++) front[i] = -1;
    for(int i = 0; i < n-1; i++) next[i] = i+1;
    next[n-1] = -1;
}

void kQueues::enqueue(int data, int qn){

    if(isfull()) return;

    int i = free;
    free = next[i];

    if(isEmpty(qn)) front[qn] = i;
    else next[rear[qn]] = i;

    next[i] = -1;
    rear[qn] = i;
    arr[i] = data;
}

void kQueues::dequeue(int qn){

    if(isEmpty(qn)) return;

    int i = front[qn];
    front[qn] = next[i];

    next[i] = free;
    free = i;
}

void kQueues::Front(int qn){
    if(isEmpty(qn)) return;
    cout << "Front of Queue " << qn << " is: " << arr[front[qn]] << endl;
}

int main(){

    int k = 3, n = 10;
    kQueues q(n, k);

    q.enqueue(15, 2);
    q.enqueue(45, 2);

    q.enqueue(17, 1);
    q.enqueue(39, 1);
    q.enqueue(49, 1);

    q.enqueue(11, 0);
    q.enqueue(9, 0);
    q.enqueue(7, 0);    

    q.Front(0);
    q.Front(1);
    q.Front(2);

    q.dequeue(0);
    q.Front(0);
    
    q.dequeue(1);
    q.Front(1);
    
    q.dequeue(1);
    q.Front(1);
    
    q.dequeue(0);
    q.Front(0);

    q.dequeue(2);
    q.Front(2);

    return 0;
}
