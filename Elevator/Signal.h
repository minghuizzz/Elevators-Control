class Signal
{
public:
	Signal();
	Signal(int whichfloor);
	int getwhichfloor();
	void setwhichfloor(int whichfloor);
	int whichfloor;
};


class Out:public Signal
{
public:
	Out(int direction,int whichfloor);
	int getdirection();
	void setdirection(int direction);
	bool operator==(const Out &out);
private:
	int direction;
};


class In:public Signal
{
public:
	In(int whichele,int whichfloor);
	int getwhichele();
	bool operator==(const In &in);
private:
	int whichele;
};
