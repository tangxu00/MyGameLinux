/*************************************************************************
    > File Name: link4.c
    > Author: dooon
    > Mail: tangxu314@163.com 
    > Created Time: 2016年10月20日 星期四 20时21分19秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define LAN sizeof(struct Student)
#define SIZE 10
struct Student
	{
		long num;
		float score1,score2,score3;
		float aver;
		char name[10];
		struct Student * next;
	}stu[SIZE];
int n;
struct Student*creat(void);
void average(struct Student *head);
int maxmum(struct Student *head);
void write();
void find(struct Student *head);

int main()
{
	struct Student * head;
	head=creat();
	average(head);
	maxmum(head);
	write();
	find(head);
	return 0;
}

struct Student*creat(void)
{
	struct Student * head;
	struct Student * p1, * p2;
	n=0;
	p1=p2=(struct Student * ) malloc(LAN);
	printf("Please enter the num,name and 3 score:(enter '0' to end)\nnum,name,score1,score2,score3\n");
	scanf("%ld,%c%c%c,%f,%f,%f",&p1->num,&p1->name[0],&p1->name[1],&p1->name[2],&p1->score1,&p1->score2,&p1->score3);
	head=NULL;
	while(p1->num!=0)
	{
		n=n+1;
		if(n==1)
			head=p1;
		else 
			p2->next=p1;
		p2=p1;
		 p1=(struct Student * )malloc(LAN);
		 scanf("%ld,%c%c%c,%f,%f,%f",&p1->num,&p1->name[0],&p1->name[1],&p1->name[2],&p1->score1,&p1->score2,&p1->score3);
	}
	p2->next=NULL;
	return(head);
}
void average(struct Student *head)
{
	struct Student *p;
	p=head;
	if(head!=NULL)
		printf("Please confim infom:\nnum,name, score1,score2,score3,  average\n");
		do 
			{
				p->aver=(p->score1+p->score2+p->score3)/3;
				printf("%ld   %c%c%c   %.2f  %.2f   %.2f    %.2f\n",p->num,p->name[0],p->name[1],p->name[2],p->score1,p->score2,p->score3,p->aver);
				p=p->next;
			}
		while(p!=NULL);
}
int maxmum(struct Student *head)
{
	struct Student *p;
	int n;
	float max;
	p=head;
	if(head!=NULL)
	{
		n=p->num;
		max=p->aver;
		do
		{
			//p=p->next;
			if(max < p->aver)
			{	
			max=p->aver;
			n=p->num;
			}
			p=p->next;
		}
		while(p!=NULL);
	}
	printf("The hightest is:NO.%d score is:%.2f\n",n,max);
	return(0);
}
void find(struct Student *head)
{
	struct Student *p;
	p=head;
	int t,n;
	printf("press '0' to find\n");
	scanf("%d",&t);
	if(t==0)
	{
		printf("please enter the num:");
		scanf("%d",&n);
		if(head!=NULL)
		{
			do
			{
				if(n==p->num)
				{
					printf("NO.%d students is %c%c%c score:%.2f %.2f %.2f average is:%.2f",n,p->name[0],p->name[1],p->name[2],p->score1,p->score2,p->score3,p->aver);
				}
				p=p->next;
			}
			while(p!=NULL);
		}

	}
}
void write()
{
	FILE *fp;
	int i;
	if((fp=fopen("text.bin","wb"))==NULL)
	{
		printf("cannot open file\n");
		return;
	}
	for(i=0;i<SIZE;i++)
		if(fwrite(&stu[i],LAN,1,fp)!=1)
			printf("file write error!\n");
	fclose(fp);
	printf("data has been writed in text.bin\n");
}
