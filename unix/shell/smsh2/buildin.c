/*************************************************************************
    > File Name: bulidin.c
    > Author: dooon
    > Mail: tangxu314@gmail.com 
    > Created Time: 2017年07月28日 星期五 09时33分01秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include"smsh.h"
#include"varlib.h"

int assign(char*);
int okname(char*);

/*
 * purpose:run a buildin command
 * returns:1 if args[0] is bulidin,0 if not
 * details:test arg[0] against all known build-ins.call functions
 */
int buildin_command(char **args,int *resultp)
{
  int rv = 0;
  if(strcmp(args[0],"set") == 0){
    VLlist();
    *resultp = 0;
    rv = 1;
  }
  else if(strchr(args[0],'=') !=NULL){
    *resultp = assign(args[0]);
    if(*resultp != -1)
      rv = 1;
  }
  else if(strcmp(args[0],"export") == 0){
    if(args[1] != NULL && okname(args[1]))
      *resultp = VLexport(args[1]);
    else
      *resultp = 1;
    rv = 1;
  }
  return rv;
}

/*
 * purpose:execute name = val and ensure that name is legal
 * returns:-1 for illegal lval,or reult of VLstore
 * warning:modifies the string,but restores it to normal
 */
int assign(char *str)
{
  char *cp;
  int rv;
  cp = strchr(str,'=');
  *cp = '\0';
  rv = (okname(str) ? VLstore(str,cp+1) : -1);
  *cp = '=';
  return rv;
}
/*
 * purpose:determines if a string is a legal variable name
 * returns:0 for no,1 for yes
 */
int okname(char *str)
{
  char *cp;
  for(cp = str;*cp;cp++){
    if((isdigit(*cp)&&cp==str)||!(isalnum(*cp)||*cp=='_'))
      return 0;
  }
  return(cp != str);
}
