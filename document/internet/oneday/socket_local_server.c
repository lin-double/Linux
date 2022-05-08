#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/un.h>
int main()
{
	int server_sockfd,client_sockfd;
	struct sockaddr_un server_address;
	struct sockaddr_un client_address;
	int server_len,client_len;
	int i,byte;
	char ch_send,ch_recv;
	server_sockfd=socket(AF_UNIX,SOCK_STREAM,0);
	if(server_sockfd!=0)
	{
		printf("failed create socket!\n");
	}

	server_address.sun_family=AF_UNIX;
	strcpy(server_address.sun_path,"server_socket");
	server_len=sizeof(server_address);
		
	bind(server_sockfd,(struct sockaddr*)&server_address,server_len);
	
	listen(server_sockfd,5);
	
	printf("server waiting for client connect\n");

	client_len=sizeof(client_address);
	client_sockfd=accept(server_sockfd,(struct sockaddr*)&client_address,(socklen_t*)&client_len);
	printf("the server wait from client data\n");
	for(i=0,ch_send='1';i<5;i++,ch_send++)
	{
		if(byte=read(client_sockfd,&ch_recv,1)==-1)
		{
			perror("read:");
		}
	
		printf("the charecter recevier from client is %c\n",ch_recv);
		sleep(1);
		
		if(byte=write(client_sockfd,&ch_send,1)==-1)
		{
			perror("send:");
		}
	}
	close(client_sockfd);
	return 0; 
}








