#include "BinaryTree.h"

template <typename T>
ostream operator<<(ostream os,BinaryTree<T> item)
{
	BinaryTree<T>::PrintTree(item);
}

