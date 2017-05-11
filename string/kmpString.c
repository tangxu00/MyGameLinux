/*************************************************************************
    > File Name: kmpString.c
    > Author: dooon
    > Mail: tangxu314@gmail.com 
    > Created Time: 2017年05月07日 星期日 20时45分04秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 20
#define TURE 1
#define FULSE 0

typedef int ElemType;
typedef enum{
  ERROR=0,
  OK=1
}Status;

char *StringCreate()
{
  char *s,ch;
  int i=0;
  s=(char*)malloc(MAXSIZE);
  ch=getchar();
  while(ch !='#')
  {
    *(s+i)=ch;
    i++;
    ch=getchar();
  }
  *(s+i)='\0';
  return s;
}
int StringLength(char *S)
{
  int l=0;
  while(*S !='\0')
  {
    l++;
    S++;
  }
  return l;
}
char *StringCopy(char *D,char *S)
{
  char *c;
  c=D;
  while((*D++=*S++)!='\0');
  return c;
}
char *StringConnect(char *D,char *S)
{
  char *c;
  int l;
  c=D;
  l=StringLength(D);
  D=D+l;
  while((*D++=*S++) !='\0');
  return c;
}
void StringPrint(char *S)
{
  while(putchar(*S++));
  printf("\n");
}
void GetNext(char *T,int *next)
{
  int i,j;
  i=0;
  j=-1;
  next[0]=-1;
  while(i<StringLength(T)-1)
  {
    if(j==-1 || T[i]==T[j])
    {
      ++i;
      ++j;next[i]=j;
    }
    else
      j=next[j];
  }
}
int IndexKMP(char *S,char *T,int pos)
{
  int i=pos;
  int j=0;
  int next[255];
  GetNext(T,next);
  while(i<StringLength(S)&&j<StringLength(T))
  {
    if(j==-1||S[i]==T[j])
    {
      ++i;
      ++j;
    }
    else
    {
      j=next[j];
    }
  }
  if(j>=StringLength(T))
    return i-StringLength(T)+1;
  else 
    return -1;
}
int main(void)
{
  char *s;
  char *t;
  s=StringCreate();
  t=StringCreate();
  StringPrint(s);
  StringPrint(t);
  printf("s String Length:%d\n",StringLength(s));
  printf("t String Length:%d\n",StringLength(t));
  printf("%d\n",IndexKMP(s,t,0));
}
