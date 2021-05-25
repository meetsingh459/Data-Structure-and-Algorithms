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

void levelorder(Node* root){
  if(!root) return;
  queue<Node*> q;
  q.push(root);
  while(!q.empty()){
    Node* node = q.front();
    q.pop();

    if(node->left) q.push(node->left);
    if(node->right) q.push(node->right);

    cout << node->data << " ";

  }
}

// 4(2(3)(1))(6(5))

Node* construct_binary_tree(string str){

  if(str.size() == 0) return NULL;

  int i = 0;
  int num = 0;
  while( i < str.size() && str[i] != '(' && str[i] != ')' ){
    num = num*10 + (str[i] - '0');
    i++;
  }

  stack<Node*> s;
  Node* root = new Node(num);
  s.push(root);

  while( i < str.size() ){
    Node *node = s.top();

    if(str[i] == '(') i++;
    else if(str[i] == ')'){ 
      i++;
      s.pop();
    }
    else{

      num = 0;
      while( i < str.size() && str[i] != '(' && str[i] != ')' ){
        num = num*10 + (str[i] - '0');
        i++;
      }

      if(!node->left){
        node->left = new Node(num);
        s.push(node->left);
      }
      else if(!node->right){
        node->right = new Node(num);
        s.push(node->right);
      }
    }
  }

  return root;
}

int main(){

  string str = "4(2(3)(1))(6(5))";
  Node *root = construct_binary_tree(str);
  cout << "Binary Tree is: ";
  levelorder(root);
  return 0;
}
