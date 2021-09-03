#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

sem_t semaphore;

int val = 0;

void * one (void)
{
	do {
	if (val%2 == 0) {
	sem_wait(&semaphore);
	printf("Printing from t1 : %d\n", val);
	val = val + 1;
	sem_post(&semaphore);
	}
	} while (val < 101);
}

void * two (void)
{
	do {
	if (val%2 != 0 ) {
	sem_wait(&semaphore);
	printf("Printing from t2 : %d\n", val);
	val = val + 1;
	sem_post(&semaphore);
	}
	} while (val < 101);
}

int main()
{
	pthread_t t1, t2;
	sem_init(&semaphore, 0, 1);

	pthread_create(&t1, NULL, one, NULL);
	pthread_create(&t2, NULL, two, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	sem_destroy(&semaphore);

	return 0;
}
