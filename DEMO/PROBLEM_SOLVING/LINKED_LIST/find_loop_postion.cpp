#include<iostream>

using namespace std;


class Node{

	public:
	Node* next;
	int val;
	Node(int val):next(0),val(val)
	{}
};

Node* add_node(Node* h, int val)
{
	if(h == 0)
		return new Node(val);
	else
		h->next = add_node(h->next, val);
}

void display(Node* h)
{
	if(h)
		cout<<h->val<<endl;
	else
		return;
	sleep(1);
	display(h->next);
}

Node* find_loop(Node* h)
{
	Node *slow=h,*fast=h->next;
	while(slow != 0 && fast != 0 && fast->next != 0)
	{
		if(slow == fast)
			break;
		slow = slow->next;
		fast = fast->next->next;
	}
	if(slow == fast )
	{//loop detected
		slow = h;
		while(slow != fast->next)
		{
			cout<<slow->val<<" ,"<<fast->val<<endl;
			slow=slow->next;
			fast=fast->next;
		}
		//removed the loop
		fast->next=0;
	}
}


int main()
{
	Node* head =0;
	head = add_node(head, 10);
	add_node(head,20);
	add_node(head,30);
	add_node(head,40);
	Node* n = add_node(head,50);
	add_node(head,60);
	add_node(head,70);
	add_node(head,80);
	add_node(head,90);
	add_node(head,100);
	head->next->next->next->next->next->next->next->next->next->next = head->next->next->next;
	find_loop(head);	
	display(head);
}
