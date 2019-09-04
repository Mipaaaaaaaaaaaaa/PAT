#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 7
#define ERROR -1

typedef int ElementType;
typedef int Position;
typedef struct LNode* List;
struct LNode {
	ElementType Data[MAXSIZE];
	Position Last; /* 保存线性表中最后一个元素的位置 */
};

List MakeEmpty() {
	List Ptr;
	Ptr = (List)malloc(sizeof(struct LNode));
	Ptr->Last = -1;
	return Ptr;
};

Position Find(List L, ElementType X) {
	for (int i = 0; i <= L->Last; i++) {
		if (X == L->Data[i]) {
			return i;
		}
	}
	return ERROR;
};
bool Insert(List L, ElementType X, Position P) {
	if (L->Last == MAXSIZE - 1) {
		printf("FULL");
		return false;
	}
	if (P<0 || P > L->Last+1) {
		printf("ILLEGAL POSITION");
		return false;
	}
	ElementType temp1 = L->Data[P];
	ElementType temp2 = -1;
	L->Data[P] = X;
	L->Last++;
	for (int i = P + 1; i <= L->Last; i++) {
		if (temp1 == -1) {
			temp1 = L->Data[i];
			L->Data[i] = temp2;
			temp2 = -1;
		}
		else if (temp2 == -1) {
			temp2 = L->Data[i];
			L->Data[i] = temp1;
			temp1 = -1;
		}
	}
	//for (int i = 0; i <= L->Last; i++) {
	//	printf("%d ", L->Data[i]);
	//}
	//printf("\n");
	return true;
};
bool Delete(List L, Position P) {
	if (P<1 || P > L->Last) {
		printf("POSITION %d EMPTY",P);
		return false;
	}
	for (int i = P; i < L->Last; i++ ) {
		L->Data[i] = L->Data[i + 1];
	}
	L->Last--;
	return true;
};

int main()
{
	List L;
	ElementType X;
	Position P;
	int N;

	L = MakeEmpty();
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &X);
		if (Insert(L, X, 0) == false)
			printf(" Insertion Error: %d is not in.\n", X);
	}
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &X);
		P = Find(L, X);
		if (P == ERROR)
			printf("Finding Error: %d is not in.\n", X);
		else
			printf("%d is at position %d.\n", X, P);
	}
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &P);
		if (Delete(L, P) == false)
			printf(" Deletion Error.\n");
		if (Insert(L, 0, P) == false)
			printf(" Insertion Error: 0 is not in.\n");
	}
	return 0;
}