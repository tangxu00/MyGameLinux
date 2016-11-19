#include<stdio.h>
#include"init.h"
#include"control.h"
int main() /*=====================================Main====================*/
{
    openFile();              //读取配置文件
    gameBegin();             //游戏开始
    endwin();                //关闭窗口
    return 0;
} 
