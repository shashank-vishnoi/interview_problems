/**

  	For example, if given array is [1, 23, 12, 9, 30, 2, 50] and you are asked for the largest 3 elements i.e., k = 3 then your program should print 50, 30 and 23.

	To find the k largest elemennts - what idea we can have minHeap of k size.
	
  **/


#include<iostream>
#include<vector>

using namespace std;

class MaxHeap{

	public:
		int count;
		vector<int> v;
		MaxHeap(int size):count(0),v(size)
		{}
		void insert(int val);
		void bubbleup(int, int);
		void deleteMin();
		void shape(int);
		int size(){return count;}
		void print();
		int deleteMax();
};


void MaxHeap::bubbleup(int pos, int val)
{
	if(pos < 0)
		return;
	int parent = (int)(pos-1)/2;
	if(parent <0)
		return;
	if(v[parent] < v[pos])
	{
		int temp=v[pos];
		v[pos]=v[parent];
		v[parent]=temp;
		bubbleup(parent, v[parent]);
	}
}

void MaxHeap::print()
{
	for(int i=0; i<count; i++)
		cout<<v[i]<<endl;
}
void MaxHeap::insert(int val)
{
	v[count] = val;
	if(count == 0)
	{
		count++;
		return;
	}
	bubbleup(count, val);
	count++;

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
int MaxHeap::deleteMax()
{
	int temp = v[0];
	v[0]=v[count-1]; //put last element
	v.erase(v.end()-1);
	count--;
	shape(0);
	return temp;	
}

void find_last_k_largest_elements(int a[],int s, int k)
{
	MaxHeap heap(s);
	for(int i=0; i<s; i++)
	{
		heap.insert(a[i]);
	}
	cout<<"Largest k elements are: "<<endl;
	for(int i=0; i <k; i++)
		cout<<heap.deleteMax()<<",";	
	cout<<endl;
}

int main()
{
	int arr[]={1, 23, 12, 14, 30, 2, 50, 3, 1, 80, 5};
	int k = 5;
	find_last_k_largest_elements(arr, sizeof(arr)/sizeof(int), k);
}
