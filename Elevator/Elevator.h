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
	int num;/*1Ϊ����1��2Ϊ����2*/
	int condition;
	int whichfloor;
	bool gate;
};
	 
