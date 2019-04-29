/*
试分别以顺序表和单链表作存储结构，各写一个实现线性表的就地(即使用尽可能少的附加空间)逆置的算法.
*/
//定义类型
typedef struct SqList{
	ElemType *elem;
	int length;
	int listsize;
}SqList;
//顺序表逆置算法
void invert S(SqList &L){
	ElemType data;
	int i;
	for(i=0;i<L.length/2;i++)
	{
		data = L.elem[i];
		L.elem[i] = L.elem[L.length-1-i];
		L.elem[L.length-1-i] = data;
	}
}
//线性表逆置算法
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

void invert L(LinkList &L){
	LinkList p,q,first = L;
	p = first->next;
	q = p->next;
	p->next = NULL;
	while(q!=NULL){
		p = q;
		q = q->next;
		p->next = first->next;
		first->next = p;
	}
}