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


Node* add_node(Node* root, int val)
{
	if(!root)
		return new Node(val);
	if(!root->left)
	{
		root->left = new Node(val);
	}
	else if(!root->right)
	{
		root->right = new Node(val);
	}
	else{
	queue<Node*> q;
	if(root->left)
		q.push(root->left);
	if(root->right)
		q.push(root->right);
	while(!q.empty())
	{
		Node* temp = q.front();	q.pop();	
		if(temp->left && temp->right)
		{
			q.push(temp->left);q.push(temp->right);
			continue;
		}
		else if(!temp->left)
		{
			temp->left = new Node(val);
			break;
		}else{
			temp->right = new Node(val);
			break;
		}
	}
	}
}


Node* create_binary_tree(int input[], int len)
{
	int i=0;
	Node* root=0;
	while(i < len)
	{
		if(i == 0)
			root = add_node(root, input[i++]);
		else
			add_node(root, input[i++]);
	}
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
	Node* root = create_binary_tree(input, len);
	display(root);
}
