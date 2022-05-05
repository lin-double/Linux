#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	//before fork 
	printf("before fork pid=[%d]\n",getpid());//获取当前进程的pid
	pid_t pid=fork();//创建子进程，
	if(pid<0)
	{
		perror("fork error\n");
		return (-1);
	}
	else if(pid==0)//pid==0,child fork
	{
		printf("child fork: pid=[%d]\tppid=[%d]\n",getpid(),getppid());
		printf("%d\n",pid);
	}
	else if(pid>0)//pid>0 father fork
	{
		printf("father fork: pid=[%d]\tppid=[%d]\n",getpid(),getppid());
		printf("%d\n",pid);
		sleep(1);
	}
	printf("after fork pid=[%d]\n",getpid());
	return 0;
}	
