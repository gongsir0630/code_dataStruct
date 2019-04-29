//date:2018-7-9 20:32:58
//author：龚涛
//function：解决约瑟夫环问题
//循环链表
#include <stdio.h>
#include <stdlib.h>

typedef struct node  /*声明一个链表节点*/
{
	int number;
	struct node *next;
}Node;

Node* CreatNode(int x)  /*创建链表节点的函数*/
{
	Node *p;
	p=(Node*)malloc(sizeof(Node));
	p->number=x;
	p->next=NULL;
	return p;
}

Node* CreatJoseph(int n)  /*创建环形链表，存放整数1到n*/
{
	Node *head,*p,*q;
	int i;
	for(i=1;i<=n;i++)
	{
		p=CreatNode(i);
		if(i==1)
			head=p;
		else
			q->next=p;
		q=p;
	}
	q->next=head;
	return head;
}

void RunJoseph(int n,int m) /*模拟运行约瑟夫环，每数到一个数，将它从环形链表中摘除，并打印出来*/
{
	Node *p,*q;
	p=CreatJoseph(n);
	int i;
	while(p->next!=p)
	{
		for(i=1;i<m-1;i++)
		{
			p=p->next;
		}
		q=p->next;
		p->next=q->next;
		p=p->next;
		free(q);
	}
	printf("\n最后剩下的数为：%d\n",p->number);
}

int main()
{
	int n,m;
	printf("请输入人数n和标志数m:\n");
	scanf("%d %d",&n,&m);
	RunJoseph(n,m);
	return 0;
}
