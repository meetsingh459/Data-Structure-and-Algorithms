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

bool isbalanced(Node* root, int *h){

  if(!root){
    *h = 0;
    return 1;
  }

  int lh = 0, rh = 0;

  bool l = isbalanced(root->left, &lh);
  bool r = isbalanced(root->right, &rh);

  *h = (lh>rh?lh:rh)+1;

  if(abs(lh-rh)>1) return 0;
  return 1;
}


int main(){

    Node *root1 = new Node(3);
    root1->left = new Node(9);
    root1->right = new Node(20);
    root1->right->left = new Node(15);
    root1->right->right = new Node(7);

    int h = 0;

    if(isbalanced(root1, &h)) cout << "Tree 1 is balanced \n";
    else cout << "Tree 1 is not balanced \n";

    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(2);
    root2->left->left = new Node(3);
    root2->left->right = new Node(3);
    root2->left->left->left = new Node(4);
    root2->left->left->right = new Node(4);

    if(isbalanced(root2, &h)) cout << "Tree 2 is balanced \n";
    else cout << "Tree 2 is not balanced \n";

    return 0;
}

