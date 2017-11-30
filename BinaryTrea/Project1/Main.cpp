#include "Tree.h"
#include "AllClocks.h"
#include "Algoritm.h"

void PrintTypesOfElements();
template<typename T>
TreeNode<T>* AddRouteKeyAndValue();
void PrintMenu();
template<typename T>
void Menu(Tree<T>* root);
template<typename T>
void DeleteItem(Tree<T>* root);
template<typename T>
void Next(Tree<T>* tree,typename Tree<T>::MyIterator& iter);
template<typename T>
void Previous(Tree<T>* tree, typename Tree<T>::MyIterator& iter);

void main() {
	bool flag_1 = true;
	do
	{
		system("cls");
		rewind(stdin);
		PrintTypesOfElements();
		int k = 0;
		cin >> k;
		void* tree;
		switch (k)
		{
		case 1:
			tree = new Tree<int>(AddRouteKeyAndValue<int>());
 			Menu(static_cast<Tree<int>*>(tree)); delete tree; break;
		case 2:
			tree = new Tree<double>(AddRouteKeyAndValue<double>());
			Menu(static_cast<Tree<double>*>(tree)); delete tree; break;
		case 3:
			tree = new Tree<Clock>(AddRouteKeyAndValue<Clock>());
			Menu(static_cast<Tree<Clock>*>(tree)); delete tree; break;
		case 4:
			tree = new Tree<MechClock>(AddRouteKeyAndValue<MechClock>());
			Menu(static_cast<Tree<MechClock>*>(tree)); delete tree; break;
		case 5:
			tree = new Tree<TableMechClock>(AddRouteKeyAndValue<TableMechClock>());
			Menu(static_cast<Tree<TableMechClock>*>(tree)); delete tree; break;
		case 6:
			tree = new Tree<WristWatch>(AddRouteKeyAndValue<WristWatch>());
			Menu(static_cast<Tree<WristWatch>*>(tree)); delete tree; break;
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
	cout << "5) Next element" << endl;
	cout << "6) Previous element" << endl;
	cout << "7) Find by key" << endl;
	cout << "0) Exit from programm" << endl;
}

template<typename T>
void Menu(Tree<T>* tree)
{
	bool flag = true;	
	do {
		system("cls");
		PrintMenu();
		int number = 0;
		cin >> number;
		switch (number)
		{
		case 1: tree->Push(AddRouteKeyAndValue<T>()); break;
		case 2: DeleteItem(tree); break;
		case 3: tree->See(tree->root); system("pause"); break;
		case 4: tree->SeeAllItem(tree->root); system("pause"); break;
		case 5: {Tree<T>::MyIterator begin(tree->GetBegin()); Next(tree, begin); break; }
		case 6: {Tree<T>::MyIterator end(tree->GetEnd()); Previous(tree, end); break; }
		case 7: Find(tree); break;
		case 0: flag = false; break;
		default: continue;
		}
	} while (flag);
}

template<typename T>
void DeleteItem(Tree<T>* tree)
{
	int key;
	cout << "print key of delete item" << endl;
	cin >> key;
	tree->Pop(key);
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

template<typename T>
void Next(Tree<T>* tree, typename Tree<T>::MyIterator& iter) {
	cout << endl << endl;
	cout << (&iter)->_key << "(" << *iter << ")" << endl;
	while (iter !=*(tree->GetEnd())) {
		++iter;
		cout << (&iter)->_key << "(" << *iter << ")" << endl;
	}
	system("pause");
}

template<typename T>
void Previous(Tree<T>* tree, typename Tree<T>::MyIterator& iter) {
	cout << endl << endl;
	cout << (&iter)->_key << "(" << *iter << ")" << endl;
	while (iter != *(tree->GetBegin())) {
		--iter;
		cout << (&iter)->_key << "(" << *iter << ")" << endl;
	}
	system("pause");
}

template<typename T>
void Find(Tree<T>* tree) {
	cout << "Enter key" << endl;
	int ans = 0;
	while (true) {
		try
		{
			cin.clear();
			rewind(stdin);
			ans = Validation::VvodChisla(-1000, 1000);
			break;
		}
		catch (InvalidArgumentsException e)
		{
			continue;
		}
	}	
	TreeNode<T>* temp = Algoritm<T>::Poisk(tree, ans);
	if (temp == nullptr) {
		cout << "Not Found" << endl;
		system("pause");
		return;
	}
	cout << temp->_key << "   " << temp->_item << endl;
	system("pause");
	return;
}