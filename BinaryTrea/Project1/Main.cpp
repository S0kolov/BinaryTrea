#include "Tree.h"

void PrintTypesOfElements();
template<typename T>
TreeNode<T>* AddRouteKeyAndValue();
void PrintMenu();
template<typename T>
void Menu(Tree<T>* root);
template<typename T>
void DeleteItem(Tree<T>* root);

void main() {
	bool flag_1 = true;
	do
	{
		system("cls");
		rewind(stdin);
		PrintTypesOfElements();
		int k = 0;
		cin >> k;
		switch (k)
		{
		case 1:
			Tree<int>* root =new Tree<int>(AddRouteKeyAndValue<int>());
			Menu(root);
			break;
		case 2:
			Tree<char>* root = new Tree<char>(AddRouteKeyAndValue<char>());
			Menu(root);
			break;
		case 0: flag_1 = false;
		default: break;
		}
	} while (flag_1);
}

void PrintTypesOfElements()
{
	cout << "Enter type of elements:" << endl;
	cout << "1) int" << endl;
	cout << "2) double" << endl;
	cout << "3) Clock" << endl;
	cout << "4) Mech clock" << endl;
	cout << "5) Table mech clock" << endl;
	cout << "6) Wrist watch" << endl;
	cout << "0) exit" << endl;
}

void PrintMenu()
{
	cout << "1) Add Element in tree" << endl;
	cout << "2) Delete Element from tree" << endl;
	cout << "3) See tree" << endl;
	cout << "4) See items" << endl;
	cout << "0) Exit from programm" << endl;
}

template<typename T>
void Menu(Tree<T>* root)
{
	bool flag = true;
	do {
		system("cls");
		PrintMenu();
		int number = 0;
		cin >> number;
		switch (number)
		{
		case 1: root->Push(AddRouteKeyAndValue<T>()); break;
		case 2: DeleteItem(root); break;
		case 3: root->See(root->root); system("pause"); break;
		case 4: root->SeeAllItems(root->root); system("pause"); break;
		case 0: flag = false; break;
		default: continue;
		}
	} while (flag);
}

template<typename T>
void DeleteItem(Tree<T>* root)
{
	int key;
	cout << "print key of delete item" << endl;
	cin >> key;
	root->Pop(key);
	system("pause");
}

template<typename T>
TreeNode<T>* AddRouteKeyAndValue()
{
	cout << "print Key" << endl;
	int key = 0;
	cin >> key;
	cout << "print Value" << endl;
	T value = 0;
	cin >> value;
	return new TreeNode<T>(key, value);
}