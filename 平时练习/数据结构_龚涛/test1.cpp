/*时间：2018-7-9 19:21:21
作者：龚涛
程序功能：单链表的基本操作
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

#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status;/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;/* ElemType类型根据实际情况而定，这里假设为int */

/* 定义LinkList */
typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node;
typedef struct Node *LinkList;

//输出
Status visit(ElemType c)
{
    printf("%d ",c);
    return OK;
}

/* 初始化顺序线性表 */
Status InitList(LinkList *L) 
{ 
    *L=(LinkList)malloc(sizeof(Node)); /* 产生头结点,并使L指向此头结点 */
    if(!(*L)) /* 存储分配失败 */
		return ERROR;
    (*L)->next=NULL; /* 指针域为空 */
	
    return OK;
}

//判断线性表是否为空
/* 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
Status ListEmpty(LinkList L)
{ 
    if(L->next)
		return FALSE;
    else
		return TRUE;
}

//将线性表置空
/* 初始条件：顺序线性表L已存在。操作结果：将L重置为空表 */
Status ClearList(LinkList *L)
{ 
	LinkList p,q;
	p=(*L)->next;           /*  p指向第一个结点 */
	while(p)                /*  没到表尾 */
	{
		q=p->next;
		free(p);
		p=q;
	}
	(*L)->next=NULL;        /* 头结点指针域为空 */
	return OK;
}

/* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
int ListLength(LinkList L)
{
    int i=0;
    LinkList p=L->next; /* p指向第一个结点 */
    while(p)                        
    {
        i++;
        p=p->next;
    }
    return i;
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：用e返回L中第i个数据元素的值 */
Status GetElem(LinkList L,int i,ElemType *e)
{
	int j;
	LinkList p;		/* 声明一结点p */
	p = L->next;		/* 让p指向链表L的第一个结点 */
	j = 1;		/*  j为计数器 */
	while (p && j<i)  /* p不为空或者计数器j还没有等于i时，循环继续 */
	{   
		p = p->next;  /* 让p指向下一个结点 */
		++j;
	}
	if ( !p || j>i ) 
		return ERROR;  /*  第i个元素不存在 */
	*e = p->data;   /*  取第i个元素的数据 */
	return OK;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：返回L中第1个与e满足关系的数据元素的位置。 */
/* 若这样的数据元素不存在，则返回值为0 */
int LocateElem(LinkList L,ElemType e)
{
    int i=0;
    LinkList p=L->next;
    while(p)
    {
        i++;
        if(p->data==e) /* 找到这样的数据元素 */
			return i;
        p=p->next;
    }
	
    return 0;
}


/* 初始条件：顺序线性表L已存在,1≤i≤ListLength(L)， */
/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
Status ListInsert(LinkList *L,int i,ElemType e)
{ 
	int j;
	LinkList p,s;
	p = *L;   
	j = 1;
	while (p && j < i)     /* 寻找第i个结点 */
	{
		p = p->next;
		++j;
	} 
	if (!p || j > i) 
		return ERROR;   /* 第i个元素不存在 */
	s = (LinkList)malloc(sizeof(Node));  /*  生成新结点(C语言标准函数) */
	s->data = e;  
	s->next = p->next;      /* 将p的后继结点赋值给s的后继  */
	p->next = s;          /* 将s赋值给p的后继 */
	return OK;
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
Status ListDelete(LinkList *L,int i,ElemType *e) 
{ 
	int j;
	LinkList p,q;
	p = *L;
	j = 1;
	while (p->next && j < i)	/* 遍历寻找第i个元素 */
	{
        p = p->next;
        ++j;
	}
	if (!(p->next) || j > i) 
		return ERROR;           /* 第i个元素不存在 */
	q = p->next;
	p->next = q->next;			/* 将q的后继赋值给p的后继 */
	*e = q->data;               /* 将q结点中的数据给e */
	free(q);                    /* 让系统回收此结点，释放内存 */
	return OK;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
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

/*  随机产生n个元素的值，建立带表头结点的单链线性表L（头插法） */
void CreateListHead(LinkList *L, int n) 
{
	LinkList p;
	int i;
	srand(time(0));                         /* 初始化随机数种子 */
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;                      /*  先建立一个带头结点的单链表 */
	for (i=0; i<n; i++) 
	{
		p = (LinkList)malloc(sizeof(Node)); /*  生成新结点 */
		p->data = rand()%100+1;             /*  随机生成100以内的数字 */
		p->next = (*L)->next;    
		(*L)->next = p;						/*  插入到表头 */
	}
}

/*  随机产生n个元素的值，建立带表头结点的单链线性表L（尾插法） */
void CreateListTail(LinkList *L, int n) 
{
	LinkList p,r;
	int i;
	srand(time(0));                      /* 初始化随机数种子 */
	*L = (LinkList)malloc(sizeof(Node)); /* L为整个线性表 */
	r=*L;                                /* r为指向尾部的结点 */
	for (i=0; i<n; i++) 
	{
		p = (Node *)malloc(sizeof(Node)); /*  生成新结点 */
		p->data = rand()%100+1;           /*  随机生成100以内的数字 */
		r->next=p;                        /* 将表尾终端结点的指针指向新结点 */
		r = p;                            /* 将当前的新结点定义为表尾终端结点 */
	}
	r->next = NULL;                       /* 表示当前链表结束 */
}
//主函数
int main()
{        
    LinkList L;
    ElemType e;
    Status i;
	int n;//随机产生的元素个数

	while(TRUE)
	{
		printf("1、随机产生n个元素的值，建立带表头结点的单链线性表L（头插法）\n");
		printf("2、随机产生n个元素的值，建立带表头结点的单链线性表L（尾插法）\n");
		printf("3、依次对L的每个数据元素输出\n");
		printf("4、在L中第i个位置之前插入新的数据元素e\n");
		printf("5、删除L的第i个数据元素，并用e返回其值\n");
		printf("6、用e返回L中第i个数据元素的值\n");
		printf("7、返回L中第1个与e满足关系的数据元素的位置\n");
		printf("0、退出程序\n");
		
		int order;
		printf("\n请输入你的选择：");
		scanf("%d", &order);

		switch(order)
		{
		case 1:{
					printf("请输入随机产生的元素个数：");
					scanf("%d", &n);
					CreateListHead(&L, n);
					if(!ListEmpty(L))
						printf("创建成功!\n\n");
					break;
			   }
		case 2:{
					printf("请输入随机产生的元素个数：");
					scanf("%d", &n);
					CreateListTail(&L, n);
					if(!ListEmpty(L))
						printf("创建成功!\n\n");
					break;
			   }
		case 3:{
					ListTraverse(L);
					break;
			   }
		case 4:{	
					printf("请输入要插入的元素的位置i和data值e：");
					scanf("%d %d", &i,&e);
					if(ListInsert(&L, i, e))
						printf("插入成功!\n");
					else
						printf("插入失败!\n\n");
					printf("插入后的L：");
					ListTraverse(L);
					printf("\n");
					break;
			   }
		case 5:{	
					printf("请输入要删除的元素的位置i：");
					scanf("%d", &i);
					if(ListDelete(&L, i, &e))
						printf("删除成功!\n");
					else
						printf("删除失败!\n\n");
					printf("输出的元素e = %d\n", e);
					printf("删除后的L：");
					ListTraverse(L);
					printf("\n");
					break;
			   }
		case 6:{
					printf("请输入i：");
					scanf("%d", &i);
					if(GetElem(L, i, &e))
						printf("L中第%d个元素的值是%d\n", i, e);
					else
						printf("查找失败!\n");
					break;
			   }
		case 7:{
					printf("请输入e：");
					scanf("%d", &e);
					if(LocateElem(L, e))
						printf("L中第%d个元素的值是%d\n", LocateElem(L, e), e);
					else
						printf("查找失败!\n");
					break;
			   }
		case 0:
					exit(0);
					break;
		default:
					printf("输入有误，请重新输入：");
		}
	}
	
    return 0;
}

