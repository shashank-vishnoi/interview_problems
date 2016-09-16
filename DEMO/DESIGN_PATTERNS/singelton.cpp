#include<iostream>

using namespace std;


class Singelton{
	static Singelton* ins;
	Singelton(){cout<<"object is created\n";}
	public:
	static Singelton* get_instance()
	{
		if(!ins)
			if(!ins)
				ins = new Singelton();
		return ins;
	}
};

Singelton* Singelton::ins=0;


int main()
{
	Singelton* obj=Singelton::get_instance();
	Singelton* obj1=Singelton::get_instance();
	Singelton* obj2=Singelton::get_instance();
	Singelton* obj3=Singelton::get_instance();
}
