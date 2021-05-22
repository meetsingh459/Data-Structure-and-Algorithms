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

// INSERT NODE AFTER A GIVEN NODE
void insertAfter(Node* prev, int data){	
	if(prev == NULL) return;

	Node* node = new Node(data);
	node->next = prev->next;
	prev->next = node;
}

//INSERT NODE AT THE END OF LINKED LIST

void append(Node** head, int data){

	Node* node = new Node(data);
	
	if(*head == NULL){
		*head = node;
		return;
	}

	Node* last = *head;
	while(last->next != NULL) last = last->next;

	last->next = node;
	return;
}

//DELETION OF A NODE FROM LINKED LIST
void deletion(Node** head, int key){

	if(head == NULL) return;

	Node* node = *head; 	

	if(node-> data == key){
		*head = node->next;
		delete node;
		return;
	}

	Node* prev = NULL;

	while(node != NULL && node->data != key){
		prev = node;
		node = node->next;
	}

	if(node == NULL) return;
	prev->next = node->next;
}


//PRINT THE LINKED LIST
void printList(Node* node){
	while(node != NULL){
		cout << node->data << endl;
		node = node->next;
	}
}


int main(){

	Node* head = NULL;
 
  	// Insert 6.  So linked list becomes 6->NULL
  	append(&head, 6);
 
  	// Insert 7 at the beginning. So linked list becomes 7->6->NULL
  	push(&head, 7);
 
  	// Insert 1 at the beginning. So linked list becomes 1->7->6->NULL
  	push(&head, 1);

  	// Insert 4 at the end. So linked list becomes 1->7->6->4->NULL
  	append(&head, 4);
 
  	// Insert 8, after 7. So linked list becomes 1->7->8->6->4->NULL
  	insertAfter(head->next, 8);

  	cout << "Created Linked list is: \n";
  	printList(head);

  	deletion(&head, 6);

  	cout << "Linked list after deletion: \n";
  	printList(head);
 
  return 0;
}


1 -> 2 -> 3 -> 4 -> 5 -> 6 
