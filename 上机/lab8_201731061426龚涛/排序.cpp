#include <stdio.h>  
#include <stdlib.h>  
#include <time.h> 
#define N 5  //����������������

typedef struct{
	int r[N+1];
	int length;
}SqList;

//ֱ�Ӳ�������
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
//ֱ��ѡ������
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
//ð������1
void bubble1(SqList &L) {
	int i,j,k;
	for (i=1; i<L.length; i++) {
		for (j=1; j<=L.length-i; j++)
			if(L.r[j]>L.r[j+1]) {L.r[0]=L.r[j];  L.r[j]=L.r[j+1];  L.r[j+1]=L.r[0];}
		for (k=1; k<=L.length; k++) printf("%5d", L.r[k]);
		printf("\n");
	}
}
//ð������2
void bubble2(SqList &L) {
	int i,j,k,Exchange;
	for (i=1; i<L.length; i++) {
		Exchange=0;
		for (j=1; j<=L.length-i; j++)
			if(L.r[j]>L.r[j+1]) {L.r[0]=L.r[j];  L.r[j]=L.r[j+1];  L.r[j+1]=L.r[0];  Exchange=1;}
			if (Exchange==0) return;  //���ĳ��ð��������û��Ԫ�ؽ��������������������
		for (k=1; k<=L.length; k++) printf("%5d", L.r[k]);
		printf("\n");
	}
}

void main(void) {
	SqList L;
	int i;
	srand(time(0));//��ϵͳʱ����Ϊ���������
	printf("��������:\n");
	for (i=1; i<=N; i++)
		scanf("%d",&L.r[i]);
	L.length=N;
	printf("����ǰ���У�");
	for (i=1; i<=L.length; i++) printf("%5d", L.r[i]);  //�������ǰ������
	printf("\n");
	//������ѧ��д�������㷨�ĵ��ô���
	bubble2(L);
	//������ѧ��д�������㷨�ĵ��ô���
	printf("��������У�\n");
	//for (i=1; i<=L.length; i++) printf("%5d", L.r[i]); //�������������
	//insertion(L);
	//selection(L);
	//bubble1(L);
	bubble2(L);
	printf("\n");
}
