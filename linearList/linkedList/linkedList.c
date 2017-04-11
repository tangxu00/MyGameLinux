/*************************************************************************
    > File Name: linkedList.c
    > Author: dooon
    > Mail: tangxu314@gmail.com 
    > Created Time: 2017年04月10日 星期一 19时51分28秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef int ElemType;
#define TRUE 1
#define FALSE 0
typedef enum
{
  ERROR = 0,
  OK =1
}Status;

//×线性链表的存储结构×/
typedef struct LNode
{
  ElemType data;
  struct LNode *next;
}LNode,*LinkList;

//构造一个空的线性表L
void InitList(LinkList *L)
{
  *L=(LinkList)malloc(sizeof(struct LNode));
  if(!*L)
    exit(OVERFLOW);
  (*L)->next=NULL;
}
//销毁线性表L
void DestroyList(LinkList *L)
{
  LinkList q;
  while(*L)
  {
    q=(*L)->next;
    free(*L);
    *L=q;
  }
}
//将线性表置为空表
void ClearList(LinkList L)
{
  LinkList p,q;
  p=L->next;
  while(p)
  {
    q=p->next;
    free(p);
    p=q;
  }
  L->next=NULL;
}
//返回L中数据元素的个数
int ListLength(LinkList L)
{
  int i=0;
  LinkList p=L->next;
  while(p)
  {
    i++;
    p=p->next;
  }
  return i;
}
//返回第i个元素的值
Status GetElem(LinkList L,int i,ElemType *e)
{
  Status flag =OK;
  int j=1;
  LinkList p=L->next;
  while(p&&j<i)
  {
    p=p->next;
    j++;
  }
  if(!p||j>i)
    flag=ERROR;
  else
    *e=p->data;
  return flag;
}
//在链表L中第i个元素前插入e
Status ListInsert(LinkList L,int i,ElemType e)
{
  Status flag = OK;
  int j=0;
  LinkList p=L,s;
  while(p&&j<i-1)
  {
    p=p->next;
    j++;
  }
  if(!p||j<i-1)
    flag=ERROR;
  else
  {
    s=(LinkList)malloc(sizeof(struct LNode));
    s->data =e;
    s->next=p->next;
    p->next=s;
  }
return flag;
}
//删除第i个元素，并由e返回其值
Status LinkDelete(LinkList L,int i,ElemType *e)
{
  Status flag =OK;
  int j=0;
  LinkList p=L,q;
  while(p->next&&j<i-1)
    {
      p=p->next;
      j++;
    }
  if(!p->next||j>i-1)
    flag=ERROR;
  else
  {
    q=p->next;
    p->next=q->next;
    *e=q->data;
    free(q);
  }
  return flag;
}
//打印链表的data
void ListPrint(LinkList L)
{
  LinkList p=L->next;
  while(p)
  {
    printf("%d ",p->data);
    p=p->next;
  }
  printf("\n");
}
int main(void)
{
  LinkList L;
  int *a;
  InitList(&L);
  ListInsert(L,1,1);
  ListInsert(L,2,2);
  ListInsert(L,3,3); 
  ListInsert(L,4,4); 
  ListInsert(L,5,5); 
  ListInsert(L,6,6); 
  ListInsert(L,7,7);
  ListPrint(L);
  GetElem(L,2,a);
  printf("get the second:%d\n",*a);
  LinkDelete(L,2,a);
  printf("delete second: %d\n",*a);
  ListPrint(L);
  ClearList(L);
  ListPrint(L);
}
