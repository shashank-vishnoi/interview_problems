/*
COR- comes under behavioral pattern - whaen a request is submitted by client, it travrses through list of handlers until satisified by one of the handler.

   */

#include<iostream>

using namespace std;

enum ErrorState {ANALYZE,FIX,VERIFY,CLOSE};

class Bug{
	public:
	ErrorState state;
		Bug(ErrorState st):state(st)
		{}
		Bug *next;
		virtual void set_next_handler(Bug*)=0;
		virtual void process_error(ErrorState st)=0;
};

class Analyze:public Bug{
	public:
		Analyze(ErrorState st):Bug(st)
		{}
		void set_next_handler(Bug* handler){next = handler;}
		void process_error(ErrorState st)
		{
			if(st == state)
				cout<<"Error has been Analyzed\n";
			else{
				cout<<"Analyze::pass to next handler\n";
				next->process_error(st);
			}
		}
};

class Fix:public Bug{
	public:
		Fix(ErrorState st):Bug(st)
		{}
		void set_next_handler(Bug* handler){next = handler;}
		void process_error(ErrorState st)
		{
			if(st == state)
				cout<<"Error has been fixed\n";
			else
			{
				cout<<"Fix::pass to next handler\n";
				next->process_error(st);
			}
		}

};

class Verify:public Bug{
	public:
		Verify(ErrorState st):Bug(st)
		{}
		void set_next_handler(Bug* handler){next = handler;}
		void process_error(ErrorState st)
		{
			if(st == state)
				cout<<"Error has been verified\n";
			else{
				cout<<"Verify::pass to next handler\n";
				next->process_error(st);
			}
		}

};

class Closed:public Bug{
	public:
		Closed(ErrorState st):Bug(st)
		{}
		void set_next_handler(Bug* handler){next = handler;}
		void process_error(ErrorState st)
		{
			if(st == state)
				cout<<"Error has been closed\n";
			else{
				cout<<"closed::error can't be handler\n";
				//next->process_error(st);
			}
		}

};

class ReportError{
	Bug* err;
	public:
		ReportError()
		{
			Analyze* a = new Analyze(ANALYZE);
			err = a;
			Fix* f= new Fix(FIX);
			Verify* v= new Verify(VERIFY);
			Closed* c= new Closed(CLOSE);
			a->set_next_handler(f);
			f->set_next_handler(v);
			v->set_next_handler(c);
		}
	void process_error(ErrorState st)
	{
		err->process_error(st);
	}
};



int main()
{
	ReportError r;
	r.process_error(CLOSE);
}
