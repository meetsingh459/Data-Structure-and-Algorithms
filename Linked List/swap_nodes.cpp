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

//10->15->12->13->20->14,  x = 12, y = 20

void swap_node(Node** head, int x, int y){

    Node *nodex, *prevx, *nodey, *prevy;

    nodex = nodey = *head;
    prevx = prevy = NULL;

    Node *node = *head, *prev = NULL;

    while(node){
        if(node->data == x){
            prevx = prev;
            nodex = node;
        }

        if(node->data == y){
            prevy = prev;
            nodey = node;
        }

        prev = node;
        node = node->next;
    }
    
    if(prevx) prevx->next = nodey;
    else *head = nodey; 

    if(prevy) prevy->next = nodex;
    else *head = nodex;
    
    Node *temp = nodex->next;
    nodex->next = nodey->next;
    nodey->next = temp;

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
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    
    

    cout << "Created Linked list is: ";
    printList(head);
    swap_node(&head, 1, 7);
    cout << "\nLinked list after swapping nodes: ";
    printList(head);
 
  return 0;
}


//1 -> 2 -> 3 -> 4 -> 5 -> 6 
