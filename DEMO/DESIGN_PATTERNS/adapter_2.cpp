#include<iostream>

using namespace std;


class PowerPlug{
	int volt;
	public:
	PowerPlug():volt(110){}
	int get_volt(){return volt;}
};

class Charger{
	public:
		PowerPlug p;
		int get_power(){return p.get_volt();}
};

class AdapterCharger: public Charger{
	public:
		int get_power(){return p.get_volt()/10;}
};

int main()
{
	AdapterCharger c;
	cout<<c.get_power();
}
