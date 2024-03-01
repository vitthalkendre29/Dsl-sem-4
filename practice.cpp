#include<iostream>
using namespace std;

class node{
    public:
    node* left;
    node* right;
    int data;
    bool lbit,rbit;
    node(int value): data(value),left(NULL),right(NULL),lbit(1),rbit(1) {}
};

class bt{
    node* root;

    node* insert(node* root,int value){
        if(root ==NULL){
            return new node(value);
        }
        if(value< root->data){
            root->left=insert(root->left,value);
            root->lbit=0;
        }else{
            root->right=insert(root->right,value);
            root->rbit=0;
        }
        return root;
    }
    void  inorder(node* root){
        if(root==NULL){
            return ;
        }else{
            inorder(root->left);
            cout<<"lbit is"<<root->lbit<<endl;
            cout<<"data is"<<root->data<<endl;
            cout<<"rbit is"<<root->rbit<<endl;
            inorder(root->right);
        }
    }
    
    public:

    bt():root(NULL){}
    
    void insert(int value){
        root=insert(root,value);
    }
    void inorder(){
        return inorder(root);
    }
    
};

int main(){
    bt b;
    b.insert(20);
    b.insert(30);
    b.insert(10);
    b.insert(5);
    b.insert(16);
    b.insert(17);
    b.insert(14);
    cout<<"\ninordertraversal"<<endl;
    b.inorder();
    
    return 0;
}