#pragma once
#include "El_Clocks.h"
class ElectronicTableClocks : public El_Clocks
{
public:
	enum Colors
	{
		Red,
		Green,
		Grey,
		Black,
		White
	};

	ElectronicTableClocks(int newCharge = 1, time_t newTime = NULL, Colors color = Colors::Red);
	~ElectronicTableClocks();
	Colors GetColor() const;
	void SetColor(Colors color);
protected:
	Colors color;
public:
	friend istream& operator>>(istream& is, ElectronicTableClocks& temp) {
		//El_Clocks* obj = &temp;
	//	is >> *dynamic_cast<El_Clocks*>(obj);
		is >> *dynamic_cast<El_Clocks*>(&temp);
		//int b;
		cout << "enter the number of color(1-5):\n";
		temp.color = (ElectronicTableClocks::Colors)Validation::VvodChisla(1, 5);
		//is >> b;
		//rewind(stdin);
		//temp.SetColor((ElectronicTableClocks::Colors)b);
		return is;
	}
	friend ostream& operator<<(ostream& os, ElectronicTableClocks& temp) {
		os << (El_Clocks)temp;
		os << setw(7);
		os << temp.GetColor();
		return os;
	}

	void Head();
};

