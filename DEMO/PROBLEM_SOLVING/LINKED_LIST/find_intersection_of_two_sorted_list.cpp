/***
For example, let the first linked list be 1->2->3->4->6 and second linked list be 2->4->6->8, then your function should create and return a third list as 2->4->6.


***/
#include<iostream>

using namespace std;


class Node{
	public:
	Node* next;
	int data;
	Node(int data):data(data),next(0)
	{}
};

Node* addNode(Node* head, int data)
{
	Node* temp = new Node(data);
	if(head == 0)
		return temp;
	head->next = addNode(head->next, data);

}

void display(Node* head)
{
	if(head == 0)
		return;
	cout<<head->data<<endl;
	display(head->next);
}

Node* create_intersect_list(Node* h1, Node* h2)
{
	if(h1==0 || h2==0)
		return 0;
	Node* curr = 0;
	while(h1 != 0 && h2!=0)
	{
		while((h1 !=0 && h2!=0) && h1->data <= h2->data)
		{
			if(h1->data == h2->data)
			{
				curr = addNode(curr, h1->data);
				h1=h1->next;
				h2=h2->next;
				break;
			}
			h1=h1->next;
		}
		while((h1 !=0 && h2!=0) && h1->data >= h2->data)
		{
			if(h1->data == h2->data)
			{
				curr = addNode(curr, h1->data);
				h1=h1->next;
				h2=h2->next;
				break;
			}
			h2=h2->next;
		}
	}
	return curr;


}


int main()
{
	Node* h=0;
	h = addNode(h, 1);
	addNode(h,2);
	addNode(h,3);
	addNode(h,4);
	addNode(h,6);
	display(h);
	cout<<endl;
	Node* h1=0;
	h1 = addNode(h1, 2);
	addNode(h1,4);
	addNode(h1,6);
	addNode(h1,8);
	display(h1);
	cout<<endl;
	Node* h2 = create_intersect_list(h,h1);
	display(h2);
	cout<<endl;
}
