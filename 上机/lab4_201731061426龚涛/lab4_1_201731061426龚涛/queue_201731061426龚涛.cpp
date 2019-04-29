#include <stdio.h>    // NULL, printf()等
#include <malloc.h>   // malloc()等
#include <string.h>
// 函数结果状态代码
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define OK 1
#define ERROR 0
typedef int Status;    // 函数返回值（表示结果状态，如OK等）

typedef int QElemType; //队列元素的数据类型

#define MAXQSIZE 10 //循环队列最大容量
//循环队列类型
typedef struct QNode{
	QElemType *base; //队列元素存储数组
	int front;       //队头指针，若队列不空，则指向队列头元素
	int rear;        //队尾指针，若队列不空，则指向队列尾元素的下一个空白位置
}SqQueue;

//初始化循环队列
Status InitQueue(SqQueue &q) {
	q.base = (QElemType *) malloc ( MAXQSIZE * sizeof (QElemType));  //分配空间
	if(!q.base) return ERROR;
	//初始化队头、队尾
	q.front = 0;
	q.rear =0;
	return OK;
}
//返回队列长度
int QueueLength(SqQueue q) {
	//本函数代码由学生编写
	return (q.rear - q.front + MAXQSIZE) % MAXQSIZE;
}
//队列空判定（如果空返回TRUE，否则返回FALSE）
Status QueueEmpty(SqQueue q) {
	//本函数代码由学生编写
	if(q.rear == q.front)
		return TRUE;
	else
		return FALSE;
}
//入队（元素值e入队，如果队列已满无法入队就返回ERROR，执行成功返回OK）
Status EnQueue(SqQueue &q, QElemType e) {	
	//本函数代码由学生编写
	if((q.rear+1) % MAXQSIZE==q.front)
		return ERROR;
	q.base[q.rear] = e;
	q.rear = (q.rear+1) % MAXQSIZE;
	return OK;
}
//出队（出队元素值通过参数变量e返回。如果队列为空则返回ERROR，执行成功返回OK）
Status DeQueue(SqQueue &q, QElemType &e) {
	//本函数代码由学生编写
	if(q.front==q.rear)
		return ERROR;
	e = q.base[q.front];
	q.front = (q.front+1) % MAXQSIZE;
	return OK;
}
//依次打印输出队列元素（执行成功返回OK，否则返回ERROR）
Status PrintQueue(SqQueue q) {
	//本函数代码由学生编写
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

//主函数
void main(void) {
	SqQueue Q;
	int select ;
	QElemType e;
	
	if ( InitQueue ( Q) == ERROR)
		printf ("\n队列空间分配失败！程序退出\n");
	
	else //显示队列操作菜单
		do {
			printf ("\n1: 判断队列是否为空\n") ;
			printf ("2: 测试队列的长度\n") ;
			printf ("3: 向队列中插入一新元素\n") ;
			printf ("4: 删除队列中一元素\n") ;
			printf ("5: 显示队列内容\n");
			printf ("0: 结束\n") ;
			
			scanf ("%d", &select ) ;
			switch (select) {
			case 1 : 
				if (QueueEmpty(Q) == TRUE) 
					printf ("\n队列空！\n") ; 
				else 
					printf ("\n队列不空\n") ; 
				break;
				
			case 2 : 
				printf ("\n队列长度＝%d \n", QueueLength ( Q) ) ; 
				break;
				
			case 3 : 
				printf ("\n请输入新元素：") ;
				scanf ("%d", &e) ; 
				if (EnQueue ( Q, e ) == ERROR) 
					printf ("\n队列满！不能添加新元素\n") ;
				else 
					printf ("\n新元素添加成功！\n") ; 
				break ;
				
			case 4 : 
				if (DeQueue ( Q, e) == ERROR) 
					printf ("\n队列空！不能进行删除\n") ; 
				else 
					printf ("\n队头元素 %d 已删除\n", e) ; 
				break;
				
			case 5 :
				printf("\n");
				PrintQueue(Q);
			case 0 : 
				printf ("\n操作结束\n") ; 
				break;
				
			default: 
				printf ("\n功能选择错！请重新输入功能号\n") ;
			}
		} while (select) ;
		
}
