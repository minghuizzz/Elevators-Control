#include"Signal.h"
#include"Elevator.h"
#include<list>
using namespace std;

list<In> listfiup;
list<In> listfidown;
list<Out> listfoup1;
list<Out> listfodown1;
list<Out> listfoup2;
list<Out> listfodown2;
list<In> listsiup;
list<In> listsidown;
list<Out> listsoup1;
list<Out> listsodown1;
list<Out> listsoup2;
list<Out> listsodown2;
list<In>::iterator i;
int k,a,b;
bool cmp(const Signal &a, const Signal &b)
{
	if(a.whichfloor>=b.whichfloor)
		return 0;
	else
		return 1;
}

bool fcmp(const Signal &a, const Signal &b)
{
	if(a.whichfloor>=b.whichfloor)
		return 1;
	else
		return 0;
}

void savesignal(Out &out,Elevator &elevator1,Elevator &elevator2)
{
	if(out.getdirection()==0)/*上行方向按钮*/
	{
		if(elevator1.getcondition()==0&&elevator2.getcondition()==0)/*两部电梯均处于空闲状态*/
		{
			if(elevator1.getwhichfloor()==elevator2.getwhichfloor())/*两部电梯处于同一楼层*/
			{
				if(out.whichfloor>=elevator1.getwhichfloor())
				{
					listfoup1.push_back(out);
					listfoup1.sort(cmp);
				}
				else
				{
					listfodown1.push_back(out);
					listfodown1.sort(cmp);
				}
			}
			else if(elevator1.getwhichfloor()>elevator2.getwhichfloor())/*电梯一在电梯二上面*/
			{
				if(out.whichfloor>=elevator1.getwhichfloor())
				{
					listfoup1.push_back(out);
					listfoup1.sort(cmp);
				}
				else if(out.whichfloor<elevator2.getwhichfloor())
				{
					listsodown1.push_back(out);
					listsodown1.sort(cmp);
				}
				else
				{
					if((elevator1.getwhichfloor()-out.whichfloor)<=(out.whichfloor-elevator2.getwhichfloor()))
					{
						listfodown1.push_back(out);
						listfodown1.sort(cmp);
					}
					else
					{
						listsoup1.push_back(out);
						listsoup1.sort(cmp);
					}
				}
			}
			else/*电梯一在电梯二下面*/
			{
				if(out.whichfloor>=elevator2.getwhichfloor())
				{
					listsoup1.push_back(out);
					listsoup1.sort(cmp);
				}
				else if(out.whichfloor<elevator1.getwhichfloor())
				{
					listfodown1.push_back(out);
					listfodown1.sort(cmp);
				}
				else
				{
					if((elevator2.getwhichfloor()-out.whichfloor)<(out.whichfloor-elevator1.getwhichfloor()))
					{
						listsodown1.push_back(out);
						listsodown1.sort(cmp);
					}
					else
					{
						listfoup1.push_back(out);
						listfoup1.sort(cmp);
					}
				}
			}
		}
		else if(elevator1.getcondition()!=0&&elevator2.getcondition()==0)/*电梯一运行状态，电梯二空闲状态*/
		{
			if(elevator1.getcondition()==1)/*电梯一处于上行状态*/
			{
				if(out.whichfloor<elevator1.getwhichfloor())
				{
					if(out.whichfloor<elevator2.getwhichfloor())
					{
						listsodown1.push_back(out);
						listsodown1.sort(cmp);
					}
					else
					{
						listsoup1.push_back(out);
						listsoup1.sort(cmp);
					}
				}
				else if(out.whichfloor==elevator1.getwhichfloor())
				{
					listfoup1.push_back(out);
					listfoup1.sort(cmp);
				}
				else
				{
					if(elevator1.getwhichfloor()>elevator2.getwhichfloor())
					{
						listfoup1.push_back(out);
						listfoup1.sort(cmp);
					}
					else if(elevator1.getwhichfloor()==elevator2.getwhichfloor())
					{
						listsoup1.push_back(out);
						listsoup1.sort(cmp);
					}
					else
					{
						if(out.whichfloor>=elevator2.getwhichfloor())
						{
							listsoup1.push_back(out);
							listsoup1.sort(cmp);
						}
						else
						{
							if((elevator2.getwhichfloor()-out.whichfloor)<=(out.whichfloor-elevator1.getwhichfloor()))
							{
								listsodown1.push_back(out);
								listsodown1.sort(cmp);
							}
							else
							{
								listfoup1.push_back(out);
								listfoup1.sort(cmp);
							}
						}
					}
				}
			}
			else
			{
				if(out.whichfloor>=elevator1.getwhichfloor())
				{
					if(out.whichfloor<elevator2.getwhichfloor())
					{
						listsodown1.push_back(out);
						listsodown1.sort(cmp);
					}
					else
					{
						listsoup1.push_back(out);
						listsoup1.sort(cmp);
					}
				}
				else
				{
					if(elevator1.getwhichfloor()<elevator2.getwhichfloor())
					{
						listfodown1.push_back(out);
						listfodown1.sort(cmp);
					}
					else if(elevator1.getwhichfloor()==elevator2.getwhichfloor())
					{
						listsodown1.push_back(out);
						listsodown1.sort(cmp);
					}
					else
					{
						if(out.whichfloor<=elevator2.getwhichfloor())
						{
							listsodown1.push_back(out);
						    listsodown1.sort(cmp);
						}
						else
						{
							if((elevator1.getwhichfloor()-out.whichfloor)<(out.whichfloor-elevator2.getwhichfloor()))
							{
								listfodown1.push_back(out);
								listfodown1.sort(cmp);
							}
							else
							{
								listsoup1.push_back(out);
								listsoup1.sort(cmp);
							}
						}
					}
				}
			}
		}
		else if(elevator1.getcondition()==0&&elevator2.getcondition()!=0)/*电梯二运行状态，电梯一空闲状态*/
		{
			if(elevator2.getcondition()==1)/*电梯二处于上行状态*/
			{
				if(out.whichfloor<elevator2.getwhichfloor())
				{
					if(out.whichfloor<elevator1.getwhichfloor())
					{
						listfodown1.push_back(out);
						listfodown1.sort(cmp);
					}
					else
					{
						listfoup1.push_back(out);
						listfoup1.sort(cmp);
					}
				}
				else if(out.whichfloor==elevator2.getwhichfloor())
				{
					listsoup1.push_back(out);
					listsoup1.sort(cmp);
				}
				else
				{
					if(elevator2.getwhichfloor()>elevator1.getwhichfloor())
					{
						listsoup1.push_back(out);
						listsoup1.sort(cmp);
					}
					else if(elevator2.getwhichfloor()==elevator1.getwhichfloor())
					{
						listfoup1.push_back(out);
						listfoup1.sort(cmp);
					}
					else
					{
						if(out.whichfloor>=elevator1.getwhichfloor())
						{
							listfoup1.push_back(out);
							listfoup1.sort(cmp);
						}
						else
						{
							if((elevator1.getwhichfloor()-out.whichfloor)<=(out.whichfloor-elevator2.getwhichfloor()))
							{
								listfodown1.push_back(out);
								listfodown1.sort(cmp);
							}
							else
							{
								listsoup1.push_back(out);
								listsoup1.sort(cmp);
							}
						}
					}
				}
			}
			else/*电梯二处于下行状态*/
			{
				if(out.whichfloor>=elevator2.getwhichfloor())
				{
					if(out.whichfloor<elevator1.getwhichfloor())
					{
						listfodown1.push_back(out);
						listfodown1.sort(cmp);
					}
					else
					{
						listfoup1.push_back(out);
						listfoup1.sort(cmp);
					}
				}
				else
				{
					if(elevator2.getwhichfloor()<elevator1.getwhichfloor())
					{
						listsodown1.push_back(out);
						listsodown1.sort(cmp);
					}
					else if(elevator2.getwhichfloor()==elevator1.getwhichfloor())
					{
						listfodown1.push_back(out);
						listfodown1.sort(cmp);
					}
					else
					{
						if(out.whichfloor<=elevator1.getwhichfloor())
						{
							listfodown1.push_back(out);
						    listfodown1.sort(cmp);
						}
						else
						{
							if((elevator2.getwhichfloor()-out.whichfloor)<(out.whichfloor-elevator1.getwhichfloor()))
							{
								listsodown1.push_back(out);
								listsodown1.sort(cmp);
							}
							else
							{
								listfoup1.push_back(out);
								listfoup1.sort(cmp);
							}
						}
					}
				}
			}
		}
		else/*两部电梯均处于运行状态*/
		{
			if(elevator1.getcondition()==1&&elevator2.getcondition()==1)/*两部电梯均处于上行状态*/
			{
				if(elevator1.getwhichfloor()==elevator2.getwhichfloor())
				{
					if(out.whichfloor>=elevator1.getwhichfloor())
					{
						listfoup1.push_back(out);
						listfoup1.sort(cmp);
					}
					else
					{
						listfodown1.push_back(out);
						listfodown1.sort(cmp);
					}
				}
				else if(elevator1.getwhichfloor()>elevator2.getwhichfloor())
				{
					if(out.whichfloor>=elevator1.getwhichfloor())
					{
						listfoup1.push_back(out);
						listfoup1.sort(cmp);
					}
					else if(out.whichfloor<elevator2.getwhichfloor())
					{
						listsodown1.push_back(out);
						listsodown1.sort(cmp);
					}
					else
					{
						listsoup1.push_back(out);
						listsoup1.sort(cmp);
					}
				}
				else
				{
					if(out.whichfloor>=elevator2.getwhichfloor())
					{
						listsoup1.push_back(out);
						listsoup1.sort(cmp);
					}
					else if(out.whichfloor<elevator1.getwhichfloor())
					{
						listfodown1.push_back(out);
						listfodown1.sort(cmp);
					}
					else
					{
						listfoup1.push_back(out);
						listfoup1.sort(cmp);
					}
				}
			}
			else if(elevator1.getcondition()==1&&elevator2.getcondition()==2)/*电梯一处于上行状态，电梯二处于下行状态*/
			{
				if(elevator1.getwhichfloor()==elevator2.getwhichfloor())
				{
					if(out.whichfloor>=elevator1.getwhichfloor())
					{
						listfoup1.push_back(out);
						listfoup1.sort(cmp);
					}
					else
					{
						listsodown1.push_back(out);
						listsodown1.sort(cmp);
					}
				}
				else if(elevator1.getwhichfloor()>elevator2.getwhichfloor())
				{
					if(out.whichfloor>=elevator1.getwhichfloor())
					{
						listfoup1.push_back(out);
						listfoup1.sort(cmp);
					}
					else if(out.whichfloor<=elevator2.getwhichfloor())
					{
						listsodown1.push_back(out);
						listsodown1.sort(cmp);
					}
					else
					{
						if((elevator1.getwhichfloor()-out.whichfloor)<=(out.whichfloor-elevator2.getwhichfloor()))
						{
							listfodown1.push_back(out);
							listfodown1.sort(cmp);
						}
						else
						{
							listsoup1.push_back(out);
							listsoup1.sort(cmp);
						}
					}
				}
				else
				{
					if(out.whichfloor>=elevator1.getwhichfloor())
					{
						listfoup1.push_back(out);
						listfoup1.sort(cmp);
					}
					else
					{
						listsodown1.push_back(out);
						listsodown1.sort(cmp);
					}
				}
			}
			else if(elevator1.getcondition()==2&&elevator2.getcondition()==1)/*电梯二处于上行状态，电梯一处于下行状态*/
			{
				if(elevator1.getwhichfloor()==elevator2.getwhichfloor())
				{
					if(out.whichfloor>=elevator1.getwhichfloor())
					{
						listsoup1.push_back(out);
						listsoup1.sort(cmp);
					}
					else
					{
						listfodown1.push_back(out);
						listfodown1.sort(cmp);
					}
				}
				else if(elevator1.getwhichfloor()>elevator2.getwhichfloor())
				{
					if(out.whichfloor>=elevator2.getwhichfloor())
					{
						listsoup1.push_back(out);
					    listsoup1.sort(cmp);
					}
					else
					{
						listfodown1.push_back(out);
					    listfodown1.sort(cmp);
					}
				}
				else
				{
					if(out.whichfloor>=elevator2.getwhichfloor())
					{
						listsoup1.push_back(out);
					    listsoup1.sort(cmp);
					}
					else if(out.whichfloor<=elevator1.getwhichfloor())
					{
						listfodown1.push_back(out);
					    listfodown1.sort(cmp);
					}
					else
					{
						if((elevator2.getwhichfloor()-out.whichfloor)<=(out.whichfloor-elevator1.getwhichfloor()))
						{
							listsodown1.push_back(out);
							listsodown1.sort(cmp);
						}
						else
						{
							listfoup1.push_back(out);
							listfoup1.sort(cmp);
						}
					}
				}
			}
			else/*两部电梯均处于下行状态*/
			{
				if(elevator1.getwhichfloor()==elevator2.getwhichfloor())
				{
					if(out.whichfloor>=elevator1.getwhichfloor())
					{
						listfoup1.push_back(out);
						listfoup1.sort(cmp);
					}
					else
					{
						listfodown1.push_back(out);
						listfodown1.sort(cmp);
					}
				}
				else if(elevator1.getwhichfloor()>elevator2.getwhichfloor())
				{
					if(out.whichfloor>=elevator1.getwhichfloor())
					{
						listfoup1.push_back(out);
						listfoup1.sort(cmp);
					}
					else if(out.whichfloor<=elevator2.getwhichfloor())
					{
						listsodown1.push_back(out);
						listsodown1.sort(cmp);
					}
					else
					{
						listfodown1.push_back(out);
						listfodown1.sort(cmp);
					}
				}
				else
				{
					if(out.whichfloor>=elevator2.getwhichfloor())
					{
						listsoup1.push_back(out);
						listsoup1.sort(cmp);
					}
					else if(out.whichfloor<=elevator1.getwhichfloor())
					{
						listfodown1.push_back(out);
						listfodown1.sort(cmp);
					}
					else
					{
						listsodown1.push_back(out);
						listsodown1.sort(cmp);
					}
				}
			}
		}
	}
	else/*下行方向按钮*/
	{
		if(elevator1.getcondition()==0&&elevator2.getcondition()==0)/*两部电梯均处于空闲状态*/
		{
			if(elevator1.getwhichfloor()==elevator2.getwhichfloor())/*两部电梯处于同一楼层*/
			{
				if(out.whichfloor>=elevator1.getwhichfloor())
				{
					listsoup2.push_back(out);
					listsoup2.sort(fcmp);
				}
				else
				{
					listsodown2.push_back(out);
					listsodown2.sort(fcmp);
				}
			}
			else if(elevator1.getwhichfloor()>elevator2.getwhichfloor())/*电梯一在电梯二上面*/
			{
				if(out.whichfloor>=elevator1.getwhichfloor())
				{
					listfoup2.push_back(out);
					listfoup2.sort(fcmp);
				}
				else if(out.whichfloor<=elevator2.getwhichfloor())
				{
					listsodown2.push_back(out);
					listsodown2.sort(fcmp);
				}
				else
				{
					if((elevator1.getwhichfloor()-out.whichfloor)<(out.whichfloor-elevator2.getwhichfloor()))
					{
						listfodown2.push_back(out);
						listfodown2.sort(fcmp);
					}
					else
					{
						listsoup2.push_back(out);
						listsoup2.sort(fcmp);
					}
				}
			}
			else/*电梯一在电梯二下面*/
			{
				if(out.whichfloor>=elevator2.getwhichfloor())
				{
					listsoup2.push_back(out);
					listsoup2.sort(fcmp);
				}
				else if(out.whichfloor<=elevator1.getwhichfloor())
				{
					listfodown2.push_back(out);
					listfodown2.sort(fcmp);
				}
				else
				{
					if((elevator2.getwhichfloor()-out.whichfloor)<=(out.whichfloor-elevator1.getwhichfloor()))
					{
						listsodown2.push_back(out);
						listsodown2.sort(fcmp);
					}
					else
					{
						listfoup2.push_back(out);
						listfoup2.sort(fcmp);
					}
				}
			}
		}
		else if(elevator1.getcondition()!=0&&elevator2.getcondition()==0)/*电梯一处于运行状态，电梯二处于空闲状态*/
		{
			if(elevator1.getcondition()==1)
			{
				if(out.whichfloor<=elevator1.getwhichfloor())
				{
					if(out.whichfloor>=elevator2.getwhichfloor())
					{
						listsoup2.push_back(out);
						listsoup2.sort(fcmp);
					}
					else
					{
						listsodown2.push_back(out);
						listsodown2.sort(fcmp);
					}
				}
				else
				{
					if(elevator1.getwhichfloor()>elevator2.getwhichfloor())
					{
						listfoup2.push_back(out);
						listfoup2.sort(fcmp);
					}
					else if(elevator1.getwhichfloor()==elevator2.getwhichfloor())
					{
						listsoup2.push_back(out);
						listsoup2.sort(fcmp);
					}
					else
					{
						if(out.whichfloor>=elevator2.getwhichfloor())
						{
							listsoup2.push_back(out);
							listsoup2.sort(fcmp);
						}
						else
						{
							if((elevator2.getwhichfloor()-out.whichfloor)<=(out.whichfloor-elevator1.getwhichfloor()))
							{
								listsodown2.push_back(out);
								listsodown2.sort(fcmp);
							}
							else
							{
								listfoup2.push_back(out);
								listfoup2.sort(fcmp);
							}
						}
					}
				}
			}
			else/*电梯一处于下行状态*/
			{
				if(out.whichfloor>elevator1.getwhichfloor())
				{
					if(out.whichfloor>=elevator2.getwhichfloor())
					{
						listsoup2.push_back(out);
						listsoup2.sort(fcmp);
					}
					else
					{
						listsodown2.push_back(out);
						listsodown2.sort(fcmp);
					}
				}
				else if(out.whichfloor==elevator1.getwhichfloor())
				{
					listfodown2.push_back(out);
					listfodown2.sort(fcmp);
				}
				else
				{
					if(elevator2.getwhichfloor()>elevator1.getwhichfloor())
					{
						listfodown2.push_back(out);
						listfodown2.sort(fcmp);
					}
					else if(elevator2.getwhichfloor()==elevator1.getwhichfloor())
					{
						listsodown2.push_back(out);
						listsodown2.sort(fcmp);
					}
					else
					{
						if(out.whichfloor<=elevator2.getwhichfloor())
						{
							listsodown2.push_back(out);
							listsodown2.sort(fcmp);
						}
						else
						{
							if((elevator1.getwhichfloor()-out.whichfloor)<(out.whichfloor-elevator2.getwhichfloor()))
							{
								listfodown2.push_back(out);
								listfodown2.sort(fcmp);
							}
							else
							{
								listsoup2.push_back(out);
								listsoup2.sort(fcmp);
							}
						}
					}
				}
			}
		}
		else if(elevator1.getcondition()==0&&elevator2.getcondition()!=0)/*电梯一处于空闲状态，电梯二处于运行状态*/
		{
			if(elevator2.getcondition()==1)
			{
				if(out.whichfloor<=elevator2.getwhichfloor())
				{
					if(out.whichfloor>elevator1.getwhichfloor())
					{
						listfoup2.push_back(out);
						listfoup2.sort(fcmp);
					}
					else
					{
						listfodown2.push_back(out);
						listfodown2.sort(fcmp);
					}
				}
				else
				{
					if(elevator1.getwhichfloor()>elevator2.getwhichfloor())
					{
						if(out.whichfloor>=elevator1.getwhichfloor())
						{
							listfoup2.push_back(out);
							listfoup2.sort(fcmp);
						}
						else
						{
							if((elevator1.getwhichfloor()-out.whichfloor)<=(out.whichfloor-elevator2.getwhichfloor()))
							{
								listfodown2.push_back(out);
								listfodown2.sort(fcmp);
							}
							else
							{
								listsoup2.push_back(out);
								listsoup2.sort(fcmp);
							}
						}
					}
					else if(elevator1.getwhichfloor()==elevator2.getwhichfloor())
					{
						listfoup2.push_back(out);
						listfoup2.sort(fcmp);
					}
					else
					{
						listsoup2.push_back(out);
						listsoup2.sort(fcmp);
					}
				}
			}
			else
			{
				if(out.whichfloor>elevator2.getwhichfloor())
				{
					if(out.whichfloor>=elevator1.getwhichfloor())
					{
						listfoup2.push_back(out);
						listfoup2.sort(fcmp);
					}
					else
					{
						listfodown2.push_back(out);
						listfodown2.sort(fcmp);
					}
				}
				else if(out.whichfloor==elevator2.getwhichfloor())
				{
					listsodown2.push_back(out);
					listsodown2.sort(fcmp);
				}
				else
				{
					if(elevator1.getwhichfloor()>elevator2.getwhichfloor())
					{
						listsodown2.push_back(out);
						listsodown2.sort(fcmp);
					}
					else if(elevator1.getwhichfloor()==elevator2.getwhichfloor())
					{
						listfodown2.push_back(out);
						listfodown2.sort(fcmp);
					}
					else
					{
						if(elevator1.getwhichfloor()>=out.whichfloor)
						{
							listfodown2.push_back(out);
							listfodown2.sort(fcmp);
						}
						else
						{
							if((elevator2.getwhichfloor()-out.whichfloor)<(out.whichfloor-elevator1.getwhichfloor()))
							{
								listsodown2.push_back(out);
								listsodown2.sort(fcmp);
							}
							else
							{
								listfoup2.push_back(out);
								listfoup2.sort(fcmp);
							}
						}
					}
				}
			}
		}
		else/*两部电梯均处于运行状态*/
		{
			if(elevator1.getcondition()==1&&elevator1.getcondition()==1)/*两部电梯均处于上行状态*/
			{
				if(elevator1.getwhichfloor()==elevator2.getwhichfloor())
				{
					if(out.whichfloor>elevator2.getwhichfloor())
					{
						listsoup2.push_back(out);
						listsoup2.sort(fcmp);
					}
					else
					{
						listsodown2.push_back(out);
						listsodown2.sort(fcmp);
					}
				}
				else if(elevator1.getwhichfloor()>elevator2.getwhichfloor())
				{
					if(out.whichfloor>=elevator1.getwhichfloor())
					{
						listfoup2.push_back(out);
						listfoup2.sort(fcmp);
					}
					else if(out.whichfloor<=elevator2.getwhichfloor())
					{
						listsodown2.push_back(out);
						listsodown2.sort(fcmp);
					}
					else
					{
						listsoup2.push_back(out);
						listsoup2.sort(fcmp);
					}
				}
				else
				{
					if(out.whichfloor>=elevator2.getwhichfloor())
					{
						listsoup2.push_back(out);
						listsoup2.sort(fcmp);
					}
					else if(out.whichfloor<=elevator1.getwhichfloor())
					{
						listfodown2.push_back(out);
						listfodown2.sort(fcmp);
					}
					else
					{
						listfoup2.push_back(out);
						listfoup2.sort(fcmp);
					}
				}
			}
			else if(elevator1.getcondition()==1&&elevator1.getcondition()==2)/*电梯一处于上行状态，电梯二处于下行状态*/
			{
				if(elevator1.getwhichfloor()==elevator2.getwhichfloor())
				{
					if(out.whichfloor>elevator1.getwhichfloor())
					{
						listfoup2.push_back(out);
						listfoup2.sort(fcmp);
					}
					else
					{
						listsodown2.push_back(out);
						listsodown2.sort(fcmp);
					}
				}
				else if(elevator1.getwhichfloor()>elevator2.getwhichfloor())/*电梯一在电梯二上面*/
				{
					if(out.whichfloor>=elevator1.getwhichfloor())
					{
						listfoup2.push_back(out);
						listfoup2.sort(fcmp);
					}
					else if(out.whichfloor<=elevator2.getwhichfloor())
					{
						listsodown2.push_back(out);
						listsodown2.sort(fcmp);
					}
					else
					{
						if((elevator1.getwhichfloor()-out.whichfloor)<(out.whichfloor-elevator2.getwhichfloor()))
						{
							listfodown2.push_back(out);
							listfodown2.sort(fcmp);
						}
						else
						{
							listsoup2.push_back(out);
							listsoup2.sort(fcmp);
						}
					}
				}
				else/*电梯一在电梯二下面*/
				{
					if(out.whichfloor>elevator2.getwhichfloor())
					{
						listfoup2.push_back(out);
						listfoup2.sort(fcmp);
					}
					else
					{
						listsodown2.push_back(out);
						listsodown2.sort(fcmp);
					}
				}
			}
			else if(elevator1.getcondition()==2&&elevator1.getcondition()==1)/*电梯一处于下行状态，电梯二处于上行状态*/
			{
				if(elevator1.getwhichfloor()==elevator2.getwhichfloor())
				{
					if(out.whichfloor>elevator2.getwhichfloor())
					{
						listsoup2.push_back(out);
						listsoup2.sort(fcmp);
					}
					else
					{
						listfodown2.push_back(out);
						listfodown2.sort(fcmp);
					}
				}
				else if(elevator1.getwhichfloor()>elevator2.getwhichfloor())/*电梯一在电梯二上面*/
				{
					if(out.whichfloor>elevator1.getwhichfloor())
					{
						listsoup2.push_back(out);
						listsoup2.sort(fcmp);
					}
					else
					{
						listfodown2.push_back(out);
						listfodown2.sort(fcmp);
					}
				}
				else/*电梯一在电梯二下面*/
				{
					if(out.whichfloor>=elevator2.getwhichfloor())
					{
						listsoup2.push_back(out);
						listsoup2.sort(fcmp);
					}
					else if(out.whichfloor<=elevator1.getwhichfloor())
					{
						listfodown2.push_back(out);
						listfodown2.sort(fcmp);
					}
					else
					{
						if((elevator2.getwhichfloor()-out.whichfloor)<=(out.whichfloor-elevator1.getwhichfloor()))
						{
							listsodown2.push_back(out);
							listsodown2.sort(fcmp);
						}
						else
						{
							listfoup2.push_back(out);
							listfoup2.sort(fcmp);
						}
					}
				}
			}
			else/*两部电梯均处于下行状态*/
			{
				if(elevator1.getwhichfloor()==elevator2.getwhichfloor())
				{
					if(out.whichfloor>elevator2.getwhichfloor())
					{
						listsoup2.push_back(out);
						listsoup2.sort(fcmp);
					}
					else
					{
						listsodown2.push_back(out);
						listsodown2.sort(fcmp);
					}
				}
				else if(elevator1.getwhichfloor()>elevator2.getwhichfloor())
				{
					if(out.whichfloor>=elevator1.getwhichfloor())
					{
						listfoup2.push_back(out);
						listfoup2.sort(fcmp);
					}
					else if(out.whichfloor<=elevator2.getwhichfloor())
					{
						listsodown2.push_back(out);
						listsodown2.sort(fcmp);
					}
					else
					{
						listfodown2.push_back(out);
						listfodown2.sort(fcmp);
					}
				}
				else
				{
					if(out.whichfloor>=elevator2.getwhichfloor())
					{
						listsoup2.push_back(out);
						listsoup2.sort(fcmp);
					}
					else if(out.whichfloor<=elevator1.getwhichfloor())
					{
						listfodown2.push_back(out);
						listfodown2.sort(fcmp);
					}
					else
					{
						listsodown2.push_back(out);
						listsodown2.sort(fcmp);
					}
				}
			}
		}
	}
}


void savesignal(In &in, Elevator &elevator)
{
	if(in.getwhichele()==1)/*第一部电梯信号*/
	{
		if(in.whichfloor>elevator.getwhichfloor())/*信号楼层比当前电梯楼层高*/
		{
			k=0;
			listfiup.push_back(in);
			listfiup.sort(cmp);
			for(i=listfiup.begin();i!=listfiup.end();i++)
			{
				if((*i)==in)
				{
					k++;
				}
			}
			if(k!=1)
			{
				listfiup.remove(in);
			}
		}
		else if(in.whichfloor<elevator.getwhichfloor())/*信号楼层比当前电梯楼层低*/
		{
			k=0;
			listfidown.push_back(in);
			listfidown.sort(cmp);
			for(i=listfidown.begin();i!=listfidown.end();i++)
			{
				if((*i)==in)
				{
					k++;
				}
			}
			if(k!=1)
			{
				listfidown.remove(in);
			}
		}
	}
	else/*第二部电梯信号*/
	{
		if(in.whichfloor>elevator.getwhichfloor())/*信号楼层比当前电梯楼层高*/
		{
			k=0;
			listsiup.push_back(in);
			listsiup.sort(cmp);
			for(i=listsiup.begin();i!=listsiup.end();i++)
			{
				if((*i)==in)
				{
					k++;
				}
			}
			if(k!=1)
			{
				listsiup.remove(in);
			}
		}
		else if(in.whichfloor<elevator.getwhichfloor())/*信号楼层比当前电梯楼层低*/
		{
			k=0;
			listsidown.push_back(in);
			listsidown.sort(cmp);
			for(i=listsidown.begin();i!=listsidown.end();i++)
			{
				if((*i)==in)
				{
					k++;
				}
			}
			if(k!=1)
			{
				listsidown.remove(in);
			}
		}
	}
}


Signal getsignal(Elevator &elevator)
{
	if(elevator.getnum()==1)
	{
		if(listfiup.empty()==1&&listfidown.empty()==1&&listfoup1.empty()==1&&listfodown1.empty()==1&&listfoup2.empty()==1&&listfodown2.empty()==1)
		{
			Signal signal(0);
			return signal;
		}
		else{
			if(elevator.getcondition()==0)/*电梯处于空闲状态*/
			{
				if(listfiup.empty()==0)
				{
					return listfiup.front();
				}
				else if(listfidown.empty()==0)
				{
					return listfidown.front();
				}
				else if(listfoup1.empty()==0)
				{
					return listfoup1.front();
				}
				else if(listfodown1.empty()==0)
				{
					return listfodown1.front();
				}
				else if(listfoup2.empty()==0)
				{
					return listfoup2.front();
				}
				else if(listfodown2.empty()==0)
				{
					return listfodown2.front();
				}
			}
			else if(elevator.getcondition()==1)/*电梯处于上行状态*/
			{
				if(listfiup.empty()==0&&listfoup1.empty()==0)
				{
					a=listfiup.front().whichfloor;
					b=listfoup1.front().whichfloor;
					if(a<b)
						return listfiup.front();
					else if(a>b)
						return listfoup1.front();
					else
					{
						return listfiup.front();
						listfoup1.pop_front();
					}
				}
				else if(listfiup.empty()==0&&listfoup1.empty()==1)
					return listfiup.front();
				else if(listfiup.empty()==1&&listfoup1.empty()==0)
					return listfoup1.front();
				else
				{
					if(listfoup2.empty()==0)
						return listfoup2.front();
					else if(listfidown.empty()==0&&listfodown2.empty()==0)
					{
						a=listfidown.front().whichfloor;
						b=listfodown2.front().whichfloor;
						if(a<b)
							return listfodown2.front();
						else if(a>b)
							return listfidown.front();
						else
						{
							return listfidown.front();
							listfodown2.pop_front();
						}
					}
					else if(listfidown.empty()==1&&listfodown2.empty()==0)
						return listfidown.front();
					else if(listfidown.empty()==0&&listfodown2.empty()==1)
						return listfodown2.front();
					else
						return listfodown1.front();
				}
			}
			else/*电梯处于下行状态*/
			{
				if(listfidown.empty()==0&&listfodown2.empty()==0)
				{
					a=listfidown.front().whichfloor;
					b=listfodown2.front().whichfloor;
					if(a<b)
						return listfodown2.front();
					else if(a>b)
						return listfidown.front();
					else
					{
						return listfidown.front();
						listfodown2.pop_front();
					}
				}
				else if(listfidown.empty()==1&&listfodown2.empty()==0)
					return listfidown.front();
				else if(listfidown.empty()==0&&listfodown2.empty()==1)
					return listfodown2.front();
				else
				{
					if(listfodown1.empty()==0)
						return listfodown1.front();
					else if(listfiup.empty()==0&&listfoup1.empty()==0)
					{
						a=listfiup.front().whichfloor;
						b=listfoup1.front().whichfloor;
						if(a<b)
							return listfiup.front();
						else if(a>b)
							return listfoup1.front();
						else
						{
							return listfiup.front();
							listfoup1.pop_front();
						}
					}
					else if(listfiup.empty()==1&&listfoup1.empty()==0)
						return listfiup.front();
					else if(listfiup.empty()==0&&listfoup1.empty()==1)
						return listfoup1.front();
					else
						return listfoup2.front();
				}
			}
		}
	}
	else
	{
		if(listsiup.empty()==1&&listsidown.empty()==1&&listsoup1.empty()==1&&listsodown1.empty()==1&&listsoup2.empty()==1&&listsodown2.empty()==1)
		{
			Signal signal(0);
			return signal;
		}
		else{
			if(elevator.getcondition()==0)/*电梯处于空闲状态*/
			{
				if(listsiup.empty()==0)
				{
					return listsiup.front();
				}
				else if(listsidown.empty()==0)
				{
					return listsidown.front();
				}
				else if(listsoup1.empty()==0)
				{
					return listsoup1.front();
				}
				else if(listsodown1.empty()==0)
				{
					return listsodown1.front();
				}
				else if(listsoup2.empty()==0)
				{
					return listsoup2.front();
				}
				else if(listsodown2.empty()==0)
				{
					return listsodown2.front();
				}
			}
			else if(elevator.getcondition()==1)/*电梯处于上行状态*/
			{
				if(listsiup.empty()==0&&listsoup1.empty()==0)
				{
					a=listsiup.front().whichfloor;
					b=listsoup1.front().whichfloor;
					if(a<b)
						return listsiup.front();
					else if(a>b)
						return listsoup1.front();
					else
					{
						return listsiup.front();
						listsoup1.pop_front();
					}
				}
				else if(listsiup.empty()==0&&listsoup1.empty()==1)
					return listsiup.front();
				else if(listsiup.empty()==1&&listsoup1.empty()==0)
					return listsoup1.front();
				else
				{
					if(listsoup2.empty()==0)
						return listsoup2.front();
					else if(listsidown.empty()==0&&listsodown2.empty()==0)
					{
						a=listsidown.front().whichfloor;
						b=listsodown2.front().whichfloor;
						if(a<b)
							return listsodown2.front();
						else if(a>b)
							return listsidown.front();
						else
						{
							return listsidown.front();
							listsodown2.pop_front();
						}
					}
					else if(listsidown.empty()==1&&listsodown2.empty()==0)
						return listsidown.front();
					else if(listsidown.empty()==0&&listsodown2.empty()==1)
						return listsodown2.front();
					else
						return listsodown1.front();
				}
			}
			else/*电梯处于下行状态*/
			{
				if(listsidown.empty()==0&&listsodown2.empty()==0)
				{
					a=listsidown.front().whichfloor;
					b=listsodown2.front().whichfloor;
					if(a<b)
						return listsodown2.front();
					else if(a>b)
						return listsidown.front();
					else
					{
						return listsidown.front();
						listsodown2.pop_front();
					}
				}
				else if(listsidown.empty()==1&&listsodown2.empty()==0)
					return listsidown.front();
				else if(listsidown.empty()==0&&listsodown2.empty()==1)
					return listsodown2.front();
				else
				{
					if(listsodown1.empty()==0)
						return listsodown1.front();
					else if(listsiup.empty()==0&&listsoup1.empty()==0)
					{
						a=listsiup.front().whichfloor;
						b=listsoup1.front().whichfloor;
						if(a<b)
							return listsiup.front();
						else if(a>b)
							return listsoup1.front();
						else
						{
							return listsiup.front();
							listsoup1.pop_front();
						}
					}
					else if(listsiup.empty()==1&&listsoup1.empty()==0)
						return listsiup.front();
					else if(listsiup.empty()==0&&listsoup1.empty()==1)
						return listsoup1.front();
					else
						return listsoup2.front();
				}
			}
		}
	}
}

void deletesignal(Elevator &elevator)
{
	if(elevator.getnum()==1)
	{
		In in(1,elevator.getwhichfloor());
		listfiup.remove(in);
		listfidown.remove(in);
		if(elevator.getcondition()==0)
		{
			Out out1(0,elevator.getwhichfloor());
			Out out2(1,elevator.getwhichfloor());
			listfoup1.remove(out1);
			listfodown1.remove(out1);
			listfoup2.remove(out2);
			listfodown2.remove(out2);
		}
		else if(elevator.getcondition()==1)
		{
			Out out1(0,elevator.getwhichfloor());
			Out out2(1,elevator.getwhichfloor());
			if(listfoup1.empty()==0||listfodown1.empty()==0)
			{
				listfoup1.remove(out1);
				listfodown1.remove(out1);
			}
			else
			{
				listfoup2.remove(out2);
				listfodown2.remove(out2);
			}
		}
		else
		{
			Out out1(0,elevator.getwhichfloor());
			Out out2(1,elevator.getwhichfloor());
			if(listfoup2.empty()==0||listfodown2.empty()==0)
			{
				listfoup2.remove(out2);
				listfodown2.remove(out2);
			}
			else
			{
				listfoup1.remove(out1);
				listfodown1.remove(out1);
			}
		}
	}
	else
	{
		In in(2,elevator.getwhichfloor());
		listsiup.remove(in);
		listsidown.remove(in);
		if(elevator.getcondition()==0)
		{
			Out out1(0,elevator.getwhichfloor());
			Out out2(1,elevator.getwhichfloor());
			listsoup1.remove(out1);
			listsodown1.remove(out1);
			listsoup2.remove(out2);
			listsodown2.remove(out2);
		}
		else if(elevator.getcondition()==1)
		{
			Out out1(0,elevator.getwhichfloor());
			Out out2(1,elevator.getwhichfloor());
			if(listsoup1.empty()==0||listsodown1.empty()==0)
			{
				listsoup1.remove(out1);
				listsodown1.remove(out1);
			}
			else
			{
				listsoup2.remove(out2);
				listsodown2.remove(out2);
			}
		}
		else
		{
			Out out1(0,elevator.getwhichfloor());
			Out out2(1,elevator.getwhichfloor());
			if(listsoup2.empty()==0||listsodown2.empty()==0)
			{
				listsoup2.remove(out2);
				listsodown2.remove(out2);
			}
			else
			{
				listsoup1.remove(out1);
				listsodown1.remove(out1);
			}
		}
	}
}r