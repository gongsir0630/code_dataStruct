typedef char* ElemType;
typedef struct node {
   ElemType  data;     //������
   struct node *next;    //ָ����
}LNode, *LinkList;     //���嵥����Ľ��ṹ������������ָ��

LinkList InitList(void);
Status DestoryList(LinkList &L);
Status ListInsert(LinkList &L,int i,ElemType e);
Status ListDelete(LinkList &L,int i,ElemType &e);
int ListLength(LinkList L);
Status GetElem(LinkList L,int i,ElemType &e);
int LocateElem(LinkList L,ElemType e);
Status PrintList(LinkList L);
LinkList MergeList (LinkList La, LinkList Lb);
