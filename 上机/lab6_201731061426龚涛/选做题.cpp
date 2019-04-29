#include <stdio.h>
#include <string.h>
#define MAXWEIGHT 999      //最大可能边权值(表示顶点间无边连接)
#define MAX_VERTEX_NUM 20 //图的最大可能顶点个数
typedef float VRType;       //边权值的类型
typedef char VertexType;  //顶点数据的类型(字符串，最大长度4)
//邻接阵类型
typedef VRType AdjMatrix[MAX_VERTEX_NUM][ MAX_VERTEX_NUM]; 

VertexType a[15] = {'A','A','A','A','B','C','C','C','H','I','E','E','F','F','F'};
VertexType b[15] = {'B','C','H','I','C','D','E','G','G','H','G','D','D','E','I'};
float c[15] = {32.80,44.60,12.10,18.20,5.90,21.30,41.40,56.40,52.50,8.70,10.50,67.30,98.70,85.60,79.20};
VertexType d[9] = {'A','B','C','D','E','F','G','H','I'};
VRType value[9];

typedef struct {
   VertexType vexs[MAX_VERTEX_NUM];  //顶点数组
   AdjMatrix  arcs;                      //邻接矩阵
   int        vexnum,arcnum;           //顶点个数   //边条数
}MGraph; //图类型


//以下为邻接阵表示的图的基本操作函数

//显示图的邻矩阵
void Display(MGraph G) {
	printf("图的邻接矩阵显示如下：\n");
	for(int i=0; i<G.vexnum; i++) {
		for(int j=0; j<G.vexnum; j++) 
			if (G.arcs[i][j]==0)
				printf("%8s", "∞"); //用∞表示无边连接
			else
				printf("%8.2f", G.arcs[i][j]);
		printf("\n");
	}
}


//查找顶点在顶点数组中的下标
int locate(MGraph G, VertexType v) {
  for (int i=0; i<G.vexnum; i++)
    if (G.vexs[i]==v) return i;
	return -1;
}


//创建有向网（带权有向图）
void CreateGraph(MGraph &G) {
//请同学编码完成有向网G的创建
	G.vexnum = 9;
	G.arcnum = 15;

	for(int i=0;i<G.vexnum;i++)G.vexs[i] = d[i];
	for(i=0;i<G.arcnum;i++)
		for(int j=0;j<G.vexnum;j++)
			G.arcs[i][j] = 0;
		for(int k = 0;k<G.arcnum;k++){
			VertexType v1 = a[k],v2 = b[k];
			float w = c[k];
			int q = locate(G,v1);
			int p = locate(G,v2);
			G.arcs[q][p] = w;
			G.arcs[p][q] = w;
		}
}


void visit(MGraph G,int v)
{
	printf("%c\n",G.vexs[v]);
}



void findbestway(MGraph &G,VertexType s[9],VertexType T[9])
{
	int location = 0;
	float val = 100.0;
	for(int i = 0;i<G.vexnum;i++)
	{
		if(s[i]!='Z')
		{
			int k = locate(G,s[i]);
			for(int m = 0;m<G.vexnum;m++)
			{
				if(G.arcs[k][m]<val && G.arcs[k][m]!=0 && T[m]!='Z')
				{
					val = G.arcs[k][m];
					location = m;
				}
			}
		}
	}
	s[location] = d[location];
	visit(G,location);

}

void bestway(MGraph &G)
{
	VertexType s[9] = {'A',};
	for(int j = 1;j<G.vexnum;j++)
		s[j] = 'Z';
	VertexType T[9] ;
	for(j = 0;j<G.vexnum;j++)
		T[j] = 'Z';
	for(int o=0;o<G.vexnum;o++)
	{
		findbestway(G,s,T);
		for(int i = 0;i<G.vexnum ;i++)
		{
			if(s[i]=='Z')
				T[i] = d[i];
			else
				T[i] = 'Z';
		}
		
	}
}


void main() {
	MGraph g;
	CreateGraph(g); //接受输入，创建有向网
	Display(g);  //显示图的邻接阵
	printf("最佳方案:\n");
	bestway(g);
}
