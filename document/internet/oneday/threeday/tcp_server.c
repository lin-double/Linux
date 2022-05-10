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
	int cfd;//通信文件描述符
	struct sockaddr_in server_address;
	struct sockaddr_in client_address;
	socklen_t addrlen;
	char buf[1024];
	unsigned int myport=atoi(argv[2]);
	//unsigned int myport=8888;
	if((lfd=socket(AF_INET,SOCK_STREAM,0))==-1)
	{
		perror("socket fail:");
	}
	//绑定IP
	server_address.sin_family=AF_INET;
	server_address.sin_port=htons(myport);
//	server_address.sin_addr.s_addr=INADDR_ANY;
	server_address.sin_addr.s_addr=inet_addr(argv[1]);
	if(bind(lfd,(struct sockaddr*)&server_address,sizeof(struct sockaddr))==-1)
	{
		perror("bind error:");
	}

	//监听网络
	if(listen(lfd,5)==-1)
	{
		perror("listen error:");
	}
	
	//等待通信
	//cfd=accept(lfd,(struct sockaddr*)&client_address,&addrlen);
	
	while(1)
	{
		//等待通信
		cfd=accept(lfd,(struct sockaddr*)&client_address,&addrlen);
		if(cfd==-1)
		{
			perror("connect fail");
		}	
		else printf("client connect successfully!\n");
		memset(buf,0,strlen(buf));
		if(read(cfd,buf,1024)<=0)
		{
			perror("read fail:");
			break;
		}
		printf("read success\n");
		
		printf("buf==[%s]\n",buf);
		sleep(1);
	}
	close(lfd);
	close(cfd);
	return 0;
}
