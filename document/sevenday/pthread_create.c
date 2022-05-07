#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>
void *pthread(void* arg)
{
	printf("child pthread---pid=[%d]--tid=[%ld]\n",getpid(),pthread_self());
	return ;
}
int main()
{
	pthread_t thread;
	int ret=pthread_create(&thread,NULL,pthread,NULL);
	if(ret!=0)
	{
		printf("pthread create failed![%s]\n",strerror(ret));
	}
	//printf("main pthread \n");
	printf("main pthread---pid=[%d]--tid=[%ld]\n",getpid(),pthread_self());
	sleep(1);
	return 0;	
}
