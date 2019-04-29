typedef char* ElemType;
typedef struct node {
   ElemType  data;     //数据域
   struct node *next;    //指针域
}LNode, *LinkList;     //定义单链表的结点结构、单链表类型指针

LinkList InitList(void);
Status DestoryList(LinkList &L);
Status ListInsert(LinkList &L,int i,ElemType e);
Status ListDelete(LinkList &L,int i,ElemType &e);
int ListLength(LinkList L);
Status GetElem(LinkList L,int i,ElemType &e);
int LocateElem(LinkList L,ElemType e);
Status PrintList(LinkList L);
LinkList MergeList (LinkList La, LinkList Lb);
