#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	int fd[2];
	int ret=pipe(fd);
	if(ret<0)
	{
		perror("pipe error\n");
		return -1;
	}
	//创建子进程
	int pid =fork();
	if(pid<0)
	{
		perror("fork error\n");
		return -1;
	}
	else if(pid>0)//父进程
	{
		//关闭读端
		close(fd[0]);
		//重定向写端
		dup2(fd[1],STDOUT_FILENO);
		//拉起一个命令
		execlp("ps","ps","aux",NULL);
	}
	else
	{
		//关闭写端
		close(fd[1]);
		//重定向读端到输入
		dup2(fd[0],STDIN_FILENO);
		//execlp("grep","grep","bash",NULL);
		execlp("grep","grep","--color=auto","bash",NULL);
	}
	return 0;
}
