#include <iostream> 
static int i = 0;

typedef struct BitNode{
   int data;
   struct BitNode *lchild, *rchild; 
}BitNode, *BiTree;

bool BSTInsert(BitNode * &p, int element)  
{  
    if(NULL == p) // ����  
    {  
        p = new BitNode;  
        p->data = element;  
        p->lchild = p->rchild = NULL;  
        return true;  
    }  

    if(element == p->data) // BST�в�������ȵ�ֵ  
        return false;  

    if(element < p->data)  // �ݹ�  
        return BSTInsert(p->lchild, element);  

    return BSTInsert(p->rchild, element); // �ݹ�  
}  

void createBst(BitNode * &T, int a[], int n){
    T = NULL;
    int i;
    for(i = 0; i < n; i++){
        BSTInsert(T, a[i]);
    }
}

//����
void searchBst(BiTree T, int key){
    //��¼�ڼ��β��ҵ� 
    ++i; 
    if(T){
        if(key == T->data){
            printf("��%d�β�ѯ\n", i);
            printf("��ã�%d", T->data);
        } else if(key < T->data)
            searchBst(T->lchild, key);
        else 
            searchBst(T->rchild, key);
    }
}

//�������
void inOrderTraverse(BiTree T)  
{  
    if(T)  
    {  
        inOrderTraverse(T->lchild);  
        printf("%d ", T->data);
        inOrderTraverse(T->rchild);  
    }  
}  

int main(){
    int a[10];
	printf("������10������:\n");
	for(int i =0; i<10; i++)
		scanf("%d", &a[i]);
    BiTree T;
	printf("���ڽ���������......\n");
    createBst(T, a, 10);

    printf("����������:\n");
    inOrderTraverse(T);
	printf("\n");
	int x;
	printf("������������ҵ�����:\n");
	scanf("%d", &x);
	searchBst(T, x);
	printf("\n");


    return 0;
}