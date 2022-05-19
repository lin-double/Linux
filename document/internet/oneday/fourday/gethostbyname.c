#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<netdb.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
int main(int argc,char* argv[])
{
	int i,j;
	struct hostent* hp;
	for(i=1;i<argc;i++)
	{
		hp=gethostbyname(argv[i]);
		printf("host\t%s:\n",argv[i]);
		printf("Officially name: \t%s\n",hp->h_name);
		fputs("Alias:\t",stdout);
		for(j=0;hp->h_aliases[j];++j)
		{
			if(j)
			{
				fputs("\t,",stdout);
				fputs(hp->h_aliases[j],stdout);
			}
		}
		fputs("\n",stdout);
		printf("Type:\t\t%s\n",hp->h_addrtype==AF_INET?"AF_INET":"AF_INET6");
		if(hp->h_addrtype==AF_INET)
		{
			for(j=0;hp->h_addr_list[j];j++)
			{
				printf("address:\t%s\n",inet_ntoa(*(struct in_addr*)hp->h_addr_list[j]));			
			}
		}
		fputc('\n',stdout);	
	}
	return 0;
}
