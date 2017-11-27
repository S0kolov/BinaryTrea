#include "ElectronicTableClocks.h"

ElectronicTableClocks::ElectronicTableClocks(int newCharge, time_t newTime, Colors color) : El_Clocks(newCharge, newTime)
{
	SetColor(color);
	//cout << "In ElectronicTableClocks ctor" << endl;
}

ElectronicTableClocks::~ElectronicTableClocks()
{
	//cout << "In ElectronicTableClocks destr" << endl;
}

ElectronicTableClocks::Colors ElectronicTableClocks::GetColor() const
{
	return color;
}

void ElectronicTableClocks::SetColor(Colors color)
{
	/*Validators::ColorValidation(color);
	this->color = color;*/
	this->color = color;
}

void ElectronicTableClocks::Head()
{
	((El_Clocks*)this)->Head();
	cout << setw(7) << "Color";
}
