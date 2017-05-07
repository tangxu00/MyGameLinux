/*************************************************************************
    > File Name: linkStack.c
    > Author: dooon
    > Mail: tangxu314@gmail.com 
    > Created Time: 2017年04月22日 星期六 19时58分06秒
 ************************************************************************/

#include<stdio.h>
#include<malloc.h>

#define SElemType int

typedef enum
{
  ERROR=0,
  OK=1
}Status;
typedef struct StackNode
{
  SElemType data;
  struct StackNode *next;
}StackNode,*LinkstackPtr;
typedef struct LinkStack
{
  LinkstackPtr top;
  int count;
}LinkStack;
Status visit(SElemType c)
{
  printf("%d ",c);
  return OK;
}
Status InitStack(LinkStack *S)
{
  S->top=(LinkstackPtr)malloc(sizeof(StackNode));
  if(!S->top)
    return ERROR;
  S->top=NULL;
  S->count=0;
  return OK;
}
Status GetTopElem(LinkStack S,SElemType *e)
{
  if(S.top==NULL)
    return ERROR;
  else
    *e=S.top->data;
  return OK;
}
Status Push(LinkStack *S,SElemType e)
{
  LinkstackPtr s=(LinkstackPtr)malloc(sizeof(StackNode));
  s->data=e;
  s->next=S->top;
  S->top=s;
  S->count++;
  return OK;
}
Status Pop(LinkStack *S,SElemType *e)
{
  LinkstackPtr p;
  if(S->count==0)
    return ERROR;
  *e=S->top->data;
  p=S->top;
  S->top=S->top->next;
  free(p);
  S->count--;
  return OK;
}
Status StackTraverse(LinkStack S)
{
  LinkstackPtr p;
  p=S.top;
  while(p)
  {
    visit(p->data);
    p=p->next;
  }
  printf("\n");
  return OK;
}
Status ClearStack(LinkStack *S)
{
  LinkstackPtr p,q;
  p=S->top;
  while(p)
  {
    q=p;
    p=p->next;
    free(q);
  }
  S->count=0;
  return OK;
}
int main(void)
{
  int j;
  LinkStack s;
  int e;
  InitStack(&s);
  for(j=1;j<=10;j++)
    Push(&s,j);
  printf("栈元素值依次为：\n");
  StackTraverse(s);
  Pop(&s,&e);
  printf("pop elem:%d\n",e);
  GetTopElem(s,&e);
  printf("top elem:%d\n",e);
  StackTraverse(s);
} 
