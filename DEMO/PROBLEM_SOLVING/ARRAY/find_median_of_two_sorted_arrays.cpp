/**
	Given two sorted int arrays, find the median of these two arrays
ex1:
	ar1[] = {1, 12, 15, 26, 38}
	ar2[] = {2, 13, 17, 30, 45} 
	={1,2,12,13,15,17,26,30,38,45} = total number of element are 10, it is even so median will be median of [position 10/2=5 and 6] i.e. (15+17)/2=16
	
ex2:
	ar1[] ={1,5,19,20,35,50,60} ==>med=20 (since odd count)
	ar2[] ={24,30,45,55,65,75,85,90} ==>med=(55+65)/2=60 (since even count)
	so combine median should be between 20 to 60 somewhere
	samething repeat on {35,50,60}==>med=50 & {24,30,45,55}==>med=37 (so med b/w 37 & 50)
	
	{35} & {45,50}

	merge = {1,5,19,20,24,30,35,45,50,55,60,65,75,85,90} ==> 45


  **/

#include<iostream>

using namespace std;

int get_median(int a1[],int s1,int a2[], int s2, bool flag)
{
	int med1=-1,med2=-1;
	if(s1 <= 2 || s2<=2)
	{
		if(s1%2 == 0)
			med1=s1/2+s1/2+1; //== >50
		else
			med1=a1[s1/2];
		if(s2%2 == 0)
			med2=(a2[s2/2]+a2[(s2/2)+1]); //== >50
		else
			med2=a2[s2/2];
		int max=0;
		if(med1< med2)
			max=med2;
		else
			max=med1;
		if(flag == false)
		{
			if(s1+s2 == 3)
			{
				if(a1[0]<a2[0])
				{
					if(s1 < s2)
						a2[0];
					else
						a1[1];
				}
			}
				
		}
		else
			return (a1[1]+a2[0])/2;
	}
	else{
	if(med1<med2)
		return get_median(&a1[med1+1],s1/2, a2,s2/2, flag);
	else
		return get_median(a1,s1/2, &a2[med2+1],s2/2, flag);
	}
}


int getMedian(int a1[],int s1, int a2[], int s2)
{
	bool isEven=false;
	int med1=-1,med2=-1;
	if((s1+s2)%2 == 0)
		isEven=true;
	if(s1%2 == 0 && s1>=1)
		med1=(a1[s1/2] + a1[(s1/2)+1])/2;
	else
		med1=a1[s1/2];
	if(s2%2 == 0 && s2>=1)
		med2=(a2[s2/2] + a2[(s2/2)+1])/2;
	else
		med2=a2[s2/2];
	if(med1 == med2)
		return med1;
	else if(med1<med2)
		return get_median(&a1[med1+1],s1/2, a2,s2/2, isEven);
	else
		return get_median(a1,s1/2, &a2[med2+1],s2/2, isEven);

}

int main()
{
	int ar1[] ={1,5,19,20,35,50,60};
	int ar2[] ={24,30,45,55,65,75,85,90};
	cout<<getMedian(ar1,sizeof(ar1)/sizeof(ar1[0]), ar2, sizeof(ar2)/sizeof(ar2[0]))<<endl;
}





