#include<iostream>

using namespace std;

class Behaviour{
	public:
		virtual void move()=0;
		virtual void fire()=0;
};

class Normal:public Behaviour{
	public:
		void move()
		{cout<<"Normal::move()\n";}
		void fire()
		{cout<<"Normal::fire()\n";}
};
class Aggressive:public Behaviour{
	public:
		void move()
		{cout<<"Aggressive::move()\n";}
		void fire()
		{cout<<"Aggressive::fire()\n";}
};
class Hurt:public Behaviour{
	public:
		void move()
		{cout<<"Hurt::move()\n";}
		void fire()
		{cout<<"Hurt::fire()\n";}
};

class Player{
	Behaviour *mood;
	public:
	Player(){mood= new Normal();}
	void get_charge()
	{
		delete mood;
		mood = new Aggressive();
	}
	void get_hurt()
	{
		delete mood;
		mood = new Hurt();
	}
	~Player()
	{delete mood;}
	void move(){mood->move();}
	void fire(){mood->fire();}
};

int main()
{
	Player p1;
	p1.move();
	p1.fire();
	p1.get_charge();
	p1.fire();
	p1.get_hurt();
	p1.fire();
}
