#include "global.h"
#include "linklist.h"
// 操作结果：构造一个空链表 L
LinkList InitList(void) {
	LinkList L;
	L=(LinkList)malloc(sizeof(LNode));//表头结点
	if(!L) return NULL; // 存储分配失败
	L->next=NULL; // 空表
	return L;
}
// 初始条件：链表 L 已存在。操作结果：销毁链表 L
Status DestoryList(LinkList &L) {
	LinkList q;
	while (  L  ) {//从表头结点开始释放
		q=L->next;//预先前行到下一结点
		free(L);
		L=q;//工作指针跟踪下一结点
	}
	return OK;
}
// 操作结果：在L中第i个位置之前插入新的数据元素e
Status ListInsert(LinkList &L,int i,ElemType e) {
	//****以下由学生给出实际代码****
	//在L中第i个位置之前插入新的数据元素e，成功返回OK，失败返回ERROR
	int j = 0;	//计数器初值为零
	LinkList s, p = L;	//p指向头结点
	while(p && j<i-1){	//寻找第i-1个结点
		j++;	//计数器+1
		p = p->next;//p指向下一个结点
	}
	if(!p || j>i-1)	//i<1或者大于表长
		return ERROR;	//插入失败
	s = (LinkList)malloc(sizeof(LNode));	//生成新节点，以下将其插入L中
	s->data = e;	//将e赋值给新结点
	s->next = p->next;	//新结点指向原第i个结点
	p->next = s;	//原第i-1个结点指向新结点
	return OK;	//插入成功
	//****以上由学生给出实际代码****
}
//删除单链表中第 i 个元素
Status ListDelete(LinkList &L,int i,ElemType &e)  {
	//****以下由学生给出实际代码****
	//删除单链表中第 i 个元素，并将删除元素值通过e返回。如果删除成功，函数返回OK，否则返回ERROR
	int j=0;
	LinkList q, p = L;
	while(p->next && j<i-1){
		j++;
		p = p->next;
	}
	if(!p->next || j>i-1)
		return ERROR;
	q = p->next;
	p->next = q->next;
	e = q->data;
	free(q);
	return OK;
	//****以上由学生给出实际代码****
}
// 初始条件：线性表 L 已存在。操作结果：返回 L 中数据元素个数
int ListLength(LinkList L) {
	int i;    LinkList p;
	i=0;
	p=L->next;
	while(p) {   i++;    p=p->next;   }
	return i;
}
// 初始条件：线性表L已存在。操作结果：用e返回L中第i个数据元素的值
Status GetElem (LinkList L,int i,ElemType &e) { 
	int j;  LinkList p;
	j=1;
	p=L->next;
	while ( p && j<i ) {
		p=p->next;
		j++;
	}
	if (!p || j>i ) return ERROR; 
	e=p->data;
	return OK;
}

// 操作结果：返回L中第1个与e相等的数据元素的位序。若这样的数据元素不存在，则返回值为0
int LocateElem(LinkList L,ElemType e) {
	int i; LinkList p;
	i=0;
	p=L->next;
	while(p) {
		i++;
		if(!strcmp (p->data, e)) return i;
		p=p->next;
	}
	return 0;
}

//输出单链表
Status PrintList(LinkList L) {
	//****以下由学生给出实际代码****
	//顺序显示输出单链表L中的所有数据元素值，元素之间用空格隔开
	LinkList p = L->next;
	while(p)
	{
		printf("%s ", p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
	//****以上由学生给出实际代码****
}

LinkList MergeList (LinkList La, LinkList Lb)
{                                                                                                              
	//已知单链线性表la，lb按值非递减排列
	//归并la,lb的元素，也按非递减排列
	LinkList Lc;
	LinkList pa = La->next, pb = Lb->next, pc;
	Lc = pc = La;
	while(pa && pb)
	{
		if(strcmp(pa->data,pb->data)<=0)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}

	pc->next = pa?pa:pb;
	free(Lb);
	Lb = NULL;

	return Lc;
}
