#include"init.h"
#include"draw.h"
#include"control.h"
#include"ui.h"
/*------------鼠标控制--------------*/
void mouseControl()
{
    //mousemask(ALL_MOUSE_EVENTS,NULL);     //监听鼠标事件
    while(1)
    {
        int i,j;                            //定义行列
        keypad(stdscr,true);
        iKey=getch();
        if(iKey==KEY_MOUSE)
        {
            if(getmouse(&event)==OK)
            {   iMouseX=event.y;
                iMouseY=event.x;
                if(event.bstate & BUTTON1_CLICKED)
                {
                    leftClicked(i,j);
                }
                else if(event.bstate & BUTTON1_DOUBLE_CLICKED)
                {
                    leftDoubleCliked(i,j);
                } 
            }  
        }
        else if(iKey=='l')                  //离开游戏
        {  
            saveFile();
	    endwin();
            exit(0);
        }     
        else if(iKey=='r')                  //重新开始
        {
            iTime_Start=0;
	    set_ticker(0);
            switch(iDifficulty)
            {
            case 1:
                iHigh=iWIN_HIGH;
                iWidth=iWIN_WIDTH;
                iBoom_Num=iSUMBOM;
		iWhite_Num=iWidth*iHigh-iBoom_Num;
                break;
            case 2:
                iHigh=iWIN_HIGH/3*4;
                iWidth=iWIN_WIDTH/3*4;
                iBoom_Num=iSUMBOM*2;
		iWhite_Num=iWidth*iHigh-iBoom_Num;
                break;
            case 3:
                iHigh=iWIN_HIGH/3*5;
                iWidth=iWIN_WIDTH/3*5;
                iBoom_Num=iSUMBOM*4;
		iWhite_Num=iWidth*iHigh-iBoom_Num;
                break;
            }		
            gameBegin();
        }
        else if(iKey=='1')                  //难度选择：1为简单，2为中等 3为困难
        {
            iTime_Start=0;
	    set_ticker(0);
            iDifficulty=1;	        
            iHigh=iWIN_HIGH;
            iWidth=iWIN_WIDTH;
            iBoom_Num=iSUMBOM;
	    iWhite_Num=iWidth*iHigh-iBoom_Num;
            gameBegin();
        }
        else if(iKey=='2')
        {
            iTime_Start=0;
	    set_ticker(0);
            iDifficulty=2;	        
            iHigh=iWIN_HIGH/3*4;
            iWidth=iWIN_WIDTH/3*4;
            iBoom_Num=iSUMBOM*2;
	    iWhite_Num=iWidth*iHigh-iBoom_Num;
            gameBegin();
        }
        else if(iKey=='3')
        {
            iTime_Start=0;
	    set_ticker(0);
            iDifficulty=3;	        
            iHigh=iWIN_HIGH/3*5;
            iWidth=iWIN_WIDTH/3*5;
            iBoom_Num=iSUMBOM*4;
	    iWhite_Num=iWidth*iHigh-iBoom_Num;
            gameBegin();
        }
    }
}
/*------------左键单击-----------*/
void leftClicked(int i,int j)
{
    if((iMouseX>=0)&&(iMouseX<=2*iHigh)&&(iMouseY>=0)&&(iMouseY<=4*iWidth))
    {
        if((iMouseX%2)!=0)
        {
            
            i=(iMouseX-1)/2;                //坐标转换
            j=iMouseY/4;
            if(Mine[i][j].iFlag==0)         //判断是否无旗
            {
                if(Mine[i][j].iBoom==1)     //判断是否有雷
                {
                    iTime_Start=0;
	            set_ticker(0);
                    for(i=0;i<iHigh;i++)
                    {
                        for(j=0;j<iWidth;j++)
                        {
                            Mine[i][j].iProcess=1;//表示已处理
                            if(Mine[i][j].iBoom==1)
                                drawBom(i,j); //画雷
                        }
                    }
                }
                else
                { if(iTime_Start==0)
			{
			    iTime_Start=1;
                             set_ticker(1000);			
                             signal(SIGALRM,showTime);      
                         }
                  showWhite(i,j);           //显示无雷区
                }
		if(iWin_Flag==iWhite_Num)
	        {
                    iTime_Start=0;
	            set_ticker(0);
                    success();
                    refresh();
                }
            }
        }
    }
}
/*-------------左键双击--------------*/
void leftDoubleCliked(int i,int j)
{
    if((iMouseX>=0)&&(iMouseX<=2*iHigh)&&(iMouseY>=0)&&(iMouseY<=4*iWidth))
    {
        if((iMouseX%2)!=0)
        {
            i=(iMouseX-1)/2;                //坐标转换
            j=iMouseY/4;
            if((Mine[i][j].iFlag==0)&&(Mine[i][j].iProcess==0))
            {
                drawFlag(i,j);              //画旗
                Mine[i][j].iFlag=1;
                iBoom_Num=iBoom_Num-1;      //总雷数减1
                showSum();                  //显示雷数
            }
            else if(Mine[i][j].iFlag==1)
            {
                eraseFlag(i,j);             //擦旗
                Mine[i][j].iFlag=0;
                iBoom_Num=iBoom_Num+1;      //总雷数加1
                showSum();                  //显示雷数
            }
        }        
    } 
}
/*------------设置定时器------------*/
int set_ticker(int n_msecs)  	            //这段是借鉴的，不用太明白
{  
    struct itimerval new_timeset;  
    long n_sec, n_usecs;  
  
    n_sec = n_msecs / 1000;                 /* int second part */  
    n_usecs = (n_msecs % 1000) * 1000L;     /* microsecond part */  
  
    new_timeset.it_interval.tv_sec = n_sec; /* set reload */  
    new_timeset.it_interval.tv_usec = n_usecs;  
  
    new_timeset.it_value.tv_sec = n_sec;    /* set new ticker value */  
    new_timeset.it_value.tv_usec = n_usecs;  
  
    return setitimer(ITIMER_REAL, &new_timeset, NULL);  
}
/*---------------游戏成功界面---------------*/
void success()
{
    win=newwin(iHigh+1,3*iWidth+3,iHigh/2,iWidth/2);
    box(win, ACS_VLINE, ACS_HLINE);         /*draw a box*/ 
    int key;
    //char name[20];
    mvwaddstr(win,iHigh/2-2,iWidth/2,"CONGRATULATIONS!");
    mvwaddstr(win,iHigh/2-1,iWidth/2,"YOU HAVE WIN THE GAME!");
    mvwaddstr(win,iHigh/2,iWidth/2,"PRESS ANY KEY TO CHOOSE!");
    mvwaddstr(win,iHigh-2,iWidth/2,"RESTART:        'r' ");
    mvwaddstr(win,iHigh-1,iWidth/2,"LEAVE:          'l' ");
    refresh();
    key=wgetch(win);
    if(key=='l')                            //离开游戏
        {  
            saveFile();
	    endwin();
            exit(0);
        }     
        else if(key=='r')                   //重新开始
        {
            iTime_Start=0;
	    set_ticker(0);
            switch(iDifficulty)
            {
            case 1:
                iHigh=iWIN_HIGH;
                iWidth=iWIN_WIDTH;
                iBoom_Num=iSUMBOM;
		iWhite_Num=iWidth*iHigh-iBoom_Num;
                break;
            case 2:
                iHigh=iWIN_HIGH/3*4;
                iWidth=iWIN_WIDTH/3*4;
                iBoom_Num=iSUMBOM*2;
		iWhite_Num=iWidth*iHigh-iBoom_Num;
                break;
            case 3:
                iHigh=iWIN_HIGH/3*5;
                iWidth=iWIN_WIDTH/3*5;
                iBoom_Num=iSUMBOM*4;
		iWhite_Num=iWidth*iHigh-iBoom_Num;
                break;
            }		
            gameBegin(); 
         }
}

