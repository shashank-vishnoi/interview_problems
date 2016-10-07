#include <iostream>
using namespace std;

class Normal;
class Charged;
class Defensive;
class Hurt;
class Dead;
class PlayerState;
class HealthStateFactory;

enum estate {NORMAL, CHARGED, DEFENCIVE, HURT, DEAD};

class PlayerState{
    public:
    estate name;
    virtual void run(){};
    virtual void fire(){};
    virtual void jump(){};
    PlayerState()
    {
    }
    virtual estate attacked(){}
    virtual estate takeMedi(){}
};

static HealthStateFactory factory;

class Player{
    PlayerState *healthState;
    //HealthStateFactory *factory;
    public:
    void run(){healthState->run();}
    void fire(){healthState->fire();}
    void jump(){healthState->jump();}
    void takeMedi()
    {
	    healthState = factory.getHealth(CHARGED);//healthState->takeMedi());
    }
    void attacked()
    {
	    healthState = factory.getHealth(healthState->attacked());
    }
    //Player(){factory = new HealthStateFactory();  healthState = factory->getHealth(NORMAL);}
    Player():healthState(factory.getHealth(NORMAL))
	{}
};

class Normal:public PlayerState{
    
    public:
    void run(){cout<<"run at 2x speed\n";}
    void fire(){cout<<"fire two time";}
    void jump(){cout<<"jump 2x level";}
    Normal(){name=NORMAL;}
    estate attacked()
    {
	    return DEFENCIVE;
    }
    estate takeMedi(){return CHARGED;}
};

class Charged:public PlayerState{
       public:
    void run(){cout<<"run at 4x speed\n";}
    void fire(){cout<<"fire four times";}
    void jump(){cout<<"jump 4x level";}
    Charged(){name=CHARGED;}
    estate takeMedi(){return CHARGED;}
    estate attacked()
    {
	    return NORMAL;
    }


};
class Defensive: public PlayerState{
    public:
    void run(){cout<<"run at x speed\n";}
    void fire(){cout<<"fire one time";}
    void jump(){cout<<"jump x level";}
    Defensive(){name = DEFENCIVE;}
    estate takeMedi(){return NORMAL;}
    estate attacked()
    {
	    return HURT;
    }

    
};

class Hurt: public PlayerState{
    public:
    void run(){cout<<"run at x/2 speed\n";}
    void fire(){cout<<"No fire";}
    void jump(){cout<<"jump x/2 level";}
    Hurt(){name=HURT;}
    estate takeMedi(){return DEFENCIVE;}
    estate attacked()
    {
	    return DEAD;
    }
    
};
class Dead: public PlayerState{
    public:
    void run(){cout<<"No run\n";}
    void fire(){cout<<"No fire";}
    void jump(){cout<<"No jump";}
    Dead(){name=DEAD;}
    estate takeMedi(){return DEAD;}
    estate attacked()
    {
	    return DEAD;
    }
    
};

class HealthStateFactory{
	public:
		PlayerState* getHealth(estate s)
		{
			//  charged = new charged();
			//  def = new 
			switch(s){
				case NORMAL:
					return  new Normal();
				case CHARGED:
					return new Charged();
				case DEFENCIVE:
					return new Defensive();
				case HURT:
					return new Hurt();
				default:
					return new Dead();
			}
			return 0;
		}
};

int main() {
	// your code goes here
	Player p1;
	p1.fire();
	p1.jump();
	p1.takeMedi();
	p1.jump();
	p1.run();
	p1.attacked();
	p1.attacked();
	p1.attacked();
	p1.run();
	p1.jump();
	return 0;
}

