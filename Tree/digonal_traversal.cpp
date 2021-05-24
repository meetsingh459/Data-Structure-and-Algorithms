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

void digonal_traversal(Node* root){

  if(!root) return;

  queue<pair<Node*, int>> q;
  map<int, vector<Node*> > mp;

  q.push(make_pair(root, 0));

  while(!q.empty()){

    pair<Node*, int> p = q.front();
    q.pop();

    if(p.first->left) q.push(make_pair(p.first->left, p.second+1));
    if(p.first->right) q.push(make_pair(p.first->right, p.second));

    mp[p.second].push_back(p.first);
  }

  for(auto i = mp.begin(); i != mp.end(); i++){
    for(auto j = i->second.begin(); j != i->second.end(); j++){
        Node* node = *j;
        cout << node->data << " ";
    }
    cout << endl;
  }
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

    cout << "Digonal Traversal is: \n";
    digonal_traversal(root);

    return 0;
}

