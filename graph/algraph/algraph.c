/*************************************************************************
    > File Name: algraph.c
    > Author: dooon
    > Mail: tangxu314@gmail.com 
    > Created Time: 2017年06月18日 星期日 19时58分05秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define MAXVEX 100
#define TRUE 1
#define FALSE 0
typedef int Boolean;
typedef char VertexType;
typedef int EdgeType;
typedef struct EdgeNode
{
  int adjvex;
  EdgeType weight;
  struct EdgeNode *next;
}EdgeNode;
typedef struct VertexNode
{
  char data;
  EdgeNode *firstedge;
}VertexNode,AdjList[MAXVEX];

typedef struct
{
  AdjList adjList;//如果是伸缩数据，必须是结构体的最后一个成员，所以要放到最后
  int numVertexes,numEdges;
  //AdjList adjList;
}GraphAdjList;

void CreatALGraph(GraphAdjList *G)
{
  int i,j,k;
  EdgeNode *e;
  printf("please input num of dots and edges:\n");
  scanf("%d,%d",&G->numVertexes,&G->numEdges);
  printf("请输入顶点数值:\n");
  for (i=0;i<G->numVertexes;i++)
  {
    scanf(" %c",&G->adjList[i].data);
    G->adjList[i].firstedge=NULL;
  }
  for(k=0;k<G->numEdges;k++)
  {
    printf("输入边(vi,vj)上的顶点序号:\n");
    scanf("%d,%d",&i,&j);
    e=(EdgeNode*)malloc(sizeof(EdgeNode));
    e->adjvex=j;
    e->next=G->adjList[i].firstedge;
    G->adjList[i].firstedge=e;
    e=(EdgeNode*)malloc(sizeof(EdgeNode));
    e->adjvex=i;
    e->next=G->adjList[j].firstedge;
    G->adjList[j].firstedge=e;
    //头插法
  }
}

Boolean visited[MAXVEX];
//临接表的深度优先递归算法
void DFS(GraphAdjList *GL,int i)
{
  EdgeNode *p;
  visited[i]=TRUE;
  printf("%C",GL-adjList[i]->data);
  p=GL->adjList[i].firstedge;
  while(p)
  {
    if(!visited[p->adjvex])
      DFS(GL,p->adjvex);
    p=p->next;
  }

}

int main(void)
{
  GraphAdjList G;
  CreatALGraph(&G);
  return 0;
}
