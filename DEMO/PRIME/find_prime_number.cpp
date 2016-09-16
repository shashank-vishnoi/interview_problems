#include<iostream>
#include<math.h>
using namespace std;


void find_twins_prime_numbers(int low, int high)
{
	bool prime[high];
	memset(prime,true, sizeof(prime));
	for(int i=2; i<sqrt(high)+1; i++)
	{
		if(prime[i])
		{
			for(int j=i*2; j<high; j=j+i)
				prime[j] = false;
		}
	}
	for(int i=low;i<high;i++)
	{
		if(prime[i] && prime[i+2])
		{
			cout<<"("<<i<<","<<i+2<<")"<<endl;
			break;
		}
	}
}



int main()
{
	find_twins_prime_numbers(50,100);
}
