#include<iostream>

using namespace std;

enum  handler {HANDLER1, HANDLER2, HANDLER3};


class BaseHandler{
	public:
		BaseHandler* next;
		virtual void start(handler h)=0;
};

class Handler1:public BaseHandler{
	public:
		void setNext(BaseHandler* h){next=h;}
		void start(handler h)
		{
			if(h == HANDLER1)
				cout<<"Request is handled in HANDLED 1 \n ";
			else {
				cout<<"Request can't be handeled here, throwing to next handler\n";
				next->start(h);
			}
		}
};
class Handler2:public BaseHandler{
	public:
		void setNext(BaseHandler* h){next=h;}
		void start(handler h)
		{
			if(h == HANDLER2)
				cout<<"Request is handled in HANDLED 2 \n ";
			else {
				cout<<"Request can't be handeled here, throwing to next handler\n";
				next->start(h);
			}
		}
};
class Handler3:public BaseHandler{
	public:
		void setNext(BaseHandler* h){next=h;}
		void start(handler h)
		{
			if(h == HANDLER3)
				cout<<"Request is handled in HANDLED 3 \n ";
			else {
				cout<<"Request can't be handeled here, throwing to next handler\n";
				//next->start(h);
			}
		}
};


class HandleRequest{
	public:
		BaseHandler* han;
	HandleRequest()
	{
		Handler1 *h1 = new Handler1();
		Handler2 *h2 = new Handler2();
		Handler3 *h3 = new Handler3();
		h1->setNext(h2);h2->setNext(h3);h3->setNext(NULL);
		han = h1;
	}
	void process_request(handler h)
	{
		han->start(h);
	}
};

int main()
{
	HandleRequest h;
	h.process_request(HANDLER3);
}
