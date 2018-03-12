class Elevator
{
public:
	Elevator();
	Elevator(int num, int condition, int whichfloor, bool gate);
	int getnum();
	int getcondition();
	int getwhichfloor();
	bool getgate();
	void setcondition(int condition);
    void setwhichfloor(int whichfloor);
	void setgate(bool gate);
private:
	int num;/*1为电梯1，2为电梯2*/
	int condition;
	int whichfloor;
	bool gate;
};
	 
