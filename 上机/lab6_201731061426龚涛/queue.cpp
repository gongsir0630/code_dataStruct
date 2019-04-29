#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define STACK_INIT_SIZE 20
#define STACKINCREMENT 5
typedef int Status;
typedef int ElemType; 

 //队列的 ADT函数定义

#define QUEUE_MAXSIZE 100   //最大队列长度
typedef  struct 
{   ElemType  base[QUEUE_MAXSIZE]; 
    int  front;     
    int  rear; 
}queue;

void InitQueue(queue &Q){
   Q.front=0;
   Q.rear=0;
}

void enQueue(queue &Q,ElemType value) //元素value进队
 {
	if (( Q.rear + 1 ) % QUEUE_MAXSIZE ==Q.front)
         exit(OVERFLOW);
	Q.base [Q.rear] = value;   
    Q.rear = ( Q.rear + 1 ) %  QUEUE_MAXSIZE;
 }

ElemType deQueue(queue &Q)        //出队列，返回队头值
{
	ElemType e;
	if (Q.front == Q.rear ) exit (OVERFLOW);
	e = Q.base [ Q.front ]  ;    
    Q.front = ( Q.front + 1 ) % QUEUE_MAXSIZE;   
	return e;
}

bool QueueEmpty(queue Q)       // 判队列空否
{
	if (Q.front == Q.rear ) return true;
	else return false;
}

