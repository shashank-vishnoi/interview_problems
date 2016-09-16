#include<iostream>

using namespace std;

template<typename T>
class smartPtr{
	T* val;
	int count;
	public:
	//ctor
	smartPtr(T* obj):val(obj),count(1)
	{
	}
	//dtor
	~smartPtr()
	{
		if((--count) == 0){delete val;cout<<"Memory is released"<<endl;}
	}
	//cop-ctor
	smartPtr(const smartPtr<T>& obj):val(obj.val)
	{count++;}
	T* operator->(){return val;}
	T operator*(){return *val;}
	smartPtr<T>& operator=(const smartPtr<T>& obj)
	{
		if(this != obj)
		{
			count++;
			val=obj.val;
			return *this;
		}
	}	
};

class Cat{
	public:
		Cat(){cout<<"cat is created"<<endl;}
		~Cat(){cout<<"cat is destroyed"<<endl;}
		void speak(){cout<<"Meow... Meow"<<endl;}
};

int main()
{
	smartPtr<Cat> sp(new Cat);
	sp->speak();
	smartPtr<Cat> sp1=sp;
	{
		smartPtr<Cat> sp2=sp;
		smartPtr<Cat> sp3=sp1;
	}	
	sp->speak();
}
