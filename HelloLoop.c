/*************************************************************************
    > File Name: HelloLoop.c
    > Author: dooon
    > Mail: tangxu314@163.com 
    > Created Time: 2016年10月13日 星期四 19时14分56秒
 ************************************************************************/

#include<stdio.h>
#include<sys/time.h>
int main(int argc,char**argv)
{
	struct timeval tv;
	int i = 0;
	for(;;)
	{
		gettimeofday(&tv,NULL);
		printf("Loop %d: Time  = %d %d \n",i,(int)tv.tv_sec,(int)tv.tv_usec);
		sleep(1);
		i++;
	}
	return 0;
}

	

