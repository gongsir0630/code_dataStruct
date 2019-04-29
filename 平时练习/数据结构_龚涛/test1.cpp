/*ʱ�䣺2018-7-9 19:21:21
���ߣ�����
�����ܣ�������Ļ�������
*/
#include "stdio.h"    
#include "string.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 /* �洢�ռ��ʼ������ */

typedef int Status;/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int ElemType;/* ElemType���͸���ʵ������������������Ϊint */

/* ����LinkList */
typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node;
typedef struct Node *LinkList;

//���
Status visit(ElemType c)
{
    printf("%d ",c);
    return OK;
}

/* ��ʼ��˳�����Ա� */
Status InitList(LinkList *L) 
{ 
    *L=(LinkList)malloc(sizeof(Node)); /* ����ͷ���,��ʹLָ���ͷ��� */
    if(!(*L)) /* �洢����ʧ�� */
		return ERROR;
    (*L)->next=NULL; /* ָ����Ϊ�� */
	
    return OK;
}

//�ж����Ա��Ƿ�Ϊ��
/* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE */
Status ListEmpty(LinkList L)
{ 
    if(L->next)
		return FALSE;
    else
		return TRUE;
}

//�����Ա��ÿ�
/* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������L����Ϊ�ձ� */
Status ClearList(LinkList *L)
{ 
	LinkList p,q;
	p=(*L)->next;           /*  pָ���һ����� */
	while(p)                /*  û����β */
	{
		q=p->next;
		free(p);
		p=q;
	}
	(*L)->next=NULL;        /* ͷ���ָ����Ϊ�� */
	return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
int ListLength(LinkList L)
{
    int i=0;
    LinkList p=L->next; /* pָ���һ����� */
    while(p)                        
    {
        i++;
        p=p->next;
    }
    return i;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
/* �����������e����L�е�i������Ԫ�ص�ֵ */
Status GetElem(LinkList L,int i,ElemType *e)
{
	int j;
	LinkList p;		/* ����һ���p */
	p = L->next;		/* ��pָ������L�ĵ�һ����� */
	j = 1;		/*  jΪ������ */
	while (p && j<i)  /* p��Ϊ�ջ��߼�����j��û�е���iʱ��ѭ������ */
	{   
		p = p->next;  /* ��pָ����һ����� */
		++j;
	}
	if ( !p || j>i ) 
		return ERROR;  /*  ��i��Ԫ�ز����� */
	*e = p->data;   /*  ȡ��i��Ԫ�ص����� */
	return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ��� */
/* �������������L�е�1����e�����ϵ������Ԫ�ص�λ�á� */
/* ������������Ԫ�ز����ڣ��򷵻�ֵΪ0 */
int LocateElem(LinkList L,ElemType e)
{
    int i=0;
    LinkList p=L->next;
    while(p)
    {
        i++;
        if(p->data==e) /* �ҵ�����������Ԫ�� */
			return i;
        p=p->next;
    }
	
    return 0;
}


/* ��ʼ������˳�����Ա�L�Ѵ���,1��i��ListLength(L)�� */
/* �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1 */
Status ListInsert(LinkList *L,int i,ElemType e)
{ 
	int j;
	LinkList p,s;
	p = *L;   
	j = 1;
	while (p && j < i)     /* Ѱ�ҵ�i����� */
	{
		p = p->next;
		++j;
	} 
	if (!p || j > i) 
		return ERROR;   /* ��i��Ԫ�ز����� */
	s = (LinkList)malloc(sizeof(Node));  /*  �����½��(C���Ա�׼����) */
	s->data = e;  
	s->next = p->next;      /* ��p�ĺ�̽�㸳ֵ��s�ĺ��  */
	p->next = s;          /* ��s��ֵ��p�ĺ�� */
	return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
/* ���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1 */
Status ListDelete(LinkList *L,int i,ElemType *e) 
{ 
	int j;
	LinkList p,q;
	p = *L;
	j = 1;
	while (p->next && j < i)	/* ����Ѱ�ҵ�i��Ԫ�� */
	{
        p = p->next;
        ++j;
	}
	if (!(p->next) || j > i) 
		return ERROR;           /* ��i��Ԫ�ز����� */
	q = p->next;
	p->next = q->next;			/* ��q�ĺ�̸�ֵ��p�ĺ�� */
	*e = q->data;               /* ��q����е����ݸ�e */
	free(q);                    /* ��ϵͳ���մ˽�㣬�ͷ��ڴ� */
	return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ��� */
/* ������������ζ�L��ÿ������Ԫ����� */
Status ListTraverse(LinkList L)
{
    LinkList p=L->next;
    while(p)
    {
        visit(p->data);
        p=p->next;
    }
    printf("\n");
    return OK;
}

/*  �������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L��ͷ�巨�� */
void CreateListHead(LinkList *L, int n) 
{
	LinkList p;
	int i;
	srand(time(0));                         /* ��ʼ����������� */
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;                      /*  �Ƚ���һ����ͷ���ĵ����� */
	for (i=0; i<n; i++) 
	{
		p = (LinkList)malloc(sizeof(Node)); /*  �����½�� */
		p->data = rand()%100+1;             /*  �������100���ڵ����� */
		p->next = (*L)->next;    
		(*L)->next = p;						/*  ���뵽��ͷ */
	}
}

/*  �������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L��β�巨�� */
void CreateListTail(LinkList *L, int n) 
{
	LinkList p,r;
	int i;
	srand(time(0));                      /* ��ʼ����������� */
	*L = (LinkList)malloc(sizeof(Node)); /* LΪ�������Ա� */
	r=*L;                                /* rΪָ��β���Ľ�� */
	for (i=0; i<n; i++) 
	{
		p = (Node *)malloc(sizeof(Node)); /*  �����½�� */
		p->data = rand()%100+1;           /*  �������100���ڵ����� */
		r->next=p;                        /* ����β�ն˽���ָ��ָ���½�� */
		r = p;                            /* ����ǰ���½�㶨��Ϊ��β�ն˽�� */
	}
	r->next = NULL;                       /* ��ʾ��ǰ������� */
}
//������
int main()
{        
    LinkList L;
    ElemType e;
    Status i;
	int n;//���������Ԫ�ظ���

	while(TRUE)
	{
		printf("1���������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L��ͷ�巨��\n");
		printf("2���������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L��β�巨��\n");
		printf("3�����ζ�L��ÿ������Ԫ�����\n");
		printf("4����L�е�i��λ��֮ǰ�����µ�����Ԫ��e\n");
		printf("5��ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ\n");
		printf("6����e����L�е�i������Ԫ�ص�ֵ\n");
		printf("7������L�е�1����e�����ϵ������Ԫ�ص�λ��\n");
		printf("0���˳�����\n");
		
		int order;
		printf("\n���������ѡ��");
		scanf("%d", &order);

		switch(order)
		{
		case 1:{
					printf("���������������Ԫ�ظ�����");
					scanf("%d", &n);
					CreateListHead(&L, n);
					if(!ListEmpty(L))
						printf("�����ɹ�!\n\n");
					break;
			   }
		case 2:{
					printf("���������������Ԫ�ظ�����");
					scanf("%d", &n);
					CreateListTail(&L, n);
					if(!ListEmpty(L))
						printf("�����ɹ�!\n\n");
					break;
			   }
		case 3:{
					ListTraverse(L);
					break;
			   }
		case 4:{	
					printf("������Ҫ�����Ԫ�ص�λ��i��dataֵe��");
					scanf("%d %d", &i,&e);
					if(ListInsert(&L, i, e))
						printf("����ɹ�!\n");
					else
						printf("����ʧ��!\n\n");
					printf("������L��");
					ListTraverse(L);
					printf("\n");
					break;
			   }
		case 5:{	
					printf("������Ҫɾ����Ԫ�ص�λ��i��");
					scanf("%d", &i);
					if(ListDelete(&L, i, &e))
						printf("ɾ���ɹ�!\n");
					else
						printf("ɾ��ʧ��!\n\n");
					printf("�����Ԫ��e = %d\n", e);
					printf("ɾ�����L��");
					ListTraverse(L);
					printf("\n");
					break;
			   }
		case 6:{
					printf("������i��");
					scanf("%d", &i);
					if(GetElem(L, i, &e))
						printf("L�е�%d��Ԫ�ص�ֵ��%d\n", i, e);
					else
						printf("����ʧ��!\n");
					break;
			   }
		case 7:{
					printf("������e��");
					scanf("%d", &e);
					if(LocateElem(L, e))
						printf("L�е�%d��Ԫ�ص�ֵ��%d\n", LocateElem(L, e), e);
					else
						printf("����ʧ��!\n");
					break;
			   }
		case 0:
					exit(0);
					break;
		default:
					printf("�����������������룺");
		}
	}
	
    return 0;
}

