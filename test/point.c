/*************************************************************************
    > File Name: point.c
    > Author: dooon
    > Mail: tangxu314@gmail.com 
    > Created Time: 2017年03月29日 星期三 16时34分54秒
 ************************************************************************/

#include<stdio.h>
int main()
{
  int a=100,b=10;
  int *pointer_1,*pointer_2;
  pointer_1=&a;
  pointer_2=&b;
  *pointer_1=b;
  printf("a=%d,b=%d\n",*pointer_1,*pointer_2);
  return 0;
}
