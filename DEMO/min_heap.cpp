/*
 *Min Heap or Max Heap:
 	1. They are complete binary tree.
	2. Parent is always min/max from childs.
	3. It can be implemented using array or vector
	Below are the rules while implementing in array/vector:
	- The left child of node in index i is: 2*i+1
	- The right child of node in index i is: 2*i+2
	- The parent of the node in index i is: (int)((i-1)/2)
	- The root of the tree is in index 0, its left child is in index 1 and its right child is in index 2 and so on.
 *
 * */

#include<iostream>
#include<vector>

using namespace std;

class minheap{
	private:
		vector<int> v;
		int index;
		int count;
	public:
		void insert(int val);
		void print_vector();
		minheap(int len);
		void bubbleup(int,int);
};

minheap::minheap(int len):index(0),count(0),v(len)
{
}

void minheap::bubbleup(int loc, int val)
{
	int root_loc = (int)(loc-1)/2;
	if(root_loc < 0)
		return;
	if(v[root_loc] > val)
	{
		v[loc]=v[root_loc];
		v[root_loc] = val;
		bubbleup(root_loc, val);
	}
	else
	{
		v[loc] = val;
		return;
	}
}
void minheap::insert(int val)
{
	if(count == 0)
	{
		v[index] = val;
		count++;
		return;
	}
	int last_index = count-1;
	if(2*index + 1 > last_index )//left child
	{
		bubbleup(2*index+1,val);
	}
	else{
		bubbleup(2*index+2,val);
		index++; // this will be incremented only when both the childs are filled
	}
	count++;
}

void minheap::print_vector()
{
	for(int i = 0; i<count; i++)
		cout<<v[i]<<",";
	cout<<endl;
}

int main()
{
	//10, 4, 5, 30, 3, 300
	minheap m(50);

	m.insert(10);
	m.insert(15);
	m.insert(4);
	m.insert(5);
	m.insert(30);
	m.insert(300);
	m.insert(400);
	m.insert(1);
	m.print_vector();
}

