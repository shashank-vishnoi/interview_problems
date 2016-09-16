#include<iostream>


using namespace std;

class Write{
	public:
	virtual void perform(){}
};

class WriteOnFile:public Write{
	string name;
	public:
		WriteOnFile(string name):name(name)
		{}//cout<<name+" written\n";}
		void perform()
		{
			cout<<"written on file: "<<name<<endl;
		}
};

class Decorator:public Write{
	public:
		Write *w;
		Decorator(Write *obj):w(obj)
		{}
		virtual void perform()
		{
			w->perform();
		}
};

class Validate:public Decorator{
	public:
		Validate(Write *obj):Decorator(obj)
		{}
		void perform(){cout<<"Validation is done\n"; w->perform();}
		void after(Write *w)
		{ w=w;}
};
class Encryption:public Decorator{
	public:
		Encryption(Write *obj):Decorator(obj)
		{}
		void perform(){cout<<"Encryption is done\n";w->perform();}
};
class Zip:public Decorator{
	public:
		Zip(Write *obj):Decorator(obj)
		             {}
	void perform(){cout<<"Zipping...\n";}
};

int main()
{
	//Write w;
	Write* wo= (new Validate(new Encryption(new WriteOnFile("file name"))));
	wo->perform();
}
