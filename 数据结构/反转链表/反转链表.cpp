// 反转链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
typedef struct Node* PtrToNode;

struct Node {
	ElementType Data;
	PtrToNode   Next;
};
typedef PtrToNode List;

List Read() {
	List L = (List)malloc(sizeof(Node*));
	List p = L;
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		List t = (List)malloc(sizeof(struct Node));
		scanf("%d",&t->Data);
		t->Next = NULL;
		p->Next = t;
		p = p->Next;
	}
	return L;
} 

void Print(List L) {
	PtrToNode p = L->Next;
	while (p != NULL) {
		printf("%d", p->Data);
		if (p->Next != NULL) {
			printf(" ");
		}
		else {
			printf("\n");
		}
		p = p->Next;
	}
}

//List Reverse(List L) {
//	List R = L;
//	List p = L;
//	while (p->Next != NULL) {
//		List temp;
//		temp = p->Next;
//		p->Next = R->Next;
//		R->Next = temp;
//		p = L->Next;
//	}
//	return R;
//}
List Reverse(List L) {
	List R = (List)malloc(sizeof(struct Node));
	R->Next = NULL;
	List t = L->Next;
	while (t != NULL) {
		List temp = (List)malloc(sizeof(struct Node));
		temp->Data = t->Data;
		temp->Next = R->Next;
		R->Next = temp;
		t = t->Next;
	}
	List temp = R;
	while (temp->Next != NULL) {
		temp = temp->Next;
	}
	L->Next = temp;
	return R;
}

int main()
{
	List L1, L2;
	L1 = Read();
	L2 = Reverse(L1);
	Print(L1);
	Print(L2);
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
