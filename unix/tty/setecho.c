/*************************************************************************
    > File Name: setecho.c
    > Author: dooon
    > Mail: tangxu314@gmail.com 
    > Created Time: 2017年07月16日 星期日 10时20分31秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<termios.h>

#define oops(s,x) {perror(s);exit(x);}

int main(int ac,char *av[])
{
  struct termios info;
  if(ac==1)
    exit(0);
  if(tcgetattr(0,&info)==-1)
    oops("tcgetattr",1);
  if(av[1][0]=='y')
    info.c_lflag|=ECHO;
  else
    info.c_lflag&=~ECHO;
  if(tcsetattr(0,TCSANOW,&info)==-1)
    oops("tcsetattr",2);
}
