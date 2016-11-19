#include <stdio.h>
#include <malloc.h>

typedef struct node
{
    int data;
    struct node * lchild;
    struct node * rchild;
}node;

void Init(node *t)
{
    t = NULL;
}

node * Insert(node *t , int key)
{
    if(t == NULL)
    {
        node * p;
        p = (node *)malloc(sizeof(node));
        p->data = key;
        p->lchild = NULL;
        p->rchild = NULL;
        t = p;
    }
    else
    {
        if(key < t->data)
            t->lchild = Insert(t->lchild, key);
        else
            t->rchild = Insert(t->rchild, key);
    }
    return t;    //important!
}

node * creat(node *t)
{
    int i, n, key;
	printf("please enter the count of data:\n");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
		printf("please enter the data:\n");
        scanf("%d", &key);
        t = Insert(t, key);
    }
    return t;
}

void InOrder(node * t)        //中序遍历输出
{
    if(t != NULL)
    {
        InOrder(t->lchild);
        printf("%d ", t->data);
        InOrder(t->rchild);
    }
}

int main()
{
    node * t = NULL;
    t = creat(t);
    InOrder(t);
    return 0;
}
