#include<iostream>


using namespace std;

class Write{

	public:
		virtual void perform(){};
};


class WriteDecorator:public Write{
	public:
		Write* wrt;
	WriteDecorator(Write* w):wrt(w){}
	virtual void perform(){wrt->perform();}
};

//since it is basic functionality and must be present earlier as well, after this decorator pattern will be applied
class WriteOnFile:public Write{
		public:
		string filename;
		WriteOnFile(string file_name)
		{filename = file_name;}
		void perform()
		{
			cout<<"Writing on file name: "<<filename<<endl;
		}
};

class Validate:public WriteDecorator{
	public:
		Validate(Write* w):WriteDecorator(w){}
		void perform(){cout<<"Validating... \n"; wrt->perform();}
};


class Encrypt:public WriteDecorator{
		public:
		Encrypt(Write* w):WriteDecorator(w){}
		void perform(){cout<<"encryption algo is running ...\n"; wrt->perform();}
};


int main()
{
	WriteDecorator* w = new Validate(new Encrypt(new WriteOnFile("file.txt")));
	w->perform();
}
