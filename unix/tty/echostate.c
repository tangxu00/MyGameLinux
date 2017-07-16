/*************************************************************************
    > File Name: echostate.c
    > Author: dooon
    > Mail: tangxu314@gmail.com 
    > Created Time: 2017年07月16日 星期日 10时37分35秒
 ************************************************************************/

#include<stdio.h>
#include<termios.h>

int main(void)
{
  struct termios info;
  int rv;
  rv = tcgetattr(0,&info);
  if(rv==-1)
    perror("tcgetattr");
  printf("%x\n",ECHO);
  if(info.c_lflag & ECHO)
    printf("echo is on,since its bit is 1\n");
  else
    printf("echo is off,since its bit is 0\n");
}
