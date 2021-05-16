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

bool reverse(Node* root, unordered_map<int , int>& mp, int data, int &h, int i){

    if(root == NULL) return 0;
    if(root->data == data){
        mp[i] = root->data;
        root->data = mp[h];
        h++;
        return 1;
    }

    mp[i] = root->data;
    bool left, right;
    left = reverse(root->left, mp, data, h, i+1);
    if(left == 0 ) right = reverse(root->right, mp, data, h, i+1);

    if( left || right ){
        root->data = mp[h];
        h++;
        return 1;
    }

    return 0;

}


void reversePath(Node* root, int data){

    unordered_map<int , int> mp;
    int h = 0;

    reverse(root, mp, data, h, 0);
}


int main(){

    Node *root = new Node(7);
    root->left = new Node(6);
    root->right = new Node(5);
    root->left->left = new Node(4);
    root->left->right = new Node(3);
    root->right->left = new Node(2);
    root->right->right = new Node(1);

    cout << "Before reversal: ";
    inorder(root);
    cout << endl;

    reversePath(root, 2);

    cout << "Afterv reversal: ";
    inorder(root);
    cout << endl;
    return 0;
}
