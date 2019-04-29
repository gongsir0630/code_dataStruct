/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
typedef int Status;
typedef char SElemType;
#define stack_INT_SIZE 100
#define stackINCREMENT 10
#define OK 1
#define ERROR 0
typedef struct {
	SElemType *base;	//’ªµ◊÷∏’Î
	SElemType *top;		//’ª∂•÷∏’Î
	int stacksize;		//’ªø’º‰
}Sqstack;

Status InitStack(Sqstack &S) {//≥ı ºªØ’ª
	//ππ‘Ï“ª∏ˆø’’ª
	S.base = (SElemType *)malloc(sizeof(SElemType)*stack_INT_SIZE);
	if(!S.base)
		return ERROR;
	S.top = S.base;
	S.stacksize = stack_INT_SIZE;
	return OK;
}//InitStack

Status push(Sqstack &S, SElemType x) {
	if (S.top-S.base >= S.stacksize)
	{
		S.base = (SElemType *)realloc(S.base,sizeof(SElemType)*(stack_INT_SIZE + stackINCREMENT)); 
		if(!S.base)
			return ERROR;
		S.top = S.base + S.stacksize;
		S.stacksize += stackINCREMENT;
	}
	*S.top++ = x;
	return OK;
}

Status pop(Sqstack &S, SElemType &e) {
	if (S.top==S.base)
		return ERROR;
	e = *--S.top;
	return OK;
}

Status GetTop(Sqstack S, SElemType &e) {
	if (S.top==S.base)
		return ERROR;
	e = *(S.top-1);
	return OK;
}

Status StackEmpty(Sqstack S) {
	if(S.base==S.top)
		return OK;
	return ERROR;
}

Status Compare(Sqstack &S) {
	int flag = OK;
	char ch, e;
	while((ch=getchar())!='\n' && flag)
	{
		switch(ch)
		{
		case'(':
		case'[':
		case'{':push(S,ch); break;
		case')':if(pop(S,e)==ERROR || e != '(') flag = ERROR; break;
		case']':if(pop(S,e)==ERROR || e != '[') flag = ERROR; break;
		case'}':if(pop(S,e)==ERROR || e != '{') flag = ERROR; break;
		default:break;
		}
	}

	if (flag && ch=='\n' && StackEmpty(S)==OK)
		return OK;
	else
		return ERROR;
}

int main()
{
	Sqstack S;
	int i;
	InitStack(S);
	i = Compare(S);
	if(i==OK)
		printf("¿®∫≈∆•≈‰≥…π¶!\n");
	if(i==ERROR)
		printf("¿®∫≈∆•≈‰ ß∞‹!\n");

	return 0;
}
*/