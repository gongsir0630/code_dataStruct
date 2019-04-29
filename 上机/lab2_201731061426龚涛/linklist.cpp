#include "global.h"
#include "linklist.h"
// �������������һ�������� L
LinkList InitList(void) {
	LinkList L;
	L=(LinkList)malloc(sizeof(LNode));//��ͷ���
	if(!L) return NULL; // �洢����ʧ��
	L->next=NULL; // �ձ�
	return L;
}
// ��ʼ���������� L �Ѵ��ڡ������������������ L
Status DestoryList(LinkList &L) {
	LinkList q;
	while (  L  ) {//�ӱ�ͷ��㿪ʼ�ͷ�
		q=L->next;//Ԥ��ǰ�е���һ���
		free(L);
		L=q;//����ָ�������һ���
	}
	return OK;
}
// �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e
Status ListInsert(LinkList &L,int i,ElemType e) {
	//****������ѧ������ʵ�ʴ���****
	//��L�е�i��λ��֮ǰ�����µ�����Ԫ��e���ɹ�����OK��ʧ�ܷ���ERROR
	int j = 0;	//��������ֵΪ��
	LinkList s, p = L;	//pָ��ͷ���
	while(p && j<i-1){	//Ѱ�ҵ�i-1�����
		j++;	//������+1
		p = p->next;//pָ����һ�����
	}
	if(!p || j>i-1)	//i<1���ߴ��ڱ�
		return ERROR;	//����ʧ��
	s = (LinkList)malloc(sizeof(LNode));	//�����½ڵ㣬���½������L��
	s->data = e;	//��e��ֵ���½��
	s->next = p->next;	//�½��ָ��ԭ��i�����
	p->next = s;	//ԭ��i-1�����ָ���½��
	return OK;	//����ɹ�
	//****������ѧ������ʵ�ʴ���****
}
//ɾ���������е� i ��Ԫ��
Status ListDelete(LinkList &L,int i,ElemType &e)  {
	//****������ѧ������ʵ�ʴ���****
	//ɾ���������е� i ��Ԫ�أ�����ɾ��Ԫ��ֵͨ��e���ء����ɾ���ɹ�����������OK�����򷵻�ERROR
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
	//****������ѧ������ʵ�ʴ���****
}
// ��ʼ���������Ա� L �Ѵ��ڡ�������������� L ������Ԫ�ظ���
int ListLength(LinkList L) {
	int i;    LinkList p;
	i=0;
	p=L->next;
	while(p) {   i++;    p=p->next;   }
	return i;
}
// ��ʼ���������Ա�L�Ѵ��ڡ������������e����L�е�i������Ԫ�ص�ֵ
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

// �������������L�е�1����e��ȵ�����Ԫ�ص�λ��������������Ԫ�ز����ڣ��򷵻�ֵΪ0
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

//���������
Status PrintList(LinkList L) {
	//****������ѧ������ʵ�ʴ���****
	//˳����ʾ���������L�е���������Ԫ��ֵ��Ԫ��֮���ÿո����
	LinkList p = L->next;
	while(p)
	{
		printf("%s ", p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
	//****������ѧ������ʵ�ʴ���****
}

LinkList MergeList (LinkList La, LinkList Lb)
{                                                                                                              
	//��֪�������Ա�la��lb��ֵ�ǵݼ�����
	//�鲢la,lb��Ԫ�أ�Ҳ���ǵݼ�����
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
