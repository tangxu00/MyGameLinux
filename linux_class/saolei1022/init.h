#include<curses.h>
#include<stdio.h>

int iWIN_HIGH;                              //雷区窗口高
int iWIN_WIDTH;                             //雷区窗口宽
int iSUMBOM;                                //雷数
int iHigh;                                  //雷区高
int iWidth;                                 //宽
int iWin_Flag;                              //胜利标志
int iBoom_Num;                              //雷数
int iWhite_Num;                             //白格数
int iGame_Time;                             //游戏时间
int iTime_Start;                            //计时开始，1表示启动，0表示关闭
int iDifficulty;                            //游戏难度


struct
{
    int iBoom;                              /*1表示有雷，0表示无雷*/
    int iRound_Num;                         /*格子周围地雷数*/
    int iFlag;                              /*1表示有旗，0表示五旗־*/
    int iProcess;                           //1表示已处理，0表示未处理
}Mine[50][50];                              //最大范围

void openFile();                            //配置文件
void init();                                //界面初始化
void gameBegin();                           //游戏开始
void saveFile();                            //保存参数

