#include<curses.h>
#include<stdio.h>

#define WIN_HIGH 9 //雷区窗口高
#define WIN_WIDTH 9//雷区窗口宽
#define SUMBOM 9//雷数
int HIGH;//雷区高
int WIDTH;//宽
int SUM;//雷数
int SUMWHITE;//白格数
int WINFLAG;//胜利标志
int TIME;//游戏时间
int TIMESTART;//计时开始，1表示启动，0表示关闭
int DIFFICULTY;//游戏难度
int ch;//获取鼠标事件
MEVENT event;//鼠标事件
int MouseX,MouseY;//鼠标坐标x为行，y为列
WINDOW *win;//胜利窗口

struct
{
    int num;/*1表示有雷，0表示无雷*/
    int roundnum;/*格子周围地雷数*/
    int flag;/*1表示有旗，0表示五旗־*/
    int process;//1表示已处理，0表示未处理
}Mine[50][50];//最大范围

void openFile();//配置文件
void init();//界面初始化
void gameBegin();//游戏开始
void saveFile();//保存参数
int set_ticker(int n_msecs);	//设置定时器，单位是毫秒
