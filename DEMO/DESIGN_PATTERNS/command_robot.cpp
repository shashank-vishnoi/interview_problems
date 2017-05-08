/*
	Command DP - A request is wrapped under an object as command and passed over invoker object that execute the command appropriately.
   */
#include<iostream>
#include<queue>
#include<stack>

using namespace std;



class Robot{
	public:
		Robot(){cout<<"Robot is created!\n";}
		void moveBackward(int distance){cout<<"Move backward: "<<distance<<endl;}
		void moveForward(int distance){cout<<"Move forward: "<<distance<<endl;}
		void leftRotate(int angle){cout<<"left rotate: "<<angle<<endl;}
		void rightRotate(int angle){cout<<"right rotate: "<<angle<<endl;}
		void move(int distance)
		{
			if(distance < 0)
				moveBackward(-distance);
			else
				moveForward(distance);
		}
		void rotate(int angle)
		{
			if(angle< 0)
				leftRotate(-angle);
			else
				rightRotate(angle);
		}
		
};


class RobotCommands{
	public:
		Robot* robot;
		RobotCommands(Robot* r):robot(r){}
		void virtual execute()=0;
		void virtual undo()=0;
};

class MoveCommands: public RobotCommands{
	public:
		int distance;
		MoveCommands(Robot* r, int d=0):RobotCommands(r),distance(d){}
		void execute()
		{
			robot->move(distance);
		}
		void undo()
		{
			robot->move(-distance);
		}

};

class RotateCommands: public RobotCommands{
	public:
		int angle;
		RotateCommands(Robot* r, int a=0):RobotCommands(r),angle(a){}
		void execute()
		{
			robot->rotate(angle);
		}
		void undo()
		{
			robot->rotate(-angle);
		}
};

class RobotController{
	public:
		queue<RobotCommands*> q;
		stack<RobotCommands*> st;
		RobotController(){}
		void enqueue(RobotCommands* cmd)
		{
			q.push(cmd);
		}
		void run()
		{
			while(!q.empty())
			{
				RobotCommands* temp = q.front();
				temp->execute();
				st.push(temp);
				q.pop();
			}
		}
		void revert()
		{
			while(!st.empty())
			{
				st.top()->undo();
				st.pop();
			}	
		}
};



int main()
{
	Robot r;
	RobotController rc;
	RobotCommands *mv_cmd = new MoveCommands(&r, 100);
	rc.enqueue(mv_cmd);
	RobotCommands *rot_cmd = new RotateCommands(&r, 45);
	rc.enqueue(rot_cmd);
	rc.run();
	rc.revert();
}
