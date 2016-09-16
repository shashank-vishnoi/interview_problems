#include<iostream>

using namespace std;


class Car{
	public:
		string body;
		string engine;
		string wheels;
		void print_specifications()
		{
			cout<<"Body: "<<body<<endl;
			cout<<"Engine: "<<engine<<endl;
			cout<<"Wheels: "<<wheels<<endl;
		}
};

class Builder{
	public:
	Car *car;
	virtual string buildBody()=0;
	virtual string buildEngine()=0;
	virtual string buildWheels()=0;
};


class SUV:public Builder{
	public:
	string buildBody(){ return "SUV body";}
	string buildEngine(){ return "SUV engine";};
	string buildWheels(){ return "SUV wheels";}
};

class HatchBack: public Builder{
	public:
	string buildBody(){ return "HatchBack body";}
	string buildEngine(){ return "HatchBack Engine";};
	string buildWheels(){ return "HatchBack wheels";}

};


class Director{
	Builder* build;
	public:
		Car* get_car()
		{
			Car *car = new Car();
			car->body = build->buildBody();
		        car->engine = build->buildEngine();
			car->wheels = build->buildWheels();	
			return car;
		}
		Director(Builder* b):build(b){}
};



int main()
{
	Director d(new SUV);
	Car* car = d.get_car();
	car->print_specifications();
}
