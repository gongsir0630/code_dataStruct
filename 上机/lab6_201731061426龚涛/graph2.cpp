#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_NUM 20   //允许的最大顶点个数

typedef int VertexType; //顶点数据的类型
typedef struct ArcNode {  //邻接表结点
  int adjvex;       //邻接点对应的顶点数组下标
  struct  ArcNode *nextarc;    //下一邻接点的指针
} ArcNode;
typedef struct VNode {  //顶点数组
  VertexType data;          //顶点数据
  ArcNode    *firstarc;     //邻接表首结点指针
} VNode, AdjList[MAX_VERTEX_NUM];
typedef struct {
  AdjList vertices;     //(可挂接邻接表的)顶点数组
  int   vexnum, arcnum;  //顶点的个数，边的条数
} ALGraph; //图
//有向图
void CreateALGraph(ALGraph &G)   {   // 建立图的邻接表
	int  i,  j,  k;
	ArcNode * s; //邻接表新结点
	printf("输入顶点数和边数(输入格式为:顶点数,边数)：\n");
	scanf("%d,%d", &(G.vexnum), &(G.arcnum) );
	//顶点数组
	printf("输入顶点编号(一个顶点占一行)：\n");
	for ( i=0; i<G.vexnum; i++ ) {
      scanf ("%d", &(G.vertices[i].data));
      G.vertices[i].firstarc = NULL;  //邻接表头指针初始为空
	}
	printf("请输入边信息(输入格式为顶点的数组下标对：i, j 回车)：\n");
  //建立边表
	for (k=0; k<G.arcnum; k++ ) {
		scanf ("\n%d,%d", &i, &j );
		//创建邻接点
		s= (ArcNode*) malloc (sizeof(ArcNode));
		s->adjvex = j;                      //邻接点数组下标
		//新结点 s 插入顶点 Vi 的链表头部
		s->nextarc = G.vertices[i].firstarc ;
		G.vertices[i].firstarc = s;
		//无向图的边关联顶点相互对称邻接
		s= (ArcNode*) malloc (sizeof(ArcNode));
		s -> adjvex = i;                      //邻接点数组下标
		//新结点 s 插入顶点 Vj 的链表头部
		s->nextarc = G.vertices[j].firstarc ;
		G.vertices[j].firstarc = s;
	}
}
//定位函数（辅助函数）
int LocateVex(ALGraph G,int v){//定位函数   
    for(int i=0;i<G.vexnum;i++){  
        if(v==G.vertices[i].data)
			return i;  
    }   
} 
//无向图
void CreateUDG(ALGraph &G){  
    ArcNode *p,*q;  
    int i,j,k,v1,v2;  
    printf("分别输入顶点个数和边的数目：\n");  
    scanf("%d%d",&G.vexnum,&G.arcnum);  
    printf("分别输入各个顶点值：\n");  
    for(i=0;i<G.vexnum;i++){  
    scanf("%d",&G.vertices[i].data);  
    G.vertices[i].firstarc=NULL;//初始化   
    }   
    printf("分别输入各条边的两个顶点：\n");  
    for(k=0;k<G.arcnum;k++){  
        scanf("%d%d",&v1,&v2);  
        i=LocateVex(G,v1);j=LocateVex(G,v2);//定位   
        p=(ArcNode*)malloc(sizeof(ArcNode));//申请一个结点   
        p->adjvex=j;p->nextarc=NULL;//赋值   
        p->nextarc=G.vertices[i].firstarc;//连接结点   
        G.vertices[i].firstarc=p;//连接结点   
        q=(ArcNode*)malloc(sizeof(ArcNode));  
        q->adjvex=i;q->nextarc=NULL;  
        q->nextarc=G.vertices[j].firstarc;  
        G.vertices[j].firstarc=q;  
    }  
}  

//显示图的邻接表
void Display (ALGraph G) {
	ArcNode *p; //邻接表结点
	for(int i=0; i<G.vexnum; i++) {
		printf("[%d]", G.vertices[i].data);
//沿邻接表显示各邻接点数据
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
	CreateALGraph(g); //接受输入，创建图
	Display(g);  //显示图的邻接表
}
