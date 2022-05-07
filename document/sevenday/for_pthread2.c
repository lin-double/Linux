#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<pthread.h>
void *mythread(void* arg)
{
	int i=*((int*)arg);
	printf("[%d]:child\n",i);
}
int main()
{
	int i=0;
	int n=10;
	pthread_t thread[n];
	int arr[10];
	//循环创建子线程
	for(i;i<n;i++)
	{
		arr[i]=i;
		int ret=pthread_create(&thread[i],NULL,mythread,&arr[i]);
		if(ret!=0)
		{
			printf("failed create pthread:[%s]\n",strerror(ret));
		}
	}	
	printf("main:pthread\n");
	sleep(10);
	return 0;
}

