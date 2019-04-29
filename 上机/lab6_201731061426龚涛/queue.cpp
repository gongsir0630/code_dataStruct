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

