#pragma once
#include "TreeNode.h"

#include <iostream>

using namespace std;

template<typename T>
class Tree
{
	TreeNode<T>* element;
public:
	
	TreeNode<T>* root;
	void Clean(TreeNode<T>* temp);
	void Push(TreeNode<T>* node);
	void Pop(int key);
	void See(TreeNode<T>* temp, int level = 0);
	void SeeAllItem(TreeNode<T>* temp=nullptr);

	Tree(int key, T item, TreeNode<T>* pr = nullptr);
	Tree(TreeNode<T>* pr) {
		this->element = this->root = pr;
	}
	~Tree();

	TreeNode<T>* GetBegin();
	TreeNode<T>* GetEnd();

	class Iterator {
		TreeNode* iter;

		Iterator(TreeNode* iter)
		{
			this->iter = iter;
		}
		void operator++() {

		}
		void operator--() {

		}
		T& operator*() {
			return iter->_item;
		}
		TreeNode& operator&() {

		}
	};
};

template<typename T>
Tree<T>::Tree(int key, T item, TreeNode<T>* pr) {
	this->root = new TreeNode<T>(key, item, pr);
	this->element = this->root;
}

template<typename T>
inline Tree<T>::~Tree()
{
	Clean(root);
	delete root;
	this->root=this->element = nullptr;
}

template<typename T>
inline TreeNode<T>* Tree<T>::GetBegin()
{
	TreeNode<T>* temp = this->element;
	while (temp->left != nullptr) {
		temp = temp->left;
	}
	return temp;
}

template<typename T>
inline TreeNode<T>* Tree<T>::GetEnd()
{
	TreeNode<T>* temp = this->element;
	while (temp->right != nullptr) {
		temp = temp->right;
	}
	return temp;
}

template<typename T>
inline void Tree<T>::Clean(TreeNode<T>* temp)
{
	TreeNode<T> * item = nullptr;
	if (temp->left != nullptr)
	{
		item = temp->left;
		Clean(item);
		delete item;
	}
	if (temp->right != nullptr)
	{
		item = temp->right;
		Clean(item);
		delete item;
	}
}

template<typename T>
void Tree<T>::Push(TreeNode<T> * node)
{
	TreeNode<T>* temp = nullptr;
	if (this->element->_key > node->_key) {
		temp = this->element->right;
	}
	else {
		temp = this->element->left;
	}
	if (temp == nullptr) {
		node->SetParent(this->element);
		if (this->element->_key > node->_key) {
			this->element->right = node;
		}
		else {
			this->element->left = node;
		}
	}
	else {
		this->element = temp;
		return this->Push(node);
	}
	this->element = this->root;
}

template<typename T>
void Tree<T>::Pop(int key)
{
	TreeNode<T>* temp = nullptr;
	if (this->element->_key == key)
	{
		if (this->element == this->root)
		{
			cout << "We can`t delete root" << endl;
			return;
		}
		if (this->element->left == nullptr)
		{	
			if (this->element->right != nullptr)
				this->element->right->parent = this->element->parent;
			this->element->parent->left = (this->element->parent->left == this->element) ? this->element->right : this->element->parent->left;
			this->element->parent->right = (this->element->parent->right == this->element) ? this->element->right : this->element->parent->right;
			delete this->element;
			return;
		}
		else if (this->element->right == nullptr)
		{
			if (this->element->left != nullptr)
				this->element->left->parent = this->element->parent;
			this->element->parent->left = (this->element->parent->left == this->element) ? this->element->left : this->element->parent->left;
			this->element->parent->right = (this->element->parent->right == this->element) ? this->element->left : this->element->parent->right;
			delete this->element;
			return;
		}
		else {
			TreeNode<T>* r = this->root;
			TreeNode<T>* e = this->element;
			this->element = this->root = this->element->left;
			Push(e->right);
			this->root = r;
			this->element = e;
			e->left->parent = e->parent;
			this->element->right = this->element->parent;
			this->element->parent->left = (this->element->parent->left == this->element) ? this->element->left : this->element->parent->left;
			this->element->parent->right = (this->element->parent->right == this->element) ? this->element->left : this->element->parent->right;
			delete this->element;
			return;
		}
	}
	else
	{
		if (this->element->_key > key) {
			temp = this->element->right;
		}
		else {
			temp = this->element->left;
		}
		if (temp == nullptr) {
			this->element = this->root;
			return;
		}
		else {
			this->element = temp;
			Pop(key);
			this->element = this->root;
			return;
		}
		this->element = this->root;
	}
}

template<typename T>
void Tree<T>::SeeAllItem(TreeNode<T>* temp)
{
	if (temp)
	{
		SeeAllItem(temp->left);
		cout << temp->_key << "|" << temp->_item << "|" << endl;
		SeeAllItem(temp->right);
	}
}

template<typename T>
void Tree<T>::See(TreeNode<T>* temp,int level)
{
	if (temp)
	{
		See(temp->left, level + 1);
		for (int i = 0; i< level; i++)
			cout << "	"; 
		cout << temp->_key << "|" << temp->_item << "|" << endl;
		See(temp->right, level + 1);
	}
}


