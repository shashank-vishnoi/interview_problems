#include<iostream>

using namespace std;
class creature;
class Worrior;
class Monster;
class Saviour;

class FightVisitor
{
	public:
	virtual void visit(Worrior&)=0;
	virtual void visit(Monster&)=0;
	virtual void visit(Saviour& s)=0;
};

class FightWithMonster:public FightVisitor{
	public:
		void visit(Worrior& w){cout<<"Monster VS Worrior\n";}
		void visit(Monster& m){cout<<"Monster VS Monster\n";}
		void visit(Saviour& s){cout<<"Monster VS Saviour\n";}
};
class FightWithWorrior:public FightVisitor{
	public:
		void visit(Worrior& w){cout<<"Worrior VS Worrior\n";}
		void visit(Monster& m){cout<<"Worrior VS Monster\n";}
		void visit(Saviour& s){cout<<"Worrior VS Saviour\n";}
};

class FightWithSaviour:public FightVisitor{
	public:
		void visit(Worrior& w){cout<<"Saviour VS Worrior\n";}
		void visit(Monster& m){cout<<"Saviour VS Monster\n";}
		void visit(Saviour& s){cout<<"Saviour VS Saviour\n";}
};

class creature{
	public:
	virtual void accept(FightVisitor& fv)=0;
};

class Worrior:public creature{
	public:
		void accept(FightVisitor& fv){fv.visit(*this);}
};
class Monster:public creature{
	public:
		void accept(FightVisitor& fv){fv.visit(*this);}

};
class Saviour:public creature{
	public:
		void accept(FightVisitor& fv){fv.visit(*this);}

};


int main()
{
	creature *w= new Worrior();
	creature *m = new Monster();
	FightWithWorrior FWW;
	FightWithSaviour FWS;
	w->accept(FWW);
	w->accept(FWS);

}
