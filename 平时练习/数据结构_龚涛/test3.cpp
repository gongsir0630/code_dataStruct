//date:2018-7-9 20:32:58
//author������
//function�����Լɪ������
//ѭ������
#include <stdio.h>
#include <stdlib.h>

typedef struct node  /*����һ������ڵ�*/
{
	int number;
	struct node *next;
}Node;

Node* CreatNode(int x)  /*��������ڵ�ĺ���*/
{
	Node *p;
	p=(Node*)malloc(sizeof(Node));
	p->number=x;
	p->next=NULL;
	return p;
}

Node* CreatJoseph(int n)  /*�������������������1��n*/
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

void RunJoseph(int n,int m) /*ģ������Լɪ�򻷣�ÿ����һ�����������ӻ���������ժ��������ӡ����*/
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
	printf("\n���ʣ�µ���Ϊ��%d\n",p->number);
}

int main()
{
	int n,m;
	printf("����������n�ͱ�־��m:\n");
	scanf("%d %d",&n,&m);
	RunJoseph(n,m);
	return 0;
}
