#include<iostream>
#include<pthread.h>
#include<queue>

using namespace std;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

queue<int> Q;

void* producer(void* dummy)
{
	int count=0;
	while(1)
	{
		pthread_mutex_lock(&mutex);
		cout<<"P-> "<<count<<endl;
		Q.push(count++);	
		pthread_mutex_unlock(&mutex);
		pthread_cond_signal(&cond);
		sleep(1);
	}
}
void* consumer(void* dummy)
{
	while(1){

		pthread_mutex_lock(&mutex);
		pthread_cond_wait(&cond, &mutex);
		cout<<"Consumed:"<<Q.front()<<endl;
		Q.pop();
		pthread_mutex_unlock(&mutex);
	}

}

int main()
{
	pthread_t t1,t2;
	pthread_create(&t1, NULL, producer, NULL);
	pthread_create(&t2, NULL, consumer, NULL);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
}
