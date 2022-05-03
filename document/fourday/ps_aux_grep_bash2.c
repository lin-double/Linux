#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	int fd[2];
	//创建管道
	int ret=pipe(fd);
	if(ret<0)
	{
		perror("pipe error\n");
		return -1;
	}
	//创建fork函数
	int pid=fork();
	if(pid<0)
	{
		perror("fork error\n");
		return -1;
	}
	else if(pid>0)//父进程
	{
		//写操作，关闭读端
		close(fd[0]);
		//dup2文件重定向
		dup2(fd[1],STDOUT_FILENO);
		//使用execl函数进行拉起一个命令
		//execlp("ps","ps","aux",NULL);
		execlp("ls","ls","-l",NULL);
		printf("父进程创建成功...\n");
	}
	else//子进程
	{
		//子进程只作为读端，关闭写端
		close(fd[1]);
		//使用dup2函数进行重定向
		dup2(fd[0],STDIN_FILENO);
		//execlp("grep","grep","bash",NULL);
		//execlp("grep","grep","--color=auto","bash",NULL);
		execlp("grep","grep","--color=auto","pipe",NULL);
	}
	return 0;
}	

