#include "MechClock.h"


int MechClock::GetCharge()
{
	return _charge;
}

void MechClock::SetCharge(int charge)
{
	_charge = charge;
	//_charge = Validators::ChargeValidation_2(charge);
}

void MechClock::WindWatch()
{
	SetCharge(100);
}

void MechClock::Head()
{
	((Clock*)this)->Head();
	cout << setw(10) << "Charge,%";
}

MechClock::MechClock(time_t newTime, int charge):Clock(newTime)
{
	//cout << "MechClock constructor" << endl;
	SetCharge(charge);
}

MechClock::~MechClock()
{
	//cout << "MechClock destructor" << endl;
}
