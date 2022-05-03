#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(int argc,char * argv[])
{
	pid_t pid=fork();
	if(pid<0)
	{
		printf("创建进程失败！\n");
	}
	else if(pid==0)
	{
		printf("子进程：pid=%d,ppid=%d\n",getpid(),getppid());
//		execl("/usr/bin/ls","ls","-l",NULL);//相当于在子进程中执行了“ls -l"命令
//不能同时执行两个execl函数，函数执行成功后就不往下执行了
		execl("/home/lin/document/oneday/myfork2","test","./myfork2",NULL);
	//路径要带上命令的名字
	}
	else
	{
		sleep(1);	
		printf("父进程：pid=%d,ppid=%d\n",getpid(),getppid());
	}
}
