#include <stdio.h>    // NULL, printf()��
#include <malloc.h>   // malloc()��
#include <string.h>
// �������״̬����
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define OK 1
#define ERROR 0
typedef int Status;    // ��������ֵ����ʾ���״̬����OK�ȣ�

typedef int QElemType; //����Ԫ�ص���������

#define MAXQSIZE 10 //ѭ�������������
//ѭ����������
typedef struct QNode{
	QElemType *base; //����Ԫ�ش洢����
	int front;       //��ͷָ�룬�����в��գ���ָ�����ͷԪ��
	int rear;        //��βָ�룬�����в��գ���ָ�����βԪ�ص���һ���հ�λ��
}SqQueue;

//��ʼ��ѭ������
Status InitQueue(SqQueue &q) {
	q.base = (QElemType *) malloc ( MAXQSIZE * sizeof (QElemType));  //����ռ�
	if(!q.base) return ERROR;
	//��ʼ����ͷ����β
	q.front = 0;
	q.rear =0;
	return OK;
}
//���ض��г���
int QueueLength(SqQueue q) {
	//������������ѧ����д
	return (q.rear - q.front + MAXQSIZE) % MAXQSIZE;
}
//���п��ж�������շ���TRUE�����򷵻�FALSE��
Status QueueEmpty(SqQueue q) {
	//������������ѧ����д
	if(q.rear == q.front)
		return TRUE;
	else
		return FALSE;
}
//��ӣ�Ԫ��ֵe��ӣ�������������޷���Ӿͷ���ERROR��ִ�гɹ�����OK��
Status EnQueue(SqQueue &q, QElemType e) {	
	//������������ѧ����д
	if((q.rear+1) % MAXQSIZE==q.front)
		return ERROR;
	q.base[q.rear] = e;
	q.rear = (q.rear+1) % MAXQSIZE;
	return OK;
}
//���ӣ�����Ԫ��ֵͨ����������e���ء��������Ϊ���򷵻�ERROR��ִ�гɹ�����OK��
Status DeQueue(SqQueue &q, QElemType &e) {
	//������������ѧ����д
	if(q.front==q.rear)
		return ERROR;
	e = q.base[q.front];
	q.front = (q.front+1) % MAXQSIZE;
	return OK;
}
//���δ�ӡ�������Ԫ�أ�ִ�гɹ�����OK�����򷵻�ERROR��
Status PrintQueue(SqQueue q) {
	//������������ѧ����д
	int i = q.front;
	if(q.rear==q.front)
	{
		printf("The Queue is Empty!");
		return ERROR;
	}
	else
	{
		printf("The Queue is:\n");
		while(i!=q.rear)
		{
			printf("%d ", q.base[i]);
			i = (i+1) % MAXQSIZE;
		}
	}
	printf("\n");
	return OK;
}

//������
void main(void) {
	SqQueue Q;
	int select ;
	QElemType e;
	
	if ( InitQueue ( Q) == ERROR)
		printf ("\n���пռ����ʧ�ܣ������˳�\n");
	
	else //��ʾ���в����˵�
		do {
			printf ("\n1: �ж϶����Ƿ�Ϊ��\n") ;
			printf ("2: ���Զ��еĳ���\n") ;
			printf ("3: ������в���һ��Ԫ��\n") ;
			printf ("4: ɾ��������һԪ��\n") ;
			printf ("5: ��ʾ��������\n");
			printf ("0: ����\n") ;
			
			scanf ("%d", &select ) ;
			switch (select) {
			case 1 : 
				if (QueueEmpty(Q) == TRUE) 
					printf ("\n���пգ�\n") ; 
				else 
					printf ("\n���в���\n") ; 
				break;
				
			case 2 : 
				printf ("\n���г��ȣ�%d \n", QueueLength ( Q) ) ; 
				break;
				
			case 3 : 
				printf ("\n��������Ԫ�أ�") ;
				scanf ("%d", &e) ; 
				if (EnQueue ( Q, e ) == ERROR) 
					printf ("\n�����������������Ԫ��\n") ;
				else 
					printf ("\n��Ԫ����ӳɹ���\n") ; 
				break ;
				
			case 4 : 
				if (DeQueue ( Q, e) == ERROR) 
					printf ("\n���пգ����ܽ���ɾ��\n") ; 
				else 
					printf ("\n��ͷԪ�� %d ��ɾ��\n", e) ; 
				break;
				
			case 5 :
				printf("\n");
				PrintQueue(Q);
			case 0 : 
				printf ("\n��������\n") ; 
				break;
				
			default: 
				printf ("\n����ѡ������������빦�ܺ�\n") ;
			}
		} while (select) ;
		
}
