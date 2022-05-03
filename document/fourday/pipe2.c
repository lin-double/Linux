#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
int main()
{
	//定义一个管道
	int fd[2];
	//创建一个管道
	int ret=pipe(fd);
	if(ret<0)
	{
		perror("pipe error\n");
		return -1;
	}
	//创建一个子进程
	int pid=fork();
	if(pid<0)
	{
		perror("fork error\n");
		return -1;
	}
	//pid>0,父进程
	else if(pid>0)
	{
		//关闭读端
		close(fd[0]);
		//写入管道
		printf("父进程正在写入....\n");
		sleep(5);//应该在写入之前休眠
		write(fd[1],"ni hao shijie",strlen("ni hao shijie"));
	}
	else//子进程
	{
		//关闭写端
		close(fd[1]);
		//定义一个缓冲区，用来读管道
		char buf[64];
		//申请内存空间
		memset(buf,64,0);
		int n=read(fd[0],buf,64);
		printf("read successfully!\nn==%d\tbuf==%s\n",n,buf);
	}
	return 0;
}
