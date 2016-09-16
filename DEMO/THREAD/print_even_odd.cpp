#include<iostream>

#include<pthread.h>
#include<signal.h>

using namespace std;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int v=0;

void* thread1(void* val)
{

	while(1){
		pthread_mutex_lock(&mutex);
		cout<<"thread1: "<<v++<<endl;
		pthread_cond_signal(&cond);
		sleep(1);
		pthread_cond_wait(&cond, &mutex);
		pthread_mutex_unlock(&mutex);

	}
}

void* thread2(void* val)
{

	while(1){
		pthread_mutex_lock(&mutex);
		pthread_cond_wait(&cond, &mutex);
		sleep(1);
		cout<<"thread2: "<<v++<<endl;
		pthread_cond_signal(&cond);
		pthread_mutex_unlock(&mutex);
	}
}


int main()
{

	pthread_t t1=0,t2=0;
	int val=0;
	
	pthread_create(&t1,NULL,&thread1,NULL);
	pthread_create(&t2,NULL,&thread2,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);

}
