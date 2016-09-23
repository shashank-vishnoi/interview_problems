/*Observer: Behvioral DP*/

/*1 to M mapping: If one object changes the state than notification to be made to all Observer objects*/
/*An object that is subjected to change is called a Subject and an object that depends on the Subject's state is called an Observer.*/

/*Example: publisher releases the Magzine and observer notify to registered consumer whenever new Magzine is arrived in the market*/

/*
Observer: will make a list of all subscribed subscriber
Publisher: Whenevr Publisher publish(i.e. craete a new object) then will notify the Observer object,Observer object in turn will update all the registered subscribers.

	
*/

#include<iostream>
#include<vector>
#include<string>


using namespace std;


class Observer{
	public:
	vector<Observer*> subscribers;
	void AddSubscription(Observer *o)
	{
		subscribers.push_back(o);
	}
	void RemoveSubscription(Observer *o)
	{
	}
	void notify()
	{
		cout<<"observer::notification will be sent shortly... \n";
		cout<<"Total Subscribers: "<<subscribers.size()<<endl;
		for(int i=0;i<subscribers.size();i++)
			subscribers[i]->update();
	}
	virtual void update()
	{
	}
};



class Publisher{
        public:
        string magzine;
        void publish(string name,Observer *o)
        {
                magzine=name;
                cout<<"new Magzine published name: "<<name<<endl;
                o->notify();

        }

};



class Consumer1:public Observer{
	public:
	void update()
	{
		cout<<"Consumer1 is updated\n";
	}
};

class Consumer2:public Observer{
	public:
	void update()
	{
		cout<<"Consumer2 is updated\n";
	}
};

class Consumer3:public Observer{
	public:
	void update()
	{
		cout<<"Consumer3 is updated\n";
	}
};

class Consumer4:public Observer{
	public:
	void update()
	{
		cout<<"Consumer4 is updated\n";
	}
};



int main()
{
	Observer o;
	o.AddSubscription(new Consumer1);
	o.AddSubscription(new Consumer2);
	o.AddSubscription(new Consumer3);
	Publisher p;
	p.publish("Dhamaka",&o);
	Observer o2;
	o2.AddSubscription(new Consumer3);
	o2.AddSubscription(new Consumer4);
	p.publish("yakuuu",&o2);

}
