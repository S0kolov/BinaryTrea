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
	void CleanRight(BinaryTree<T> * &temp);
	void CleanLeft(BinaryTree<T> * &temp);
public:
	
	friend ostream operator << (ostream os,BinaryTree<T> item);

	void CleanTree();

	void CleanRight(BinaryTree<T> * &temp);

	void CleanLeft(BinaryTree<T> * &temp);

	static void PrintTree(BinaryTree<T>* temp, int level = 0);

	void PrintTree(int level = 0);
	bool AddNewItem(int key, T newItem);

	static BinaryTree<T>* GoRight(BinaryTree<T>* temp);
	static BinaryTree<T>* GoLeft(BinaryTree<T>* temp);

	bool AddNewItem(int key, BinaryTree newItem);

	BinaryTree(int key, T newItem = NULL);
	~BinaryTree();

};



