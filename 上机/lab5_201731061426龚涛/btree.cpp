#include <stdlib.h>
#include <stdio.h>
typedef char BTElemType; //二叉树的数据元素类型
//二叉树结点类型
typedef struct BiTNode{
BTElemType data;
struct BiTNode *lchild, *rchild;    /*左右孩子指针*/
}BiTNode, *BiTree;

//以下为二叉树链式存储结构的操作函数
//创建二叉树（先序遍历方式）
void createbt (BiTree &bt) {
	//以下代码由学生编写
	//按先序输入二叉树结点值，递归创建二叉链表。当输入字符'#'时代表空。
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
	//以上代码由学生编写
}

//结点访问
void visit(BiTree bt) {
printf("%5c", bt->data);
}
//先序遍历
void PreOrder(BiTree bt) {
if(bt!=NULL) {
    	visit(bt);
        PreOrder(bt->lchild);
        PreOrder(bt->rchild);
    }
}

//中序遍历
void InOrder(BiTree bt) {
	//以下代码由学生编写
	//按中序递归访问二叉树结点值并显示
	if(bt!=NULL) {
        InOrder(bt->lchild);
		visit(bt);
        InOrder(bt->rchild);
    }
	//以上代码由学生编写
}

//后序遍历
void PostOrder(BiTree bt) {
	//以下代码由学生编写
	//按后序递归访问二叉树结点值并显示
	if(bt!=NULL) {
        PostOrder(bt->lchild);
        PostOrder(bt->rchild);
		visit(bt);
    }
	//以上代码由学生编写
}

//以下程序段采用先根遍历方法求二叉树的叶子数
void LeafCount(BiTree bt, int &count) { /*根指针为bt，假定叶子数 count 的初值 = 0 */ 

  if (bt!=NULL) {
     if((bt->lchild==NULL) && (bt->rchild==NULL))
		 count++;
     LeafCount(bt->lchild,count);
	 LeafCount(bt->rchild,count);
  }
}
//求二叉树结点总数//
int Count(BiTree bt)
{
	if(bt==NULL)
		return 0;
	else
		return Count(bt->lchild) + Count(bt->rchild) + 1;
}
//主程序示例
void main(void) {
	BiTree t;
	int count = 0;
	printf("请先序输入二叉树各结点值（用'#'表示当前结点值为空):\n");
	createbt(t);
	printf("\n二叉树先序遍历结果为:\n");
	PreOrder(t);
	printf("\n二叉树中序遍历结果为:\n");;
	InOrder(t);
	printf("\n二叉树后序遍历结果为:\n");
	PostOrder(t);
	printf("\n该二叉树的结点总数为:\n");
	Count(t);
	printf("%5d", Count(t));
	printf("\n该二叉树的叶子数为:\n");
	LeafCount(t,count);
	printf("%5d", count);
	printf("\n");
}
