/*************************************************************************
    > File Name: varlib.c
    > Author: dooon
    > Mail: tangxu314@gmail.com 
    > Interface: VLstore(name,value) return 1 for ok,0 for no
    >            VLlookup(name) return striong or NULL if not there
    >            VList() prints out current table
    >            VLexport(name) adds name to list of env vars
    >            VLtable2environ() copy from table to environ
    >            VLenviron2table() copy form environ to table
    > Created Time: 2017年07月29日 星期六 15时14分35秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"varlib.h"

#define MAXVARS 200

struct var{
  char *str;//name=var string
  int global;
};
static struct var tab[MAXVARS];

static char *new_string(char *,char *);
static struct var *find_item(char *,int);

/*
 * purpose: traverse list,if found,replace it,else add at the end
 * returns: 1 if trouble,0 if ok
 */
int VLstore(char *name,char *val)
{
  struct var *itemp;
  char *s;
  int rv = 1;
  if((itemp = find_item(name,1)) != NULL && (s = new_string(name,val)) != NULL)
  {
    if(itemp->str)
      free(itemp->str);
    itemp->str = s;
    rv = 0;
  }
  return rv;
}

/*
 * returns new string of form name=value or NULL on error
 */
char *new_string(char *name,char *val)
{
  char *retval;
  retval = (char *)malloc(strlen(name) + strlen(val) +2);
  if(retval !=NULL)
    sprintf(retval,"%s=%s",name,val);
  return retval;
}

/*
 * returns value of var or empty string if not there
 */
char *VLlookup(char *name)
{
  struct var *itemp;
  if((itemp = find_item(name,0)) != NULL)
    return itemp->str + 1 + strlen(name);
  return "";
}

/*marks a var for export,adds it if not there
 * returns 1 for no,0 for ok
 */
int VLexport(char *name)
{
  struct var *itemp;
  int rv = 1;
  if((itemp = find_item(name,0)) != NULL){
    itemp->global = 1;
    rv = 0;
  }
  else if(VLstore(name,"") == 1)
    rv = VLexport(name);
  return rv;
}

/*searches table for an item
 * returns ptr to struct or NULL if not found 
 * OR if(first_blank) then pte to first blank one
 */
static struct var *find_item(char *name,int first_blank)
{
  int i;
  int len = strlen(name);
  char *s;
  for(i = 0;i<MAXVARS && tab[i].str != NULL;i++)
  {
    s = tab[i].str;
    if(strncmp(s,name,len) == 0 && s[len] == '=')
      return &tab[i];
  }
  if(i<MAXVARS && first_blank)
    return &tab[i];
  return NULL;
}

/*
 * preforms the shell set command
 * Lists the contents of the variable table,marking each 
 * exported variable with the symbol '*'
 */
void VLlist()
{
  int i;
  for(i = 0;i<MAXVARS && tab[i].str != NULL;i++)
  {
    if(tab[i].global)
      printf("* %s\n",tab[i].str);
    else
      printf(" %s\n",tab[i].str);
  }
}
/*
 * initalize the varble table by loading array of strings
 * return 1 for ok,0 for not ok
 */
int VLenviron2table(char *env[])
{
  int i;
  char *newstring;
  for(i=0;env[i] != NULL;i++)
  {
    if(i == MAXVARS)
      return 0;
    newstring = (char *)malloc(1+strlen(env[i]));
    if(newstring == NULL)
      return 0;
    strcpy(newstring,env[i]);
    tab[i].str = newstring;
    tab[i].global = 1;
  }
  while(i<MAXVARS){
    tab[i].str = NULL;
    tab[i++].global = 0;
  }
  return 1;
}
/*
 * build an array of pointers suitable for making a new environment
 * note,you need to free() this when done to avoid memory leaks
 */
char ** VLtable2environ()
{
  int i,       //index
      j,      //another index
      n = 0; //counter
  char **envtab;
  for(i=0;i<MAXVARS && tab[i].str != NULL;i++)
    if(tab[i].global == 1)
      n++;
  envtab = (char **)malloc((n+1) * sizeof(char *));
  if(envtab == NULL)
    return NULL;
  for(i=0,j=0;i<MAXVARS && tab[i].str != NULL;i++)
    if(tab[i].global == 1)
      envtab[j++] = tab[i].str;
  envtab[j] = NULL;
  return envtab;
}
