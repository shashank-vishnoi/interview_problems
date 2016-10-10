#include<iostream>


using namespace std;


int find_number_of_1(int data)
{
	if(!(data & (data-1)))
		return 1;
	int count=0, n=1;
	int loop_count=0;
	while(data > n)
	{

		if(data & n)
			count++;
		n=n<<1;
		loop_count++;
	}
	//cout<<"Loop Count: "<<loop_count<<endl;
	return count;
}

void sort_array_by_binary_bit_set(int input[], int len)
{
	int** array = new int*[32];
	for(int i=0; i<32; i++ )
	{
		array[i] = new int[len]();
		memset(array[i],0,len);
	}
	cout<<"Priniting empty array\n";
	for(int col=0; col<32; col++ )
	{
		cout<<"-----------------------\n";
		for(int row=0; row<len; row++)
			cout<<array[col][row]<<endl;
	}
	cout<<"Priniting empty array end\n";
	
	int i=0, num=0,max_num=0;
	while(i < len)
	{
		num = find_number_of_1(input[i]);
		if(max_num < num)
			max_num = num;
		int j =0 ;
		while(array[num][j] != 0)
			j++;
		array[num][j] = input[i++];
	}
	int count=0;
	for(int ii=0; ii<= max_num; ii++)
	{
		int jj=0;
		while(array[ii][jj] != 0)
		{
			input[count++] = array[ii][jj];
			jj++;
		}
	}

}




int main()
{
	//int input[] = {20,10,45,2,12,7,11,4,71,79,13,16};
	int input[] = {2,7,8,4,5,3,12};
	//cout<<find_number_of_1(2)<<endl;
	//cout<<find_number_of_1(7)<<endl;
	//cout<<find_number_of_1(44007)<<endl;

	sort_array_by_binary_bit_set(input, sizeof(input)/sizeof(int));
	for(int i=0; i< (sizeof(input)/sizeof(int)); i++)
		cout<<input[i]<<endl;

}
