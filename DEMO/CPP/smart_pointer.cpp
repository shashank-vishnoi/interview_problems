#include<iostream>

using namespace std;

template<typename T>
class SP{
	public:
		T* value;
		int count;
		SP(T* ptr):value(ptr),count(1)
		{
			
		}
		~SP()
		{
			if((--count) == 0)
			{
				delete value;
				cout<<"memory is freed..\n";
			}
		}
		T operator*()
		{
			return *value;
		}
		T* operator->()
		{
			return value;
		}
		SP<T>& operator=(const SP<T>& sp)
		{
			if(this != sp)
			{
				++count;
				value = sp.value;
				return *this;
			}
		}
		SP(const SP<T>& sp):value(sp.value)
		{
			count++;
		}
};

class Demo{
	public:
		int a;
		Demo(int val):a(val)
		{}
		int get(){return a;}
		void set(int val){a=val;}
};


int main()
{
	SP<int> integer(new int(10));
	cout<<(*integer)<<endl;
	SP<Demo> d(new Demo(50));
	int val=d->get();
	cout<<d->get()<<endl;
	d->set(1000);
	cout<<d->get()<<endl;

	SP<Demo> d2=d;
	d2->set(0);
	cout<<d->get()<<endl;
}

