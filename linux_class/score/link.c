/*************************************************************************
    > File Name: link.c
    > Author: dooon
    > Mail: tangxu314@163.com 
    > Created Time: 2016年10月20日 星期四 14时35分59秒
 ************************************************************************/

#include<stdio.h>
struct Student 
{
	int num;
	float score;
	struct Student *next;
};
int main()
{
	struct Student a,b,c,*head,*p;
	a.num = 101; a.score = 88;
	b.num = 102; b.score = 45;
	c.num = 103; c.score = 84;
	head = &a;
	a.next = &b;
	b.next = &c;
	c.next = NULL;
	p = head;
	while(head!=NULL)
	{
		printf("%d %f\n",head->num,head->score);
		head=head->next;
	}
	return 0;
}
