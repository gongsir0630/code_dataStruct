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
//-------- 线性表的基本运算 -----------------------------
//运算1：初始化空顺序表L
Status InitList(SqList &L){
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	L.length = 0;
	return OK;
}
//运算2：销毁顺序表L
void DestroyList(SqList &L){
	free(L.elem);
	L.elem = NULL;
	L.length = 0;
	L.listsize = 0;
}
//运算3：在顺序表L中第i个位置前插入新元素e
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
//运算4：显示顺序表元素
void print(SqList L){
	for(int i=1;i<=L.length;i++){
		printf("%5d",L.elem[i-1]);
	}
	printf("\n");
}
//运算5：删除L的第i个元素，并用e返回其值
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
//运算6：返回L中数据元素个数
int ListLength(SqList L)  { 
	return L.length;
}
//运算7：用e返回L中第i个元素的值
Status GetElem(SqList L,int i,ElemType &e) {
	if(i<1||i>L.length) return ERROR;
	e=L.elem[i-1];
	return OK;
}
//改写print函数
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
//查找函数：查找指定值在表中的位置
void LocateElem(SqList L, ElemType e){
	for(int i=1;i<=L.length;i++){
		if(e==L.elem[i-1])
			printf("Locate: %d\n", i);
	}
}
//主函数1
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

//主函数2
/*
void main(void) {
	SqList L; //声明顺序表变量
	InitList(L);
	ListInsert(L,1,10);
	ListInsert(L,2,20);
	ListInsert(L,4,30);
	ListInsert(L,5,40);
	print(L);
	DestroyList(L);
}
*/
//主函数3
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
	//****以下由学生给出实际代码****
	ListInsert(L, 2, 7);//在位置2插入整数7
	ListInsert(L, 5, 5);//在位置5插入整数5
	ListInsert(L, 1, 3);//在位置1插入整数3
	ListInsert(L, 2, 1);//在位置2插入整数1
	//****以上由学生给出实际代码****
	printf("%d\n", L.length);
	print_1(L);                      //顺序表的第1次显示
	//****以下由学生给出实际代码****
	ListDelete(L,2,e);//删除位置2的元素
	ListDelete(L,3,e);//删除位置3的元素
	ListDelete(L,5,e);//删除位置5的元素
	//****以上由学生给出实际代码****
	printf("%d\n", L.length);
	print_1(L);                     //顺序表的第2次显示
	LocateElem(L, 30);
	DestroyList(L);
}



