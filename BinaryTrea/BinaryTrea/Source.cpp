#include "BinaryTree.cpp"

void PrintTypesOfElements();
template<typename T>
BinaryTree<T>* AddRouteKeyAndValue();
void PrintMenu();
template<typename T>
void Menu(BinaryTree<T>* root);
template<typename T>
void DeleteItem(BinaryTree<T>* root,bool flag);

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
		case 3: 
			root = AddRouteKeyAndValue<Clock>();
			Menu(static_cast<BinaryTree<Clock>*>(root));
			break;
		case 4:
			root = AddRouteKeyAndValue<MechClock>();
			Menu(static_cast<BinaryTree<MechClock>*>(root));
			break;
		case 5:
			root = AddRouteKeyAndValue<TableMechClock>();
			Menu(static_cast<BinaryTree<TableMechClock>*>(root));
			break;
		case 6:
			root = AddRouteKeyAndValue<WristWatch>();
			Menu(static_cast<BinaryTree<WristWatch>*>(root));
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
	cout << "5) Find element" << endl;
	cout << "6) Delete and return" << endl;
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
		case 2: delete DeleteItem(root,true); break;
		case 3: root->See(); system("pause"); break;
		case 5: cout << "enter key: " << endl; cin >> number; root->seach(number)->SeeThis(); system("pause"); break;
		case 4:  root->SeeAllItems(); system("pause"); break;
		case 6:DeleteItem(root, true); break;
		case 0: flag = false; break;
		default: continue;
		}
	} while (flag);
}

template<typename T>
void DeleteItem(BinaryTree<T>* root,bool flag)
{
	int key;
	cout << "print key of delete item" << endl;
	cin >> key;
	if (!flag) {
		if (!root->Pop(key)) {
			cout << "item with this key not found" << endl;
			system("pause");
		}
	}
	else {
		cout << root->GetItem(*(root->Pop(key, true)))<<endl;
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
