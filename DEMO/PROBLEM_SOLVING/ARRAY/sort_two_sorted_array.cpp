/*
	Input: {8,10,12,14,16,18} & {13,17,19}
	Output: {8,10,12,13,14,16} & {17,18,19}

   */

#include<iostream>

using namespace std;

//this function put the value in correct place in sorted array a, start from location loc
void shift(int a[], int s, int loc, int value)
{
	int end=s-1;
	a[end] = value;
	while( s- loc > 0)
	{
		if(a[end] < a[end-1])
		{
			int temp=a[end];
			a[end]=a[end-1];
			a[end-1]=temp;
		}
		else
			break;
		end--;
	}
}


void helper(int a1[], int s1, int a2[], int s2)
{
	int end1=s1-1,end2=s2-1;
	while(s2 > 0)
	{
		if(a2[end2] > a1[end1])
		{
			end2--;
			s2--;
			continue;
		}
		int temp_end1 = end1;
		while(a1[temp_end1]> a2[end2])
		{
			temp_end1--;
		}
		int temp=a1[temp_end1+1];
		int a2_end = a2[end2];
		a2[end2] = a1[end1];
		a1[temp_end1+1] = a2_end; 
		if(temp_end1+1 != end1)
			shift(a1,s1,temp_end1+1, temp); //a1[end] can be think as blank since it is already put in a2.
		end2--;
		s2--;
	}
}

void sort(int a1[], int s1, int a2[], int s2)
{
	if(s1 > s2)
		helper(a1,s1,a2,s2);
	else
		helper(a2,s2,a1,s1);
}

void print(int a[], int s)
{
	for(int i=0; i<s; i++)
		cout<<a[i]<<endl;
	cout<<endl;
}

int main()
{
	int a1[]={8,10,12,14,16,18};
	int a2[]={13,17,19};

	sort(a1,sizeof(a1)/sizeof(int), a2, sizeof(a2)/sizeof(int));
	print(a1, sizeof(a1)/sizeof(int));
	print(a2, sizeof(a2)/sizeof(int));
}
