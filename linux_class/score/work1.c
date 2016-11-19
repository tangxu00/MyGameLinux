/*************************************************************************
    > File Name: work1.c
    > Author: dooon
    > Mail: tangxu314@163.com 
    > Created Time: 2016年10月19日 星期三 11时15分17秒
 ************************************************************************/

#include<stdio.h>
typedef struct _student
{
	int num;
	char name[20];
	float score1, score2, score3;
	float aver; 
	struct _student *next;
} stu;
int n;
struct _student *creat(void);
stu myClass[5];
//void readarray(stu array[]);
void calarray(stu array[]);
int findarray(stu array[]);
int main(void)
{
	int high;
	creat();
	//readarray(myClass);
	calarray(myClass);
	high = findarray(myClass);
printf("\noutput:\n");
	printf("\nThe Highest is %s(%d)\nscore1=%.2f  score2=%.2f  score3=%.2f  aver=%.2f\n",
		myClass[high].name, myClass[high].num,
		myClass[high].score1, myClass[high].score2, myClass[high].score3, myClass[high].aver);
	return 0;
}
struct _student *creat(void)
{
	stu *head,*p1,p2;
	n=0;
	p1=p2=(struct _student*)maclloc(sizeof(struct _student));
	scanf("%d%s%f%f%f",&p1->num,&p1->name,&p1->score1,&p1->score2,&p1->score3);
	head = NULL;
	while(p1->num!=0)
	{
		n=n+1;
		if(n==1)
			head=p1;
		else
			p2->next=p1;
		p2=p1;
		p1=(struct _student*)malloc(sizeof(struct _student));
		scanf("%d%s%f%f%f",&p1->num,&p1->name,&p1->score1,&p1->score2,&p1->score3);
	}
	p2->next=NULL;
	return(0);
}
void readarray(stu array[])
{
	int i;
	printf("input students  info:\nNum  Name        score1 score2 score3\n");
	for (i = 0; i < 5; i++)
	{
		/*printf("%d:", i + 1);*/
		scanf("%d%s%f%f%f", &array[i].num, array[i].name, 
			&array[i].score1, &array[i].score2, &array[i].score3);
	}
}
void calarray(stu array[])
{
	int i;
	for (i = 0; i < 5; i++)
	{
		array[i].aver = (array[i].score1 + array[i].score2 + array[i].score3) / 3;
	}
}
int findarray(stu array[])
{
	int i, pos;
	float maxaver;
	maxaver = array[0].aver;
	pos = 0;
	for (i = 1; i < 5; i++)
	{
		if (maxaver< array[i].aver)
		{
			maxaver = array[i].aver;
			pos = i;
		}
	}
	return pos;
}

