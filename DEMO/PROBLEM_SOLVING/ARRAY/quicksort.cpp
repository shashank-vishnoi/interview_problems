#include<iostream>



using namespace std;


void swap(int a[],int l, int r)
{
	if(l == r)
		return;
	int temp=a[l];
	a[l]=a[r];
	a[r]=temp;
}

int partiotion(int a[],int low, int high)
{
	int pivot=a[high],left=low,right=high-1;
	do{
		while(a[left] < pivot)
			left++;
		while(a[right]> pivot)
			right--;
		if(left>=right)
			break;
		else
			swap(a,left,right);
		cout<<"left: "<<left<<"\n"<<"right: "<<right<<endl;
	}while(1);
	swap(a,left,high);
	return left;
}


void QuickSort(int a[], int l, int h)
{
	int pivot = partiotion(a,l,h);
	QuickSort(a,l,pivot-1);
	QuickSort(a,pivot+1,h);
}


int main()
{
	int a[]={50,10,30,80,20,40,60};
	QuickSort(a,0,6);
	for(int i=0; i<6; ++i)
		cout<<a[i]<<endl;
}
