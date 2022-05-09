#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>

int main()
{
	int sock_fd;
	struct sockaddr_un send_address;
	sock_fd=socket(AF_INET,SOCK_DGRAM,0);
	if(sock_fd<0)
	{
		perror("socket error:");
	}
	
	send_address.sun_family=AF_INET;
	strcpy(send_address.sun_path,"server_socket");
	len=sizeof(aend_address);
	bind(sock_fd,
}
