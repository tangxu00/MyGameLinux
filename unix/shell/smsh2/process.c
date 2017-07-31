/*************************************************************************
    > File Name: process.c
    > Author: dooon
    > Mail: tangxu314@gmail.com 
    > Created Time: 2017年07月27日 星期四 10时40分06秒
 ************************************************************************/

#include<stdio.h>
#include"smsh.h"

int is_control_command(char *);
int do_control_command(char **);
int ok_to_execute();
int buildin_command(char **,int *);
/*
 * purpose: process user command
 * returns: result of processing command
 * details:if a build-in then call appropriate fuction,if not execute
 * errors: arise from subroutines,handled there
 */
int process(char **args)
{
  int rv = 0;
  if(args[0] == NULL)
    rv = 0;
  else if(is_control_command(args[0]))
    rv = do_control_command(args);
  else if(ok_to_execute())
    if(!buildin_command(args,&rv))
      rv = execute(args);
  return rv;
}
