#include <iostream>
using namespace std;
 
void findSize(int arr[])
{
	cout<<arr<<endl;
	cout<<&arr+1<<endl;
	cout<<(((&arr)+1) - &arr)<<endl;//<</sizeof(int)<<endl;
    cout << sizeof(arr) << endl;
}
 
int main()
{
    int a[15];
    //cout << sizeof(a) << " ";
    findSize(a);
    return 0;
}
