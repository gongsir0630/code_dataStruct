/*
�Էֱ���˳���͵��������洢�ṹ����дһ��ʵ�����Ա�ľ͵�(��ʹ�þ������ٵĸ��ӿռ�)���õ��㷨.
*/
//��������
typedef struct SqList{
	ElemType *elem;
	int length;
	int listsize;
}SqList;
//˳��������㷨
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
//���Ա������㷨
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