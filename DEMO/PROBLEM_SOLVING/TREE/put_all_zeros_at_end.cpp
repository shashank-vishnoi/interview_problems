/* Given an array- need to put all zeros at the end of that given array without chaning the order
   e.g. Input -> A[]={10,-2,0,3,0,5,6,0,10};
	Output -> A[]={10,-2,3,5,6,10,0,0,0}
   */

#include<iostream>

using namespace std;


void zero_at_end(int a[], int len)
{
	int zero_count=0;
	for(int i=0; i<len;i++)
	{
		if(a[i] != 0)
		{
			a[zero_count++] = a[i];
		}
	}
	for(int i=zero_count; i<len; i++)
		a[i]=0;
}


int main()
{
	int A[]={10,-2,0,3,0,5,6,0,10};
	int len = sizeof(A)/sizeof(int);
	for(int i=0; i<len;i++)
		cout<<A[i]<<" ,";
	cout<<endl;
	zero_at_end(A,len);
	for(int i=0; i<len;i++)
		cout<<A[i]<<" ,";
	cout<<endl;

}
