#include"process.h"
#include"init.h"
#include"draw.h"

/*------生成地雷-------*/ 
void produceBom()
{
    srand((unsigned)time(0));                          //生成随机因子
    int i,j,k;
    
    for(k=0;k<iBoom_Num;k++)
    {
        i = rand() % iHigh;
        j= rand() % iWidth ;
        if(Mine[i][j].iBoom==1)                        //判断是否有雷，有雷则此次不算       
            k=k-1;	
        else 
            Mine[i][j].iBoom=1;
    }
}
/*------统计格子周围的雷-------*/ 
int bomStatics(int i, int j)
{
    int nNUM=0;
    if((i==0)&&(j==0))                                 /*左上角*/
    {
        if(Mine[0][1].iBoom==1)
            nNUM++;
        if(Mine[1][0].iBoom==1)
            nNUM++;
        if(Mine[1][1].iBoom==1)
            nNUM++;
    }
    else
        if((i==0)&&(j==(iWidth-1)))                    /*右上角*/
        {
            if(Mine[0][iWidth-2].iBoom==1)
                nNUM++;
            if(Mine[1][iWidth-1].iBoom==1)
                nNUM++;
            if(Mine[1][iWidth-2].iBoom==1)
                nNUM++;
        }
        else
            if((i==(iHigh-1))&&(j==0))                 /*左下角*/
            {
                if(Mine[iHigh-2][0].iBoom==1)
                    nNUM++;
                if(Mine[iHigh-1][1].iBoom==1)
                    nNUM++;
                if(Mine[iHigh-2][1].iBoom==1)
                    nNUM++;
            }
            else
                if((i==(iHigh-1))&&(j==(iWidth-1)))    /*右下角*/
                {
                    if(Mine[iHigh-1][iWidth-2].iBoom==1)
                        nNUM++;
                    if(Mine[iHigh-2][iWidth-1].iBoom==1)
                        nNUM++;
                    if(Mine[iHigh-2][iWidth-2].iBoom==1)
                        nNUM++;
                }
                else if(j==0)                          /*第一列*/
                {
                    if(Mine[i][j+1].iBoom==1)
                        nNUM++;
                    if(Mine[i+1][j].iBoom==1)
                        nNUM++;
                    if(Mine[i-1][j].iBoom==1)
                        nNUM++;
                    if(Mine[i-1][j+1].iBoom==1)
                        nNUM++;
                    if(Mine[i+1][j+1].iBoom==1)
                        nNUM++;
                }
                else if(j==(iWidth-1))                 /*最右边一行*/
                {
                    if(Mine[i][j-1].iBoom==1)
                        nNUM++;
                    if(Mine[i+1][j].iBoom==1)
                        nNUM++;
                    if(Mine[i-1][j].iBoom==1)
                        nNUM++;
                    if(Mine[i-1][j-1].iBoom==1)
                        nNUM++;
                    if(Mine[i+1][j-1].iBoom==1)
                        nNUM++;
                }
                else if(i==0)                          /*第一行*/
                {
                    if(Mine[i+1][j].iBoom==1)
                        nNUM++;
                    if(Mine[i][j-1].iBoom==1)
                        nNUM++;
                    if(Mine[i][j+1].iBoom==1)
                        nNUM++;
                    if(Mine[i+1][j-1].iBoom==1)
                        nNUM++;
                    if(Mine[i+1][j+1].iBoom==1)
                        nNUM++;
                }
                else if(i==(iHigh-1))                  /*最下面一行*/
                {
                    if(Mine[i-1][j].iBoom==1)
                        nNUM++;
                    if(Mine[i][j-1].iBoom==1)
                        nNUM++;
                    if(Mine[i][j+1].iBoom==1)
                        nNUM++;
                    if(Mine[i-1][j-1].iBoom==1)
                        nNUM++;
                    if(Mine[i-1][j+1].iBoom==1)
                        nNUM++;
                }
                else                                   /*普通格*/
                {
                    if(Mine[i-1][j].iBoom==1)
                        nNUM++;
                    if(Mine[i-1][j+1].iBoom==1)
                        nNUM++;
                    if(Mine[i][j+1].iBoom==1)
                        nNUM++;
                    if(Mine[i+1][j+1].iBoom==1)
                        nNUM++;
                    if(Mine[i+1][j].iBoom==1)
                        nNUM++;
                    if(Mine[i+1][j-1].iBoom==1)
                        nNUM++;
                    if(Mine[i][j-1].iBoom==1)
                        nNUM++;
                    if(Mine[i-1][j-1].iBoom==1)
                        nNUM++;
                }
    return nNUM;
}
/*--------打开白格---------*/
void showWhite(int i,int j)
{
    if((Mine[i][j].iFlag==1)||(Mine[i][j].iProcess==1))/*有旗或者已处理则退出*/
        return;
    Mine[i][j].iRound_Num=bomStatics(i,j);             //统计周围雷数
    if((Mine[i][j].iRound_Num==0)&&(Mine[i][j].iProcess!=1)) /*未处理，周围无雷*/
    {
        drawWhite(i,j);                                //画白格
	iWin_Flag++;
        Mine[i][j].iProcess=1;
    }
    else
        if((Mine[i][j].iRound_Num!=0)&&(Mine[i][j].iProcess!=1))/*周围有雷*/
        {
            drawNum(i,j,Mine[i][j].iRound_Num);
            
            Mine[i][j].iProcess=1;
	    iWin_Flag++;
	   
            return ;
        }
    /*8个方向递归*/
    if((i!=0)&&(Mine[i-1][j].iProcess!=1))
        showWhite(i-1,j);
    if((i!=0)&&(j!=(iWidth-1))&&(Mine[i-1][j+1].iProcess!=1))
        showWhite(i-1,j+1);
    if((j!=(iWidth-1))&&(Mine[i][j+1].iProcess!=1))
        showWhite(i,j+1);
    if((j!=(iWidth-1))&&(i!=(iHigh-1))&&(Mine[i+1][j+1].iProcess!=1))
        showWhite(i+1,j+1);
    if((i!=(iHigh-1))&&(Mine[i+1][j].iProcess!=1))
        showWhite(i+1,j);
    if((i!=(iHigh-1))&&(j!=0)&&(Mine[i+1][j-1].iProcess!=1))
        showWhite(i+1,j-1);
    if((j!=0)&&(Mine[i][j-1].iProcess!=1))
        showWhite(i,j-1);
    if((i!=0)&&(j!=0)&&(Mine[i-1][j-1].iProcess!=1))
        showWhite(i-1,j-1);
}
