#include "global.h"
#include "linklist.h"
#define Num 5 //�����������
#if(0)
void main(void) {
LinkList L;  ElemType e;  int i;
	L=InitList();
	//����΢ٿ�ʼ
	for(i=1;i<=Num;i++) {
		e=(char *)malloc(sizeof(char * ));
		scanf("%s", e);
		ListInsert(L, i, e);
	}
	//����΢ٽ���
	printf("%d\n", ListLength(L));   PrintList(L);
#if(1)
	//****������ѧ������ʵ�ʴ���****
	ListInsert(L, 2, "first");//��λ��2�����ַ���"first"
	ListInsert(L, 5, "second");//��λ��5�����ַ���"second"
	//****������ѧ������ʵ�ʴ���****
	printf("%d\n", ListLength(L));   PrintList(L);
	//****������ѧ������ʵ�ʴ���****
	ListDelete(L, 3, e);//ɾ��λ��3�Ľ��
	ListDelete(L, 10, e);//ɾ��λ��10�Ľ��
	//****������ѧ������ʵ�ʴ���****
	printf("%d\n", ListLength(L));
	PrintList(L); 
#endif
	//���Բ����㷨
	char str1[10];
	char *str2 = "#";
	
	while(1)
	{
		printf("Please input the elem you want to find:\n");
		scanf("%s", str1);
		if(strcmp(str1,str2))
		{
			printf("The locate: %d\n", LocateElem(L, str1));
		}
		else
		{
			printf("Locate finish!\n");
			goto Next;
		}
	}
Next:
	DestoryList(L);
}
#endif

//������2
#if(1)
void main(void){
	LinkList La, Lb, Lc;
	int i;
	ElemType e;
	La=InitList();
	Lb=InitList();
	
	printf("input La:\n");
	for(i=1;i<=Num;i++) {
		e=(char *)malloc(sizeof(char * ));
		scanf("%s", e);
		ListInsert(La, i, e);
	}

	printf("input Lb:\n");
	for(i=1;i<=Num;i++) {
		e=(char *)malloc(sizeof(char * ));
		scanf("%s", e);
		ListInsert(Lb, i, e);
	}
	printf("\nthe result:\n\n");
	printf("La: ");		PrintList(La);
	printf("\n");
	printf("Lb: ");		PrintList(Lb);
	Lc = MergeList (La, Lb);	//�鲢
	printf("\nLc: ");		PrintList(Lc);
	
	DestoryList(Lc);
}
#endif
