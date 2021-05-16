#include<bits/stdc++.h>

using namespace std;

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


bool check_complete_binary_tree(Tree* root){

    queue<Tree*> q;
    q.push(root);

    bool full_node = 1;

    while(!q.empty()){

        Tree* node = q.front();
        q.pop();

        if(!node->left && node->right) return 0;
        if(!node->left && !node->right) break;
            
        if(node->left) q.push(node->left);
        
        if(node->right) q.push(node->right);
        else break;
    }

    while(!q.empty()){
        Tree* node = q.front();
        if(node->left || node->right) return 0;
        q.pop();
    }

    return 1;
}



int main(){

    Tree* root1 = new Tree(1);
    root1->left = new Tree(2);
    root1->right = new Tree(3);
    root1->left->left = new Tree(4);
    root1->left->right = new Tree(5);
    root1->right->right = new Tree(6);
    
    if(check_complete_binary_tree(root1)) cout << "Tree 1 is Complete Binary Tree \n";
    else cout << "Tree 1 is Not Complete Binary Tree \n"; 


    Tree* root2 = new Tree(1);
    root2->left = new Tree(2);
    root2->right = new Tree(3);
    root2->left->left = new Tree(4);
    root2->left->right = new Tree(5);
    root2->right->left = new Tree(6);
    
    if(check_complete_binary_tree(root2)) cout << "Tree 2 is Complete Binary Tree \n";
    else cout << "Tree 2 is Not Complete Binary Tree \n"; 


    return 0;
}
