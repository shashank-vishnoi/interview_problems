/*
	A[]={50,30,60,20,10,80,40} ==> wanna delete 20
	we can do it less than o(n) time but max o(n) time .
	here we also learn to shift the elements from one point in an array

	I have given two solutions - 1 is mainly shifting the elements from end
	2 is swapping the elements from last element 
*/

#include<iostream>

using namespace std;

//by shifting elements in an array
void deleteNumber(int a[],int s, int num)
{
	int end=s-1;
	int temp=a[end];
	int prev=a[end-1];
	while(end > 0)
	{
		prev=a[end-1];
		a[end-1]=temp;
		temp=prev;
		end--;
		if(prev == num)
			break;



	}
}
//by swapping from last element traverse from end , here once the delete element found we will put in last
void del(int a[], int s, int num)
{
	int end=s-1-1; int last= s-1;
	while(end > 1)
	{
			int temp=a[last];
			a[last]=a[end];
			if(a[end] == num)
			{
				a[end]=temp;
				break;
			}
			a[end]=temp;
			end--;
	}
}


void print(int a[], int s)
{
	for(int i=0; i<s; i++)
		cout<<a[i]<<endl;
}

int main()
{
	int a[]={50,30,60,20,10,80,40};
	//deleteNumber(a,sizeof(a)/sizeof(int),20);
	del(a,sizeof(a)/sizeof(int),20);
	print(a,6);
}
