#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include <sys/types.h>
#include "fun.h"
//int val;
main()
{
	sem_t sem1;
	sem_t sem2;
	sem_init(&sem1,0,2);
	sem_init(&sem2,0,1);
        pthread_t thread1;
	pthread_t thread2;
        char *msg="Thread of 1";
	char *n="Thraed of 2";
        int rv1;
	int rv2;
        rv1=pthread_create(&thread1,NULL,print,(void*) &sem1);
	rv2=pthread_create(&thread2,NULL,cal,(void*) &sem2);
//      printf("Return value of thread1 is %d\n",rv1);
//	printf("Return value of thread2 is %d\n",rv2);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);

}

void* print(void* id)
{
	 sem_wait((sem_t*)id);

	printf("%s\n",__func__);
	  sem_post((sem_t*)id);
}
void* cal(void* id2)
{
	 sem_wait((sem_t*)id2);
	printf("%s\n",__func__);
	 sem_post((sem_t*)id2);
}

