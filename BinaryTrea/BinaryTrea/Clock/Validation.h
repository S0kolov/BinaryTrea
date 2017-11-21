#pragma once
#include <iostream>
#include "InvalidArgumentsException.h"

using namespace std;

class Validation {
public:
	static int VvodChisla(int min, int max)
	{
		int res;
		bool flag = false;
		do {
			try {
				cin >> res;
				if ((!cin.good() || cin.get() != '\n') || !(res >= min && res <= max))
					throw InvalidArgumentsException("vvedeno ne chislo ili chislo v nepravelnom diapazone");
				else
					flag = false;
			}
			catch (InvalidArgumentsException e) {
				flag = true;
				cout << e.what() << endl;
			}
		} while (flag);
		return res;
	}
};