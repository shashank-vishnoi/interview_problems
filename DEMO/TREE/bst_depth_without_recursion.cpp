#include<iostream>
#include<stack>

using namespace std;


class Node{
	public:
		Node* left;
		Node* right;
		int data;
		Node(int val):left(0),right(0),data(val)
		{}
};


int depth(Node* r)
{
	if(!r)
		return 0;
	stack<Node*> st;
	st.push(r);
	Node* current = r->left;
	int count=0,max=0;
	while(1)
	{
		count=0;
		while(current != 0)
		{
			st.push(current);
			current=current->left;
			count++;
		}
		if(st.empty())
			break;
		current = st.top();
		st.pop();
		cout<<current->data<<endl;
		current=current->right;
		while(current != 0)
		{
			st.push(current);
			current=current->left;
			count++;
		}
		if(count > max)
			max = count;
	}
	return max;
}



int main()
{
	Node* root= new Node(10);
	root->left=new Node(5);
	root->right=new Node(20);
	root->left->left = new Node(3);
	root->left->right = new Node(7);
	root->right->left = new Node(15);
	root->right->right = new Node(30);
	root->right->right->left = new Node(25);
	cout<<"Depth: "<<depth(root)<<endl;
}
