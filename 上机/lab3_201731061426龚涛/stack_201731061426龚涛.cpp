#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define MAXSIZE 20
typedef int Status;
typedef int SElemType;
typedef struct {
       SElemType  base[MAXSIZE]; 
       int top;  
}SqStack;

void InitStack(SqStack &S){
   //请编码实现初始化一个空栈S
	S.top = 0;
}

Status Push(SqStack &S,SElemType e){
  //请编码实现将元素值e压入栈S。若入栈失败返回ERROR，否则返回成功状态值OK
	if (S.top==MAXSIZE)
		return ERROR;
	else
	{
		S.base[S.top] = e;
		S.top = S.top + 1;
	}
	return OK;
}

Status Pop(SqStack &S,SElemType &e){
   //请编码实现弹出S的栈顶元素，并将其值通过e传出。若出栈失败返回ERROR，否则返回成功状态值OK
	if (S.top == 0)
		return ERROR;
	e = S.base[--S.top];
	return OK;
}

Status StackEmpty(SqStack S){
   //请编码实现判断栈S是否为空。若栈为空返回OK,否则返回ERROR
	if (S.top == 0)
		return OK;
	else
		return ERROR;
}

void conversion(int N ){
  int e;
  SqStack S;
  InitStack(S); 
  while(N) {    
    Push(S,N%2);  //将N取模后压入栈S
    N=N/2;        //将N整除2
  }             
  printf("转换所得结果为：");
  while(!StackEmpty(S)){ 
    Pop(S,e);         
    printf("%d",e);   
 }                  
  printf("\n");
}//conversion

void main()
{
  int N;
  printf("输入任意非负十进制整数：");
  scanf("%d",&N);

  conversion(N);
}
