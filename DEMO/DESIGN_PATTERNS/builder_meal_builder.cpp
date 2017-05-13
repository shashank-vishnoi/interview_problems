/*
	Need to implement builder desgin pattern to build Meal for Kids & Adult, Veg & Non-Veg
	Builder design patterns seperats the complex object creation from it's representation so that same construction process can create different objects.
	Director - It is a engineer who creates the Object for us.(it contains the blue print of object how to create)
	Builder  - Director or Enginner asks to builder class to build object (it actuall creates)

   */

#include<iostream>
#include<string>

using namespace std;

class Meal{
	public:
	string starter1;
	string starter2;
	string mainCourse1;
	string mainCourse2;
	string drink1;
	string drink2;
	string desert1;
	string desert2;
	Meal(){}
	void display()
	{
		cout<<"STARTER1 -"<<starter1<<endl;
		cout<<"MIAN COURSE1 -"<<mainCourse1<<endl;
		cout<<"DRINK1 -"<<drink1<<endl;
		cout<<"desert1 -"<<desert1<<endl;
	}	
};


class MealBuilder{
	public:
	Meal *meal;
		MealBuilder(){
			meal = new Meal;
		}
		virtual void buildStarters()=0;
		virtual void buildMainCourse()=0;
		virtual void buildDrinks()=0;
		virtual void buildDeserts()=0;
		Meal* build()
		{
			return meal;
		}
};

class VegMealBuilder: public MealBuilder{
	void buildStarters()
	{
		meal->starter1="French Fries";
	}
	void buildMainCourse()
	{meal->mainCourse1="Veg Burger";}
	void buildDrinks()
	{meal->drink1="Mojito";}
	void buildDeserts()
	{meal->desert1="Pudding";}
};

class NonVegMealBuilder: public MealBuilder{
	void buildStarters()
	{
		meal->starter1="Chiken roll";
	}
	void buildMainCourse()
	{meal->mainCourse1="Chicken Burger";}
	void buildDrinks()
	{meal->drink1="Blood";}
	void buildDeserts()
	{meal->desert1="Egg Cake";}
};






class Director{
	public:
		MealBuilder *meal_builder;
		Director(MealBuilder* m):meal_builder(m)
		{	}
		Meal* makeMeal()
		{

			meal_builder->buildStarters();
			meal_builder->buildMainCourse();
			meal_builder->buildDrinks();
			meal_builder->buildDeserts();
			return meal_builder->build();
		}
};


int main()
{
	Director d = (new NonVegMealBuilder());
	Meal* meal = d.makeMeal();
	meal->display();

}


