#pragma once
#include "MechClock.h"
class TableMechClock :
	public MechClock
{
	bool _secondsHand;
	bool _allarm;
public:
	bool WithSecondsHand();
	bool WithAllarm();

	void SetSecondsHand(int is);
	void SetAllarm(int is);

	friend istream& operator>>(istream& is, TableMechClock& temp) {
		is >> *dynamic_cast<MechClock*>(&temp);
		cout << "enter has this clock seconds hand?(1/0):" << endl;
		temp._secondsHand = Validation::VvodChisla(0, 1);
		cout << "has clock allarm function?(1/0):" << endl;
		temp._allarm = Validation::VvodChisla(0, 1);
		return is;
	}
	friend ostream& operator<<(ostream& os, TableMechClock& temp) {
		os << (MechClock)temp;
		os << setw(8);
		if(temp._allarm)
			os << "true";
		else
			os << "false";
		os << setw(8);
		if(temp._secondsHand)
			os << "true";
		else
			os << "false";
		return os;
	}
	void Head();
	TableMechClock(time_t time=NULL,bool secondsHand=false,bool allarm=false,int charge=100);
	~TableMechClock();
};

