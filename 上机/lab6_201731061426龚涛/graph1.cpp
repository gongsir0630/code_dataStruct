#include <stdio.h>
#include <string.h>
#define MAXWEIGHT 999      //�����ܱ�Ȩֵ(��ʾ������ޱ�����)
#define MAX_VERTEX_NUM 20 //ͼ�������ܶ������
typedef int VRType;       //��Ȩֵ������(����)
typedef int ArcType;	//�ߣ�������������
typedef char VertexType[5];  //�������ݵ�����(�ַ�������󳤶�4)
//�ڽ�������
typedef VRType AdjMatrix[MAX_VERTEX_NUM][ MAX_VERTEX_NUM]; 
typedef struct {
   VertexType vexs[MAX_VERTEX_NUM];  //��������
   ArcType arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; //�ڽӾ���
   int        vexnum,                   //�������
arcnum;                   //������
}MGraph; //ͼ����
int visited[MAX_VERTEX_NUM];	//������ʱ�־����
//����Ϊ�ڽ����ʾ��ͼ�Ļ�����������
//��ʾͼ���ڽӾ���
void Display(MGraph G) {
	printf("ͼ���ڽӾ�����ʾ���£�\n");
	for(int i=0; i<G.vexnum; i++) {
		for(int j=0; j<G.vexnum; j++) 
			if (G.arcs[i][j]==MAXWEIGHT)
				printf("%5s", "��"); //�áޱ�ʾ�ޱ�����
			else
				printf("%5d", G.arcs[i][j]);
		printf("\n");
	}
}
//�ж����������Ƿ���ͬ
int equal(VertexType v1, VertexType v2) {
  return(strcmp(v1, v2)==0);
}
//���Ҷ����ڶ��������е��±�
int locate(MGraph G, VertexType v) {
  for (int i=0; i<G.vexnum; i++)
    if (equal(G.vexs[i], v)) return i;
	return -1;
}
//��������������Ȩ����ͼ��
void CreateGraph(MGraph &G) {
//��ͬѧ�������������G�Ĵ���
	VertexType v1, v2;
	ArcType weight;	//Ȩֵ
	int i, j, k;

	printf("���붥�����ͱ���:\n");
	scanf("%d %d", &G.vexnum, &G.arcnum);

	//������������
	printf("��������%d�����������:\n", G.vexnum);
	for(i = 0; i<G.vexnum; i++)
	{
		scanf("%s", G.vexs[i]);
	}
	//��ʼ���ڽӾ���
	for(i = 0; i<G.vexnum; i++)
	{
		for(j = 0; j<G.vexnum; j++)
		{
			G.arcs[i][j] = MAXWEIGHT;
		}
	}
	for(i = 0; i<G.vexnum; i++)
		G.arcs[i][j] = 0;

	//�����ڽӾ�������
	printf("�������뻡����㡢�յ����ּ���Ȩֵ:\n");
	for(k = 0; k<G.arcnum; k++)
	{
		//���붥���ż���Ȩֵ
		scanf("%s%s%d", v1, v2, &weight);
		//�����Ӧ����Ԫ���±�
		i = locate(G, v1);
		j = locate(G, v2);
		G.arcs[i][j] = weight;
	}
}
//��������ͼ
void CreateGraph1(MGraph &G) {
	VertexType v1, v2;
	int i, j, k;

	printf("���붥�����ͱ���:\n");
	scanf("%d %d", &G.vexnum, &G.arcnum);

	//������������
	printf("��������%d�����������:\n", G.vexnum);
	for(i = 0; i<G.vexnum; i++)
	{
		scanf("%s", G.vexs[i]);
	}
	//��ʼ���ڽӾ���
	for(i = 0; i<G.vexnum; i++)
	{
		for(j = 0; j<G.vexnum; j++)
		{
			G.arcs[i][j] = MAXWEIGHT;
		}
	}
	for(i = 0; i<G.vexnum; i++)
		G.arcs[i][j] = 0;

	//�����ڽӾ�������
	printf("��������ߵĽڵ�����:\n");
	for(k = 0; k<G.arcnum; k++)
	{
		//���붥���ż���Ȩֵ
		scanf("%s%s", v1, v2);
		//�����Ӧ����Ԫ���±�
		i = locate(G, v1);
		j = locate(G, v2);
		G.arcs[i][j] = 1;
		G.arcs[j][i] = 1;
		G.arcs[k][k] = 0;
	}
}
//��������
void visit(MGraph G,int v)
{
	printf("%s\n",G.vexs[v]);
}
//������ȱ���DFS����
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
//������ȱ�������
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
	CreateGraph(g); //�������룬����������
	//CreateGraph1(g); //�������룬����������
	Display(g);  //��ʾͼ���ڽ���
	printf("ͼ��������ȱ������:\n");
	dfstraver(g);
}

