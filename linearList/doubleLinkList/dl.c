/*************************************************************************
    > File Name: dl.c
    > Author: dooon
    > Mail: tangxu314@gmail.com 
    > Created Time: 2017年04月18日 星期二 18时38分47秒
 ************************************************************************/

#include<stdio.h>
#include<malloc.h>

typedef struct DuLNode
{
  int i;
  struct DuLNode *next,*prior;
}DuLNode,*DuLinkList;
DuLNode *creat_list()
{
  int a[]={1,2,3,4,5};
  int j;
  DuLNode *head,*p1,*p2;
  p2=head=(DuLinkList)malloc(sizeof(DuLNode));
  head->next=head->prior=NULL;
  for(j=4;j>=0;j--)
  {
    p1=(DuLinkList)malloc(sizeof(DuLNode));
    p1->i=a[j];
    p1->prior=head;
    p1->next=head->next;
    head->next=p1;
  }
  return head;
}
DuLNode *insert_list(DuLNode *head,int i,int num)
{
  DuLNode *p,*q;
  int j;
  for(j=1,p=head->next;j<i&&p->next;j++)
  {
    q=p->next;
    q->prior=p;
    p=q;
  }
  q=(DuLinkList)malloc(sizeof(DuLNode));
  q->i=num;
  q->prior=p->prior;
  q->next=p;
  p->prior->next=q;
  p->prior=q;
  return head;
}
DuLNode *del_list(DuLNode *head,int i,int *e)
{
  DuLNode *p,*q;
  int j;
  for (j=1,p=head->next;j<i&&p->next;j++)
  {
    q=p->next;
    q->prior=p;
    p=q;
  }
  p->prior->next=p->next;
  p->next->prior=p->prior;
  *e=p->i;
  free(p);
  return head;
}
void printf_list(DuLNode *head)
{
  DuLNode *p;
  for(p=head->next;p;p=p->next)
  {
    printf("%d ",p->i);
  }
  printf("\n");
}
int main(void)
{
  struct DuLNode *head;
  int i,num,e;
  head=creat_list();
  printf_list(head);
  scanf("%d",&i);
  scanf("%d",&num);
  head=insert_list(head,i,num);
  printf_list(head);
  head=del_list(head,i,&e);
  printf_list(head);
  printf("%d\n",e);
}
