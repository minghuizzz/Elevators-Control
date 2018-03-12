#include"Elevator.h"

Elevator::Elevator()
{
	num=0;
	condition=0;
	whichfloor=0;
	gate=0;
}

Elevator::Elevator(int num, int condition, int whichfloor, bool gate)/*condition 0Îª¿ÕÏĞ×´Ì¬£¬1ÎªÉÏĞĞ×´Ì¬£¬2ÎªÏÂĞĞ×´Ì¬*/
{
	this->num=num;
	this->condition=condition;
	this->whichfloor=whichfloor;
	this->gate=gate;
}

int Elevator::getnum()
{
	return num;
}

int Elevator::getcondition()
{
	return condition;
}

int Elevator::getwhichfloor()
{
	return whichfloor;
}

bool Elevator::getgate()
{
	return gate;
}

void Elevator::setcondition(int condition)
{
	this->condition=condition;
}

void Elevator::setwhichfloor(int whichfloor)
{
	this->whichfloor=whichfloor;
}

void Elevator::setgate(bool gate)
{
	this->gate=gate;
}