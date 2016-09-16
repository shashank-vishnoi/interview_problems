#include<iostream>

using namespace std;
class Body;

class Vehicle{
	Body* body;
	public:
		virtual void buildEngine()=0;
		virtual void buildBody()=0;
		//virtual void assembleWheels()=0;
		void setBodyType(string type){
			if (type == "STANDARD")
				body = new Stnadard();
			else
				body = new Modern();
		}
};


class Body{
	public:
		virtual void create()=0;
};

class Stnadard:public Body{
	public:
		void create(){cout<<"standard body\n";}
};

class Modern:public Body{
	public:
		void create(){cout<<"modern body\n";}

};

class Scooter:public Vehicle{
	public:
	void buildBody()
	{
		body->create();
	}
	void buildEngine()
	{
		cout<<"Scooter engine is done\n";
	}
};


class Director{
	Vehicle *builder;
	string type;
	public:
		Director(Vehicle* v, string type){ builder = v; builder.setBodyType(type);}
		void buildVehicle(string type)
		{
			if(type == "STANDARD")
			{
				builder->buildEngine();
				builder->buildBody()
			}
			else if(type == "MODERN")
			{

			}
		}
};


int main()
{
	Director d;

	d.setBuild();
}
