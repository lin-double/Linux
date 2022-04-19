/* Example show usage of setbuf & setvbuf*/
#include<stdio.h>
#include<error.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char ** argv)
{
	int i;
	FILE* fp;
	char msg1[]="hello,world\n";
	char msg2[]="hello\nworld";
	char buf[128];
	//setbuf:no buf
	if((fp=fopen("no_buf1.txt","w"))==NULL)
	{
		printf("file open failture!");
		return (-1);                                                      
	}
	setbuf(fp,NULL);
	memset(buf,'\0',128);
	fwrite(msg1,7,1,fp);
	printf("test setbuf(no buf) !check no_buf1.txt\n");
	printf("now buf data is :buf=%s\n",buf);
	printf("press enter to continue!\n");
	getchar();
	//调用fclose函数刷新了缓冲区
	fclose(fp);
	//setvbuf: no buf
	if((fp=fopen("no_buf2.txt","w"))==NULL)
	{
		printf("file open failture!");
		return (-1);
	}
	//setvbuf:function has four parameter :*fp,buf,isbuf,sizeof(buf) 
	setvbuf(fp,NULL,_IOLBF,0);
	memset(buf,'\0',128);
	fwrite(msg1,100,1,fp);
	printf("test setvbuf(no buf) !check no_buf2.txt\n");
	printf("now buf data is :buf=%s\n",buf);
	printf("press enter to continue!\n");
	getchar();
	fclose(fp);
	//setvbuf: line buf
	if((fp=fopen("line_buf.txt","w"))==NULL)
	{
		printf("file open failture!");
		return(-1);
	}
	setvbuf(fp,buf,_IOLBF,sizeof(buf));
	memset(buf,'\0',128);
	//fwrite(msg2,sizeof(msg2),1,fp);buf中存了world
	fwrite(msg2,9,1,fp);//buf=worlo;为什么呢
	printf("test setvbuf(lin buf)!check line_buf.txt\n");
	printf("now buf data is :buf=%s\n",buf);
	printf("press enter to continue!\n");
	getchar();
	fclose(fp);
	//setvbuf: full buf
	if((fp=fopen("full_buf.txt","w"))==NULL)
	{
		printf("file open failture!\n");
		return 0;
	}
	setvbuf(fp,buf,_IOFBF,sizeof(buf));
	memset(buf,'\0',128);
	fwrite(msg2,9,1,fp);
	printf("test setvbuf(full buf)!check full_buf.txt\n");
	printf("now buf data is :buf=%s\n",buf);
	printf("press enter to continue!\n");
	getchar();
	fclose(fp);
	return 0;
}	
