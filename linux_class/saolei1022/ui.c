#include"draw.h"
#include"init.h"
void ui()                                             //绘制界面
{
    int i,j;
    for(j=0;j<2*iHigh+2;j=j+2)
    {for(i=1;i<4*iWidth;i++)
        {
            if((i%4)!=0)
            {mvaddch(j,i,ACS_HLINE);}
            else
            {mvaddch(j,i,'+');}
        }
    }
    //------画竖线----
    for(j=0;j<2*iHigh;j++)
    {
        for(i=0;i<4*iWidth+4;i=i+4)
        {
          
            mvaddch(j,i,ACS_VLINE);
          
        }
    }
    //补充边角
    
    for(j=2;j<2*iHigh;j=j+2)
    {
        for(i=4;i<4*iWidth;i=i+4)
        {
          
            mvaddch(j,i,ACS_PLUS);
          
        }
    }
    mvaddch(0,0,ACS_ULCORNER);
    mvaddch(0,4*iWidth,ACS_URCORNER);
    mvaddch(2*iHigh,0,ACS_LLCORNER);
    mvaddch(2*iHigh,4*iWidth,ACS_LRCORNER);
    for(i=4;i<4*iWidth;i=i+4)
    {
      mvaddch(0,i,ACS_TTEE);
      mvaddch(2*iHigh,i,ACS_BTEE);
    }
    
    for(j=2;j<2*iHigh;j=j+2)
    {
      mvaddch(j,0,ACS_LTEE);
      mvaddch(j,4*iWidth,ACS_RTEE);
    }

    //画点，表示未点开
    for(j=1;j<2*iHigh;j=j+2)
    {
        for(i=2;i<4*iWidth;i=i+4)
        {
            attrset(A_REVERSE);
            mvaddch(j,i,' ');
            mvaddch(j,i+1,' ');
            mvaddch(j,i-1,' ');
            
        }
    }
    attrset(A_NORMAL);
    for(i=0;i<iHigh;i++)                              //初始化结构体
    {
        for(j=0;j<iWidth;j++)
        {
            Mine[i][j].iBoom=0;
            Mine[i][j].iFlag=0;
            Mine[i][j].iRound_Num=0;
            Mine[i][j].iProcess=0;
        }
    }
    /*------显示时间雷数窗口-------*/
    //---------画编辑框----------
    
    for(i=4*iWidth+3;i<4*iWidth+33;i++)
        mvaddch(0,i,'*');
    for(i=4*iWidth+3;i<4*iWidth+33;i++)
        mvaddch(2*iHigh,i,'*');
    for(j=0;j<2*iHigh+1;j++)
        mvaddch(j,4*iWidth+3,'*');
    for(j=0;j<2*iHigh+1;j++)
        mvaddch(j,4*iWidth+33,'*');
    for(i=4*iWidth+4;i<4*iWidth+32;i++)
    {
        mvaddch((2*iHigh+1)/3,i,'*');
        mvaddch((2*iHigh+1)/3+1,i,'*');
    }
    //-------------编辑框信息-------------
    showSum();                                        //显示剩余雷数
    showTime();                                       //显示时间
    mvaddstr((2*iHigh+1)/3+2,4*iWidth+4,"Version 1.3");
    mvaddstr((2*iHigh+1)/3+3,4*iWidth+4,"uuuuuuuuuuu");
    mvaddstr((2*iHigh+1)/3+5,4*iWidth+4,"RESTART:              'r' ");
    mvaddstr((2*iHigh+1)/3+6,4*iWidth+4,"LEAVE:                'l' ");
    mvaddstr((2*iHigh+1)/3+7,4*iWidth+4,"DIFFICULTY:");
    mvaddstr((2*iHigh+1)/3+8,4*iWidth+4,"EASY:                 '1' ");
    mvaddstr((2*iHigh+1)/3+9,4*iWidth+4,"NORMAL:               '2' ");
    mvaddstr((2*iHigh+1)/3+10,4*iWidth+4,"HARD:                 '3' ");
    mvaddstr((2*iHigh+1)/3+11,4*iWidth+4,"PRESS KEY TO CHOOSE LEVEL");
}
