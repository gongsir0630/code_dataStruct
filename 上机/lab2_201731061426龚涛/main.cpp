#include "global.h"
#include "linklist.h"
#define Num 5 //单链表结点个数
#if(0)
void main(void) {
LinkList L;  ElemType e;  int i;
	L=InitList();
	//代码段①开始
	for(i=1;i<=Num;i++) {
		e=(char *)malloc(sizeof(char * ));
		scanf("%s", e);
		ListInsert(L, i, e);
	}
	//代码段①结束
	printf("%d\n", ListLength(L));   PrintList(L);
#if(1)
	//****以下由学生给出实际代码****
	ListInsert(L, 2, "first");//在位置2插入字符串"first"
	ListInsert(L, 5, "second");//在位置5插入字符串"second"
	//****以上由学生给出实际代码****
	printf("%d\n", ListLength(L));   PrintList(L);
	//****以下由学生给出实际代码****
	ListDelete(L, 3, e);//删除位置3的结点
	ListDelete(L, 10, e);//删除位置10的结点
	//****以上由学生给出实际代码****
	printf("%d\n", ListLength(L));
	PrintList(L); 
#endif
	//测试查找算法
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

//主函数2
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
	Lc = MergeList (La, Lb);	//归并
	printf("\nLc: ");		PrintList(Lc);
	
	DestoryList(Lc);
}
#endif
