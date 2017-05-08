/*Write a function rotate(ar[], d, n) that rotates arr[] of size n by d elements.

Array [1,2,3,4,5,6,7]

Rotation of the above array by 2 will make array

ArrayRotation [3,4,5,6,7,1,2]
*/
#include<iostream>

using namespace std;

void rotate(int* a, int s, int point)
{
	for(int i=0; i<point; i++)
	{
		int temp=*a; //=1
		for(int j=0; j<s-1; j++)
			*(a+j)=*(a+j+1); 
		*(a+s-1)=temp; //after Pass1- 2,3,4,5,6,7,1
	}
	//for(int i=0; i<s; i++)
	//	cout<<a[i]<<endl;
}


int main()
{
	int a[]={1,2,3,4,5,6,7};
	rotate(a, 7, 2);
	for(int i=0; i<7; i++)
		cout<<a[i]<<endl;
}

