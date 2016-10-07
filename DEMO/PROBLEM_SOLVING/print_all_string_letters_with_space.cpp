/*Print all possible strings that can be made by placing spaces
Given a string you need to print all possible strings that can be made by placing spaces (zero or one) in between them.

Input:  str[] = "ABC"
Output: ABC
        AB C
        A BC
        A B C
*/

#include<iostream>

using namespace std;

void print(char str[], int spos, int epos, bool flag=false)
{
	for(int i=spos; i<=epos; i++)
		cout<<str[i];
	if(flag)
		cout<<endl;
	else
		cout<<" ";
	if(spos != epos && spos != 0)
	{
		for(int i=0; i<spos-1; i++)
			cout<<str[i];
		print(str,spos+1,epos,false);
	}
}

int display(char str[], int l)
{
	int a=1, len=l, prev_len=0;
	for(int i=0;i < len; len--)
	{
		
		print(str, 0, len-1,!prev_len);
		if(prev_len != 0)
			print(str, prev_len,l-1,true);
		prev_len = len-1;
		
	}
	for(int i=0; i<l; i++)
		cout<<str[i]<<" ";
	cout<<endl;
}
int main()
{
	char str[]="ABC";
	display(str,sizeof(str)-1);
}
