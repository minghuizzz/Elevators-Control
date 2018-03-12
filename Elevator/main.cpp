#include"Run.h"
#include<iostream>
using namespace std;

int main()
{
	Elevator ele1(1,0,1,0);
	Elevator ele2(2,0,1,0);
	In in1(1,10);
	savesignal(in1,ele1);
	In in2(1,20);
	savesignal(in2,ele1);
	In in3(1,20);
	savesignal(in3,ele1);
	Out out1(0,22);
	savesignal(out1,ele1,ele2);
	Out out2(1,25);
	savesignal(out2,ele1,ele2);
	cout<<"1:"<<ele1.getcondition()<<" "<<ele1.getwhichfloor()<<" "<<ele1.getgate()<<endl;
	cout<<"2:"<<ele2.getcondition()<<" "<<ele2.getwhichfloor()<<" "<<ele2.getgate()<<endl;
	do
	{
		run(ele1);
		cout<<"1:"<<ele1.getcondition()<<" "<<ele1.getwhichfloor()<<" "<<ele1.getgate()<<endl;
		run(ele2);
		cout<<"2:"<<ele2.getcondition()<<" "<<ele2.getwhichfloor()<<" "<<ele2.getgate()<<endl;
	}while(ele1.getcondition()!=0||ele2.getcondition()!=0);
	cin.get();



	return 0;
}