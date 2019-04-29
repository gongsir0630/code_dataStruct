#include <malloc.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define OK 1
#define ERROR 0
typedef int Status;

#define LIST_INIT_SIZE 100
#define LIST_INCREMENT 10
typedef int ElemType;

typedef struct{
	ElemType *elem;
	int length;
	int listsize;
}SqList;
//-------- ���Ա�Ļ������� -----------------------------
//����1����ʼ����˳���L
Status InitList(SqList &L){
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	L.length = 0;
	return OK;
}
//����2������˳���L
void DestroyList(SqList &L){
	free(L.elem);
	L.elem = NULL;
	L.length = 0;
	L.listsize = 0;
}
//����3����˳���L�е�i��λ��ǰ������Ԫ��e
Status ListInsert(SqList &L, int i, ElemType e){
	ElemType *newbase;
	if(i<1 || i>L.length+1)return ERROR;
	if(L.length>=L.listsize){
		newbase = (ElemType *)realloc(L.elem,(L.listsize+LIST_INCREMENT)*sizeof(ElemType));
		if(!newbase)
			return OVERFLOW;
		L.elem = newbase;
		L.listsize += LIST_INCREMENT;
	}
	for(int j=L.length-1;j>=i-1;j--)
		L.elem[j+1] = L.elem[j];
	L.elem[i-1] = e;
	++L.length;
	return OK;
}
//����4����ʾ˳���Ԫ��
void print(SqList L){
	for(int i=1;i<=L.length;i++){
		printf("%5d",L.elem[i-1]);
	}
	printf("\n");
}
//����5��ɾ��L�ĵ�i��Ԫ�أ�����e������ֵ
Status ListDelete(SqList &L,int i,ElemType &e)  {
	ElemType *p, *q;
	if(i<1 || i>L.length)
		return ERROR;
	p = &L.elem[i-1];
	e = *p;
	q = L.elem + L.length - 1;
	for(++p;p<=q;++p)
		*(p-1) = *p;
	--L.length;
	return OK;
}
//����6������L������Ԫ�ظ���
int ListLength(SqList L)  { 
	return L.length;
}
//����7����e����L�е�i��Ԫ�ص�ֵ
Status GetElem(SqList L,int i,ElemType &e) {
	if(i<1||i>L.length) return ERROR;
	e=L.elem[i-1];
	return OK;
}
//��дprint����
void print_1(SqList L){
	int i;
	ElemType e;
	
	for(i=1;i<=L.length;i++)
	{
		GetElem(L,i,e);
		printf("%5d", e);
	}
	printf("\n");
}
//���Һ���������ָ��ֵ�ڱ��е�λ��
void LocateElem(SqList L, ElemType e){
	for(int i=1;i<=L.length;i++){
		if(e==L.elem[i-1])
			printf("Locate: %d\n", i);
	}
}
//������1
/*
void main(){
	SqList L;
	InitList(L);
	ListInsert(L,1,10);
	ListInsert(L,2,20);
	ListInsert(L,3,30);
	ListInsert(L,4,40);
	print(L);
	DestroyList(L);
}
*/

//������2
/*
void main(void) {
	SqList L; //����˳������
	InitList(L);
	ListInsert(L,1,10);
	ListInsert(L,2,20);
	ListInsert(L,4,30);
	ListInsert(L,5,40);
	print(L);
	DestroyList(L);
}
*/
//������3
void main(void) {
	SqList L;
	ElemType e;
	InitList(L);
	ListInsert(L, 1, 10);
	ListInsert(L, 2, 20);
	ListInsert(L, 3, 30);
	ListInsert(L, 4, 40);
	printf("%d\n", L.length);
	print_1(L);   
	//****������ѧ������ʵ�ʴ���****
	ListInsert(L, 2, 7);//��λ��2��������7
	ListInsert(L, 5, 5);//��λ��5��������5
	ListInsert(L, 1, 3);//��λ��1��������3
	ListInsert(L, 2, 1);//��λ��2��������1
	//****������ѧ������ʵ�ʴ���****
	printf("%d\n", L.length);
	print_1(L);                      //˳���ĵ�1����ʾ
	//****������ѧ������ʵ�ʴ���****
	ListDelete(L,2,e);//ɾ��λ��2��Ԫ��
	ListDelete(L,3,e);//ɾ��λ��3��Ԫ��
	ListDelete(L,5,e);//ɾ��λ��5��Ԫ��
	//****������ѧ������ʵ�ʴ���****
	printf("%d\n", L.length);
	print_1(L);                     //˳���ĵ�2����ʾ
	LocateElem(L, 30);
	DestroyList(L);
}



