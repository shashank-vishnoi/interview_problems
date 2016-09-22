#include<iostream>



using namespace std;


class R1{
	static pthread_mutex_t mutex;
	public:
		int lock()
		{
			cout<<"going to acquire lock on R1 resource\n";
			return pthread_mutex_lock(&mutex);
		}
		int unlock()
		{
			return pthread_mutex_unlock(&mutex);
		}
		void display()
		{
			for(int i=0; i <10; i++)
			{
				cout<<"working on resource R1- "<<i<<"\n";
				usleep(10);
			}
		}
};

pthread_mutex_t R1::mutex = PTHREAD_MUTEX_INITIALIZER;

class R2{
	static pthread_mutex_t mutex;
	public:
		int lock()
		{
			cout<<"going to acquire lock on R2 resource\n";
			return pthread_mutex_lock(&mutex);
		}
		int unlock()
		{
			return pthread_mutex_unlock(&mutex);
		}
		void display()
		{
			for(int i=0; i <10; i++)
			{
				usleep(30);
				cout<<"working on resource R2- "<<i<<"\n";
			}
		}
};

pthread_mutex_t  R2::mutex = PTHREAD_MUTEX_INITIALIZER;

void* routine1(void* dummy)
{
	R1 r1;R2 r2;
	r1.lock();
	cout<<"routine1 -> calling r1.display()\n";
	r1.display();
	r2.lock();
	cout<<"routine1 -> calling r2.display()\n";
	r2.display();
	r2.unlock();
	r1.unlock();	
}

void* routine2(void* dummy)
{
	R1 r1;R2 r2;
	r2.lock();
	cout<<"routine2 -> calling r2.display()\n";
	r2.display();
	r1.lock();
	cout<<"routine1 -> calling r1.display()\n";
	r1.display();
	r1.unlock();
	r2.unlock();	
}
int main()
{
	R1 r1;
	R2 r2;
	pthread_t t1,t2;
	pthread_create(&t1, NULL, routine1, NULL);
	pthread_create(&t2, NULL, routine2, NULL);
	pthread_exit(0);
}
