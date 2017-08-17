/*************************************************************************
    > File Name: popendemo.c
    > Author: dooon
    > Mail: tangxu314@gmail.com 
    > Created Time: 2017年08月14日 星期一 09时08分43秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main()
{
  FILE *fp;
  char buf[100];
  int i = 0;
  fp = popen("who|sort","r");
  while(fgets(buf,100,fp) != NULL)
    printf("%3d %s",i++,buf);
  pclose(fp);
  return 0;
}
