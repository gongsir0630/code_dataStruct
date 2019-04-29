#include <stdlib.h>
#include <stdio.h>
typedef char BTElemType; //������������Ԫ������
//�������������
typedef struct BiTNode{
BTElemType data;
struct BiTNode *lchild, *rchild;    /*���Һ���ָ��*/
}BiTNode, *BiTree;

//����Ϊ��������ʽ�洢�ṹ�Ĳ�������
//���������������������ʽ��
void createbt (BiTree &bt) {
	//���´�����ѧ����д
	//������������������ֵ���ݹ鴴�����������������ַ�'#'ʱ����ա�
	BTElemType ch;
	scanf("%c", &ch);
	if(ch=='#')
		bt = NULL;
	else
	{
		if(!(bt = (BiTNode *)malloc(sizeof(BiTNode))))
			exit(0);
		bt->data = ch;
		createbt(bt->lchild);
		createbt(bt->rchild);
	}
	//���ϴ�����ѧ����д
}

//������
void visit(BiTree bt) {
printf("%5c", bt->data);
}
//�������
void PreOrder(BiTree bt) {
if(bt!=NULL) {
    	visit(bt);
        PreOrder(bt->lchild);
        PreOrder(bt->rchild);
    }
}

//�������
void InOrder(BiTree bt) {
	//���´�����ѧ����д
	//������ݹ���ʶ��������ֵ����ʾ
	if(bt!=NULL) {
        InOrder(bt->lchild);
		visit(bt);
        InOrder(bt->rchild);
    }
	//���ϴ�����ѧ����д
}

//�������
void PostOrder(BiTree bt) {
	//���´�����ѧ����д
	//������ݹ���ʶ��������ֵ����ʾ
	if(bt!=NULL) {
        PostOrder(bt->lchild);
        PostOrder(bt->rchild);
		visit(bt);
    }
	//���ϴ�����ѧ����д
}

//���³���β����ȸ������������������Ҷ����
void LeafCount(BiTree bt, int &count) { /*��ָ��Ϊbt���ٶ�Ҷ���� count �ĳ�ֵ = 0 */ 

  if (bt!=NULL) {
     if((bt->lchild==NULL) && (bt->rchild==NULL))
		 count++;
     LeafCount(bt->lchild,count);
	 LeafCount(bt->rchild,count);
  }
}
//��������������//
int Count(BiTree bt)
{
	if(bt==NULL)
		return 0;
	else
		return Count(bt->lchild) + Count(bt->rchild) + 1;
}
//������ʾ��
void main(void) {
	BiTree t;
	int count = 0;
	printf("��������������������ֵ����'#'��ʾ��ǰ���ֵΪ��):\n");
	createbt(t);
	printf("\n����������������Ϊ:\n");
	PreOrder(t);
	printf("\n����������������Ϊ:\n");;
	InOrder(t);
	printf("\n����������������Ϊ:\n");
	PostOrder(t);
	printf("\n�ö������Ľ������Ϊ:\n");
	Count(t);
	printf("%5d", Count(t));
	printf("\n�ö�������Ҷ����Ϊ:\n");
	LeafCount(t,count);
	printf("%5d", count);
	printf("\n");
}
