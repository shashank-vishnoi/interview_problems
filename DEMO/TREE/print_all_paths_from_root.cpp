#include<iostream>
#include<queue>

using namespace std;

class Node{
	public:
		int val;
		Node *right,*left;
		Node(int val):val(val),right(NULL),left(NULL)
		{}
	
};

Node* add_node(Node* r, int val)
{
	Node *temp = new Node(val);
	if(!r)
		return temp;
	if(r->val > val)
		r->left = add_node(r->left,val);
	else
		r->right = add_node(r->right,val);
}

void display(Node* r)
{
	if(r == NULL)
		return;
	display(r->left);
	if(r)
		cout<<r->val<<endl;
	display(r->right);
}

int hieght(Node* r)
{
	if(!r)
		return 0;
	 return  1 + ((hieght(r->left) > hieght(r->right)) ?  hieght(r->left): hieght(r->right));
}

void print_paths(Node* r, int *path, int len)
{
	if(!r)
		return;
	path[len] = r->val;
	if(r->left == NULL && r->right == NULL)
	{
		for(int i=0; i<=len ; i++)
			cout<<path[i]<<" ";
		cout<<endl;
	}
	print_paths(r->left, path,len + 1);
	print_paths(r->right, path,len + 1);
}

void print_all_paths(Node* r)
{
	if(!r)
		return;
	int h = hieght(r);
	int *path = new int[h];
	print_paths(r,path,0);
	delete[] path;
}

int main()
{
	Node* root = NULL;
	root = add_node(root,10);
	add_node(root,7);
	add_node(root,50);
	add_node(root,30);
	add_node(root,40);
	add_node(root,70);
	add_node(root,60);
	add_node(root,20);
	add_node(root,80);
	display(root);
	cout<<"Print All paths from root\n";
	print_all_paths(root);
	cout<<"Hieght: "<<hieght(root)<<endl;
}
