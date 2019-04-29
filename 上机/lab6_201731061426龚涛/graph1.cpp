#include <stdio.h>
#include <string.h>
#define MAXWEIGHT 999      //最大可能边权值(表示顶点间无边连接)
#define MAX_VERTEX_NUM 20 //图的最大可能顶点个数
typedef int VRType;       //边权值的类型(整数)
typedef int ArcType;	//边（弧）数据类型
typedef char VertexType[5];  //顶点数据的类型(字符串，最大长度4)
//邻接阵类型
typedef VRType AdjMatrix[MAX_VERTEX_NUM][ MAX_VERTEX_NUM]; 
typedef struct {
   VertexType vexs[MAX_VERTEX_NUM];  //顶点数组
   ArcType arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; //邻接矩阵
   int        vexnum,                   //顶点个数
arcnum;                   //边条数
}MGraph; //图类型
int visited[MAX_VERTEX_NUM];	//顶点访问标志数组
//以下为邻接阵表示的图的基本操作函数
//显示图的邻接矩阵
void Display(MGraph G) {
	printf("图的邻接矩阵显示如下：\n");
	for(int i=0; i<G.vexnum; i++) {
		for(int j=0; j<G.vexnum; j++) 
			if (G.arcs[i][j]==MAXWEIGHT)
				printf("%5s", "∞"); //用∞表示无边连接
			else
				printf("%5d", G.arcs[i][j]);
		printf("\n");
	}
}
//判断两个顶点是否相同
int equal(VertexType v1, VertexType v2) {
  return(strcmp(v1, v2)==0);
}
//查找顶点在顶点数组中的下标
int locate(MGraph G, VertexType v) {
  for (int i=0; i<G.vexnum; i++)
    if (equal(G.vexs[i], v)) return i;
	return -1;
}
//创建有向网（带权有向图）
void CreateGraph(MGraph &G) {
//请同学编码完成有向网G的创建
	VertexType v1, v2;
	ArcType weight;	//权值
	int i, j, k;

	printf("输入顶点数和边数:\n");
	scanf("%d %d", &G.vexnum, &G.arcnum);

	//创建顶点数组
	printf("逐行输入%d个顶点的名字:\n", G.vexnum);
	for(i = 0; i<G.vexnum; i++)
	{
		scanf("%s", G.vexs[i]);
	}
	//初始化邻接矩阵
	for(i = 0; i<G.vexnum; i++)
	{
		for(j = 0; j<G.vexnum; j++)
		{
			G.arcs[i][j] = MAXWEIGHT;
		}
	}
	for(i = 0; i<G.vexnum; i++)
		G.arcs[i][j] = 0;

	//接受邻接矩阵数据
	printf("逐行输入弧的起点、终点名字及边权值:\n");
	for(k = 0; k<G.arcnum; k++)
	{
		//输入顶点编号及边权值
		scanf("%s%s%d", v1, v2, &weight);
		//顶点对应数据元素下标
		i = locate(G, v1);
		j = locate(G, v2);
		G.arcs[i][j] = weight;
	}
}
//创建无向图
void CreateGraph1(MGraph &G) {
	VertexType v1, v2;
	int i, j, k;

	printf("输入顶点数和边数:\n");
	scanf("%d %d", &G.vexnum, &G.arcnum);

	//创建顶点数组
	printf("逐行输入%d个顶点的名字:\n", G.vexnum);
	for(i = 0; i<G.vexnum; i++)
	{
		scanf("%s", G.vexs[i]);
	}
	//初始化邻接矩阵
	for(i = 0; i<G.vexnum; i++)
	{
		for(j = 0; j<G.vexnum; j++)
		{
			G.arcs[i][j] = MAXWEIGHT;
		}
	}
	for(i = 0; i<G.vexnum; i++)
		G.arcs[i][j] = 0;

	//接受邻接矩阵数据
	printf("逐行输入边的节点名称:\n");
	for(k = 0; k<G.arcnum; k++)
	{
		//输入顶点编号及边权值
		scanf("%s%s", v1, v2);
		//顶点对应数据元素下标
		i = locate(G, v1);
		j = locate(G, v2);
		G.arcs[i][j] = 1;
		G.arcs[j][i] = 1;
		G.arcs[k][k] = 0;
	}
}
//辅助函数
void visit(MGraph G,int v)
{
	printf("%s\n",G.vexs[v]);
}
//深度优先遍历DFS函数
void dfs(MGraph &G,int v)
{
	visited[v] = 1;
	visit(G,v);
	for(int j = 0;j<G.vexnum;j++)
	{
		int w = G.arcs[v][j];
		if(w!=MAXWEIGHT && visited[j]==0){
			dfs(G,j);
		}
	}

}
//深度优先遍历函数
void dfstraver(MGraph &G)
{
	for(int i=0;i<G.vexnum;i++)
	{
		visited[i] = 0;
	}
	for(i=0;i<G.vexnum;i++)
	{
		if(visited[i]==0)
		{
			dfs(G,i);
		}
	}
}

void main() {
	MGraph g;
	CreateGraph(g); //接受输入，创建有向网
	//CreateGraph1(g); //接受输入，创建无向网
	Display(g);  //显示图的邻接阵
	printf("图的深度优先遍历结果:\n");
	dfstraver(g);
}

