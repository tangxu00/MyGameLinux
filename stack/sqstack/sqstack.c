/*************************************************************************
    > File Name: sqstack.c
    > Author: dooon
    > Mail: tangxu314@gmail.com 
    > Created Time: 2017年04月19日 星期三 20时33分41秒
 ************************************************************************/

#include<stdio.h>
#include<malloc.h>
typedef int SElemType;
#define MAXSIZE 100
typedef struct{
  SElemType data[MAXSIZE];
  int top;
}sqstack;

#define TRUE 1
#define FALSE 2
typedef enum{
  ERROR=0,
  OK=1
}Status;
Status Init(sqstack *S)
{
  S->top=-1;
  return OK;
}
Status Push(sqstack *S,SElemType e)
{
  if(S->top==MAXSIZE-1)
    return ERROR;
    S->top++;
    S->data[S->top]=e;
    return OK;
}
Status Pop(sqstack *S,SElemType *e)
{ 
  if(S->top==-1)
    return ERROR;
  *e=S->data[S->top];
  S->top--;
  return OK;
}
Status GetTop(sqstack *S,SElemType *e)
{
  if(S->top==-1)
    return ERROR;
  *e=S->data[S->top];
  return OK;
}
int main(void)
{
  int p;
  int q;
  sqstack s;
  Init(&s);
  Push(&s,1);
  Push(&s,2);
  GetTop(&s,&p);
  printf("%d\n",p);
  Pop(&s,&q);
  printf("%d\n",q);
  GetTop(&s,&p);
  printf("%d\n",p);
}
