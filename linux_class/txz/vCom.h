
int i,j;
void vCom(int iMap[10][12])
{
	char cInput;     
	int bCount=0;   //定义记分变量 
	
	while (1)   //死循环，等待用户命令  
	{  
		system("clear");  
		usleep(65000);
		vDrawMap(iMap);	 
		printf("\033[%d;%dH", (3), (40));
		printf("当前得分：%d\n",bCount);
		printf("\033[%d;%dH", (1), (40));
		printf("操作说明：w:上，a:左，s:下，d:右\n"); 
		//找初始位置  
		for (i=0;i<10;i++)  
		{  
			for (j=0;j<12;j++)  
			{  
				if (iMap[i][j]==6||iMap[i][j]==9)  
					break;  
			}  
			if (iMap[i][j]==6||iMap[i][j]==9)  
				break;  
		}  
		printf("\033[%d;%dH", (5), (40));
		printf("您的当前坐标（%d，%d）",i,j);          
		cInput = iGetch(); 
		
		switch (cInput)  
		{  
		case 'w':  
			if(iMap[i-1][j]==0)  	//如果人前面是空地。  //0代表空地  6代表人  //3代表目的地 
			{  
				iMap[i-1][j]=6+0; 
				if(iMap[i][j]==9) 
					iMap[i][j]=3; 
				else  
					iMap[i][j]=0;    
			}  
			
			else if((iMap[i-1][j]==3))  
			{  
				iMap[i-1][j]=6+3; 
				if(iMap[i][j]==9)   
					iMap[i][j]=3; 
				else  
					iMap[i][j]=0;  
			}  
			
			else if(iMap[i-1][j]==4)  	//如果人前面是箱子。//4代表箱子   //7箱子进入目的地
			{    
				if (iMap[i-2][j]==0)  
				{   
					iMap[i-2][j]=4; 
					if(iMap[i-1][j]==7) 
						iMap[i-1][j]=9; 
					else  
						iMap[i-1][j]=6;
					if(iMap[i][j]==9)  
						iMap[i][j]=3; 
					else  
						iMap[i][j]=0;  
				}    
				else if (iMap[i-2][j]==3)  
				{   
					iMap[i-2][j]=7;  
					bCount++;   
					if(iMap[i-1][j]==7)  
						iMap[i-1][j]=9;  
					else  
						iMap[i-1][j]=6;  
					if(iMap[i][j]==9)  
						iMap[i][j]=3;  
					else  
						iMap[i][j]=0;  
				}  
			}    
			else if(iMap[i-1][j]==7)  
			{  
				if(iMap[i-2][j]==0)  
				{  
					bCount--;  
					iMap[i-2][j]=4;   
					iMap[i-1][j]=9;     
					if(iMap[i][j]==9)   
						iMap[i][j]=3;  
					else  
						iMap[i][j]=0;  
				}  
				if(iMap[i-2][j]==3)  
				{  
					iMap[i-2][j]=7;   
					iMap[i-1][j]=9;   
					if(iMap[i][j]==9)   
						iMap[i][j]=3;  
					else  
						iMap[i][j]=0;  
				}  
			}  
			break;  
		case 's':    
			if(iMap[i+1][j]==0)  
			{  
				iMap[i+1][j]=6+0; 
				if(iMap[i][j]==9) 
					iMap[i][j]=3; 
				else  
					iMap[i][j]=0;    
			}    
			else if(iMap[i+1][j]==3)  
			{  
				iMap[i+1][j]=6+3; 
				if(iMap[i][j]==9)   
					iMap[i][j]=3; 
				else  
					iMap[i][j]=0;   
			}  
			
			else if(iMap[i+1][j]==4)  
			{  
				if (iMap[i+2][j]==0)  
				{   
					iMap[i+2][j]=4;  
					if(iMap[i+1][j]==7) 
						iMap[i+1][j]=9; 
					else  
						iMap[i+1][j]=6;  
					if(iMap[i][j]==9)   
						iMap[i][j]=3; 
					else  
						iMap[i][j]=0;   
				}   
				else if (iMap[i+2][j]==3)  
				{   
					iMap[i-2][j]=7;    
					bCount++;    
					if(iMap[i+1][j]==7)  
						iMap[i+1][j]=9;  
					else  
						iMap[i+1][j]=6;    
					if(iMap[i][j]==9)  
						iMap[i][j]=3;  
					else  
						iMap[i][j]=0;  
				}  
			}   
			else if(iMap[i+1][j]==7)  
			{  
				if(iMap[i+2][j]==0)  
				{  
					bCount--;  
					iMap[i+2][j]=4;   
					iMap[i+1][j]=9;     
					if(iMap[i][j]==9)   
						iMap[i][j]=3;  
					else  
						iMap[i][j]=0;  
				}  
				
				if(iMap[i+2][j]==3)  
				{  
					iMap[i+2][j]=7;   
					iMap[i+1][j]=9;     
					if(iMap[i][j]==9)   
						iMap[i][j]=3;  
					else  
						iMap[i][j]=0;  
				}  
			}  
			break;  
		case 'a':  
			
			if(iMap[i][j-1]==0)  //如果人前面是空地。  
			{  
				iMap[i][j-1]=6+0; 
				if(iMap[i][j]==9) 
					iMap[i][j]=3; 
				else  
					iMap[i][j]=0;    
			}  
			
			else if(iMap[i][j-1]==3)  //如果人前面是目的地。
			{  
				iMap[i][j-1]=6+3; 
				if(iMap[i][j]==9)   
					iMap[i][j]=3; 
				else  
					iMap[i][j]=0;   
			}  
			
			else if(iMap[i][j-1]==4) //如果人前面是箱子。
			{    
				if (iMap[i][j-2]==0)  
				{   
					iMap[i][j-2]=4;  
					if(iMap[i][j-1]==7) 
						iMap[i][j-1]=9; 
					else  
						iMap[i][j-1]=6; 
					
					if(iMap[i][j]==9)  	//下面是对人原地进行判断
						iMap[i][j]=3; 
					else  
						iMap[i][j]=0;   
				}    
				else if (iMap[i][j-2]==3)  
				{   
					bCount++;  
					iMap[i][j-2]=7;    
					if(iMap[i][j-1]==7)  
						iMap[i][j-1]=9;  
					else  
						iMap[i][j-1]=6;    
					if(iMap[i][j]==9)  
						iMap[i][j]=3;  
					else  
						iMap[i][j]=0;  
				}  
			}  
			
			else if(iMap[i][j-1]==7)  //如果人前面是已经进入某目的地的箱子（ID=7）
			{  
				if(iMap[i][j-2]==0)  
				{  
					bCount--;  
					iMap[i][j-2]=4;   
					iMap[i][j-1]=9;     
					if(iMap[i][j]==9)   
						iMap[i][j]=3;  
					else  
						iMap[i][j]=0;  
				}  
				
				if(iMap[i][j-2]==3)  
				{  
					iMap[i][j-2]=7;   
					iMap[i][j-1]=9;    
					if(iMap[i][j]==9)   
						iMap[i][j]=3;  
					else  
						iMap[i][j]=0;  
				}  
			}  
			break;  
		case 'd':   
			if(iMap[i][j+1]==0)  
			{  
				iMap[i][j+1]=6+0; 
				if(iMap[i][j]==9) 
					iMap[i][j]=3; 
				else  
					iMap[i][j]=0;   
			}    
			else if(iMap[i][j+1]==3)  
			{  
				iMap[i][j+1]=6+3; 
				if(iMap[i][j]==9)   
					iMap[i][j]=3; 
				else  
					iMap[i][j]=0;   
			}    
			else if(iMap[i][j+1]==4)  
			{    
				if (iMap[i][j+2]==0)  
				{   
					iMap[i][j+2]=4;  
					if(iMap[i][j+1]==7) 
						iMap[i][j+1]=9; 
					else  
						iMap[i][j+1]=6;  
					if(iMap[i][j]==9)  
						iMap[i][j]=3; 
					else  
						iMap[i][j]=0;   
				}   
				else if (iMap[i][j+2]==3)  
				{   
					bCount++;  
					iMap[i][j+2]=7;     
					if(iMap[i][j+1]==7)  
						iMap[i][j+1]=9;  
					else  
						iMap[i][j+1]=6;   
					if(iMap[i][j]==9)  
						iMap[i][j]=3;  
					else  
						iMap[i][j]=0;  
				}  
			}   
			else if(iMap[i][j+1]==7)  
			{  
				if(iMap[i][j+2]==0)  
				{  
					bCount--;  
					iMap[i][j+2]=4;   
					iMap[i][j+1]=9;     
					if(iMap[i][j]==9)   
						iMap[i][j]=3;  
					else  
						iMap[i][j]=0;  
				}  
				if(iMap[i][j+2]==3)  
				{  
					iMap[i][j+2]=7;   
					iMap[i][j+1]=9;   
					if(iMap[i][j]==9)   
						iMap[i][j]=3;  
					else  
						iMap[i][j]=0;  
				}  
			}  
			break;  
   }  
			if(bCount==5)         //如果达到分则清屏
			{  
				system("clear");
				vDrawMap(iMap);   
				break;            //退出死循环  
			}  
	}  
	printf("\n恭喜你，过关了！！\n"); 
	}
