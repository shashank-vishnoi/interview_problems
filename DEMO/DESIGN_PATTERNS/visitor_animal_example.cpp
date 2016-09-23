//Suppose you have a hierarchy of animals
#include<iostream>
using namespace std;
/*(Suppose it is a complex hierarchy with a well-established interface.)

	Now we want to add a new operation to the hierarchy, namely we want each animal to make its sound. As far as the hierarchy is this simple, you can do it with straight polymorphism:
*/
/*
class Animal
{ public: virtual void makeSound() = 0; };

class Dog : public Animal
{ public: void makeSound(); };

void Dog::makeSound()
{ std::cout << "woof!\n"; }

class Cat : public Animal
{ public: void makeSound(); };

void Cat::makeSound()
{ std::cout << "meow!\n"; }*/
/*But proceeding in this way, each time you want to add an operation you must modify the interface to every single class of the hierarchy. Now, suppose instead that you are satisfied with the original interface, and that you want to make the fewest possible modifications to it.

The Visitor pattern allows you to move each new operation in a suitable class, and you need to extend the hierarchy's interface only once. Let's do it. First, we define an abstract operation (the "Visitor" class in GoF) which has a method for every class in the hierarchy:
*/

/*
Def: Visitor lets you define a new operation without changing the classes of the elements on which it operates.
*/

class Dog;
class Cat;
class Animal;
class Operation
{
	public:
		virtual void perform(Dog d) = 0;
		virtual void perform(Cat c) = 0;
};
//Then, we modify the hierarchy in order to accept new operations:

class Animal
{ public: virtual void letsDo(Operation *v) = 0; };

class Dog : public Animal
{ public: void letsDo(Operation *v); };

void Dog::letsDo(Operation *v)
{ v->perform(*this); }

class Cat : public Animal
{ public: void letsDo(Operation *v); };

void Cat::letsDo(Operation *v)
{ v->perform(*this); }



class Sound : public Operation
{
	public:
		void perform(Dog d);
		void perform(Cat c);
};

void Sound::perform(Dog d)
{ std::cout << "woof!\n"; }

void Sound::perform(Cat c)
{ std::cout << "meow!\n"; }

int main()
{
	Cat c;
	Sound theSound;
	c.letsDo(&theSound);
	Dog d;
	d.letsDo(&theSound);
}
