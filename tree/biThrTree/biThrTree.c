/*************************************************************************
    > File Name: biThrTree.c
    > Author: dooon
    > Mail: tangxu314@gmail.com 
    > Created Time: 2017年05月23日 星期二 19时55分26秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ERROR 0
#define OK 1

typedef int Status;
typedef char TElemType;
typedef enum{Link,Thread}PoniterTag;

typedef struct BiThrNode
{
  TElemType data;
  struct BiThrNode *lchild,*rchild;
  PoniterTag LTag;
  PoniterTag RTag;
}BiThrNode,*BiThrTree;

TElemType Nil='#';

Status visit(TElemType e)
{
  printf("%c",e);
  return OK;
}
//前序输入构造二叉树
Status CreatBiThrTree(BiThrTree *T)
{
  TElemType h;
  scanf("%c",&h);
  if(h==Nil)
    *T=NULL;
  else
  {
    *T=(BiThrTree)malloc(sizeof(BiThrNode));
    if(!*T)
      exit(0);
    (*T)->data=h;
    CreatBiThrTree(&(*T)->lchild);
    if((*T)->lchild)
      (*T)->LTag=Link;
    CreatBiThrTree(&(*T)->rchild);
    if((*T)->rchild)
      (*T)->RTag=Link;
  }
  return OK;
}
BiThrTree pre;
void InThreading(BiThrTree p)
{
  if(p)
  {
    InThreading(p->lchild);
    if(!p->lchild)
    {
      p->LTag=Thread;
      p->lchild=pre;
    }
    if(!pre->rchild)
    {
      pre->RTag=Thread;
      pre->rchild=p;
    }
    pre=p;
    InThreading(p->rchild);
  }
}
Status InOrderThreading(BiThrTree *Thrt,BiThrTree T)
{
  *Thrt=(BiThrTree)malloc(sizeof(BiThrNode));
  if(!*Thrt)
    exit(0);
  else
  {
    (*Thrt)->LTag=Link;
    (*Thrt)->RTag=Thread;//右指针回指
    (*Thrt)->rchild=*Thrt;
    if(!T)
      (*Thrt)->lchild=*Thrt;
    else
    {
      (*Thrt)->lchild=T;
      pre=(*Thrt);
      InThreading(T);
      pre->rchild=*Thrt;//最后一个节点线索化
      (*Thrt)->rchild=pre;
    }
  }
  return OK;
}
Status InOrderTraverse_Thr(BiThrTree T)
{
  BiThrTree p;
  p=T->lchild;
  while(p!=T)
  {
    while(p->LTag==Link)
      p=p->lchild;
    if(!visit(p->data))
      return ERROR;
    while(p->RTag==Thread&&p->rchild!=T)
    {
      p=p->rchild;
      visit(p->data);
    }
    p=p->rchild;
  }
  return OK;
}
int main()
{
  BiThrTree H,T;
  printf("请按前序输入二叉树(如:'ABDH##I##EJ###CF##G##')\n");
  CreatBiThrTree(&T);
  InOrderThreading(&H,T);
  printf("中序遍历(输出)二叉线索树:\n");
  InOrderTraverse_Thr(H);
  return 0;
}
