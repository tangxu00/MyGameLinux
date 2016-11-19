#include<stdio.h>
#include<signal.h>
#include <sys/time.h>
#include<stdlib.h>

int iKey;                                   //获取鼠标事件
MEVENT event;                               //鼠标事件
int iMouseX,iMouseY;                        //鼠标坐标x为行，y为列
WINDOW *win;                                //胜利窗口
void mouseControl();                        //鼠标控制
void leftClicked(int i,int j);              //左键点击
void leftDoubleCliked(int i,int j);         //左键双击
int set_ticker(int n_msecs);	            //设置定时器，单位是毫秒
void success();                             //胜利画面

