#include<bits/stdc++.h>

using namespace std;

class Stack{

    queue<int> q;
    public:
        void push(int data);
        void pop();
        int top();
};

void Stack::push(int data){

    int s = q.size();
    q.push(data);

    for (int i = 0; i < s; ++i){
        q.push(q.front());
        q.pop();
    }
}

void Stack::pop(){
    if(q.empty()) return;
    q.pop();
}

int Stack::top(){
    return (q.empty())? -1: q.front();
}


int main(){

    Stack s;
    s.push(30);
    s.push(20);

    cout << "Top of stack is: " << s.top() << endl;

    s.pop();
    cout << "Top of stack is: " << s.top() << endl;

    s.push(25);
    cout << "Top of stack is: " << s.top() << endl;

    return 0;
}
