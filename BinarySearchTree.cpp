#include "BinarySearchTree.h"
BinarySearchTree::BinarySearchTree()
{
	root = NULL;
	size = 0;
}
void BinarySearchTree::read()
{
	ifstream inputfile;
	inputfile.open("score.txt");
	if (inputfile.is_open())
	{
		int r;
		while (!inputfile.eof())
		{
			inputfile >> r;
			insert(r);
		}
		inputfile.close();
	}
}
void BinarySearchTree::insert(int data)
{
	Node* newNode = new Node;
	newNode->value = data;
	newNode->left = NULL;
	newNode->right = NULL;
	if (root == NULL)
		root = newNode;
	else
	{
		Node* temp1 = root, * temp2 = root;
		while (temp2 != NULL)
			if (data > temp2->value)
			{
				temp1 = temp2;
				temp2 = temp2->right;
			}
			else if (data < temp2->value)
			{
				temp1 = temp2;
				temp2 = temp2->left;
			}
			else
				return;
		if (data > temp1->value)
			temp1->right = newNode;
		else
			temp1->left = newNode;
	}
	size++;
	
}
void BinarySearchTree::desorder(Node* n)
{
	if (n == NULL)
		return;
	else
	{
		desorder(n->right);
		cout << n->value << " " << endl;
		desorder(n->left);
	}
}
void BinarySearchTree::printdes()
{
	desorder(root);
}