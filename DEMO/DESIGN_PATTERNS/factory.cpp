#include<iostream>

using namespace std;

class IShape{
	public:
		virtual void draw()=0;
};

class Square:public IShape{
	public:
		virtual void draw(){cout<<"Square::draw()\n";}
};

class Circle:public IShape{
	public:
		virtual void draw(){cout<<"Circle::draw()\n";}
};



class Factory{
	public:
	IShape* create(int type)
	{
		switch(type){
		case 1:
			return new Square();
			break;
		case 2:
			return new Circle();
			break;
		default:
			return 0;
		}
	}
};

int main()
{
	Factory fp;
	IShape* obj = fp.create(1);
	obj->draw();
}
