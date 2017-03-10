/*************************************************************************
    > File Name: fibonacci.c
    > Author: dooon
    > Mail: tangxu314@gmail.com 
    > Created Time: 2017年02月20日 星期一 10时29分47秒
 ************************************************************************/

#include<stdio.h>
long int num;
long int fibrecursion(long int num);
void startcalcu();
long int fibrecursion(long int num)
{
  if (num<2)
    return 1;
  else
    return(fibrecursion(num-1)+fibrecursion(num-2));
}
void startcalcu()
{
  long int p;
  printf("please input a num:");
  scanf("%d",&num);
  p=fibrecursion(num);
  printf("%d\n",p);
}
void main()
{
  long int num=0;
  while(1)
  {
    startcalcu();
  }
}
