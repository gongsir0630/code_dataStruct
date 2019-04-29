#include <stdio.h>    // NULL, printf()等
#include <malloc.h>   // malloc()等
#include <string.h>

// 函数结果状态定义
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define OK 1
#define ERROR 0

typedef int Status;    // 函数返回类型（表示结果状态，如OK等）
