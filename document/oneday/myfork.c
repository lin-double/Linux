#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
//fork()
int main(int argc,char* argv[])
{	
	int a=10,b=20;
	int c=a+b;		
	pid_t pid=fork();//父进程中,fork()返回子进程的pid，子进程中返回0，以区别父进程
	if(pid<0)
	{
		printf("fork failed\n");	
	}
	else if(pid==0)
	{
		//pid等于0,是子进程执行的逻辑
		printf("子进程运行:\npid=%d , ppid=%d\n",getpid(),getppid());
		printf("子进程中打印函数：\n");
		printf("子进程中:\na=%d\nb=%d\nc=a+b=%d\n",a,b,c);
	}
	else
	{
		//父进程中运行的程序，此时pid返回的是子进程的，是父进程执行的逻辑，父子进程是独立执行的
		printf("父进程运行:\npid=%d , ppid=%d\n",getpid(),getppid());
		printf("父进程中打印函数：\n");
		printf("父进程中:\na=%d\nb=%d\nc=a+b=%d\n",a,b,c);}
	return 0;
}
