#pragma once
#include "Tree.h"
#include "TreeNode.h"

template<typename T>
class Algoritm {
public:
	static TreeNode<T>* Poisk(Tree<T> *tree, int key) {
		TreeNode<T> *temp = nullptr;
		Tree<T>::MyIterator iter(tree->GetBegin());
		while (iter != *(tree->GetEnd())) {
			if ((&iter)->_key == key) {
				temp = &iter;
				break;
			}
			++iter;
		}
		return temp;
	}
};