/*************************************************************************
    > File Name: sqstack.c
    > Author: dooon
    > Mail: tangxu314@gmail.com 
    > Created Time: 2017年04月30日 星期日 20时26分15秒
 ************************************************************************/

#include<stdio.h>
#define MAXSIZE 100
typedef int QElemType;
typedef struct 
{
  QElemType data[MAXSIZE];
  int front;
  int rear;
}SqQueue;
typedef enum
{
  OK=1,
  ERROR=0
}Status;
Status InitQueue(SqQueue *Q)
{
  Q->front=0;
  Q->rear=0;
  return OK;
}
int QueueLength(SqQueue Q)
{
  return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}
Status EnQueue(SqQueue *Q,QElemType e)
{
  if((q->rear+1)%MAXSIZE==Q->front)
  {
    return ERROR;
  }
  Q->data[Q->rear]=e;
  Q->rear=(Q->rear+1)%MAXSIZE;//rear指针后移一
  return OK;
}
Status DeQueue(SqQueue *Q,QElemType *e)
{
  if(Q->front==Q->rear)
    return ERROR;
  *e=Q->data[Q->front];
  Q->front=(Q->front+1)%MAXSIZE;//front指针向前移一位置
  return OK;
}

