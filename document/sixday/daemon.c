#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<time.h>
#include<string.h>
#include<sys/time.h>
void mysighandler(int signo)
{
	int fd =open("mydaemon.txt",O_RDWR|O_CREAT|O_APPEND,0777);
	if(fd<0)
	{
		return ;
	}
	time_t t;
	time(&t);
	char *p=ctime(&t);
	//write(fd,p,sizeof(p));//只打印日期，不打印时间
	write(fd,p,strlen(p));
	//strlen是计算字符串的长度，是一个库函数，需要运行才知道，
	//sizeof是计算类型占内存的空间大小，编译的时候就得到
	close(fd);
	return ;	
}
int main()
{
	//创建守护进程,创建子进程，退出父进程
	pid_t pid=fork();
	if(pid<0||pid>0)
	{
		exit(1);
	}
	//子进程创建会话
	setsid();
	//更改文件路径
	chdir("/home/lin/document/sixday");	
//	printf("child\n");
	//重设文件掩码
	umask(0000);
	//关闭文件描述符
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	//执行核心工作	
	//注册信号处理函数
	
	//sa_handler:void (*sa_handler)(int)---信号处理函数
	//sa_handler：指定信号捕捉后的处理函数名(即注册函数)。
	//			也可赋值为SIG_IGN表忽略 或 SIG_DFL表执行默认动作
	/*sa_mask: 用来指定在信号处理函数执行期间需要被屏蔽的信号，特别是当某个信号被处理时，
				它自身会被自动放入进程的信号掩码，因此在信号处理函数执行期间这个信号不会再度发生。
				注意：仅在处理函数被调用期间屏蔽生效，是临时性设置。
				信号处理函数执行期间需要阻塞的信号
	sa_flags：通常设置为0，使用默认属性。
	sa_restorer：已不再使用	*/


	struct sigaction act;
	act.sa_handler=mysighandler;	
	act.sa_flags=0;
	
	//将每个信号集清0
	sigemptyset(&act.sa_mask);
	//第一个参数：捕捉的信号；
	//第二个参数：传入参数，新的处理方式；
	//第三个参数：传出参数，旧的处理方式，一般为NULL
	sigaction(SIGALRM,&act,NULL);

	struct itimerval tm;
	//设定以后每几秒执行函数
	tm.it_interval.tv_sec=2;//秒
	tm.it_interval.tv_usec=0;//毫秒

	//设定第一次执行函数所延迟的秒数
	tm.it_value.tv_sec=3;
	tm.it_value.tv_usec=0;
	setitimer(ITIMER_REAL,&tm,NULL);
	while(1)
	{
		sleep(1);
	}
	return 0;
}





