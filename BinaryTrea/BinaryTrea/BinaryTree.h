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
	BinaryTree* parent;

	bool AddRight(int key, T newItem);
	bool AddRight(BinaryTree<T> * newItem);
	bool AddLeft(int key, T newItem);
	bool AddLeft(BinaryTree<T>* newItem);
	bool Add(int key, T newItem);
	bool Add(BinaryTree<T>* newItem);
	void CleanRight(BinaryTree<T> * temp);
	void CleanLeft(BinaryTree<T> * temp);
	static BinaryTree<T>* GoRight(BinaryTree<T>* temp);
	static BinaryTree<T>* GoLeft(BinaryTree<T>* temp);
	bool DellThisShit();
public:
	friend ostream operator << (ostream os,BinaryTree<T> item);
	void Clear();
	void See(BinaryTree<T>* temp, int level = 0);
	void See(int level = 0);
	bool Push(int key, T newItem);
	bool Push(BinaryTree<T>* newItem);
	bool Pop(int key);
	BinaryTree(int key, T newItem =NULL, BinaryTree<T>* pa=nullptr);
	~BinaryTree();

};

template <typename T>
ostream operator<<(ostream os, BinaryTree<T> item)
{
	BinaryTree<T>::See(item);
}
template<typename T>
void BinaryTree<T>::See(int level)
{
	BinaryTree<T>* temp = nullptr;
	if (this)
	{
		if (this->left != nullptr) { temp = this->left; temp->See(level + 1); }
		for (int i = 0; i< level; i++) cout << "	"; cout << this->_key << endl;
		if (this->right != nullptr) { temp = this->right; temp->See(level + 1); }
	}
}

template<typename T>
void BinaryTree<T>::See(BinaryTree<T>* temp, int level)
{
	if (temp)
	{
		See(temp->left, level + 1);
		for (int i = 0; i< level; i++) cout << "	"; cout << temp->_key << endl;
		See(temp->right, level + 1);
	}
}

template<typename T>
void BinaryTree<T>::Clear()
{
	BinaryTree<T>* temp = this;
	CleanLeft(temp);
	CleanRight(temp);
}

template<typename T>
void BinaryTree<T>::CleanRight(BinaryTree<T>* temp)
{
	if (this->right != nullptr)
	{
		temp = this->right;
		temp->Clear();
		this->right = nullptr;
	}
}

template<typename T>
void BinaryTree<T>::CleanLeft(BinaryTree<T>* temp)
{
	if (this->left != nullptr)
	{
		temp = this->left;
		temp->Clear();
		this->left = nullptr;
	}
}

template<typename T>
BinaryTree<T>::~BinaryTree()
{
	this->Clear();
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
bool BinaryTree<T>::DellThisShit()
{
	if (this->left == nullptr)
	{
		this->parent->left = (this->parent->left == this)? this->right: this->parent->left;
		this->parent->right = (this->parent->right == this)? this->right: this->parent->right;
		return true;
	}
	else if (this->right == nullptr) {
		this->parent->left = (this->parent->left == this)? this->left: this->parent->left;
		this->parent->right = (this->parent->right == this)? this->left: this->parent->right;
		return true;
	}
	else {
		bool res= this->left->Push(this->right);
		this->parent->left = (this->parent->left == this) ? this->left : this->parent->left;
		this->parent->right = (this->parent->right == this) ? this->left : this->parent->right;
		return res;
	}
}

template<typename T>
inline bool BinaryTree<T>::AddRight(int key, T newItem)
{
	return((this->right = new BinaryTree<T>(key, newItem, this)) != nullptr) ? true : false;
}

template<typename T>
inline bool BinaryTree<T>::AddRight(BinaryTree<T> * newItem)
{
	return((this->right = newItem)!= nullptr) ? true : false;
}

template<typename T>
inline bool BinaryTree<T>::AddLeft(int key, T newItem)
{
	return((this->left = new BinaryTree<T>(key, newItem, this)) != nullptr) ? true : false;
}

template<typename T>
inline bool BinaryTree<T>::AddLeft(BinaryTree<T>* newItem)
{
	return((this->left = newItem) != nullptr) ? true : false;
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
bool BinaryTree<T>::Add( BinaryTree<T>* newItem)
{
	if (newItem->_key >= this->_key)
		return BinaryTree::AddRight(newItem);
	else
		return BinaryTree::AddLeft(newItem);
}

template<typename T>
bool BinaryTree<T>::Push(int key, T newItem)
{
	BinaryTree<T>* temp = nullptr;
	temp = (key >= this->_key) ? GoRight(this) : GoLeft(this);
	if (temp == this) return this->Add(key, newItem);
	else return temp->Push(key, newItem);
}

template<typename T>
bool BinaryTree<T>::Push(BinaryTree<T>* newItem)
{
	BinaryTree<T>* temp = nullptr;
	temp = (newItem->_key >= this->_key) ? GoRight(this) : GoLeft(this);
	if (temp == this) return this->Add(newItem);
	else return temp->Push(newItem);
}

template<typename T>
bool BinaryTree<T>::Pop(int key)
{
	BinaryTree<T>* temp = nullptr;
	if( this->_key == key)
	{
		bool res = this->DellThisShit();
		if (res)
			temp = nullptr;
		return res;
	}
	else
	{
		temp = (key >= this->_key) ? GoRight(this) : GoLeft(this);
		if (temp == this) return false;
		else return temp->Pop(key);
	}
}

template<typename T>
BinaryTree<T>::BinaryTree(int key, T newItem, BinaryTree<T>* pa)
{
	this->_key = key;
	this->_item = newItem;
	this->left = nullptr;
	this->right = nullptr;
	this->parent = pa;
}