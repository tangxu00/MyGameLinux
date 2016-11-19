#include<stdio.h>
#include<curses.h>
void drawFlag(int i,int j);                      //画旗
void eraseFlag(int i,int j);                     //擦旗
void drawWhite(int i,int j);                     //画白格
void drawNum(int i,int j,int k);                 //画数字
void drawBom(int i,int j);                       //画地雷
void showSum();                                  //显示雷数
void showTime();                                 //显示时间
