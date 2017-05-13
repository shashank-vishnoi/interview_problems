#include<iostream>


using namespace std;


class Node{
	public:
		Node* left;
		Node* right;
		int data;
		Node(int data):left(NULL),right(NULL),data(data)
		{}
};

class Tree{
	public:
		Node* root;
		Tree(){root=NULL;}
		void add_node(int data);
		void display(Node* root);
		int height(Node* roo);
};

void Tree::add_node(int data)
{
	if(root == NULL)
	{
		root = new Node(data);
		return;
	}
	Node* temp = root;
	Node* prev=NULL;
	while(temp != NULL)
	{
		prev = temp;
		if(data < temp->data)
			temp = temp->left;
		else
			temp = temp->right;
	}
	if(prev->data > data)
		prev->left = new Node(data);
	else
		prev->right= new Node(data);
}


void Tree::display(Node* root)
{
	if(root == NULL)
		return;
	display(root->left);
	cout<<root->data<<endl;
	display(root->right);
}

int max(int a, int b)
{
	return (a>b?a:b);
}

int Tree::height(Node* root)
{
	if(root == NULL)
		return 0;
	return 1 + max(height(root->left) , height(root->right));
}


int main()
{
		Tree t;
		t.add_node(20);
		t.add_node(30);
		t.add_node(10);
		t.add_node(40);
		t.add_node(5);
		t.add_node(8);
		t.display(t.root);
		cout<<t.height(t.root)<<endl;
}
