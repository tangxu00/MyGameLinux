/*************************************************************************
    > File Name: write.c
    > Author: dooon
    > Mail: tangxu314@163.com 
    > Created Time: 2016年10月21日 星期五 16时55分20秒
 ************************************************************************/
nclude <stdio.h>
#include <stdlib.h>

struct worker
{
	    char num[10];              /*职工号*/
		char name[10];        /*姓名*/  
		char sex[5];         /*性别*/
		char age[3];              /*年龄*/
		char graduation[10];  /*学历*/
		char salary[10];           /*工资*/
		char address[20];      /*地址*/
		char telephone[15];     /*电话号码*/
}wor[100];

void save(void);
void load(void);
int n=0;
void main()
{
	   
	    int i;
		    printf("请输入职工人数:");
			    scanf("%d",&n);
				for(i=0;i<n;i++)
					{
						printf("\n请输入职工的工号:");
						scanf("%s",wor[i].num);
						printf("\n请输入职工姓名:");
						scanf("%s",wor[i].name);
						printf("\n请输入职工性别:");
						scanf("%s",wor[i].sex);
						printf("\n请输入职工年龄:");
						scanf("%s",wor[i].age);
						printf("\n请输入职工学历:");
						scanf("%s",wor[i].graduation);
						printf("\n请输入职工工资:");
						scanf("%s",wor[i].salary);
						printf("\n请输入职工地址:");
						scanf("%s",wor[i].address);
						printf("\n请输入职工电话号码:");
						scanf("%s",wor[i].telephone);
					}
					save();
					load();
}

void save(void){
	    FILE *fp;
		    int i;
			if((fp=fopen("d:\\dx.txt","wb"))==NULL)  /*打开失败*/
				{
					printf("open fail\n");
					exit(0);        /*退出程序*/
											    }
				    for(i=0;i<n;i++)
						{
							if(fwrite(&wor[i],sizeof(wor),1,fp)!=1)
								{
									printf("file write error\n");
									exit(0);
								}
						}
					    fclose(fp);
}

void load(void){
	    FILE *fp;
		    int i;
			if((fp=fopen("d:\\dx.txt","rb"))==NULL)  /*打开失败*/
				{
					printf("open fail\n");
					exit(0);        /*退出程序*/
											    }
				    for(i=0;i<n;i++)
						{
							if(fread(&wor[i],sizeof(wor),1,fp)!=1)
								{
									printf("file read error\n");
									exit(0);
								}
						}
					    fclose(fp);
}
