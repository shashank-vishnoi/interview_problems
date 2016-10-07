/*
Given a sorted (increasing order) array, write a program to create a binary tree with minimal height
*/
#include<iostream>
#include<queue>


using namespace std;

class Node{
	public:
	Node *left, *right;
	int data;
	Node(int data):left(0),right(0),data(data)
	{
	}
};





Node* create_binary_treefrom_sorted_array(int input[], int start, int end )
{
	int mid = (start+end)/2;
	cout<<"MID:"<<mid<<endl;
	if(start >  end)
		return 0;
	Node* root = new Node(input[mid]);
	root->left = create_binary_treefrom_sorted_array(input, start, mid-1);
	root->right = create_binary_treefrom_sorted_array(input,mid+1,end);
	return root;
}


void display(Node* root)
{
	if(!root)
		return;
	if(root)
		cout<<root->data<<endl;
	display(root->left);
	display(root->right);
}




int main()
{
	int input[]={5,10,15,20,25,30,35,40};
	int len = sizeof(input)/sizeof(int);
	Node* root = create_binary_treefrom_sorted_array(input, 0, len-1);
	display(root);
}
