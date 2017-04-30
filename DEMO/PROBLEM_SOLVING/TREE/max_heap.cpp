/**
	Funda is to maintain the heap in vector or array that gives the feeling as u r working on binary tree.
	2*i denotes root in vector where i is tracker.
	2*i+1 denotes root->left in vector
	2*i+2 denotes root->right in vector
Note: why v r doing this? - from any node u can find out the root node this is the reason we have such formula.
	e.g. 3  2  1  7  8  4  10  16  12
	     0  1  2  3  4  5  6   7   8
	Difficulty of this program what i feel is to determine the next location in vector, for example 3 elements are inserted in heap i.e. vector here i used tracker that will help in this,incremented only when both it childs are filled already

	After analyzing the logic of getting left, right and parent i found that we shouldn't have worry about left and right since it is in vector insertion is sequential - the main logic is to u have to find the parent node and bubble up if required
	Logic is:
step1: take first element and insert in vector at pos=0 & increment the count++ (initialaized with 0)
step2: If count is greater than 0 so u need to figure out the parent node since u r going to insert this second element at index 1(pos=1) i.e. count=1- parent = (pos-1)/2 now bubble up if required otherwise insert this element at pos
  */


#include<iostream>
#include<vector>

using namespace std;

class MaxHeap{
	public:
		vector<int> v;
		int count;
		int tracker;
	MaxHeap():count(0),tracker(0),v(50)
	{}
	void insert(int);
	void deleteMax();
	void bubblify(int,int);
	void print_vector();
	void shape(int);
};

void MaxHeap::bubblify(int pos, int val)
{
	
	int parent=(pos-1)/2;
	if(parent < 0)
		return ;
	if(v[parent] < val)
	{
		//swap
		v[pos]=v[parent];
		v[parent]=val;
		bubblify(parent, val);
	}else{
		v[pos]=val;
	}
}

void MaxHeap::shape(int pos)
{
	int left = pos*2 +1;
	int right = pos*2 +2;
	int maxPos = -1;
	if(left >= count && right>= count)
		return;
	else if (left >= count)
		maxPos = right;
	else if (right >= count)
		maxPos=left;
	else
		maxPos= v[left]<v[right]?right:left;

	if(v[maxPos] > v[pos])
	{
		int temp = v[pos];
		v[pos] = v[maxPos];
		v[maxPos] = temp;
		shape(maxPos);
	}
	return;
}


void MaxHeap::deleteMax()
{
	cout<<"After erasing Max element from heap\n";
	//v.erase(v.begin());
	v[0] = v[count-1];
	v.erase(v.end()-1);
	count--;
	print_vector();
	shape(0);

}

void MaxHeap::insert(int val)
{
	if(count == 0)
	{
		v[tracker] = val;
		count++;
		return;
	}
	//no need to calculate whether left or right since our main goal is to keep the root max means bubble up from parent i.e. compare the element to it's parent if it is greater the swap and same thing perform until it is smaller it is called bubble up
	/*if((2*tracker+1) > (count-1))
	{
		bubblify(2*tracker+1, val);
		cout<<"Inserted at position: "<<(2*tracker+1)<<endl;
	}
	else{
		bubblify(2*tracker+2, val);
		cout<<"Inserted at position: "<<(2*tracker+2)<<endl;
		tracker++; //to track if tree's left and right both re full or not
	}*/
	bubblify(count, val);

	count++;
	
}

void MaxHeap::print_vector()
{
	for(int i=0; i<count; i++)
		cout<<v[i]<<endl;
}

int find_max_element(int a[],int s)
{
	MaxHeap heap;
	for(int i=0; i<s; i++)
		heap.insert(a[i]);	

	heap.print_vector();
	heap.deleteMax();
	cout<<"after delete:\n";
	heap.print_vector();
}

int main()
{
	int arr[]={3,2,1,7,8,4,10,16,12,4,18,2,22,11,9,6,5,25};
	find_max_element(arr,sizeof(arr)/sizeof(int));
}
