#pragma once
#include <iostream>

using namespace std;

template <typename T>
class BinaryTree
{
	int _key;
	T _item;
	BinaryTree* left;
	BinaryTree* right;
public:

	bool AddNewItem(int key,T newItem) {
		BinaryTree* temp;
		//if (newItem._key >= this->_key)	GoRight();
		//else GoLeft();
		tepm = (newItem._key >= this->_key) ? GoRight() : GoLeft();
		if (temp == this)
			if (newItem._key >= this->_key)
				return AddRight(key, newItem);
			else
				return AddLeft(key, newItem);
	}
	bool AddRight(int key,T newItem ) {
		return( (this->right = new BinaryTree(key, newItem))!=nullptr)? true:false;
	}

	bool AddLeft(int ket, T newItem) {
		return((this->left = new BinaryTree(key, newItem)) != nullptr) ? true : false;
	}

	BinaryTree* GoRight() {
		if (this->right != nullptr)
			return this->right;
		else
			return this;
	}
	BinaryTree* GoLeft() {
		if (this->left != nullptr)
			return this->left;
		else
			return this;
	}

	bool AddNewItem(int key,BinaryTree newItem) {
		if (item.Left == NULL && item.Right == NULL) {
			return AddNewItem(key,item._item);
		}
		return false;
	}

	BinaryTree(int key,T newItem=NULL) {
		_key = key;
		_item = item;
		left = NULL;
		right = NULL;
	}
	~BinaryTree() {}

};

