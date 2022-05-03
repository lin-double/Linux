#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
int main()
{
	int fd[2];
	int ret=pipe(fd);
	if(ret<0)
	{
		perror("pipe failed\n");
		return -1;
	}
	int pid=fork();
	if(pid<0)
	{
		perror("fork failed\n");
		return -1;
	}
	else if(pid==0)
	{
		//子进程读
		close(fd[1]);//关闭写端
		char buf[1024];//缓冲区设置1024个字节
		memset(buf,1024,0);
		int n=read(fd[0],buf,sizeof(buf));
		printf("read successfully!\nn==%d\tbuf==%s\n",n,buf);
	}
	else
	{
		printf("父进程正在写入......\n");
		sleep(10);//子进程会一直等待父进程写入
		close(fd[0]);//关闭读端
		//write(fd[1],"hello world",strlen("hello world"));
		write(fd[1],"hello world",13);
	}
	return 0;

}
