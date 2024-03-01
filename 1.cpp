#include <iostream>
using namespace std;

class BinaryTree {
private:
    struct Node {
        int value;
        Node* left;
        Node* right;

        Node(int val) : value(val), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void insert(Node* &root, int val) {
        if (root == nullptr) {
            root = new Node(val);
        } else {
            if (val < root->value) {
                insert(root->left, val);
            } else {
                insert(root->right, val);
            }
        }
    }

    void inorderTraversal(Node* root) {
        if (root == nullptr) 
            return;
        else{
            inorderTraversal(root->left);
            cout<< root->value;
            inorderTraversal(root->right);
        }
    }
    
    void search(Node* root){
    	while (root->left!=nullptr)
    		root=root->left;
    	cout<<"\nsmallest node is"<<root->value;
    }
    
    int contmaxnode(Node* root) {
    if (root == nullptr) // Base case: empty tree
        return 0;
    else {
        // Recursively find the maximum depth of left and right subtrees
        int left_depth = contmaxnode(root->left);
        int right_depth = contmaxnode(root->right);
        
        // Return the maximum depth among the left and right subtrees, plus 1 for the current node
        return max(left_depth, right_depth) + 1;
    }
}
    void searchbykey(Node* root,int key){
    	if (root==nullptr)
    		cout<<"empty"<<endl;
    	if (root->value==key)
    		cout<<"element found in tree"<<endl;
    	else if (root->value > key)
    		searchbykey(root->left,key);
    	else 
    		searchbykey(root->right,key);
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(int val) {
        insert(root, val);
    }

    void inorderTraversal() {
        inorderTraversal(root);
    }
    void search() {
        search(root);
    }
    int contmaxnode() {
        cout<<contmaxnode(root);
    }
    void searchbykey() {
    	int key;
    	cout<<"\nenter node value to be check:";
    	cin>>key;
        searchbykey(root,key);
    }

};

int main() {
    BinaryTree tree;
    int vk,sk;
    cout<<"\nenter no of  nodes to be entered:"<<endl;
    cin>>sk;
    cout<<"\nenter nodes starting from root node:"<<endl;
    for (int i=0;i<sk;i++){
        // cout<<"\nenter nodes starting from root node:"<<endl;
    	cin>>vk;
    	tree.insert(vk);
    }
    
    tree.inorderTraversal();
    tree.search();
    tree.contmaxnode();
    tree.searchbykey();

    return 0;
}