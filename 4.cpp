#include <iostream>
#include<cstdlib>
using namespace std;

struct Node {
    string key;
    string value;
    Node* left;
    Node* right;

    Node(string k, string v) : key(k), value(v), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    Node* insertRecursively(Node* node, string key, string value) {
        if (node == nullptr) {
            return new Node(key, value);
        }
        if (key < node->key) {
            node->left = insertRecursively(node->left, key, value);
        } else if (key > node->key) {
            node->right = insertRecursively(node->right, key, value);
        } else { // Update value if key already exists
            node->value = value;
        }
        return node;
    }

    // Node* searchRecursively(Node* node, string key) {
    //     if (node == nullptr || node->key == key) {
    //         return node;
    //     }
    //     if (key < node->key) {
    //         return searchRecursively(node->left, key);
    //     } else {
    //         return searchRecursively(node->right, key);
    //     }
    // }


    void inorderTraversalRecursively(Node* node) {
        if (node != nullptr) {
            inorderTraversalRecursively(node->left);
            cout << "(" << node->key << ", " << node->value << ") ";
            inorderTraversalRecursively(node->right);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(string key, string value) {
        root = insertRecursively(root, key, value);
    }

    // string search(string key) {
    //     Node* result = searchRecursively(root, key);
    //     return (result != nullptr) ? result->value : "Key not found";
    // }

  

    void inorderTraversal() {
        inorderTraversalRecursively(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst;
    string word,meaning;
    int a;
    cout<<"enter how many word meaning enter:"<<endl;
    cin>>a;
    for (int i=0;i<a;i++){
        cout<<"enter Word:"<<endl;
        cin>>word;
        cout<<"\nenter meaning:"<<endl;
        cin>>meaning;
        bst.insert(word,meaning);
    }

    
    bst.inorderTraversal();

    return 0;
}
