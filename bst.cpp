#include <iostream>
#include <queue>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;
};

class BST
{
	Node* root;
	Node* mirror;

	public:
		BST();
		Node* getroot();
		Node* getmirror();
		void insert();
		void insert_rec(Node *);
		void mirror_tree(Node *);
		void search(int);
};

BST::BST()
{
	root = NULL;
	mirror = NULL;
}

Node* BST::getroot()
{
	return root;
}

Node* BST::getmirror()
{
	return mirror;
}

void BST::insert()
{
	Node* temp, *newNode;
	char ch = 'y';

	while(ch == 'y' || ch == 'Y')
	{
		newNode = new Node();
		cout<<"\nEnter data for new Node: ";
		cin>>newNode->data;
		newNode->left = newNode->right = NULL;

		if(root == NULL)
			root = newNode;
		else
		{
			temp = root;
			check:
			if(newNode->data < temp->data)
			{
				if(temp->left != NULL)
				{
					temp = temp->left;
					goto check;
				}
				else
				{
					temp->left = newNode;
				}
			}
			else if(newNode->data > temp->data)
			{
				if(temp->right != NULL)
				{
					temp = temp->right;
					goto check;
                	}
				else
				{
					temp->right = newNode;
				}
            	}
        }
        cout<<"\nEnter y or Y to add more Nodes: ";
        cin>>ch;
    }

}

void BST::mirror_tree(Node* t)
{
	
	if(t==NULL)
	{
		return;
	}
	else{
		mirror_tree(t->left);
		cout<<t->data<<" ";
		mirror_tree(t->right);
	}
}

void BST::search(int no)
{
	
	Node *temp;
	temp = root;


	check:
	if(no == temp->data)
	{
		cout<<"\nData found!";
		return;
	}
	if(no < temp->data)
	{
		if(temp->left != NULL)
		{
			temp = temp->left;
			goto check;
		}
		else
		{
			cout<<"\nData doesnt exist.";
			return;
		}
	}
	else if(no > temp->data)
	{
		if(temp->right != NULL)
		{
			temp = temp->right;
			goto check;
		}
		else
		{
			cout<<"\nData doesnt exist.";
			return;
		}
	}
}

int main()
{
	BST tree;
	int x, choice;
	char ch = 'y';
    
	while(1)
	{
		cout<<"\n\nBinary Search Tree Operations ";
		cout<<"\n1. Insert.";
		cout<<"\n2. Mirror Image.";
		cout<<"\n3. Search.";
		cout<<"\n4. Exit.";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		
		switch(choice)
		{
			case 1: 
				tree.insert();
				break;
			case 2: 
				cout<<"\nMirror Image of tree: ";
				tree.mirror_tree(tree.getroot());
				tree.mirror_tree(tree.getroot());
				break;
			case 3: 
				cout<<"\nEnter number to search: ";
				cin>>x;
				tree.search(x);
				break;
			case 4: 
				return 0;
		}
	}
	return 0;
}
