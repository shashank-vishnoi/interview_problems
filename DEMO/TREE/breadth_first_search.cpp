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

void bfs(Node* r)
{
	queue<Node*> qu;
	qu.push(r);
	while(!qu.empty())
	{
		Node* temp = qu.front();
		qu.pop();
		cout<<temp->val<<",";
		if(temp->left)
			qu.push(temp->left);
		if(temp->right)
			qu.push(temp->right);

	}
	cout<<endl;
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
	cout<<"Breadthe First Print\n";
	bfs(root);
}
