#include<iostream>
#include<queue>
#include<vector>

using namespace std;


class Node{
	public:
		int val;
		Node *left, *right;
		Node(int val):val(val),left(0),right(0)
		{}

};



Node* insert(Node* root, int val)
{
	if(!root)
		return new Node(val);

	if(val < root->val)
		root->left = insert(root->left, val);
	else
		root->right = insert(root->right, val);
}


void display(Node* root)
{
	if(!root)
		return;
	display(root->left);
	cout<<root->val<<endl;
	display(root->right);

}


void bfPrint_root_to_leaf(Node* root)
{
	queue<Node*> Q;
	if(!root)
		return;
	Q.push(root);
	while(!Q.empty())
	{
		Node* temp = Q.front();
		Q.pop();
		cout<<temp->val<<endl;
		if(temp->left)
		{
			Q.push(temp->left);
		}
		if(temp->right)
		{
			Q.push(temp->right);
		}
		
	}
}
void bfPrint_leaf_to_root(Node* root)
{
	queue<Node*> Q;
	vector<int> V;
	if(!root)
		return;
	Q.push(root);
	while(!Q.empty())
	{
		Node* temp = Q.front();
		Q.pop();
		V.push_back(temp->val);
		if(temp->left)
		{
			Q.push(temp->left);
		}
		if(temp->right)
		{
			Q.push(temp->right);
		}
		
	}
	for(vector<int>::iterator  it= V.end(); it != V.begin(); --it)
	{
		cout<<*it<<endl;
	}
}

int main()
{
	Node* root = insert(NULL, 50);
	insert(root, 30);
	insert(root, 40);
	insert(root, 10);
	insert(root, 60);
	display(root);
	cout<<"Breadth First Print\n";
	bfPrint_root_to_leaf(root);
	cout<<"Breadth First Print in differnt order\n";
	bfPrint_leaf_to_root(root);
}
