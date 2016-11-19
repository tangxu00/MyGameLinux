/*************************************************************************
    > File Name: cp_file.c
    > Author: dooon
    > Mail: tangxu314@163.com 
    > Created Time: 2016年11月07日 星期一 15时24分32秒
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<fcntl.h>
#include<stdlib.h>
#define BUFFER_SIZE 1024
int main(int argc,char *argv[])
{
	int from_fd,to_fd;
	int bytes_read,bytes_write;
	char buffer[BUFFER_SIZE];
	char *ptr;

	if(argc!=3)
	{
		fprintf(stderr,"Usage: %s fromfile tofile/n/a",argv[0]);
		exit(1);
	}
	//打开源文件
	if((from_fd=open(argv[1],O_RDONLY))==-1)
	{
		fprintf(stderr,"open %s Error:%s\n",argv[1],strerror(errno));
		exit(1);
	}
	//创建目标文件
	if((to_fd=open(argv[2],O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR))==-1)
	{
		fprintf(stderr,"Usage:%s Error:%s\n",argv[2],strerror(errno));
		exit(1);
	}
	//classical copy code
	while(bytes_read=read(from_fd,buffer,BUFFER_SIZE))
	{
		//error happen
		if((bytes_read==-1)&&(errno!=EINTR)) 
			break;
		else if(bytes_read>0)
		{
			ptr=buffer;
			while(bytes_write=write(to_fd,ptr,bytes_read))
			{
				//error happen
				if((bytes_write==-1)&&(errno!=EINTR))
					break;
				//finish all bytes of read
				else if(bytes_write==bytes_read)
					break;
				//contuine to write
				else if(bytes_write>0)
				{
					ptr+=bytes_write;
					bytes_read-=bytes_write;
				}
			}
			//error happen
			if(bytes_write==-1)
				break;
					
		}
	}
	close(from_fd);
	close(to_fd);
	exit(0);
}
