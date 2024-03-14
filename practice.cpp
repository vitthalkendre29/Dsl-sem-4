#include<iostream>
using namespace std;

class node{
    public:
    node *left;
    node *right;
    int data;
};

class binarytree{
    public:
    node* root;
    void insert(node*,node*);
    void inordertraversal(node*);
    binarytree(){root=NULL;}
};

void binarytree:: insert(node*root,node*temp){
    if(root==NULL){
        root=temp;
    }
    if (root->data>temp->data){
        if(root->right==NULL){
            root->right=temp;
        }else{
            insert(root->right,temp);
        }
    }
    if (root->data<temp->data){
        if(root->left==NULL){
            root->left=temp;
        }else{
            insert(root->left,temp);
        }
    }
}

void binarytree::inordertraversal(node* root){
    if(root==NULL){
        return;
    }else{
        inordertraversal(root->left);
        cout<<root->data<<endl;
        inordertraversal(root->right);
    }
}

int main(){

}