#include<iostream>


using namespace std;


template<typename T>
class Vector{
	//int capacity;
	T arr[8];//capacity];
	int count;
	public:
	T* 
	Vector(){count=0;} 
	bool push_back(T val)
	{
		if(count < 8)
			arr[count++] = val;
		else{
			//increase_capacity();
			cout<<"Vector is full\n";
		}
	}
	int* begin(){ return &arr[0];}
	int* end(){return &arr[count];}


};


int main()
{
	Vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	for(int *it= v.begin(); it!= v.end(); it++)
	{
		cout<<*it<<endl;
	}
}
