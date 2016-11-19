//此小游戏使用C语言编写，编译环境VS2008  

#include <stdio.h>       
#include <stdlib.h>      
#include <termio.h>
#include <pthread.h>
#include <unistd.h>
#include "vDrawMap.h"
#include "vCom.h"
#include "iGetch.h"
#define MOVETO(x,y)
int i,j; 
 
void *music1(void)
{ 
	system("mplayer  '/home/tarena/txz/陈小春 - 相依为命.mp3' > /home/tarena/txz/music  2> /home/tarena/txz/music"); 
}
void *music2(void)
{
	system("mplayer  '/home/tarena/txz/林忆莲 - 为你我受冷风吹.mp3'  > /home/tarena/txz/music  2> /home/tarena/txz/music"); 
}
void *music3(void)
{ 
	system("mplayer  '/home/tarena/txz/钱嘉乐 - 同一秒 (Live).mp3'  > /home/tarena/txz/music  2> /home/tarena/txz/music");
}
void *music4(void)
{
	system("mplayer '/home/tarena/txz/周杰伦 - 龙卷风.mp3'  > /home/tarena/txz/music  2> /home/tarena/txz/music"); 
}

void *tableone()
{
	int iMap[10][12] = 
	{      
		{2,2,2,2,2,2,2,2,2,2,2,2},  
		{2,2,2,2,2,2,0,0,0,2,2,2},  
		{2,2,2,2,2,2,0,0,0,2,2,2},  
		{2,1,1,1,1,2,0,0,0,2,2,2},  
		{2,1,3,3,3,1,1,1,1,2,2,2},  
		{2,1,4,4,4,4,0,3,1,2,2,2},  
		{1,3,0,4,6,0,1,1,2,2,2,2},  
		{1,1,1,1,1,1,1,1,1,2,2,2},  
		{2,2,2,2,2,2,2,2,2,2,2,2},  
		{2,2,2,2,2,2,2,2,2,2,2,2}  
	};  
	vCom(iMap);
}
void *tabletwo()
{
	int iMap[10][12] = 
	{      
		{2,2,2,2,2,1,1,1,1,1,2,2},  
		{1,1,1,1,2,1,0,0,0,1,1,2},  
		{1,3,3,1,1,1,0,1,0,0,1,2},  
		{1,4,4,4,3,3,0,0,1,0,1,1},  
		{1,0,0,1,1,4,0,3,4,0,0,1},  
		{1,0,0,0,0,0,1,1,0,1,0,1},  
		{1,0,0,1,0,0,0,0,0,0,0,1},  
		{1,1,0,6,0,1,1,1,0,1,0,1},  
		{2,1,1,1,1,1,2,1,0,0,0,1},  
		{2,2,2,2,2,2,2,1,1,1,1,1}  
	};  
	vCom(iMap);
}
void *tablethree()
{
	int iMap[10][12] = 
	{      
		{2,2,2,2,2,1,1,1,1,1,2,2},  
		{1,1,1,1,2,1,0,0,0,1,1,2},  
		{1,0,0,1,1,1,0,1,0,0,1,2},  
		{1,0,4,3,3,3,0,0,1,0,1,1},  
		{1,0,0,1,1,3,0,3,4,0,0,1},  
		{1,0,4,4,0,4,1,1,0,1,0,1},  
		{1,0,0,1,0,0,0,0,0,0,0,1},  
		{1,1,0,6,0,1,1,1,0,1,0,1},  
		{2,1,1,1,1,1,2,1,0,0,0,1},  
		{2,2,2,2,2,2,2,1,1,1,1,1}  
	};  
	vCom(iMap);
}
void *tablefour()
{
	int iMap[10][12] = 
	{      
		{2,2,2,2,2,1,1,1,1,1,2,2},  
		{1,1,1,1,2,1,0,0,0,1,1,2},  
		{1,3,3,1,1,1,0,1,0,0,1,2},  
		{1,4,4,3,3,3,0,0,1,0,1,1},  
		{1,0,0,1,1,4,0,3,4,0,0,1},  
		{1,0,4,0,4,0,1,1,0,1,0,1},  
		{1,0,0,1,0,0,0,0,0,0,0,1},  
		{1,1,0,6,0,1,1,1,0,1,0,1},  
		{2,1,1,1,1,1,2,1,0,0,0,1},  
		{2,2,2,2,2,2,2,1,1,1,1,1}  
	};  
	vCom(iMap);
}
main()
{
  int k;
  int bRet1=0;
	int bRet2=0;
	int bRet3=0;
	int bRet4=0;
  char Ch;
	FILE *fp;      //配置文件
  fp=fopen("a","r");
  fscanf(fp,"%d",&k);
  pthread_t id1,id2,id3,id4,id5,id6,id7,id8,id9;
  system("clear");    
  do
	{
		switch(k)      
		{		
		case 0:
			bRet1 = pthread_create(&id1, NULL, (void*)music1, NULL);
			if(bRet1)
			{
				printf("Create pthread error!\n");
				return 1;
			}
			bRet1 = pthread_create(&id2, NULL, (void*)tableone, NULL);
			if(bRet1)
			{
				printf("Create pthread error!\n");
				return 1;
			}
			
			pthread_join(id1,NULL);
			pthread_join(id2,NULL);
			break;
		case 1:	 
			bRet2 = pthread_create(&id3, NULL, (void*)music2, NULL);
			if(bRet2)
			{
				printf("Create pthread error!\n");
				return 1;
			}
			bRet2 = pthread_create(&id4, NULL, (void*)tabletwo, NULL);
			if(bRet2)
			{
				printf("Create pthread error!\n");
				return 1;
			}
			pthread_join(id3,NULL);
			pthread_join(id4,NULL);
			break;
		case 2: 
			bRet3 = pthread_create(&id5, NULL, (void*)music3, NULL);
			if(bRet3)
			{
				printf("Create pthread error!\n");
				return 1;
			}
			bRet3 = pthread_create(&id6, NULL, (void*)tablethree, NULL);
			if(bRet3)	
			{
				printf("Create pthread error!\n");
				return 1;
			}
			pthread_join(id5,NULL);
			pthread_join(id6,NULL);
			break;
		case 3:
			bRet4 = pthread_create(&id7, NULL, (void*)music4, NULL);
			if(bRet4)
			{
				printf("Create pthread error!\n");
				return 1;
			}
			bRet4 = pthread_create(&id8, NULL, (void*)tablefour, NULL);
			if(bRet4)
			{
				printf("Create pthread error!\n");
				return 1;
			}
			pthread_join(id7,NULL);
			pthread_join(id8,NULL);
			break;		
		}
		printf("是否继续下一关（y/n）:");
		scanf("%c", &Ch);
		k++;
	}
	while(Ch == 'Y'||Ch == 'y'); 
}


  
  

