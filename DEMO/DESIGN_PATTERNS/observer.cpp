/*Now a days merchant sites provide one feature that is "Notify Me" in case product is not available during buyer wants to buy- this is good example of observer pattern
 Observer pattern comes under behavioral patterns - it has two main compnents 1. Subject(maintains the list of observer/listener) who notifies 2. Observer/Listner (who wants to be notified )
 
 */

#include<iostream>
#include<vector>
using namespace std;



class Observer{
	string name;
	public:
		Observer(string n):name(n)
		{}
	virtual void get_notification()
	{
		cout<<name + " I got notifcation from Merchant\n";
	}
};


class user1:public Observer{
	public:
	void get_notification()
	{cout<<"user1 ->I got notifcation from Merchant\n";}
};
class user2:public Observer{
	public:
	void get_notification()
	{cout<<"user2 ->I got notifcation from Merchant\n";}
};

class Subject{
	public:
		vector<Observer*> list;
		void register_listener(Observer* o)
		{ list.push_back(o);}
		void product_available()
		{
			for(vector<Observer*>::iterator it=list.begin(); it!= list.end(); it++)
			{
				(*it)->get_notification();
			}
		}
};



int main()
{
	Subject s;
	Observer u1("ABC"),u2("ZYX");
	s.register_listener(&u1);
	s.register_listener( &u2);
	s.product_available();

}
