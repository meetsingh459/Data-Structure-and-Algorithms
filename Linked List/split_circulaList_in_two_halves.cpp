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


Node* two_halves(Node** head){
  
  Node *slow = *head, *fast = *head;

  while(fast->next != *head && fast->next->next != *head){
    slow = slow->next;
    fast = fast->next->next;
  } 

  if(fast->next != *head) fast = fast->next;
    
  Node* mid = slow->next;
  slow->next = *head;
  fast->next = mid;

  return mid;
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
  push(&head, 1);

  cout << "Circular List is: ";
  printList(head);

  Node* mid = two_halves(&head);

  cout << "\nCircular List 1 is: ";
  printList(head);

  cout << "\nCircular List 2 is: ";
  printList(mid);
  return 0;
}
