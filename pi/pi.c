/*************************************************************************
    > File Name: pi.c
    > Author: dooon
    > Mail: tangxu314@gmail.com 
    > Created Time: 2016年11月30日 星期三 21时15分12秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
long a = 10000,b,c = 2800;
long d,e,f[2801],g;
main()
{
  for(;b-c;)
    f[b++] = a/5;
  for(;d=0,g=c*2;c-=14,printf("%.4d",e+d/a),e=d%a)
    for(b=c;d+=f[b]*a,f[b]=d%--g,d/=g--,--b;d*=b);
}
