/*************************************************************************
    > File Name: easyList.c
    > Author: dooon
    > Mail: tangxu314@gmail.com 
    > Created Time: 2017年03月28日 星期二 19时42分10秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 50
typedef int ElemType;//为现有的类型创建一个新的名字
typedef struct
{
  ElemType data[MAXSIZE];
  int length;
}SqList;

#define TRUE 1
#define FALSE 0
typedef enum
{
  ERROR=0,
  OK=1
}Status;
//用a返回第i个元素的值
Status GetElem(SqList s,int i,ElemType *a)
{
  Status flag;
  if((s.length==0)||(i<1)||(i>s.length))
    flag=ERROR;
  else
  {
    *a=s.data[i-1];
    flag=OK;
  }
  return flag;
}
//在第i个位置之前插入元素a
Status ListInsert(SqList *s,int i,ElemType a)
{
  int j;
  Status flag;
  if(s->length==MAXSIZE||(i<1)||(i>s->length+1))
    flag=ERROR;
  else
    {
      for(j=s->length-1;j>=i-1;j--)
        s->data[j+1]=s->data[j];
      s->data[i-1]=a;
      s->length++;
      flag=OK;
    }
  return flag;
}
//删除第i个元素，用a表示删除的值
Status ListDelete(SqList *s,int i,ElemType *a)
{
  int j;
  Status flag;
  if(s->length==0||(i<1)||(i>s->length))
    flag=ERROR;
  else
  {
    *a=s->data[i-1];
    for(j=i-1;j<s->length;j++)
      s->data[j]=s->data[j+1];
    s->length--;
    flag=OK;
  }
  return flag;
}
//打印链表数据
void ListDisplay(SqList *s)
{
  int i;
  printf("SqList is: ");
  for(i=0;i<s->length;i++)
    printf("%d ",s->data[i]);
  printf("\n");
}
void main()
{
  SqList test;
  test.length=0;
  ListDisplay(&test);
  int i;
  for(i=0;i<10;i++)
  {
    ListInsert(&test,i,i*2);
    printf("insert data %d,now ",i*2);
    ListDisplay(&test);
  }
  int data=0;
  GetElem(test,5,&data);
  printf("SqList test fifth data is %d\n",data);
  printf("SqList test fifth data is %d\n",test.data[4]);
  int len=test.length;
  for(i=0;i<len;i++)
  {
    int b;
    ListDelete(&test,1,&b);
    printf("delete data %d,now ",b);
    ListDisplay(&test);
  }
}
