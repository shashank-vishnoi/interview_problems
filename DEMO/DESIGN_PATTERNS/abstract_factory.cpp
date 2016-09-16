//AF Pattern - encapsulate the similar kind of factories that have common themes, it provides the interface to organize to produce similar kind of objects which are different in implementation based on 

#include<iostream>

using namespace std;

class MediaController{
	public:
		virtual void load()=0;
};

class Dvr:public MediaController{
	public:
		void load(){cout<<"Dvr::load()\n";}
};
class MRDvr:public MediaController{
	public:
		void load(){cout<<"MRDvr::load()\n";}
};
class Dvr_IPC:public MediaController{
	public:
		void load(){cout<<"Dvr_IPC::load()\n";}
};
class MRDvr_IPC:public MediaController{
	public:
		void load(){cout<<"MRDvr_IPC::load()\n";}
};

//Abstract factory class
class AFC{
	public:
		virtual MediaController* get_media_controller(int url)=0;
};

//factory class for G8
class FC_G8:public AFC{
	public:
		MediaController* get_media_controller(int url)
		{
			if(url  == 0)
				return new Dvr();
			else
				return new MRDvr();
		}

};
class FC_IPC:public AFC{
	public:
		MediaController* get_media_controller(int url)
		{
			if(url  == 0)
				return new Dvr_IPC();
			else
				return new MRDvr_IPC();
		}

};

AFC* initialize_controller(string str)
{
	if(str == "IPC")
		return new FC_IPC();
	else
		return new FC_G8();
}


int main()
{
	AFC* handler = initialize_controller("IPC");
	MediaController* cont = handler->get_media_controller(0);
	cont->load();
	return 0;
}
