/*

     1
   /   \
  2     2     is a mirror tree.
 / \   / \
3   4 4   3


*/
#include<iostream>

using namespace std;



class Node{
	public:
	int data;
	Node *left, *right;
	Node(int val):data(val),left(0),right(0)
	{}
};


void display(Node* r)
{
	if(!r)
		return;
	display(r->left);
	cout<<r->data<<endl;
	display(r->right);
}

Node* add_node(Node* r, int val)
{
	Node* temp = new Node(val);
	if(!r)
		return temp;
	if(val> r->data)
		r->right = add_node(r->right,val);
	else
		r->left= add_node(r->left,val);

}

bool isMirror(Node* rl,Node* rh)
{
	if(!rl && !rh)
		return true;
	if(rl && rh && rl->data == rh->data)
		return isMirror(rl->left, rh->right) && (rl->right && rh->left);
	return false;
}


bool is_mirror(Node* r)
{
	cout<<"shashank: " <<isMirror(r, r); 
}



int main()
{
	Node* root1 = add_node(0,20);
	add_node(root1,10);
	add_node(root1,40);
	add_node(root1,15);
	display(root1);
	cout<<"is mirror tree: "<<is_mirror(root1)<<endl;
	Node *root        = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(2);
    root->left->left  = new Node(3);
    root->left->right = new Node(4);
    root->right->left  = new Node(4);
    root->right->right = new Node(3);
 
	display(root);
	cout<<"is mirror tree: "<<is_mirror(root)<<endl;
}



