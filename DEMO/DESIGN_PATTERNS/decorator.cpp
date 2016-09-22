#include<iostream>

using namespace std;

class top_in{
	public:
	virtual int get_cost()=0;
	virtual void add()=0;	
};
class Soy:public top_in{
	public:
		int get_cost(){return 20;}
		void add(){cout<<"Soy is added\n";}
};
class Moca:public top_in{
	public:
		int get_cost(){return 30;}
		void add(){cout<<"Moca is added\n";}
};
class whip:public top_in{
	public:
		int get_cost(){return 40;}
		void add(){cout<<"Whip is added\n";}
};
class coffee{
	public:
		coffee(int p):price(p)
		{}
		int price;
		virtual int get_price()=0;
		virtual coffee* add(top_in *flavour)
		{
			flavour->add();
			price = get_price() + flavour->get_cost();
			return this;
		}
};

class Expresso:public coffee{
	public:
		Expresso():coffee(100)
		{cout<<"Expresso is ready\n";}
		int get_price(){return price;}
};
class Latte:public coffee{
	public:
		Latte():coffee(120)
		{cout<<"Latte is ready\n";}
		int get_price(){return price;}
};

int main()
{
	coffee *e = new Expresso();
	e->add(new Soy())->add(new whip());
	cout<<"Price: "<<e->get_price()<<endl;
}
