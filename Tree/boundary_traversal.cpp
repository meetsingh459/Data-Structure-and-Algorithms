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

void left_boundary(Node* root, vector<int> &res){

  if(!root) return;

  queue<Node*> q;
  q.push(root);

  while(!q.empty()){

    Node* node = q.front();
    q.pop();

    if(node->left) q.push(node->left);
    else if(node->right) q.push(node->right);

    if(node->left || node->right) res.push_back(node->data);
  }
}


void bottom_boundary(Node *root, vector<int> &res){
  if(!root) return;

  bottom_boundary(root->left, res);
  if(!root->left && !root->right) res.push_back(root->data);
  bottom_boundary(root->right, res);
}

void right_boundary(Node* root, vector<int> &res){

  if(!root) return;

  queue<Node*> q;
  q.push(root);
  stack<int> s;

  while(!q.empty()){

    Node* node = q.front();
    q.pop();

    if(node->right) q.push(node->right);
    else if(node->left) q.push(node->left);

    if(node->left || node->right) s.push(node->data);
  }

  while(!s.empty()){
    res.push_back(s.top());
    s.pop();
  }
}

void boundary_traversal(Node* root){

  vector<int> res;

  if(root) res.push_back(root->data);

  left_boundary(root->left, res);
  bottom_boundary(root, res);
  right_boundary(root->right, res);

  for(auto i : res) cout << i << " ";
}

int main(){

    Node *root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->right->left = new Node(6);
    root->right->right = new Node(14);
    root->right->left->left = new Node(4);
    root->right->left->right = new Node(7);
    root->right->right->left = new Node(13);

    cout << "Boundary Traversal is: ";
    boundary_traversal(root);

    return 0;
}



