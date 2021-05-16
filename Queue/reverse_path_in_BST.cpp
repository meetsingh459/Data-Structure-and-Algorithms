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

void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

bool reverse(Node* root, queue<int>& q, int data){

    if(root == NULL) return 0;
    if(root->data == data){
        q.push(root->data);
        root->data = q.front();
        q.pop();
        return 1;
    }

    q.push(root->data);
    if(root->data > data ){
        bool left = reverse(root->left, q, data);
        if(left){
            root->data = q.front();
            q.pop();
            return 1;
        }
    }
    else if(root->data < data){
        bool right = reverse(root->right, q, data);
        if(right){
            root->data = q.front();
            q.pop();
            return 1;
        }
    }

    return 0;
}


void reversePath(Node* root, int data){
    queue<int> q;
    reverse(root, q, data);
}


int main(){

    Node *root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

       //        50
       //     /     \
       //    30      70
       //   /  \    /  \
       // 20   40  60   80 

    cout << "Tree 1 Before reversal: ";
    inorder(root);
    cout << endl;

    reversePath(root, 70);

    cout << "Tree 1 Afterv reversal: ";
    inorder(root);
    cout << endl << endl;

    Node *root1 = new Node(8);
    root1->left = new Node(3);
    root1->right = new Node(10);
    root1->left->left = new Node(1);
    root1->left->right = new Node(6);
    root1->right->right = new Node(14);
    root1->left->right->left = new Node(4);
    root1->left->right->right = new Node(7);
    root1->right->right->left = new Node(13);

       //        8
       //     /     \
       //    3       10
       //   /  \       \
       // 1    6         14
       //     /  \      /
       //    4    7    13

    cout << "Tree 2 Before reversal: ";
    inorder(root1);
    cout << endl;

    reversePath(root1, 13);

    cout << "Tree 2 Afterv reversal: ";
    inorder(root1);
    cout << endl;

    return 0;
}
