#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int a){
        data = a;
        next = NULL;
    }
};

// INSERT NODE AT FRONT OF LINKED LIST
void push(Node** head, int data){

    Node* node = new Node(data);
    node->next = *head;
    *head = node;
}

void segerate_even_and_odd(Node** head){

  Node* last = *head;

  while(last->next) last = last->next;

  Node* node = *head , *prev = NULL, *end = last;

  while(node != end){

    if(node->data % 2){
      last->next = node;
      if(prev) prev->next = node->next;

      if(node == *head ){
        *head = node->next;
        node->next = NULL;
        node = *head;
      }
      else{
        node->next = NULL;
        node = prev->next;
      }
      
      last = last->next;
    }
    else{
      prev = node;
      node = node->next;
    }
  }

  if(node->data % 2){
    last->next = node;
    if(prev) prev->next = node->next;

    if(node == *head ) *head = node->next;
    node->next = NULL;
  }

}

//PRINT THE LINKED LIST
void printList(Node* node){
    while(node != NULL){
        cout << node->data << " ";
        node = node->next;
    }
}


int main(){

    Node* head = NULL;
    push(&head, 6);
    push(&head, 7);
    push(&head, 1);
    push(&head, 4);
    push(&head, 5);
    push(&head, 10);
    push(&head, 12);
    push(&head, 8);
    push(&head, 15);
    push(&head, 17);



    cout << "Before: ";
    printList(head);
    segerate_even_and_odd(&head);
    cout << "\nAfter  : ";
    printList(head);
 
  return 0;
}

