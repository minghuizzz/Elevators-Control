#include"Signal.h"


Signal::Signal()
{
	whichfloor=1;
}
Signal::Signal(int whichfloor)
{
	this->whichfloor=whichfloor;
}
int Signal::getwhichfloor()
{
	return whichfloor;
}
void Signal::setwhichfloor(int whichfloor)
{
	this->whichfloor=whichfloor;
}


Out::Out(int direction,int whichfloor)/*direction 0为上行，1为下行*/
{
	this->direction=direction;
	setwhichfloor(whichfloor);
}
int Out::getdirection()
{
	return direction;
}
void Out::setdirection(int direction)
{
	this->direction=direction;
}
bool Out::operator==(const Out &out)
{
	if((this->whichfloor)==(out.whichfloor))
		return 1;
	else
		return 0;
}



In::In(int whichele,int whichfloor)
{
	this->whichele=whichele;
	setwhichfloor(whichfloor);
}
int In::getwhichele()
{
	return whichele;
}
bool In::operator==(const In &in)
{
	if((this->whichfloor)==(in.whichfloor)&&(this->whichele)==(in.whichele))
		return 1;
	else
		return 0;
}
