#include<stdio.h>
#include<pthread.h>

int val = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER; 

void* even_t ()
{
	pthread_mutex_lock(&mutex);
	do {
		if ( val%2 == 0) {
			printf("Even thread val: %d\n", val);
			val = val + 1;
			pthread_cond_signal(&cond);
		} else {
			pthread_cond_wait(&cond, &mutex);
		}
	} while (val < 101);
	pthread_mutex_unlock(&mutex);
	return NULL;
}

void* odd_t ()
{
	pthread_mutex_lock(&mutex);
	do {
		if ( val%2 != 0) {
			printf("Odd thread val: %d\n", val);
			val = val + 1;
			pthread_cond_signal(&cond);
		} else {
			pthread_cond_wait(&cond, &mutex);
		}
	} while (val < 100);  
	pthread_mutex_unlock(&mutex);
	return NULL;
}



int main()
{
  pthread_t even, odd;

  pthread_create(&even, NULL, even_t, NULL);
  pthread_create(&odd, NULL, odd_t, NULL);

  pthread_join(even, NULL);
  pthread_join(odd, NULL);

  return 0;

}
