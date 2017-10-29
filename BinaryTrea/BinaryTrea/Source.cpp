#include "BinaryTree.h"

void main(){
	BinaryTree<int>* root = new BinaryTree<int>(12, 1);
	root->Push(4, 1);
	root->Push(1, 1);
	root->Push(8, 2);
	root->Push(6, 1);
	root->Push(9, 1);
	root->Push(10, 1);
	root->Push(5, 1);
	root->Push(7, 1);
	//BinaryTree<int>::PrintTree(root);
	root->See();
	root->Pop(8);
	root->See();
	delete root;
	system("pause");
}
