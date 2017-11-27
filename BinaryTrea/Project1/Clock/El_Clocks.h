#pragma once
#include "Clock.h"

class El_Clocks : public Clock
{
protected:
	int Charge;
	bool Backlighting = false;
public:
	int GetCharge() const;
	void SetCharge(int newCharge);
	bool IsBacklighting() const;
	void SetBacklighting(int);
	friend istream& operator>>(istream& is, El_Clocks& temp) {
		is >> *dynamic_cast<Clock*>(&temp);
		cout << "enter charge value(0-100):\n";
		temp.Charge = Validation::VvodChisla(0, 100);
		cout << "has clock blacklighting?(1/0):" << endl;
		temp.Backlighting = Validation::VvodChisla(0, 1);
		return is;
	}
	friend ostream& operator<<(ostream& os, El_Clocks& temp) {
		os << (Clock)temp;
		os << setw(10);
		os << temp.GetCharge();
		os << setw(14);
		if (temp.IsBacklighting())
			os << "true";
		else
			os << "false";
		return os;
	}
	void Head();
	El_Clocks(int newCharge = 1, time_t newTime = NULL);
	~El_Clocks();
};