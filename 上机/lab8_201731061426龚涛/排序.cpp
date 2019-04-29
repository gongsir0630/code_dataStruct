#include <stdio.h>  
#include <stdlib.h>  
#include <time.h> 
#define N 5  //最大排序数据项个数

typedef struct{
	int r[N+1];
	int length;
}SqList;

//直接插入排序
void insertion(SqList &L) { 
	int i,j,k;
	for (i=2; i<=L.length; i++)
	{
		if(L.r[i]<L.r[i-1])
		{
			L.r[0]=L.r[i];
			L.r[i]=L.r[i-1];
			for (j=i-2; L.r[0]<L.r[j];j--)
				L.r[j+1]=L.r[j];
			L.r[j+1]=L.r[0];
		}
		for (k=1; k<=L.length; k++) printf("%5d", L.r[k]);
		printf("\n");
	}
}
//直接选择排序
void selection (SqList &L) {
	int i, j, k, min;
	for (i=1; i<L.length; i++) {
		min = i; 
		for (j = i+1; j <=L.length; j++)  
			if (L.r[j]<L.r[min] ) min=j;		
			if(i!=min) {L.r[0]=L.r[i];  L.r[i]=L.r[min];  L.r[min]=L.r[0];}
		for (k=1; k<=L.length; k++) printf("%5d", L.r[k]);
		printf("\n");
	}
}
//冒泡排序1
void bubble1(SqList &L) {
	int i,j,k;
	for (i=1; i<L.length; i++) {
		for (j=1; j<=L.length-i; j++)
			if(L.r[j]>L.r[j+1]) {L.r[0]=L.r[j];  L.r[j]=L.r[j+1];  L.r[j+1]=L.r[0];}
		for (k=1; k<=L.length; k++) printf("%5d", L.r[k]);
		printf("\n");
	}
}
//冒泡排序2
void bubble2(SqList &L) {
	int i,j,k,Exchange;
	for (i=1; i<L.length; i++) {
		Exchange=0;
		for (j=1; j<=L.length-i; j++)
			if(L.r[j]>L.r[j+1]) {L.r[0]=L.r[j];  L.r[j]=L.r[j+1];  L.r[j+1]=L.r[0];  Exchange=1;}
			if (Exchange==0) return;  //如果某趟冒泡排序中没有元素交换，则表明已整体有序
		for (k=1; k<=L.length; k++) printf("%5d", L.r[k]);
		printf("\n");
	}
}

void main(void) {
	SqList L;
	int i;
	srand(time(0));//用系统时间作为随机数种子
	printf("输入数字:\n");
	for (i=1; i<=N; i++)
		scanf("%d",&L.r[i]);
	L.length=N;
	printf("排序前序列：");
	for (i=1; i<=L.length; i++) printf("%5d", L.r[i]);  //输出排序前的数列
	printf("\n");
	//以下由学生写入排序算法的调用代码
	bubble2(L);
	//以上由学生写入排序算法的调用代码
	printf("排序后序列：\n");
	//for (i=1; i<=L.length; i++) printf("%5d", L.r[i]); //输出排序后的数列
	//insertion(L);
	//selection(L);
	//bubble1(L);
	bubble2(L);
	printf("\n");
}
