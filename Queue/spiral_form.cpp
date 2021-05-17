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


void spiral_traversal(Node* root){

    deque<Node*>  q;
    q.push_back(root);

    vector<int> res;
    res.push_back(root->data);
    bool ltr = 1;

    while(!q.empty()){

        int n = q.size();
        for(int i = 0; i < n; i++){

            Node *node;
            if(ltr){
                node = q.back();
                if(node->left) q.push_front(node->left);
                if(node->right) q.push_front(node->right);

                if(node->left) res.push_back(node->left->data);
                if(node->right) res.push_back(node->right->data);

                q.pop_back();
            }
            else{
                node = q.front();
                if(node->left) q.push_back(node->left);
                if(node->right) q.push_back(node->right);

                if(node->right) res.push_back(node->right->data);
                if(node->left) res.push_back(node->left->data);
                

                q.pop_front();
            }
            ltr = !ltr;
        }
    }

    for(int i = 0; i < res.size(); i++) cout << res[i] << " ";
}


int main(){

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);

    cout << "Spiral Traversal: ";
    spiral_traversal(root);

    return 0;
}
