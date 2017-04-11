/*************************************************************************
    > File Name: test.c
    > Author: dooon
    > Mail: tangxu314@gmail.com 
    > Created Time: 2017年03月29日 星期三 20时23分04秒
 ************************************************************************/

#include<stdio.h>
int main()
{
  void swap(int x,int y);
  int a=5;
  int b=9;
  if(a<b)
    swap(a,b);
  printf("max=%d,min=%d\n",a,b);
}
void swap(int x,int y)
{
  int temp;
  temp=x;
  x=y;
  y=temp;
}
