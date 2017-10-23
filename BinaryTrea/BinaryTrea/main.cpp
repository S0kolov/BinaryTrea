#include "BinaryTree.h"



void main() {
	BinaryTree<int>* root = new BinaryTree<int>(10, 1);
	root->AddNewItem(5,1);
	root->AddNewItem(20, 1);
	root->AddNewItem(1, 1);
	root->AddNewItem(4, 1);
	root->AddNewItem(11, 1);
	//BinaryTree<int>::PrintTree(root);
	root->PrintTree();
	delete root;
	system("pause");
}