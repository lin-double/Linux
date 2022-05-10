#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<arpa/inet.h>
int main(int argc,char* argv[])
{
	int lfd;//监听文件描述符


	struct sockaddr_in client_address;
	socklen_t addrlen;
	char buf[1024];
	//unsigned int myport=atoi(argv[2]);
	unsigned int myport=8888;
	if((lfd=socket(AF_INET,SOCK_STREAM,0))==-1)
	{
		perror("socket fail:");
	}
	//绑定IP
	client_address.sin_family=AF_INET;
	client_address.sin_port=htons(myport);
	client_address.sin_addr.s_addr=INADDR_ANY;
	//server_address.sin_addr.s_addr=inet_addr(argv[1]);
	if(bind(lfd,(struct sockaddr*)&client_address,sizeof(struct sockaddr))==-1)
	{
		perror("bind error:");
	}

	//监听网络
	if(connect(lfd,(struct sockaddr*)&client_address,&addrlen)==-1)
	{
		perror("connect error:");
	}
	else printf("client connect successfully!\n");
	while(1)
	{
		memset(buf,0,strlen(buf));
		if(write(lfd,"hello world",1024)==-1)
		{
			perror("write fail:");
			break;
		}
		printf("write success\n");
		
		printf("buf==[%s]\n",buf);
		sleep(1);
	}
	return 0;
}
