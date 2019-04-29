#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_NUM 20   //�������󶥵����

typedef int VertexType; //�������ݵ�����
typedef struct ArcNode {  //�ڽӱ���
  int adjvex;       //�ڽӵ��Ӧ�Ķ��������±�
  struct  ArcNode *nextarc;    //��һ�ڽӵ��ָ��
} ArcNode;
typedef struct VNode {  //��������
  VertexType data;          //��������
  ArcNode    *firstarc;     //�ڽӱ��׽��ָ��
} VNode, AdjList[MAX_VERTEX_NUM];
typedef struct {
  AdjList vertices;     //(�ɹҽ��ڽӱ��)��������
  int   vexnum, arcnum;  //����ĸ������ߵ�����
} ALGraph; //ͼ
int visited[MAX_VERTEX_NUM];
//����ͼ
void CreateALGraph(ALGraph &G)   {   // ����ͼ���ڽӱ�
	int  i,  j,  k;
	ArcNode * s; //�ڽӱ��½��
	printf("���붥�����ͱ���(�����ʽΪ:������,����)��\n");
	scanf("%d,%d", &(G.vexnum), &(G.arcnum) );
	//��������
	printf("���붥����(һ������ռһ��)��\n");
	for ( i=0; i<G.vexnum; i++ ) {
      scanf ("%d", &(G.vertices[i].data));
      G.vertices[i].firstarc = NULL;  //�ڽӱ�ͷָ���ʼΪ��
	}
	printf("���������Ϣ(�����ʽΪ����������±�ԣ�i, j �س�)��\n");
  //�����߱�
	for (k=0; k<G.arcnum; k++ ) {
		scanf ("\n%d,%d", &i, &j );
		//�����ڽӵ�
		s= (ArcNode*) malloc (sizeof(ArcNode));
		s->adjvex = j;                      //�ڽӵ������±�
		//�½�� s ���붥�� Vi ������ͷ��
		s->nextarc = G.vertices[i].firstarc ;
		G.vertices[i].firstarc = s;
		//����ͼ�ı߹��������໥�Գ��ڽ�
		s= (ArcNode*) malloc (sizeof(ArcNode));
		s -> adjvex = i;                      //�ڽӵ������±�
		//�½�� s ���붥�� Vj ������ͷ��
		s->nextarc = G.vertices[j].firstarc ;
		G.vertices[j].firstarc = s;
	}
}
//��λ����������������
int LocateVex(ALGraph G,int v){//��λ����   
    for(int i=0;i<G.vexnum;i++){  
        if(v==G.vertices[i].data)
			return i;  
    }   
} 
//����ͼ
void CreateUDG(ALGraph &G){  
    ArcNode *p,*q;  
    int i,j,k,v1,v2;  
    printf("�ֱ����붥������ͱߵ���Ŀ��\n");  
    scanf("%d%d",&G.vexnum,&G.arcnum);  
    printf("�ֱ������������ֵ��\n");  
    for(i=0;i<G.vexnum;i++){  
    scanf("%d",&G.vertices[i].data);  
    G.vertices[i].firstarc=NULL;//��ʼ��   
    }   
    printf("�ֱ���������ߵ��������㣺\n");  
    for(k=0;k<G.arcnum;k++){  
        scanf("%d%d",&v1,&v2);  
        i=LocateVex(G,v1);j=LocateVex(G,v2);//��λ   
        p=(ArcNode*)malloc(sizeof(ArcNode));//����һ�����   
        p->adjvex=j;p->nextarc=NULL;//��ֵ   
        p->nextarc=G.vertices[i].firstarc;//���ӽ��   
        G.vertices[i].firstarc=p;//���ӽ��   
        q=(ArcNode*)malloc(sizeof(ArcNode));  
        q->adjvex=i;q->nextarc=NULL;  
        q->nextarc=G.vertices[j].firstarc;  
        G.vertices[j].firstarc=q;  
    }  
}  

//��ʾͼ���ڽӱ�
void Display (ALGraph G) {
	ArcNode *p; //�ڽӱ���
	for(int i=0; i<G.vexnum; i++) {
		printf("[%d]", G.vertices[i].data);
//���ڽӱ���ʾ���ڽӵ�����
		p=G.vertices[i].firstarc;
		while(p) { 
			printf("-->%d", G.vertices[p->adjvex].data);
			p=p->nextarc;
		}
		printf("\n");
	}
}
//--------------------------������ȷ��ʺ���-----------------------------------------
//��������
void visit(ALGraph G, int i)
{
	printf("%d  ",G.vertices[i].data);
}
//ѭ������
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define STACK_INIT_SIZE 20
#define STACKINCREMENT 5
typedef int Status;
typedef int ElemType; 

 //���е� ADT��������

#define QUEUE_MAXSIZE 100   //�����г���
typedef  struct 
{   ElemType  base[QUEUE_MAXSIZE]; 
    int  front;     
    int  rear; 
}queue;

void InitQueue(queue &Q){
   Q.front=0;
   Q.rear=0;
}

void enQueue(queue &Q,ElemType value) //Ԫ��value����
 {
	if (( Q.rear + 1 ) % QUEUE_MAXSIZE ==Q.front)
         exit(OVERFLOW);
	Q.base [Q.rear] = value;   
    Q.rear = ( Q.rear + 1 ) %  QUEUE_MAXSIZE;
 }

ElemType deQueue(queue &Q)        //�����У����ض�ͷֵ
{
	ElemType e;
	if (Q.front == Q.rear ) exit (OVERFLOW);
	e = Q.base [ Q.front ]  ;    
    Q.front = ( Q.front + 1 ) % QUEUE_MAXSIZE;   
	return e;
}

bool QueueEmpty(queue Q)       // �ж��пշ�
{
	if (Q.front == Q.rear ) return true;
	else return false;
}


//������ȷ���
void BFSTraverse(ALGraph G) { //��ͼ G ���й�����ȱ���
int no;  //�ڽӵ�������±�
queue Q; //�����ڽӵ��±�Ķ���
ArcNode *p;//�ڽӱ���ָ��
	for(int i=0; i<G.vexnum; i++) visited[i]=0; //��ʼ��������ʱ�־

	InitQueue(Q);
	for(i=0; i<G.vexnum; i++)
		if (visited[i]==0) {
			InitQueue(Q);
			enQueue(Q,i);
			while(!QueueEmpty(Q))
			{
				no = deQueue(Q);
				if(visited[no]==1)
					break;
				visit(G,no);
				visited[no] = 1;
				p = G.vertices[no].firstarc;
				while(p)
				{
					enQueue(Q,p->adjvex);
					p = p->nextarc;
				}
			}
			

		}//end if
}

void main(void) {
	ALGraph g;
	CreateALGraph(g); //�������룬����ͼ
	Display(g);  //��ʾͼ���ڽӱ�
	printf("ͼ�Ĺ�����ȷ���˳����:\n");
	BFSTraverse(g);
	printf("\n");
}
