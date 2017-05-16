/*************************************************************************
    > File Name: parentChild.c
    > Author: dooon
    > Mail: tangxu314@gmail.com 
    > Created Time: 2017年05月12日 星期五 19时43分07秒
 ************************************************************************/

#include<stdio.h>

typedef char TElemType;
typedef enum
{
  ERROR=0,
  OK=1
}Status;
typedef struct CTNode
{
  int child;
  struct CTNode *next;
}*ChildPtr;
typedef struct
{
  TElemType data;
  int parent;
  ChildPtr fistchild;
}CTBox;
typedef struct
{
  CTBox *nodes;
  int r,n;//位置和节点数
}CTree;
void TreeInit(CTree *tree)
{
  tree->nodes=NULL;
  tree->r=0;
  tree->n=0;
}
Status TreeCreat(CTree *tree)
{
  TreeInit(tree);
  for(i=1;i<10;i++)
  {
  }
}
int CTreeDepth(CTree T)
{
  
}
