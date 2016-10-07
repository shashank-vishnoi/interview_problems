#include<iostream>

using namespace std;


class Node{
	public:
	int val;
	Node *left, *right;
	Node(int val):val(val),left(0),right(0)
	{
	}
};



Node* insert(Node* root, int val)
{
	if(!root)
	{
		Node* temp = new Node(val);
		return temp;
	}
	if(val <= root->val)
		root->left = insert(root->left, val);
	else
		root->right = insert(root->right, val);
			
}

void display(Node* root)
{
	if(!root)
		return ;
	if(root->left)
		display(root->left);
	cout<<root->val<<endl;
	if(root->right)
		display(root->right);
}


bool isComplete(Node* root)
{
	if(!root)
		return true;
	//1. if node is leaf node then return true
	if(root->left == 0 && root->right == 0)
		return true;
	if(root->left == 0 && root->right )
		return false;
	//2. if both the node present then again check for full node 
	if(root->right && root->left && isComplete(root->left) && isComplete(root->right) )
		return true;
	
}



int main()
{
	/*	20
		/\
	      10  40
		  /\
	  	30  50

	   */
	Node* root = insert(NULL, 20);
	insert(root, 40);
	insert(root, 10);
	insert(root, 30);
	insert(root, 18);
	insert(root, 5);
	display(root);
	if(isComplete(root))
		cout<<"Complete tree...\n";
	else
		cout<<"Not a Complete tree...\n";
}
