#include <iostream>

using namespace std;

template<class T>
class MyClass
{
	T _item;
public:
	void Add(T item) {
		_item = item;
	}
	MyClass();
	~MyClass();

};
template<class T>
void AddElement(MyClass<T> element) {
	T item;
	//cin >> item;
	element.Add(item);
}

void main() {
	char* p = new char*;
	cin >> p;
	MyClass<char*> element;
	AddElement<char*>(element);

}

template<class T>
MyClass<T>::MyClass()
{
}

template<class T>
MyClass<T>::~MyClass()
{
}
