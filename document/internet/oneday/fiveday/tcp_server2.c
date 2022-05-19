#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<error.h>
int main(int argc,char* argv[])
{
	int lfd,cfd;
	int myport,listenlist;
	struct sockaddr_in server_addr,client_addr;
	unlink("server socket");
	socklen_t addrlen;
	if(argv[2])
	{
		myport=atoi(argv[2]);
	}
	else
	{
		myport=8888;
	}
	if(argv[3])
	{
		listenlist=atoi(argv[3]);
	}
	else
	{
		listenlist=5;
	}
	if((lfd=socket(AF_INET,SOCK_STREAM,0))==-1)
	{
		perror("socket failed");
		exit(EXIT_FAILURE);
	}
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(myport);
	if(argv[1])
	{
		server_addr.sin_addr.s_addr=inet_addr(argv[1]);
	}
	else
	{
		server_addr.sin_addr.s_addr=INADDR_ANY;
	}
	if(bind(lfd,(struct sockaddr*)&server_addr,sizeof(struct sockaddr))==-1)
	{
		perror("bind fail");
		exit(EXIT_FAILURE);
	}
	if(listen(lfd,listenlist)==-1)
	{
		perror("listen error");
		exit(EXIT_FAILURE);
	}
	if((cfd=accept(lfd,(struct sockaddr*)&client_addr,&addrlen))==-1)
	{
		perror("accept error");
		exit(EXIT_FAILURE);
	}

	
		char buf[1024];
		int n=0;
		memset(buf,0,strlen(buf));
		if((n=read(cfd,&buf,1024))<=0)
		{
			printf("read fail\n");

		}
		printf("server read success:\tbuf==[%s]\tn==[%d]\n",buf,n);
		sleep(5);
		bzero(buf,1024);
		fgets(buf,1024,stdin);
		write(cfd,buf,strlen(buf)-1);
		printf("write success:\tbuf==%s\t\n",buf);

	
	close(lfd);
	close(cfd);
	unlink("server socket");
	return 0;
}

















