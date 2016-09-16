#include<iostream>
using namespace std;

class Monster;
class Warrior;

class Creature{
public:
    virtual void fight(Creature&) =0;
    virtual void fightwho(Creature&)=0;
     virtual void fightwho(Warrior& w)=0;
     virtual void fightwho(Monster& m)=0;
};

class Monster: public Creature{
    void fightwho(Creature& c){cout<<"Monster::\n";c.fightwho(*this);}
    void fightwho(Warrior& w) {cout<<"Monster versus Warrior"<<endl; }
    void fightwho(Monster& m) {cout<<"Monster versus Monster"<<endl; }
public:
    void fight(Creature& c)  {c.fightwho(*this);}
};

class Warrior: public Creature{
    void fightwho(Warrior& w) {cout<<"Warrior versus Warrior"<<endl; }
    void fightwho(Monster& m) {cout<<"Monster versus Warrior"<<endl; }
    void fightwho(Creature& c){c.fightwho(*this);}
public:
    void fight(Creature& c) {
	    cout<<"Warrior::fight()\n";
	    c.fightwho(*this);
    }
};

int main()
{
Warrior w;
Monster m;
w.fight(m);
}
