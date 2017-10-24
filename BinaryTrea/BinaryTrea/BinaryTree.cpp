#include "BinaryTree.h"

template <typename T>
ostream operator<<(ostream os,BinaryTree<T> item)
{
	BinaryTree<T>::PrintTree(item);
}

template<typename T>
void BinaryTree<T>::PrintTree(int level = 0)
{
	BinaryTree<T>* temp = nullptr;
	if (this)
	{
		if (this->left != nullptr) { temp = this->left; temp->PrintTree(level + 1); }
		for (int i = 0; i< level; i++) cout << "	"; cout << this->_key << endl;
		if (this->right != nullptr) { temp = this->right; temp->PrintTree(level + 1); }
	}
}

template<typename T>
static void BinaryTree<T>::PrintTree(BinaryTree<T>* temp, int level = 0)
{
	if (temp)
	{
		PrintTree(temp->left, level + 1);
		for (int i = 0; i< level; i++) cout << "	"; cout << temp->_key << endl;
		PrintTree(temp->right, level + 1);
	}
}

template<typename T>
void BinaryTree<T>::CleanTree()
{
	BinaryTree<T>* temp = this;
	CleanLeft(temp);
	CleanRight(temp);
}

template<typename T>
void BinaryTree<T>::CleanRight(BinaryTree<T> * &temp)
{
	if (this->right != nullptr)
	{
		temp = this->right;
		temp->CleanTree();
		this->right = nullptr;
	}
}

template<typename T>
void BinaryTree<T>::CleanLeft(BinaryTree<T> * &temp)
{
	if (this->left != nullptr)
	{
		temp = this->left;
		temp->CleanTree();
		this->left = nullptr;
	}
}

template<typename T>
BinaryTree<T>::~BinaryTree()
{
	this->CleanTree();
}

template<typename T>
bool BinaryTree<T>::AddNewItem(int key, T newItem)
{
	BinaryTree<T>* temp = nullptr;
	temp = (key >= this->_key) ? GoRight(this) : GoLeft(this);
	if (temp == this) return this->Add(key, newItem);
	else return temp->AddNewItem(key, newItem);
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
