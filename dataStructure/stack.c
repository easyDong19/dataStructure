#include "node.h"
#define MAX 100

NODE *Stack[MAX]; //스택을 배열로 선언
int Top;

void InitializeStack(void);
void Push(NODE *);
NODE *Pop(void);
int IsStackEmpty(void);

//스택 초기화 함수
void InitializeStack(void)
{
	Top = 0;
}

void Push(NODE *ptrNode)
{
	Stack[Top] = ptrNode;
	Top = (Top++) % MAX;
}

NODE *Pop(void)
{
	NODE *ptrNode;

	if (!IsStackEmpty()) {
		ptrNode = Stack[--Top];

		return ptrNode;
	}
	else printf("Stack is Empty \n");

	return NULL;
}

int IsStackEmpty(void)
{
	if (Top == 0) return TRUE;
	else return FALSE;
}