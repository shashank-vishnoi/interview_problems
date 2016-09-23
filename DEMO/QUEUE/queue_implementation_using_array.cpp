#include<iostream>

#define MAX_SIZE 8
using namespace std;

template<typename T>
class Queue{
	T arr[MAX_SIZE];
	int front,rear, size;
	public:
	Queue():front(-1), rear(-1),size(0)
	{}
	bool full()
	{
		return size == MAX_SIZE;
	}
	bool empty()
	{
		if(size == 0)
			return true;
		return false;
	}
	void push(T val)
	{
		if(!full())
		{
			rear++;
			rear = rear%MAX_SIZE;
			arr[rear] = val;
			size++;
		}
		else
			cout<<"Queue is full...\n";
	}
	T pop()
	{
		if(empty())
			cout<<"Queue is empty...\n";
		else{
			front++;
			front = front%MAX_SIZE;
			size--;
			return arr[front];
		}
	}
	void display()
	{
		if(empty())
			return;
		int count=0;
		while(size != count)
			cout<<pop()<<endl;
	}
};


int main()
{
	Queue<int> Q;
	Q.push(10);
	Q.push(20);
	Q.push(30);
	Q.push(40);
	Q.push(50);
	Q.push(60);
	Q.push(70);
	Q.push(80);
	Q.pop();
	Q.push(90);
	Q.display();
}
