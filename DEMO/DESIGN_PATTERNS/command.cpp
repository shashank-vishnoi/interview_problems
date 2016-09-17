#include<iostream>
#include <map>

using namespace std;

enum Buttons {BUTTON_A, BUTTON_B, BUTTON_X, BUTTON_Y};
enum Actions {JUMP, FIRE, RUN, HIT};

class Command{
	public:
	virtual void execute()=0;

};
class Jump:public Command{
	public:
	void execute(){cout<<"Jump\n";}
};
class Fire:public Command{
	public:
	void execute(){cout<<"Fire\n";}
};
class Run:public Command{
	public:
	void execute(){cout<<"Run\n";}
};
class Hit:public Command{
	public:
	void execute(){cout<<"Hit\n";}
};


class RemoteController{

	map<Buttons, Command* > mymap;
	public:
	RemoteController()
	{
			
	}
	void setAction(Buttons b, Actions a)
	{
		if(a == JUMP)
			mymap.insert(make_pair<Buttons, Command* >(b,new Jump()));
		else if(a == FIRE)
			mymap.insert(make_pair<Buttons, Command* >(b,new Fire()));
		else if(a == RUN)
			mymap.insert(make_pair<Buttons, Command* >(b,new Run()));
		else if(a == HIT)
			mymap.insert(make_pair<Buttons, Command* >(b,new Hit()));
	}
	void pressButton(Buttons b)
	{
		mymap[b]->execute();
	}
};


int main()
{
	RemoteController remote;
	remote.setAction(BUTTON_A,JUMP);
	remote.setAction(BUTTON_B, FIRE);
	remote.setAction(BUTTON_X,HIT);
	remote.setAction(BUTTON_Y,RUN);

	remote.pressButton(BUTTON_A);
	remote.pressButton(BUTTON_X);
	remote.pressButton(BUTTON_Y);

	remote.pressButton(BUTTON_B);
	remote.pressButton(BUTTON_B);
	remote.pressButton(BUTTON_B);
	remote.pressButton(BUTTON_Y);
	remote.pressButton(BUTTON_Y);
}
