/*************************************************************************
    > File Name: psh1.c
    > Author: dooon
    > Mail: tangxu314@gmail.com 
    > Created Time: 2017年07月23日 星期日 15时34分53秒
 ************************************************************************/

#include<stdio.h>
#include<signal.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

#define MAXSIZE 20
#define ARGLEN 100

int execute(char *arglist[]);
int main()
{
  char *arglist[MAXSIZE+1];
  int numargs;
  char argbuf[ARGLEN];
  char *makestring();
  numargs = 0;
  while(numargs<MAXSIZE)
  {
    printf("Arg[%d]?",numargs);
    if(fgets(argbuf,ARGLEN,stdin)&&*argbuf != '\n')
      arglist[numargs++] = makestring(argbuf);
    else
    {
      if(numargs>0){
        arglist[numargs]=NULL;
        execute(arglist);
        numargs=0;
      }
    }
  }
  return 0;
}
int execute(char *arglist[])
{
  execvp(arglist[0],arglist);
  perror("exexvp failed!");
  exit(1);
}
char *makestring(char *buf)
{
  char *cp;//*malloc();
  buf[strlen(buf)-1]='\0';
  cp = (char*)malloc(strlen(buf)+1);
  if(cp==NULL){
    fprintf(stderr,"no memory\n");
    exit(1);
  }
  strcpy(cp,buf);
  return cp;
}
