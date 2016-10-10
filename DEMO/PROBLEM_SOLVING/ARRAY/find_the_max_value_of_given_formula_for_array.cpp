/*Maximize value of (arr[i] – i) – (arr[j] – j) in an array
Given an array, arr[] find the maximum value of (arr[i] – i) – (arr[j] – j) where i is not equal to j. Where i and j vary from 0 to n-1 and n is size of input array arr[].

Examples:

Input : arr[] = {9, 15, 4, 12, 13}
Output : 12
We get the maximum value for i = 1 and j = 2
(15 - 1) - (4 - 2) = 12

Input : arr[] = {-1, -2, -3, 4, 10}
Output : 6
We get the maximum value for i = 4 and j = 2
(10 - 4) - (-3 - 2) = 11

*/
#include<iostream>


using namespace std;

int max_value(int input[], int len)
{
	int i=0, max=0, min=input[0];
	while( i < len)
	{
		if(max < input[i]-i)
			max = input[i]-i;
		if(min > input[i]-i)
			min = input[i]-i;
		i++;
	}
	return max-min;
}

int main()
{
	int input[] = {9, 15, 4, 12, 13};
	cout<<max_value(input, sizeof(input)/sizeof(int))<<endl;	

	int input1[] = {-1, -2, -3, 4, 10}; 
	cout<<max_value(input1, sizeof(input1)/sizeof(int))<<endl;	
}
