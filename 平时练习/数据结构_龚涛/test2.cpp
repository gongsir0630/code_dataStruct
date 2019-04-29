//DATE:2018-7-9 21:00:53
//author：龚涛
//function：Bitree

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node {
    char a;
    struct Node *lchild;
    struct Node *rchild;
}BiNode, *BiTree;
 
void PosTraverse(BiTree T) {
    if (T == NULL) return;
    PosTraverse(T->lchild);
    PosTraverse(T->rchild);
    printf("%c", T->a);
}
 
void BuildTree(char *pre, char* mid, BiTree root) {
    int len = strlen(pre);
    if (0 == len) 
		return;
    char *p = strchr(mid, pre[0]);
    int pos = p - mid;
    root->a = pre[0];
    root->lchild = root->rchild = NULL;
    if (pos != 0) {
        BiTree left;
        root->lchild = (BiTree)malloc(sizeof(BiNode));
        left = root->lchild;
        char *left_pre = (char*)malloc(sizeof(char) * (pos + 1));
        char *left_mid = (char*)malloc(sizeof(char) * (pos + 1));
        strncpy(left_pre, pre + 1, pos);
        strncpy(left_mid, mid, pos);
        left_pre[pos] = 0;
        left_mid[pos] = 0;
        BuildTree(left_pre, left_mid, left);
    }
    if (pos != len - 1) {
        BiTree right;
        root->rchild = (BiTree)malloc(sizeof(BiNode));
        right = root->rchild;
        char *right_pre = (char*)malloc(sizeof(char) * (len - pos));
        char *right_mid = (char*)malloc(sizeof(char) * (len - pos));
        strncpy(right_pre, pre + 1 + pos, len - pos - 1);
        strncpy(right_mid, mid + 1 + pos, len - pos - 1);
        right_pre[len - pos - 1] = 0;
        right_mid[len - pos - 1] = 0;
        BuildTree(right_pre, right_mid, right);
    }
}
 
int main() {
    BiNode temp;
	char s1[100], s2[100];
	printf("请输入先序遍历结果：\n");
	scanf("%s", s1);
	printf("请输入中序遍历结果：\n");
	scanf("%s", s2);
    BuildTree(s1, s2, &temp);
	printf("后序遍历结果：\n");
    PosTraverse(&temp);
	printf("\n");
	return 0;
}