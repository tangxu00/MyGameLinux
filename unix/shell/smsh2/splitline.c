/*************************************************************************
    > File Name: splitline.c
    > Author: dooon
    > Mail: tangxu314@gmail.com 
    > Created Time: 2017年07月25日 星期二 15时54分59秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"smsh.h"

/*
 * purpose: read next command line from fp
 * returns: dynamically allocated string holdong command line
 * errors:NULL at EOF
 * notes:allocate space in BUFFIZE chunks
 */
char *next_cmd(const char *prompt,FILE *fp)
{
  char *buf;
  int bufspace = 0;
  int pos = 0;
  int c;
  printf("%s",prompt);
  while((c = getc(fp)) != EOF){
    if(pos+1>=bufspace){
      if(bufspace == 0)
        buf = (char*)emalloc(BUFSIZ);
      else
        buf = (char*)erealloc(buf,bufspace + BUFSIZ);
      bufspace +=BUFSIZ;
    }
    if(c == '\n')
      break;
    buf[pos++]=c;
  }
  if(c == EOF && pos == 0)
    return NULL;
  buf[pos] ='\0';
  return buf;
}
/*
 * purpose: split a line into array of white-space separated tokens
 * returns: a NULL-terminated array of pointers to copies of the line
 *          tokens of NULL if line if no tokens on the line
 * action: traverse the array,locate strings,make copies
 * notes: strtok() could work,bur we may want to add qutoes later
 */
#define is_delim(x) ((x)==' '||(x)=='\t')

char **splitline(char *line)
{
  char *newstr(char *,int);
  char **args;
  int spots = 0;
  int bufspace = 0;
  int argnum = 0;
  char *cp = line;
  char * start;
  int len;
  if(line == NULL)
    return NULL;
  args = (char **)emalloc(BUFSIZ);
  bufspace = BUFSIZ;
  spots = BUFSIZ/sizeof(char *);
  while(*cp !='\0')
  {
    while(is_delim(*cp))
      cp++;
    if(*cp =='\0')
      break;
    if(argnum+1>=spots){
      args =(char**) erealloc(args,bufspace+BUFSIZ);
      bufspace +=(BUFSIZ/sizeof(char *));
    }
    start = cp;
    len = 1;
    while(*++cp !='\0' && !(is_delim(*cp)))
      len++;
    args[argnum++] = newstr(start,len);
  }
  args[argnum] = NULL;
  return args;
}

/*
 * purpose: constructor for string
 * returns: a string,never NULL
 */
char *newstr(char *s,int l)
{
  char *rv = (char*)emalloc(l+1);
  rv[l] = '\0';
  strncpy(rv,s,l);
  return rv;
}

/*
 * purpose: free the list returned bu splitline
 * returns: nothing
 * action:  free all strings in list and then free the list
 */
void freelist(char **list)
{
  char **cp =list;
  while(*cp)
    free(*cp++);
  free(list);
}

void *emalloc(size_t n)
{
  void *rv;
  if((rv = malloc(n)) == NULL)
    fatal("out of memory","",1);
  return rv;
}

void *erealloc(void *p,size_t n)
{
  void *rv;
  if((rv=realloc(p,n)) == NULL)
    fatal("realloc() failed","",1);
  return rv;
}
