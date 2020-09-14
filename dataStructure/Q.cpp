#include "pch.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

//큐 선언
int Queue[MAX];
int Front, Rear;

void InitializeQueue(void); // 큐 초기화 함수
void Put(int); // 데이터 삽입
int Get(void); // 데이터 삭제
void DisplayQueue(void); // 큐를 보여줌

// 큐 초기화 함수
void InitializeQueue(void)
{
	Front = Rear = 0;
}

void Put(int num)
{
	Queue[Rear++] = num;

	if (Rear >= MAX) Rear = 0;
}

int Get(void)
{
	int ret;
	ret = Queue[Front++];

	if (Front >= MAX)
		Front = 0;

	return ret;
}

void DisplayQueue(void)
{
	int i;
	printf("Front -> ");
	for (i = Front; i < Rear; i++) printf("%2d -> ", Queue[i]);

	printf("Rear");
}

void main()
{
	int ret;
	InitializeQueue();

	Put(1);
	Put(3);
	Put(10);
	Put(20);
	Put(12);

	printf("다섯 번의 Put() 함수 호출 후 결과\n");
	DisplayQueue();

	ret = Get();
	ret = Get();
	ret = Get();

	printf("\n세 번의 Get() 함수 호출 후 결과\n");
	DisplayQueue();

	printf("\n두 번의 Get() 함수 호출 후 결과\n");

	ret = Get();
	ret = Get();
	DisplayQueue();
}
