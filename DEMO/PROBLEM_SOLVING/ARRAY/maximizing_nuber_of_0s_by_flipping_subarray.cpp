/*Maximize number of 0s by flipping a subarray
Given a binary array, find the maximum number zeros in an array with one flip of a subarray allowed. A flip operation switches all 0s to 1s and 1s to 0s.

Examples:

Input :  arr[] = {0, 1, 0, 0, 1, 1, 0}
Output : 6
We can get 6 zeros by flipping the subarray {1, 1}

Input :  arr[] = {0, 0, 0, 1, 0, 1}
Output : 5

*/

#include<iostream>

using namespace std;


int max_number_of_zeros(int input[], int len)
{
	int max_count=0,count=0,i=0,zero=0;
	bool flag=false;
	while(i <len)
	{
		if(count == 0 && input[i] == 1)
			flag = true;
		else if(input[i] == 0)
		{
			zero++;
			if(count >= 1)
			{
				flag = false;count=0;
			}
		}
		if(input[i++] == 1 && flag == true)
			count++;

		if(max_count < count)
			max_count=count;
	}
	return zero + max_count;

}


int main()
{
	int arr[] = {0, 1, 0, 0, 1, 1, 0};
	cout<<max_number_of_zeros(arr, sizeof(arr)/sizeof(int))<<endl;
	int arr1[] ={0, 0, 0, 1, 0, 1}; 
	cout<<max_number_of_zeros(arr1, sizeof(arr1)/sizeof(int))<<endl;
}
