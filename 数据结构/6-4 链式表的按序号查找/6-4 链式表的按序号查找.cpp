// 6-4 链式表的按序号查找.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef int ElementType;
typedef struct LNode* PtrToLNode;
struct LNode {
	ElementType Data;
	PtrToLNode Next;
};
typedef PtrToLNode List;

List Read() {
	List L = (List)malloc(sizeof(struct LNode));
	L->Next = NULL;
	int in;
	scanf("%d", &in);
	while (in != -1) {
		List temp = (List)malloc(sizeof(struct LNode));
		temp->Data = in;
		temp->Next = L->Next;
		L->Next = temp;
		scanf("%d", &in);
	}
	return L;
}

ElementType FindKth(List L, int K) {
	List p = L;
	if (K <= 0) {
		return ERROR;
	}
	for (int i = 1; i < K; i++) {
		if (p == NULL) {
			return ERROR;
		}
		p = p->Next;
	}
	if (p != NULL) {
		return p->Data;
	}
	else
		return ERROR;
};

int main()
{
	int N, K;
	ElementType X;
	List L = Read();
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &K);
		X = FindKth(L, K);
		if (X != ERROR)
			printf("%d ", X);
		else
			printf("NA ");
	}
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
