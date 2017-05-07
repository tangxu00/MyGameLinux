/*************************************************************************
    > File Name: linkQueue.c
    > Author: dooon
    > Mail: tangxu314@gmail.com 
    > Created Time: 2017年04月30日 星期日 21时00分00秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef int QEleType;
typedef struct QNode
{
  QEleType data;
  struct QNode *next;
}QNode,*QueuePtr;
typedef struct
{
  QueuePtr front,rear;
}LinkQueue;
typedef enum
{
  OK=1,
  ERROR=0
}Status;
int OVERFLOW=0;
Status InitQueue(LinkQueue *Q)
{
  Q->front=Q->rear=(QueuePtr)malloc(sizeof(QNode));
  if(!Q->front)
    exit(OVERFLOW);
  Q->front->next=NULL;
  return OK;
}
int QueueLength(LinkQueue Q)
{
  int i=0;
  QueuePtr p=Q.front;
  while(Q.rear!=p)
  {
    i++;
    p=p->next;
  }
  return i;
}
Status EnQueue(LinkQueue *Q,QEleType e)
{
  QueuePtr s=(QueuePtr)malloc(sizeof(QNode));
  if(!s)
    exit(OVERFLOW);
  s->data=e;
  s->next=NULL;
  Q->rear->next=s;
  Q->rear=s;
  return OK;
}
Status DeQueue(LinkQueue *Q,QEleType *e)
{
  QueuePtr p;
  if(Q->front==Q->rear)
    return ERROR;
  p=Q->front->next;
  *e=p->data;
  Q->front->next=p->next;
  if(Q->rear==p)
    Q->rear=Q->front;
  free(p);
  return OK;
}
int main(void)
{
  LinkQueue q;
  InitQueue(&q);
  int i,e;
  for(i=0;i<10;i++)
    EnQueue(&q,i);
  printf("the length is:%d\n",QueueLength(q));
  printf("front is:%d\n",q.front->next->data);
  printf("rear is:%d\n",q.rear->data);
  DeQueue(&q,&e);
  printf("delate front:%d,now front is:%d\n",e,q.front->next->data);
}
