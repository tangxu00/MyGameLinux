/*************************************************************************
    > File Name: smsh1.c
    > Author: dooon
    > Mail: tangxu314@gmail.com 
    > Created Time: 2017年07月25日 星期二 14时41分59秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include"smsh.h"

#define DEFL_PROMPT "> "
int main()
{
  char *cmdline,**arglist;
  const char *prompt;
  int result;
  int i;
  void setup();
  prompt = DEFL_PROMPT;
  setup();
  while((cmdline = next_cmd(prompt,stdin))!=NULL){
    if((arglist = splitline(cmdline)) !=NULL){
      for(i=0;arglist[i];i++)
        printf("%s ",arglist[i]);
      result = execute(arglist);
      freelist(arglist);
    }
    free(cmdline);
  }
  return 0;
}
/*
 *pourse: initalize shell
 *return: nothing
 */
void setup()
{
  signal(SIGINT,SIG_IGN);
  signal(SIGQUIT,SIG_IGN);
}
void fatal(char *s1,char *s2,int n)
{
  fprintf(stderr,"Error:%s,%s\n",s1,s2);
  exit(n);
}
