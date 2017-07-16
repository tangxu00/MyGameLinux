/*************************************************************************
    > File Name: mgraphTraverse.c
    > Author: dooon
    > Mail: tangxu314@gmail.com 
    > Created Time: 2017年07月08日 星期六 20时04分07秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<unistd.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int Boolean;

typedef char VertexType;
typedef int EdgeType;

#define MAXSIZE 9
#define MAXVEX 9
#define INF 65535

typedef struct {
  VertexType vexs[MAXVEX];
  EdgeType arc[MAXVEX][MAXVEX];
  int numNodes,numEdges;
}MGraph;
void CreateMGraph(MGraph *G)
{
  int i,j,k,w;
  printf("please enter num of dots and edges:\n");
  scanf("%d,%d",&G->numNodes,&G->numEdges);
  for (i=0;i<G->numNodes;i++){
    //fflush(stdin);
    scanf(" %c",&G->vexs[i]);//必须加空格，回车赋给空格，%c才能正确赋值
    //fflush(stdin);
  }
  for (i=0;i<G->numNodes;i++)
    for(j=0;j<G->numNodes;j++)
      G->arc[i][j]=INF;
  for (k=0;k<G->numEdges;k++)
  {
    printf("输入边(vi,ji)的下标i,j和权w:\n");
    scanf("%d,%d,%d",&i,&j,&w);
    G->arc[i][j]=w;
    G->arc[i][j]=G->arc[j][i];
  }
}

Boolean visited[MAXVEX];
//邻接矩阵的深度优先递归算法
void DFS(MGraph G,int i)
{
  int j;
  visited[i]=TRUE;
  printf("%c",G.vexs[i]);
  for(j=0;j<G.numNodes;j++)
    if(G.arc[i][j]==1&&!visited[j])
      DFS(G,j);
}
void DFSTraverse(MGraph G)
{
  int i;
  for(i=0;i<G.numNodes;i++)
    visited[i]=FALSE;
  for(i=0;i<G.numNodes;i++)
    DFS(G,i);
}

int main(void)
{
  MGraph G;
  CreateMGraph(&G);
  DFSTraverse(G);
  return 0;
}

