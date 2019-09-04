// 6-5 链式表操作集.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef int ElementType;
typedef struct LNode* PtrToLNode;
struct LNode {
	ElementType Data;
	PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

Position Find(List L, ElementType X) {
	List p = L;
	while (p != NULL) {
		if (p->Data == X) {
			return p;
		}
		p = p->Next;
	}
	return ERROR;
};

List Insert(List L, ElementType X, Position P) {
	List temp = (List)malloc(sizeof(struct LNode));
	List pos = L;
	List pre = L;
	temp->Data = X;
	temp->Next = NULL;
	int flag = 0;
	if (L == P) {//理解为头插
		temp->Next = P;
		List t = temp;
		return temp;
	}
	while (pos != NULL) {//非头插,头不变
		if (pos == P) {
			temp->Next = pos;
			pre->Next = temp;
			flag = 1;
			break;
		}
		pre = pos;
		pos = pos->Next;
	}
	if (flag == 1) {
		return L;
	}
	else {
		printf("Wrong Position for Insertion");
		return ERROR;
	}
};

List Delete(List L, Position P) {
	List pos = L;
	List pre = L;
	List temp;
	int flag = 0;
	if (L == P) {//理解为头删;
		temp = L->Next;
		free(L);
		return temp;
	}
	while (pos != NULL) {//非头删,头不变
		if (pos == P) {
			pre->Next = pos->Next;
			free(P);
			flag = 1;
			break;
		}
		pre = pos;
		pos = pos->Next;
	}
	if (flag == 1) {
		return L;
	}
	else {
		printf("Wrong Position for Deletion");
		return ERROR;
	}
};

int main()
{
	List L;
	ElementType X;
	Position P, tmp;
	int N;

	L = NULL;
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &X);
		L = Insert(L, X, L);
		if (L == ERROR) printf("Wrong Answer\n");
	}
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &X);
		P = Find(L, X);
		if (P == ERROR)
			printf("Finding Error: %d is not in.\n", X);
		else {
			L = Delete(L, P);
			printf("%d is found and deleted.\n", X);
			if (L == ERROR)
				printf("Wrong Answer or Empty List.\n");
		}
	}
	L = Insert(L, X, NULL);
	if (L == ERROR) printf("Wrong Answer\n");
	else
		printf("%d is inserted as the last element.\n", X);
	P = (Position)malloc(sizeof(struct LNode));
	tmp = Insert(L, X, P);
	if (tmp != ERROR) printf("Wrong Answer\n");
	tmp = Delete(L, P);
	if (tmp != ERROR) printf("Wrong Answer\n");
	for (P = L; P; P = P->Next) printf("%d ", P->Data);
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
