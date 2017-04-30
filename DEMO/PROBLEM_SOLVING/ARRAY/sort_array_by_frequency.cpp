/*
Given an array of integers, sort the array according to frequency of elements. For example, if the input array is {2, 3, 2, 4, 5, 12, 2, 3, 3, 3, 12}, then modify the array to {3, 3, 3, 3, 2, 2, 2, 12, 12, 4, 5}. 
used map and multi map-> first insert into map to get the count as value then inset into multi map count as key and print
*/


#include<iostream>
#include<map>

using namespace std;

void sort_array(int a[], int size)
{
	multimap<int,int, greater<int> > mymap;
	map<int,int> m;
	for(int i=0; i<size; ++i)
	{
		if(m.find(a[i]) == m.end())
			m[a[i]] = 1;
		else
			m[a[i]] = m[a[i]]+1;
	}
	for(map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout<<"FirstMap: "<<it->first<<":"<<it->second<<endl;
		mymap.insert(pair<int,int>(it->second,it->first));
	}
	for(multimap<int, int>::iterator it = mymap.begin(); it != mymap.end(); it++)
	{
		//cout<<"SecondMap: "<<it->first<<endl;
		for(int i =1; i<=it->first; i++)
			cout<<it->second<<",";
	}
	cout<<endl;

}


int main()
{
	int array[]={2, 3, 2, 4, 5, 12, 2, 3, 3, 3, 12,5};
	sort_array(array, sizeof(array)/sizeof(int));
}


