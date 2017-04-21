/*************************************************************************
    > File Name: sqDoubleStack.c
    > Author: dooon
    > Mail: tangxu314@gmail.com 
    > Created Time: 2017年04月21日 星期五 20时42分04秒
 ************************************************************************/

#include<stdio.h>
#include<malloc.h>
#define SElemType int
#define MAXSIZE 100
typedef enum
{
  ERROR=0,
  OK=1
}Status;
typedef struct
{
  SElemType data[MAXSIZE];
  int top1;
  int top2;
}SqDouStack;
SqDouStack *creat()
{
  SqDouStack *head;
  if((head=(SqDouStack*)malloc(sizeof(SqDouStack)))==NULL)
    printf("error\n");
  head->top1=-1;
  head->top2=MAXSIZE;
  return head;
}
Status Push(SqDouStack *S,SElemType e,int stackNum)
{
  if(S->top1+1==S->top2)
    return ERROR;
  if(stackNum==1)
    S->data[++S->top1]=e;
  else if(stackNum==2)
    S->data[--S->top2]=e;
  return OK;
}
Status Pop(SqDouStack *S,SElemType *e,int stackNum)
{
  if(stackNum==1)
  {
    if(S->top1==-1)
      return ERROR;
    *e=S->data[S->top1--];
  }
  else if(stackNum==2)
  {
    if(S->top2==MAXSIZE)
      return ERROR;
    *e=S->data[S->top2++];
  }
  return OK;
}
int main(void)
{
  SqDouStack *s;
  int p;
  s=creat();
  Push(s,1,1);
  Push(s,2,1);
  Push(s,100,2);
  Push(s,99,2);
  printf("push data:1,2 in stack1,push data:100,99 in stack2\n");
  printf("top1 is:%d\n",s->data[s->top1]);
  printf("top2 is:%d\n",s->data[s->top2]);
  Pop(s,&p,1);
  printf("pop stack1 data is:%d\n",p);
  printf("now top1 is:%d\n",s->data[s->top1]);
  Pop(s,&p,2);
  printf("pop stack2 data is:%d\n",p);
  printf("now top2 is:%d\n",s->data[s->top2]);
}
