#include<iostream>
//4:15 --> 4:15 AM
//23:10 --> 11:10 PM
using namespace std;

//1. Check if date =< 12 then add AM
//2. If date > 12 then (date-12 + add PM )



void convert(const char time[], int len)
{
	int i=0, base = 10, new_time=0;
	while(time[i] != '\0')
	{
		int digit = (time[i] - (int)'0'); 
		if(int(time[i] - (int)'0') >= 0 && int(time[i] - (int)'0') <9 )
		{
			new_time = new_time + (int(time[i++] - (int)'0')) * base;
			base= base/10;
		}
		if(base <= 0)
			break;

	}
	if(new_time > 12)
	{
		new_time -=12;
		cout<<new_time<<":"<<*(time+3)<<time[4]<<" PM"<<endl;
	}
	else if(new_time == 12)
	{
		if(time[3] == '0' && time[4] == '0')
			cout<<time<<" AM"<<endl;
		else
			cout<<time<<" PM"<<endl;
	}
	else
	{
		cout<<time<<" AM"<<endl;
	}
	
}



int main()
{
	char time[]="23:10";
	int len = sizeof(time)/sizeof(char);


	convert(time, len);
	char time1[]="04:15";
	convert(time1, len);
	char time2[]="12:15";
	convert(time2, len);
	char time3[]="12:00";
	convert(time3, len);
}
