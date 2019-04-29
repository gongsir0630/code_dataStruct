#include "stdio.h"
#include "stdlib.h"
#define MAXSIZE 10
//�������
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
	//����������ST����˳����ҹؼ���key����������򷵻����ڱ���λ�ã�
	//�������򷵻�0��ͬʱͨ������i���رȽϴ�����
	ST.elem[0] = key;
	i = 0;
	for(int j = ST.length; !EQ(ST.elem[j], key); --j)
		i++;
	return j;
}

int Search_Bin(SSTable ST, elemtype key,int &i){
	//����������ST�����۰���ҹؼ���key��������ڷ������ڱ���λ�ã�
	//�������򷵻�0��ͬʱͨ������i���رȽϴ�����
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
	printf("�����򣨵������������Ԫ�عؼ���ֵ��-1��������\n");
	scanf("%d",&m);
	while (m!=-1 && ST.length<MAXSIZE-1)
	{
	ST.elem[++ST.length]=m;
	scanf("%d",&m); 
	}
	printf("����������Ϊ��");
	for(i=1;i<=ST.length;i++)
		printf("%d,",ST.elem[i]);
	printf("\n");
	printf("��������ҹؼ���ֵ����-1��ʾ�������ң�\n");
	scanf("%d",&key);
	while (key!=-1)
	{
	printf("\n˳����ҽ����\n");
	i=Search_Seq(ST,key,k);    //�ڱ�ST��˳�����ָ��ֵkey��������λ��ֵ��i����ͨ������k���ز��ҹ����н��еıȽϴ���
	if (i!=0)
		printf("Ԫ��%d�ڱ��е�λ����%d,�Ƚϴ���Ϊ%d\n",key,i,k);
	else
		printf("Ԫ��%d���ڱ���,�Ƚϴ���Ϊ%d\n",key,k);

	printf("�۰���ҽ����\n");
	i=Search_Bin(ST,key,k);   //�ڱ�ST���۰����ָ��ֵkey��������λ��ֵ��i����ͨ������k���ز��ҹ����н��еıȽϴ���
	if (i!=0)
		printf("Ԫ��%d�ڱ��е�λ����%d,�Ƚϴ���Ϊ%d\n",key,i,k);
	else
		printf("Ԫ��%d���ڱ���,�Ƚϴ���Ϊ%d\n",key,k);

	printf("\n��������ҹؼ���ֵ����-1��ʾ�������ң�\n");
	scanf("%d",&key);
	}
}
