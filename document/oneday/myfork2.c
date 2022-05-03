#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
//循环创建父子进程
int main(int argc,char* argv[])
{
	int i=0;
	for(i;i<3;i++)
	{
		pid_t pid=fork();
		if(pid<0)
		{
			printf("创建进程失败!\n");
		}
		else if(pid==0)
		{
			printf("创建子进程： pid=%d, ppid=%d\n",getpid(),getppid());
		}
		else
		{

			//sleep(1);
			printf("创建父进程： pid=%d, ppid=%d\n",getpid(),getppid());
			break;
		}	
		sleep(2);
	}
	return 0;
}	

