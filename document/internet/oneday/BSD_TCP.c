#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<socket.h>
int main()
{
	//创建socket对象
	int server_sockfd,client_sockfd;
	struct sock	

	server_sockfd=socket(AF_UNIX,SOCK_STREAM,0);
	//绑定ip地址
	
	if(socket!=0)
	{
		printf("failed create socket\n");
	}
	return 0;
}
