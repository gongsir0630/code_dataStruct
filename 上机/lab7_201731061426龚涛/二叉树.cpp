#include <iostream> 
static int i = 0;

typedef struct BitNode{
   int data;
   struct BitNode *lchild, *rchild; 
}BitNode, *BiTree;

bool BSTInsert(BitNode * &p, int element)  
{  
    if(NULL == p) // 空树  
    {  
        p = new BitNode;  
        p->data = element;  
        p->lchild = p->rchild = NULL;  
        return true;  
    }  

    if(element == p->data) // BST中不能有相等的值  
        return false;  

    if(element < p->data)  // 递归  
        return BSTInsert(p->lchild, element);  

    return BSTInsert(p->rchild, element); // 递归  
}  

void createBst(BitNode * &T, int a[], int n){
    T = NULL;
    int i;
    for(i = 0; i < n; i++){
        BSTInsert(T, a[i]);
    }
}

//查找
void searchBst(BiTree T, int key){
    //记录第几次查找到 
    ++i; 
    if(T){
        if(key == T->data){
            printf("第%d次查询\n", i);
            printf("查得：%d", T->data);
        } else if(key < T->data)
            searchBst(T->lchild, key);
        else 
            searchBst(T->rchild, key);
    }
}

//中序遍历
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
	printf("请输入10个数据:\n");
	for(int i =0; i<10; i++)
		scanf("%d", &a[i]);
    BiTree T;
	printf("正在建立二叉树......\n");
    createBst(T, a, 10);

    printf("中序遍历结果:\n");
    inOrderTraverse(T);
	printf("\n");
	int x;
	printf("请输入你想查找的数据:\n");
	scanf("%d", &x);
	searchBst(T, x);
	printf("\n");


    return 0;
}