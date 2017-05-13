/**
Chain Of responsibilty: This Pattern comes under Behavioral Pattern.
It cretaes rail of handlers and client submit the request that goes to set of handlers until it is fulfiled or default handle

  */
#include<iostream>

using namespace std;

class MoneyHandler{
	public:
	MoneyHandler* next;
	void virtual setHandler(MoneyHandler*)=0;
	void virtual processRequest(int money)=0;
};

class TwoThousand: public MoneyHandler{
	public:
		int two_thousand_count;
		TwoThousand(int number):two_thousand_count(number)
		{}
		void setHandler(MoneyHandler* m)
		{
			next=m;
		}
		void processRequest(int money)
		{
			int notes = money/2000;
			int demon = money%2000;
			if(notes > 0 && two_thousand_count >0)
			{
				if(notes<= two_thousand_count)
				{	
					two_thousand_count=two_thousand_count-notes;
					cout<<"2000 INR: "<<notes<<endl;
					if(demon != 0)
						next->processRequest(demon);
				}
				else
				{
					cout<<"2000 INR: "<<two_thousand_count<<endl;
					next->processRequest((notes-two_thousand_count)*2000 + demon);
					two_thousand_count=0;

				}
			}
			else
				next->processRequest(money);

			

		}
};

class FiveHundred: public MoneyHandler{
	public:
		int five_count;
		FiveHundred(int number):five_count(number)
		{}
		void setHandler(MoneyHandler* m)
		{
			next=m;
		}
		void processRequest(int money)
		{
			int notes = money/500;
			int demon = money%500;
			if(notes > 0 && five_count >0)
			{
				if(notes<= five_count)
				{	
					five_count=five_count-notes;
					cout<<"500 INR: "<<notes<<endl;
					if(demon != 0)
						next->processRequest(demon);
				}
				else
				{
					cout<<"500 INR: "<<five_count<<endl;
					next->processRequest((notes-five_count)*500+ demon);
					five_count=0;

				}
			}
			else
				next->processRequest(money);
		}
};

class Hundred: public MoneyHandler{
	public:
		int hundred_count;
		Hundred(int number):hundred_count(number)
		{}
		void setHandler(MoneyHandler* m)
		{
			next=m;
		}
		void processRequest(int money)
		{
			int notes = money/100;
			int demon = money%100;
			if(notes > 0 && hundred_count>0)
			{
				if(notes<= hundred_count)
				{	
					hundred_count=hundred_count-notes;
					cout<<"100 INR: "<<notes<<endl;
					if(demon != 0)
					next->processRequest(demon);
				}
				else
				{
					cout<<"100 INR: "<<hundred_count<<endl;
					next->processRequest((notes-hundred_count)*100 + demon);
					hundred_count=0;

				}
			}
			else
				next->processRequest(money);
		}
};

class Exception: public MoneyHandler{
	public:
		void setHandler(MoneyHandler* m){}
		void processRequest(int money)
		{
			cout<<"Money Can't be withdrawl\n";
		}

};

class ATM{

	int two_thousand_count;
	int five_hundred_count;
	int hundred_count;
	public:
	MoneyHandler *mh;
	ATM(int two, int five, int hundred):two_thousand_count(two),five_hundred_count(five),hundred_count(hundred)
	{
		MoneyHandler* h_two= new TwoThousand(two_thousand_count);
		MoneyHandler* h_five= new FiveHundred(five_hundred_count);
		MoneyHandler* h_hundred= new Hundred(hundred_count);
		h_two->setHandler(h_five);
		h_five->setHandler(h_hundred);
		 MoneyHandler* h_exception = new Exception();
		 h_hundred->setHandler(h_exception);
		mh = h_two;

	}
	int withdraw(int money)
	{
		mh->processRequest(money);
	}

};



int main()
{
	ATM atm(5,1,500);
	atm.withdraw(7000);

}




