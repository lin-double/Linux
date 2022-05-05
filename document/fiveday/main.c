#include<stdio.h>
#include<stdlib.h>
#include<sum.h>

int main(int argc,char* argv[])
{
	printf("这是一个打印测试程序\n");
	int a=10;
	int b=20;
	printf("a==%d\nb==%d\n",a,b);
	printf("sum==%d\n",sum(&a,&b));
	return 0;
}
