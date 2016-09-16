#include<iostream>

using namespace std;

class Algo{
	public:
		virtual void execute()=0;
};

class Algo_A:public Algo{
	public:
		void execute()
		{cout<<"Algo_A::execute()\n";}
};
class Algo_B:public Algo{
	public:
		void execute()
		{cout<<"Algo_B::execute()\n";}
};

class context{
	Algo *algo;
	public:
		context(Algo* a):algo(a)
		{
		}
		void execute()
		{
			algo->execute();
		}
};


int main()
{
	context cA= context(new Algo_A());
	cA.execute();
	context cB= context(new Algo_B());
	cB.execute();
}
