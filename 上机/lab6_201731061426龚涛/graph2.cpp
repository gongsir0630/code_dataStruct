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

void main(void) {
	ALGraph g;
	CreateALGraph(g); //�������룬����ͼ
	Display(g);  //��ʾͼ���ڽӱ�
}
