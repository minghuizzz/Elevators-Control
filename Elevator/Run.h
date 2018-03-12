#include"usesignal.h"
//#include<ctime>
//using namespace std;

/*void delay(int time)//time*1000ÎªÃëÊý 
{
	clock_t now=clock();
	while(clock()-now<time); 
} 
*/
Elevator run(Elevator &elevator)
{
	Signal signal=getsignal(elevator);
	if(signal.whichfloor==0)
	{
		elevator.setcondition(0);
        elevator.setgate(0);
	    return elevator;
	}
	else
	{
		if(signal.whichfloor==elevator.getwhichfloor())
		{
			elevator.setgate(1);
			//delay(5*1000);
			elevator.setgate(0);
			deletesignal(elevator);
			return elevator;
		}	
		else if(signal.whichfloor>elevator.getwhichfloor())
		{
			elevator.setcondition(1);
			//delay(5*1000);
			elevator.setwhichfloor(elevator.getwhichfloor()+1);
			return elevator;
		}
		else
		{
			elevator.setcondition(2);
			//delay(5*1000);
			elevator.setwhichfloor(elevator.getwhichfloor()-1);
			return elevator;
		}
	}	
}