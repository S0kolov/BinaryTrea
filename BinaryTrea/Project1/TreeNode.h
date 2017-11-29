#pragma once
template<typename T>
class TreeNode
{
public:
	int _key;
	T _item;
	TreeNode<T> *left, *right, *parent;

	void SetParent(TreeNode<T>* pr) {
		this->parent = pr;
	}
	int CompareKey(TreeNode<T> &node) {
		int ansver;
		if (this->_key >= node._key)
			ansver = 1;
		else if (this->_key < node._key)
			ansver = 2;
		return ansver;
	}

	T GetItem() {
		return _item;
	}

	friend bool operator>(TreeNode<T> &first, TreeNode<T> &second) {
		bool result;
		switch (first.CompareKey(second))
		{
		case 1: result = true; break;
		case 2: result = false; break;
		}
		return result;
	}
	friend bool operator<(TreeNode<T> &first, TreeNode<T> &second) {
		bool result;
		switch (first.CompareKey(second))
		{
		case 1: result = false; break;
		case 2: result = true; break;
		}
		return result;
	}

	TreeNode(int key, T item,TreeNode<T>* pr=nullptr) {
		this->_key = key;
		this->_item = item;
		this->left = this->right = nullptr;
		this->parent = pr;
	}
	~TreeNode() {}
};

