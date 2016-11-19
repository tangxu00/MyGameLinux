/*************************************************************************
    > File Name: open_file.c
    > Author: dooon
    > Mail: tangxu314@163.com 
    > Created Time: 2016年11月07日 星期一 11时15分56秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(int argc,char *argv[])
{
	int fd;
	if(argc<2)
	{
		puts("please input the file pathname");
	exit(1);
	}
	if((fd=open(argv[1],O_CREAT|O_RDWR,0755))<0)
	{
		perror("open file failure!/n");
		exit(1);
	}
	else 
		printf("open file %d sucess!",fd);
	close(fd);
	exit(0);


}

