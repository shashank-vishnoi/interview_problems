/*
You are given an array of integers and a number K. You have to find the any continue sub-array whose elements sum is K. Please note that, the array may have positive, negative, and zeros as its element. 
The desired complexity is O(N). 
Example: 
Input: [7 0 9 -10 0 789], K = 0 
Output: Array from index 1 to Index 1. 
Input: [1 2 3 5 -10] K = 0 
Output: Array from Index 1 to Index 4. 
If K = -2, Output would have been SubArray from Index 2 to Index 4.
*/

#include<iostream>
#include<map>

using namespace std;


void findSubArray(int a[], int size, int sum)
{
	int curr_sum = 0;
	map<int, int> mymap;
	for(int i=0; i<size; ++i)
	{
		curr_sum = curr_sum + a[i];
		if(curr_sum == sum)
			cout<<"===Found ["<<mymap[curr_sum]<<" to "<<i<<"]"<<endl;
		else
		{
			if(mymap.find(curr_sum-sum) == mymap.end())
			{
				mymap[curr_sum]=i;
			}else{
				cout<<"Found ["<<mymap[curr_sum-sum]+1<<" to "<<i<<"]"<<endl;
			}

		}
	}
	for(map<int,int>::iterator it=mymap.begin(); it!=mymap.end(); it++)
		cout<<it->first<<endl;
}
int main()
{
	int arr[]={10,-20,-10,50,30,10,40,-20};//{1, 2, 3, -6, -10};
	findSubArray(arr,sizeof(arr)/sizeof(int), 120);
}
