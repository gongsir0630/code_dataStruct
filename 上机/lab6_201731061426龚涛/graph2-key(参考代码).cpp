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
