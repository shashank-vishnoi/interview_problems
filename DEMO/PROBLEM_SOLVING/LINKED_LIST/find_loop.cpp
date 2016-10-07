#include<iostream>
#include <unistd.h>

using namespace std;


class Node{
	public:
		int val;
		Node* next;
		Node(int val):val(val),next(0)
		{}
};


Node* add_node(Node* h, int val)
{
	Node* temp = new Node(val);
	if(!h)
		return temp;
	while(h->next)
	{
		h=h->next;
	}
	h->next=temp;
	return h->next;
}

void display(Node* h)
{
	while(h)
	{
		cout<<h->val<<endl;
		h=h->next;
		usleep(300000);
	}
}

bool find_loop(Node* h)
{
	if(!h)
		return false;
	Node *ptr1=h,*ptr2=h;
	while(ptr1 && ptr2  && ptr2->next )
	{
		ptr1=ptr1->next;
		ptr2=ptr2->next->next;
		if(ptr1 == ptr2)
		{
			ptr1=h;
			Node* prev_ptr=ptr2;
			while(ptr1 != ptr2)
			{
				prev_ptr=ptr2;
				ptr1=ptr1->next;
				ptr2=ptr2->next;
			}
			cout<<"Loop at: "<<ptr1->val<<endl;
			prev_ptr->next = NULL;
			return true;
		}
	}
	return false;
}



int main()
{
	Node* head=0;
	head = add_node(head, 10);
	add_node(head,20);
	add_node(head,30);
	add_node(head,40);
	add_node(head,50);
	Node* last = add_node(head,60);
	last->next = new Node(70); 
	add_node(head,80);
	add_node(head,90);
	add_node(head,100);
	add_node(head,110);
	Node* temp = add_node(head,120);
	temp->next = last;
	cout<<find_loop(head)<<endl;
	display(head);
}
