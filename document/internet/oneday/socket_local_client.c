#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<stdlib.h>
#include<sys/un.h>
int main()
{
	int client_fd;
	int len,result;
	int i,byte;
	char ch_send,ch_recv;
	struct sockaddr_un client_address;
	client_fd=socket(AF_UNIX,SOCK_STREAM,0);
	if(client_fd!=0)
	{
		perror("socket faild\n");
	}
	client_address.sun_family=AF_UNIX;
	strcpy(client_address.sun_path,"server_socket");
	len=sizeof(client_address);
	result=connect(client_fd,(struct sockaddr*)&client_address,len);
	if(result==-1)
	{
		printf("please click the server \n");
		perror("failed connect");
	}
	for(i=0,ch_send='A';i<5;i++,ch_send++)
	{
		if(byte=write(client_fd,&ch_send,1)==-1)
		{
			perror("write:");
		}
		if(byte=read(client_fd,&ch_recv,1)==-1)
		{
			perror("read:");
		}
		printf("receive server data is %c\n",ch_recv);
	}
	close(client_fd);
	return 0;
}
