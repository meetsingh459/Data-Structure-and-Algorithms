#include<bits/stdc++.h>

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

void push(Node** head, int data){

    Node* node = new Node(data);
    node->next = *head;
    *head = node;
}

class Tree{
    
    public:
    int data;
    Tree *left, *right;

    Tree(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void inorder(Tree* root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void printList(Node* node){
    while(node != NULL){
        cout << node->data << " ";
        node = node->next;
    }
}

Tree* convertBST(Node* head){

    Tree* root = new Tree(head->data);
    queue<Tree*> q;

    q.push(root);

    head = head->next;
    while(head){

        Tree *node = q.front();
        q.pop();
        
        node->left = new Tree(head->data);
        q.push(node->left);
        head = head->next;

        if(head){
            node->right = new Tree(head->data);
            q.push(node->right);
            head = head->next;
        }
    }

    return root;
}



int main(){

    Node *head = NULL;
    push(&head, 36);  
    push(&head, 30);
    push(&head, 25);
    push(&head, 15);
    push(&head, 12);
    push(&head, 10); 

    cout << "Linked List: ";
    printList(head);

    Tree* root = convertBST(head);
    cout << "\nBinary search tree: ";
    inorder(root);

    return 0;
}
