#include<iostream>


using namespace std;

enum PLATFORM_TYPE {ANDROID, IOS};

//Abstract class for widget
class Widget{
	public:
		void virtual create()=0;
		void virtual draw()=0;

};

class MenuForiOS:public Widget{
	public:
		void create(){cout<<"iOS::Menu() created."<<endl;}
		void draw(){cout<<"iOS::Menu() drawn."<<endl;}
};

class MenuForAndroid:public Widget{
	public:
		void create(){cout<<"Android::Menu() created."<<endl;}
		void draw(){cout<<"Android::Menu() drawn."<<endl;}
};


class ButtonForiOS:public Widget{
	public:
		void create(){cout<<"iOS::Button() created."<<endl;}
		void draw(){cout<<"iOS::Button() drawn."<<endl;}
};

class ButtonForAndroid:public Widget{
	public:
		void create(){cout<<"Android::Button() created."<<endl;}
		void draw(){cout<<"Android::Button() drawn."<<endl;}
};


class AbstractFactoryForWidget{
	public:
		virtual  Widget* createMenu()=0;
		virtual Widget* createButton()=0;
};
//Widget Factory for iOS:
class WidgetFactoryForiOS: public AbstractFactoryForWidget{
	public:
		Widget* createMenu()
		{
			return new MenuForiOS();
		}
		Widget* createButton()
		{
			return new ButtonForiOS();
		}
};


//Widget Factory for Android:
class WidgetFactoryForAndroid: public AbstractFactoryForWidget{
	public:
		Widget* createMenu()
		{
			return new MenuForAndroid();
		}
		Widget* createButton()
		{
			return new ButtonForAndroid();
		}

};


AbstractFactoryForWidget* initialize(PLATFORM_TYPE type)
{
	if(type == ANDROID)
		return new WidgetFactoryForAndroid();
	else
		return new WidgetFactoryForiOS();
}


int main()
{
	AbstractFactoryForWidget* factory = initialize(IOS);

	Widget* menu = factory->createMenu();
	menu->create();
	menu->draw();
	Widget* button = factory->createButton();
	button->create();
	button->draw();

}
