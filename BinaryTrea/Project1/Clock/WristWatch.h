#pragma once
#include "MechClock.h"
#include <iomanip>



class WristWatch :
	public MechClock
{
public:
	enum Matirial {
		Metal=0,
		Plastic,
		Glass,
		Gold,
		Silver,
		Titan,
		Carbon
	};
	enum Mark {
		Sitizen=0,
		Aerowatch,
		Azzaro,
		Balmain,
		Gucci,
		Boss,
		Tissot,
		SwissMilitary,
		Viceroy,
		Versage
	};
protected:
	Matirial _corpusMatirial;
	Mark _mark;

public:
	

	friend istream& operator>>(istream& is,WristWatch& temp) {
		//WristWatch* obj = &temp;
		is >> *dynamic_cast<MechClock*>(&temp);
		cout << "Enter corpus matirial (number form 0 to 5): " << endl;
	//	int c, m;
	//	is >> c;
		//rewind(stdin);
		/*temp.SetMatirial((WristWatch::Matirial)c);*/
	    temp._corpusMatirial= (WristWatch::Matirial)Validation::VvodChisla(0, 5);
		cout << "watch mark(number form 0 to 9):" << endl;
	//	is >> m;
		rewind(stdin);
		//temp.SetMark((WristWatch::Mark)m);
		temp._mark= (WristWatch::Mark)Validation::VvodChisla(0, 9);
		return is;
	}

	friend ostream& operator<<(ostream& os, WristWatch& temp) {
		os << (MechClock)temp;
		os << setw(6) <<  temp._mark;
		os << setw(10) <<  temp._corpusMatirial;
		return os;
	}
	Matirial GetMatirial();
	void SetMatirial(Matirial corpusMatirial);
	Mark GetMark();
	void SetMark(Mark mark);
	void Head();

	WristWatch(time_t time = NULL,Mark mark=Mark::Tissot,Matirial corpusMatirial = Matirial::Metal,int charge=100);
	~WristWatch();
};

