#include "El_Clocks.h"


int El_Clocks::GetCharge() const
{
	return Charge;
}

void El_Clocks::SetCharge(int newCharge)
{	
	Charge = newCharge;
	//Charge = Validators::ChargeValidation(newCharge);
}

bool El_Clocks::IsBacklighting() const
{
	return Backlighting;
}

void El_Clocks::SetBacklighting(int backlighting)
{

	//Backlighting = Validators::BackLightningValidation(backlighting);
}

void El_Clocks::Head()
{
	((Clock*)this)->Head();
	cout << setw(10) << "Charge,%" << setw(14) << "Backlighting";
}

El_Clocks::El_Clocks(int newCharge, time_t newTime) : Clock(newTime)
{
	//cout << "El_Clocks ctor" << endl;
	SetCharge(newCharge);
}

El_Clocks::~El_Clocks()
{
	//cout << "El_Clocks destr" << endl;
}