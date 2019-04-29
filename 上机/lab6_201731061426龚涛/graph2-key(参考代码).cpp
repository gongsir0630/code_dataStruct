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
