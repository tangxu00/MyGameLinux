# include "vDrawMap.h"
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
				printf("  "); //������·  
				break;  
			case 1:  
				printf("����"); //����ǽ��  
				break;  
			case 2:  
				printf("  "); //��Ϸ�߿�Ŀհײ���  
				break;  
			case 3:  
				printf("�� "); //����Ŀ�ĵ�  
				break;  
			case 4:  
				printf("�� "); //��������  
				break;  
			case 7:  
				printf("�� "); //�������ӽ���Ŀ�ĵ�  
				break;  
			case 6:  
				printf("�� "); //������  
				break;  
			case 9:  
				printf("�� "); //�����˽���Ŀ�ĵ�  
				break; 
			}              
		}  
		printf("\n");    //�������  
	}  
}  