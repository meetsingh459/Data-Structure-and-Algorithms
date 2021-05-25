#include<bits/stdc++.h>

using namespace std;

class Node{
    
    public:
    int data;
    Node *left, *right;

    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node *head = NULL, *last = NULL;

void btoDLL(Node* root){
  if(root == NULL) return;
  btoDLL(root->left);
  if(!last){
    head = root;
    last = root;
  }
  else{
    last->right = root;
    root->left = last;
    last = root;
  }
  btoDLL(root->right);
}

Node* binary_tree_to_ddl(Node* root){
  btoDLL(root);
  return head;
}

void printList(Node* node){
  while(node != NULL){
    cout << node->data << " ";
    node = node->right;
  }
}


int main(){

  Node* root = new Node(10);
  root->left = new Node(12);
  root->right = new Node(15);
  root->left->left = new Node(25);
  root->left->right = new Node(30);
  root->right->left = new Node(36);

  Node *head = binary_tree_to_ddl(root);
  cout << "Doubly LinkedList is: ";
  printList(head);

  return 0;
}
