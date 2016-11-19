#include <sys/time.h>
#include<stdlib.h>
#include <time.h>
#include<stdio.h>
void produceBom();                               //生成地雷
int bomStatics(int i, int j);                    //统计格子周围的雷
void showWhite(int i,int j);                     //显示白格
