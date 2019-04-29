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
   //�����ʵ�ֳ�ʼ��һ����ջS
	S.top = 0;
}

Status Push(SqStack &S,SElemType e){
  //�����ʵ�ֽ�Ԫ��ֵeѹ��ջS������ջʧ�ܷ���ERROR�����򷵻سɹ�״ֵ̬OK
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
   //�����ʵ�ֵ���S��ջ��Ԫ�أ�������ֵͨ��e����������ջʧ�ܷ���ERROR�����򷵻سɹ�״ֵ̬OK
	if (S.top == 0)
		return ERROR;
	e = S.base[--S.top];
	return OK;
}

Status StackEmpty(SqStack S){
   //�����ʵ���ж�ջS�Ƿ�Ϊ�ա���ջΪ�շ���OK,���򷵻�ERROR
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
    Push(S,N%2);  //��Nȡģ��ѹ��ջS
    N=N/2;        //��N����2
  }             
  printf("ת�����ý��Ϊ��");
  while(!StackEmpty(S)){ 
    Pop(S,e);         
    printf("%d",e);   
 }                  
  printf("\n");
}//conversion

void main()
{
  int N;
  printf("��������Ǹ�ʮ����������");
  scanf("%d",&N);

  conversion(N);
}
