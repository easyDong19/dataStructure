#include "node.h"


//외부 함수 정의
extern void InitializeQueue(void);
extern int put(NODE *);
extern NODE *Get(void);
extern int IsQueueEmpty(void);

//내부 함수 정의
void InitializeTree(void);
void MakeTree(void);
void Level_Traverse(NODE *);
void Visit(NODE *);

//전역 변수 정의
NODE *Parent, *LeftChild, *RightChild;
NODE *HeadNode, *EndNode;

//트리의 초기화
void InitializeTree(void)
{
	HeadNode = (NODE *)malloc(sizeof(NODE));
	EndNode = (NODE *)malloc(sizeof(NODE));

	HeadNode->Left = EndNode;
	HeadNode->Right = EndNode;

	EndNode->Left = EndNode;
	EndNode->Right = EndNode;
}

//트리의 초기 구성
void MakeTree(void)
{
	Parent = (NODE *)malloc(sizeof(NODE));
	Parent->Data = 'A';

	LeftChild = (NODE *)malloc(sizeof(NODE));
	LeftChild->Data = 'B';

	RightChild = (NODE *)malloc(sizeof(NODE));
	RightChild->Data = 'C';

	Parent->Left = LeftChild;
	Parent->Right = RightChild;

	HeadNode->Left = Parent;
	HeadNode->Right = Parent;

	Parent = Parent->Left;

	LeftChild = (NODE *)malloc(sizeof(NODE));
	LeftChild->Data = 'D';
	LeftChild->Left = EndNode;
	LeftChild->Right = EndNode;

	RightChild = (NODE *)malloc(sizeof(NODE));
	RightChild->Data = 'E';
	RightChild->Left = EndNode;
	RightChild->Right = EndNode;

	Parent->Left = LeftChild;
	Parent->Right = RightChild;
	Parent = HeadNode->Right->Right;

	LeftChild = (NODE *)malloc(sizeof(NODE));
	LeftChild->Data = 'F';
	LeftChild->Left = EndNode;
	LeftChild->Right = EndNode;

	RightChild = (NODE *)malloc(sizeof(NODE));
	RightChild->Data = 'G';
	RightChild->Left = EndNode;
	RightChild->Right = EndNode;

	Parent->Left = LeftChild;
	Parent->Right = RightChild;
}

//큐를 이용한 트리의 순회 알고리즘
void Level_Traverse(NODE *ptrNode)
{
	Put(ptrNode);
	while (!IsQueueEmpty()) {
		ptrNode = Get();
		Visit(ptrNode);

		if (ptrNode->Left != EndNode) Put(ptrNode->Left);

		if (ptrNode->Right != EndNode) Put(ptrNode->Right);
	}
}


void Visit(NODE *ptrNode)
{
	printf("%2c -> ", ptrNode->Data);
}

void main()
{
	InitializeQueue(); // 큐의 초기화
	InitializeTree(); // 트리의 초기화

	MakeTree(); // 트리의 구성
	printf("큐를 사용한 단계 순회 : ");

	Level_Traverse(HeadNode->Left);
}

