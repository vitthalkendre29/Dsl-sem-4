#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    int findLongestPath() const {
        return root ? max(longestPath(root->left), longestPath(root->right)) + 1 : 0;
    }

    int findMinValue() const {
        return minValue(root);
    }

    void swapLeftAndRight() {
        swapLeftRight(root);
    }

    bool searchValue(int value) const {
        return search(root, value);
    }

private:
    TreeNode* insertRecursive(TreeNode* node, int value) {
        if (!node)
            return new TreeNode(value);

        if (value < node->data)
            node->left = insertRecursive(node->left, value);
        else if (value > node->data)
            node->right = insertRecursive(node->right, value);

        return node;
    }

    int longestPath(const TreeNode* node) const {
        return node ? 1 + max(longestPath(node->left), longestPath(node->right)) : 0;
    }

    int minValue(const TreeNode* node) const {
        return node ? min(node->data, min(minValue(node->left), minValue(node->right))) : INT_MAX;
    }

    void swapLeftRight(TreeNode* node) {
        if (node) {
            swap(node->left, node->right);
            swapLeftRight(node->left);
            swapLeftRight(node->right);
        }
    }

    bool search(const TreeNode* node, int value) const {
        return node ? (node->data == value || (value < node->data ? search(node->left, value) : search(node->right, value))) : false;
    }
};

int main() {
    BinarySearchTree bst;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert new node\n";
        cout << "2. Find number of nodes in longest path\n";
        cout << "3. Minimum data value found in the tree\n";
        cout << "4. Change a tree so that the roles of the left and right pointers are swapped at every node\n";
        cout << "5. Search a value\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                cout << "Enter value to insert: ";
                cin >> value;
                bst.insert(value);
                break;
            }
            case 2:
                cout << "Number of nodes in the longest path: " << bst.findLongestPath() << endl;
                break;
            case 3:
                cout << "Minimum data value: " << bst.findMinValue() << endl;
                break;
            case 4:
                bst.swapLeftAndRight();
                cout << "Tree modified: Left and right pointers swapped at every node.\n";
                break;
            case 5: {
                int searchValue;
                cout << "Enter value to search: ";
                cin >> searchValue;
                cout << "Value " << searchValue << " found: " << (bst.searchValue(searchValue) ? "Yes" : "No") << endl;
                break;
            }
            case 6:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
