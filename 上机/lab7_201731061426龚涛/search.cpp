#include "stdio.h"
#include "stdlib.h"
#define MAXSIZE 10
//补充代码
#define EQ(a,b) ((a)==(b))
#define LT(a,b) ((a)<(b))
#define LQ(a,b) ((a)<=(b))

typedef int elemtype;
typedef struct{
	elemtype elem[MAXSIZE];
	int length;
}SSTable;

void InitS(SSTable &ST){
	ST.length=0;
}

int Search_Seq(SSTable ST, elemtype key,int &i){
	//请编码完成在ST表中顺序查找关键字key，如果存在则返回其在表中位置，
	//不存在则返回0；同时通过参数i返回比较次数。
	ST.elem[0] = key;
	i = 0;
	for(int j = ST.length; !EQ(ST.elem[j], key); --j)
		i++;
	return j;
}

int Search_Bin(SSTable ST, elemtype key,int &i){
	//请编码完成在ST表中折半查找关键字key，如果存在返回其在表中位置，
	//不存在则返回0；同时通过参数i返回比较次数。
	int low, mid, high;
	low = 1;
	high = ST.length;
	i = 0;
	while(low<=high)
	{
		i++;
		mid = (low+high)/2;
		if(EQ(key, ST.elem[mid]))
			return mid;
		else if(LT(key, ST.elem[mid]))
			high = mid - 1;
		else
			low = mid + 1;
	}
	return 0;
}


void main()
{
	int i,m,key,k;
	SSTable ST;
	InitS(ST);
	printf("请依序（递增）输入表中元素关键字值（-1结束）：\n");
	scanf("%d",&m);
	while (m!=-1 && ST.length<MAXSIZE-1)
	{
	ST.elem[++ST.length]=m;
	scanf("%d",&m); 
	}
	printf("待查找序列为：");
	for(i=1;i<=ST.length;i++)
		printf("%d,",ST.elem[i]);
	printf("\n");
	printf("请输入查找关键字值：（-1表示结束查找）\n");
	scanf("%d",&key);
	while (key!=-1)
	{
	printf("\n顺序查找结果：\n");
	i=Search_Seq(ST,key,k);    //在表ST中顺序查找指定值key，返回其位置值给i，并通过参数k返回查找过程中进行的比较次数
	if (i!=0)
		printf("元素%d在表中的位置是%d,比较次数为%d\n",key,i,k);
	else
		printf("元素%d不在表中,比较次数为%d\n",key,k);

	printf("折半查找结果：\n");
	i=Search_Bin(ST,key,k);   //在表ST中折半查找指定值key，返回其位置值给i，并通过参数k返回查找过程中进行的比较次数
	if (i!=0)
		printf("元素%d在表中的位置是%d,比较次数为%d\n",key,i,k);
	else
		printf("元素%d不在表中,比较次数为%d\n",key,k);

	printf("\n请输入查找关键字值：（-1表示结束查找）\n");
	scanf("%d",&key);
	}
}
