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

	bool AddRight(int key, T newItem);
	bool AddLeft(int key, T newItem);
	bool Add(int key, T newItem);
public:

	bool AddNewItem(int key, T newItem) ;

	static BinaryTree<T>* GoRight(BinaryTree<T>* temp) ;
	static BinaryTree<T>* GoLeft(BinaryTree<T>* temp) ;

	bool AddNewItem(int key, BinaryTree newItem);

	BinaryTree(int key, T newItem = NULL);
	~BinaryTree() {}

};

template<typename T>
bool BinaryTree<T>::AddNewItem(int key, T newItem)
{
	BinaryTree<T>* temp = nullptr;
	temp = (key >= this->_key) ? GoRight(this) : GoLeft(this);
	if (temp == this)
		this->Add(key, newItem);
	else
		return temp->AddNewItem(key, newItem);
}

template<typename T>
inline bool BinaryTree<T>::AddRight(int key, T newItem)
{
	return((this->right = new BinaryTree<T>(key, newItem)) != nullptr) ? true : false;
}

template<typename T>
inline bool BinaryTree<T>::AddLeft(int key, T newItem)
{
	return((this->left = new BinaryTree<T>(key, newItem)) != nullptr) ? true : false;
}

template<typename T>
bool BinaryTree<T>::Add(int key, T newItem)
{
	if (key >= this->_key)
		return BinaryTree::AddRight(key, newItem);
	else
		return BinaryTree::AddLeft(key, newItem);
}

template<typename T>
BinaryTree<T>* BinaryTree<T>::GoRight(BinaryTree<T>* temp)
{
	if (temp->right != nullptr)
		return temp->right;
	else
		return temp;
}

template<typename T>
BinaryTree<T>* BinaryTree<T>::GoLeft(BinaryTree<T>* temp)
{
	if (temp->left != nullptr)
		return temp->left;
	else
		return temp;
}

template<typename T>
bool BinaryTree<T>::AddNewItem(int key, BinaryTree newItem)
{
	if (item.Left == NULL && item.Right == NULL) {
		return AddNewItem(key, item._item);
	}
	return false;
}

template<typename T>
BinaryTree<T>::BinaryTree(int key, T newItem)
{
	this->_key = key;
	this->_item = newItem;
	this->left = NULL;
	this->right = NULL;
}
