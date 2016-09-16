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


void inOrder(Node* r)
{
	Node* current = r;
	stack<Node*> st;
	while(1)
	{
		if(current)
		{
			st.push(current);
			current = current->left;
		}
		else
		{
			if(st.empty())
				break;
			Node* temp = st.top();
			st.pop();
			cout<<temp->data<<endl;
			current = temp->right;
		}
	}
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
	add_node(root,5);
	add_node(root,3);
	add_node(root,7);
	add_node(root,20);
	add_node(root,40);
	add_node(root,15);

	inOrder(root);
	cout<<endl;
	display(root);
}
