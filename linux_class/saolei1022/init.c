#include"draw.h"
#include"init.h"
#include"process.h"
#include"control.h"
#include"ui.h"

void gameBegin()
{
    init();
    ui();
    refresh();
    produceBom();                              //生成地雷
    mouseControl();                            //鼠标控制
}

/*-------文件配置-----------*/
void openFile()
{
    FILE *fp1;
    fp1=fopen("ok.txt","r");
    fscanf(fp1,"%d,%d,%d,%d",&iDifficulty,
                             &iWIN_HIGH,
                             &iWIN_WIDTH,
                             &iSUMBOM);
    fclose(fp1);
    switch(iDifficulty)
            {
            case 1:
                iHigh=iWIN_HIGH;                  //9*9
                iWidth=iWIN_WIDTH;
                iBoom_Num=iSUMBOM;                //9个雷
		iWhite_Num=iWidth*iHigh-iBoom_Num;
                break;
            case 2:
                iHigh=iWIN_HIGH/3*4;              //12*12
                iWidth=iWIN_WIDTH/3*4;
                iBoom_Num=iSUMBOM*2;              //36个
		iWhite_Num=iWidth*iHigh-iBoom_Num;
                break;
            case 3:
                iHigh=iWIN_HIGH/3*5;              //15*15
                iWidth=iWIN_WIDTH/3*5;
                iBoom_Num=iSUMBOM*4;              //36个
		iWhite_Num=iWidth*iHigh-iBoom_Num;
                break;
            }		
} 
/*----------初始化-----------*/
void init()
{
    initscr();                                   //初始化
    clear();                                     //清屏R
    noecho();                                    //取消回显
    cbreak();                                    //直接输出字符
    curs_set(0);                                 // 光标隐藏
    iWin_Flag=0;                                 //点开的白格数为0
    iGame_Time=0;                                //游戏时间初始化
    iTime_Start=0;                               //计时未启动
    mousemask(ALL_MOUSE_EVENTS,NULL);            //监听鼠标事件
    mouseinterval(200);                          //设置单次点击鼠标间隔
    
}

/*----------文件保存------------*/
void saveFile()
{
    FILE *fp1;
    fp1=fopen("ok.txt","w");
    fprintf(fp1,"%d,%d,%d,%d",iDifficulty,
                              iWIN_HIGH,
                              iWIN_WIDTH,
                              iSUMBOM);
    fclose(fp1);
}




