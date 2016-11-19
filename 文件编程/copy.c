/*************************************************************************
    > File Name: copy.c
    > Author: dooon
    > Mail: tangxu314@163.com 
    > Created Time: 2016年10月31日 星期一 21时28分08秒
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#define PERMS 0666
#define DUMMY 0
#define BUFFERSIZE 1024
main(int argc,char *argv[])
{
	int source_fd,target_fd,num;
	char iobuffer[BUFFERSIZE];
	if(argc!=3)
	{
		printf("Usage:copy sourcefile targetfile\n");
		return 1;
	}
	if((source_fd=open(*(argv+1),O_RDONLY,DUMMY))==-1)

	{
		printf("sourcefile open error\n");
		return 2;
	}
	if((target_fd=open(*(argv+2),O_WRONLY|O_CREAT,PERMS))==-1)
	{
		printf("targetfile open error\n");
		return 3;
	}
	while((num=read(source_fd,iobuffer,BUFFERSIZE))>0)
		if(write(target_fd,iobuffer,num)!=num)
		{
			printf("targetfile write error\n");
			return 4;
		}
	close(source_fd);
	close(target_fd);
	return 0;

}

