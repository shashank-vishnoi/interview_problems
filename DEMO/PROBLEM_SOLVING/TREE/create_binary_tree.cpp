#include<iostream>

using namespace std;


class Node{
	public:
		Node* left;
		Node* right;
		int val;
		Node(int val):left(NULL),right(NULL),val(val)
		{}

};

Node* add_node(Node* r, int val)
{
	if(!r)
		return new Node(val);
       if(val < r->val)	
	       r->left = add_node(r->left, val);
       else
	       r->right = add_node(r->right, val);
}

void display(Node* root)
{
	if(!root)
		return;
	display(root->left);
	cout<<root->val<<endl;
	display(root->right);
}




int main()
{
	Node* root;
	root = add_node(root,10);
	add_node(root,20);
	add_node(root,5);
	add_node(root,30);
	add_node(root,0);
	display(root);
}
