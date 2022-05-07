#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>
#include<string.h>
void* mythread(void* arg)
{
	int i=*(int*)arg;
	printf("[%d]:child pthread\n",i);
}
int main()
{
	int i=0;
	int n=10;
	pthread_t thread[n];
	for(i;i<n;i++)
	{
		int ret = pthread_create(&thread[i],NULL,mythread,&i);
		if(ret!=0)
		{
			printf("failed create pthread :[%s]\n",strerror(ret));
		}
	
	//	sleep(1);
	}
	printf("main: pthread \n");

	sleep(1);
	return 0;
}
