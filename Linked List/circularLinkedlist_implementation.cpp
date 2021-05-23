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


void push(Node** head, int data){
  Node *node = new Node(data);
  Node *last = *head;
  node->next = *head;
  if(last){
    while(last->next != *head) last = last->next;
    last->next = node;
  }
  else node->next = node;

  *head = node; 
}


void printList(Node* head){
  Node* node = head;
  do{
    cout << node->data << " ";
    node = node->next;
  }while(node != head);
}

int main(){

  Node *head = NULL;
  push(&head, 10);
  push(&head, 8);
  push(&head, 7);
  push(&head, 5);
  push(&head, 2);

  cout << "Circular List is: ";
  printList(head);
  return 0;
}
