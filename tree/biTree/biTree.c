/*************************************************************************
    > File Name: biTree.c
    > Author: dooon
    > Mail: tangxu314@gmail.com 
    > Created Time: 2017年05月17日 星期三 20时05分14秒
 ************************************************************************/

#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define MAXSIZE 100

typedef int Status;
typedef char ElemType;
typedef struct BiTNode
{
  ElemType data;
  struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
int in=1;
typedef char String[24];
String str;
Status StrAssign(String T,char *chars)
{
  int i;
  if(strlen(chars)>MAXSIZE)
    return ERROR;
  else 
  {
    T[0]=strlen(chars);
    for(i=1;i<=T[0];i++)
      T[i]=*(chars+i-1);
    return OK;
  }
}
ElemType Nil=' ';
Status visit(ElemType e)
{
  printf("%c ",e);
  return OK;
}
//构造空二叉树T
Status InitBiTree(BiTree *T)
{
  *T=NULL;
  return OK;
}
void DestroyBiTree(BiTree *T)
{
  if(*T)
  {
    if((*T)->lchild)
      DestroyBiTree(&(*T)->lchild);
    if((*T)->rchild)
      DestroyBiTree(&(*T)->rchild);
    free(*T);
    *T=NULL;
  }
}
void CreatBiTree(BiTree *T)
{
  ElemType ch;
  ch=str[in++];
  if(ch=='#')
    *T=NULL;
  else
  {
    *T=(BiTree)malloc(sizeof(BiTNode));
    if(!*T)
      exit(0);
    (*T)->data=ch;
    CreatBiTree(&(*T)->lchild);
    CreatBiTree(&(*T)->rchild);
  }
}
int BiTreeDepth(BiTree T)
{
  int i,j;
  if(!T)
    return 0;
  if(T->lchild)
    i=BiTreeDepth(T->lchild);
  else
    i=0;
  if(T->rchild)
    j=BiTreeDepth(T->rchild);
  else
    j=0;
  return i>j?i+1:j+1;
}
Status BiTreeEmpty(BiTree T)
{
  if(T)
    return ERROR;
  else 
    return OK;
}
//返回二叉树的根
ElemType Root(BiTree T)
{
  if(BiTreeEmpty(T))
    return Nil;
  else 
    return T->data;
}
ElemType Value(BiTree P)
{
  return P->data;
}
void Assign(BiTree P,ElemType Value)
{
  P->data=Value;
}
//中序递归遍历T
void InorderTraverse(BiTree T)
{
  if(T==NULL)
    return;
  InorderTraverse(T->lchild);
  printf("%c",T->data);
  InorderTraverse(T->rchild);
}
//前序递归遍历T
void PreorderTraverse(BiTree T)
{
  if(T==NULL)
    return;
  printf("%c",T->data);
  PreorderTraverse(T->lchild);
  PreorderTraverse(T->rchild);
}
//后续递归遍历T
void PostorderTraverse(BiTree T)
{
  if(T==NULL)
    return;
  PostorderTraverse(T->lchild);
  PostorderTraverse(T->rchild);
  printf("%c",T->data);
}
int main()
{
  BiTree T;
  ElemType e1;
  InitBiTree(&T);
  StrAssign(str,"ABDH#K###E##CFI###G#J##");
    printf("%s\n",str);
  CreatBiTree(&T);
  printf("Empty? %d Depth:%d\n",BiTreeEmpty(T),BiTreeDepth(T));
  e1=Root(T);
  printf("Root of tree is:%c\n",e1);
  printf("Preorder,Inorder,Postorder:\n");
  PreorderTraverse(T);
  printf("\n");
  InorderTraverse(T);
  printf("\n");
  PostorderTraverse(T);
  printf("\n");
  DestroyBiTree(&T);
  printf("Tree empty when clear? %d\n",BiTreeEmpty(T));
  return 0;
}
