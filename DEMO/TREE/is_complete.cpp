#include<iostream>
#include<stack>
using namespace std;


class Node{
	public:
	Node* left;
	Node* right;
	int data;
	Node(int data):left(0),right(0),data(data)
	{}
};


Node* add_node(Node* r, int val)
{
	Node* temp = new Node(val);
	if(!r)
		return temp;
	if(r->data > val)
		r->left = add_node(r->left, val);
	else
		r->right = add_node(r->right,val);
}

bool isComplete(Node* r)
{
	//1. Traverse tree until Full node- if found not full node then check it should be leaf node
	//2. If left node is empty then right node sould be empty

	if(!r)
		return true;
	if(r->left ==0 && r->right != 0)
		return false;
	if(r->left ==0 && r->right == 0)
		return true;
	return isComplete(r->left) && isComplete(r->right);
}


void display(Node* root)
{
	if(!root)
		return;
	display(root->left);
	cout<<root->data<<endl;
	display(root->right);
}
int main()
{
	Node* root;
	root = add_node(root,10);
	add_node(root,8);
	//add_node(root,3);
	add_node(root,6);
	add_node(root,20);
	add_node(root,4);
	add_node(root,7);

	display(root);
	cout<<"complete(1) or non-complete(0):"<<isComplete(root)<<endl;
}

