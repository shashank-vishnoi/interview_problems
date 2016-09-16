/* It works as mediator for two incompatible interfaces*/


#include<iostream>

using namespace std;


class Power{
	public:
	int volt;
		Power():volt(110)
		{}
		int get_power()
		{return volt;}
};

class Charger{
	public:
		Power p;
		int get_power(){return p.volt;}
};

class AdapterCharger:public Charger{
	public:
		int get_power()
		{
			return Charger::get_power()/11;
		}

};

int main()
{
	Charger c1;
	cout<<c1.get_power()<<endl;
	AdapterCharger ac1;
	cout<<ac1.get_power()<<endl;
}


