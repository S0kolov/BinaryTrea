#include "BinaryTree.cpp"

void PrintTypesOfElements();
template<typename T>
BinaryTree<T>* AddRouteKeyAndValue();
void PrintMenu();
template<typename T>
void Menu(BinaryTree<T>* root);
template<typename T>
void DeleteItem(BinaryTree<T>* root);

void main(){
	bool flag_1 = true;
	do
	{
		system("cls");
		rewind(stdin);
		void* root = nullptr;
		PrintTypesOfElements();
		int k = 0;
		cin >> k;
		switch (k)
		{
		case 1:
			root = AddRouteKeyAndValue<int>();
			Menu(static_cast<BinaryTree<int>*>(root));
			break;
		case 2:
			root = AddRouteKeyAndValue<double>();
			Menu(static_cast<BinaryTree<double>*>(root));
			break;
		case 0: flag_1 = false;
		default: break;
		}
		delete root;
	} while (flag_1);
}

void PrintTypesOfElements()
{
	cout << "Enter type of elements:" << endl;
	cout << "1) int" << endl;
	cout << "2) double" << endl;
	cout << "0) exit" << endl;
}

void PrintMenu()
{
	cout << "1) Add Element in tree" << endl;
	cout << "2) Delete Element from tree" << endl;
	cout << "3) See tree" << endl;
	cout << "4) Find element" << endl;
	cout << "0) Exit from programm" << endl;
}

template<typename T>
void Menu(BinaryTree<T>* root)
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
		case 3: root->See(); system("pause"); break;
		case 4: cout << "enter key: " << endl; cin >> number; root->seach(number)->SeeThis(); system("pause"); break;
		case 0: flag = false; break;
		default: continue;
		}
	} while (flag);
}

template<typename T>
void DeleteItem(BinaryTree<T>* root)
{
	int key;
	cout << "print key of delete item" << endl;
	cin >> key;
	if (!root->Pop(key)) {
		cout << "item with this key not found" << endl;
		system("pause");
	}
}

template<typename T>
BinaryTree<T>* AddRouteKeyAndValue()
{
	cout << "print Key" << endl;
	int key = 0;
	cin >> key;
	cout << "print Value" << endl;
	T value = 0;
	cin >> value;
	return new BinaryTree<T>(key, value);
}
