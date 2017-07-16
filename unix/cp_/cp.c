/*************************************************************************
    > File Name: cp.c
    > Author: dooon
    > Mail: tangxu314@gmail.com 
    > Created Time: 2017年07月14日 星期五 09时50分33秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

#define BUFFERSIZE 4096
#define COPYMODE O_CREAT|O_RDWR

void oops(char*,char*);
int main(int ac,char *av[])
{
  int in_fd,out_fd,n_chars;
  char buf[BUFFERSIZE];
  if(ac!=3){
    fprintf(stderr,"usage: %s source destination\n",*av);
    exit(1);
  }
  if((in_fd=open(av[1],O_RDONLY))==-1)
    oops("Cannot open",av[1]);
  if((out_fd=open(av[2],COPYMODE))==-1)
    oops("Cannot creat",av[2]);
  while((n_chars=read(in_fd,buf,BUFFERSIZE))>0)
    if(write(out_fd,buf,n_chars)!=n_chars)
      oops("write error to ",av[2]);
  if(n_chars==-1)
    oops("Read error from",av[1]);
  if(close(in_fd)==-1|close(out_fd)==-1)
    oops("error close files","");
  return 0;
}

void oops(char *s1,char *s2)
{
  fprintf(stderr,"error: %s",s1);
  perror(s2);
  exit(1);
}

