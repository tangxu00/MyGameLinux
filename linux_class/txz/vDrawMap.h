
int i,j;
void vDrawMap(int iMap[10][12])  
{  
	
	for(i=0;i<10;i++)  
	{  
		for(j=0;j<12;j++)  
		{         
			switch(iMap[i][j])  
			{  
			case 0:  
				printf("  "); //代表道路  
				break;  
			case 1:  
				printf("▓▓"); //代表墙壁  
				break;  
			case 2:  
				printf("  "); //游戏边框的空白部分  
				break;  
			case 3:  
				printf("● "); //代表目的地  
				break;  
			case 4:  
				printf("□ "); //代表箱子  
				break;  
			case 7:  
				printf("★ "); //代表箱子进入目的地  
				break;  
			case 6:  
				printf("♀ "); //代表人  
				break;  
			case 9:  
				printf("♀ "); //代表人进入目的地  
				break; 
			}              
		}  
		printf("\n");    //分行输出  
	}  
}  
