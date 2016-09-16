#include<iostream>
#include<math.h>
using namespace std;



void print_primes(int max)
{
	int sqrt_val  = sqrt(max);
	cout<<max;
	bool *prime = new bool[max];
	fill(prime,prime+max,true);

	for(int i =2; i<sqrt_val; i++)
	{
		for(int j=i*2; j<max; j=j+i)
		{
			prime[j] = false;
		}
	}
	for(int k=1;k<max;k++)
	{
		if(prime[k])
			cout<<k<<"   ";
	}
}

int main()
{
	print_primes(200);
}
