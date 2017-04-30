/*
You are given a rotated sorted array of size N. You have to search a given number into it. 
Example: [4,6,8,14,90,-9,-2,0,3], Search -2. ==> -9,-2,0,3,4,6,8,14,90
*/
#include<iostream>

void find(int a[], int start, int end, int key)
{
	int mid = (start+end)/2;
	if(a[mid] == key)
	{
		std::cout<<"Key found\n";
		return;
	}
	if(mid <= end && mid >= start)
	{
		if(a[mid+1]<key && a[mid-1]> key )
		{
			find(a, mid+1, end,key);
			find(a,start,mid-1,key);
		}
		else
		{
			find(a,start,mid-1,key);
			find(a, mid+1, end,key);
		}
	}
}
void find_number(int a[], int size, int key)
{
	find(a, 0,size-1, key);
}


int main()
{
	int arr[]={-3,4,6,8,14,90,-9,-2,0,3};

	find_number(arr,sizeof(arr)/sizeof(int), -3);
}
