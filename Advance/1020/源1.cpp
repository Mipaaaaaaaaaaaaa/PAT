struct TreeNode {
	ElementType Element;
	Tree Left;
	Tree Right;
};

typedef struct SNode* PtrToSNode;
struct SNode {
	Tree Data;
	PtrToSNode Next;
};
typedef PtrToSNode Stack;

Stack CreateStack()
{ /* 构建一个堆栈的头结点，返回该结点指针 */
	Stack S;

	S = (Stack)malloc(sizeof(struct SNode));
	S->Next = NULL;
	return S;
}

bool IsEmpty(Stack S)
{ /* 判断堆栈S是否为空，若是返回true；否则返回false */
	return (S->Next == NULL);
}

bool Push(Stack S, Tree X)
{ /* 将元素X压入堆栈S */
	PtrToSNode TmpCell;

	TmpCell = (PtrToSNode)malloc(sizeof(struct SNode));
	TmpCell->Data = X;
	TmpCell->Next = S->Next;
	S->Next = TmpCell;
	return true;
}

Tree Pop(Stack S)
{ /* 删除并返回堆栈S的栈顶元素 */
	PtrToSNode FirstCell;
	Tree TopElem;

	if (IsEmpty(S)) {
		printf("堆栈空");
		return TopElem;
	}
	else {
		FirstCell = S->Next;
		TopElem = FirstCell->Data;
		S->Next = FirstCell->Next;
		free(FirstCell);
		return TopElem;
	}
}
//先序遍历过程:
//1.访问根结点
//2.先序遍历左子树
//3.先序遍历右子树
//
//void PreOrderTraversal(Tree T) {
//	if (T) {
//		cout << T->Element;
//		PreOrderTraversal(T->Left);
//		PreOrderTraversal(T->Right);
//	}
//}

void PreOrderTreversal(Tree T) {
	Stack S = CreateStack();
	Tree t = T;
	while (t || !IsEmpty(S)) {
		while (t) {
			Push(S, t);
			t = t->Left;
		}
		if (!IsEmpty(S)) {
			T = Pop(S);
			cout << t->Element;
			t = t->Right;
		}
	}
}

//中序遍历过程:
//1.中序遍历左子树
//2.访问根结点
//3.中序遍历右子树

void InOrderTraversal(Tree T) {
	if (T) {
		InOrderTraversal(T->Left);
		cout << T->Element;
		InOrderTraversal(T->Right);
	}
}

//后序遍历过程:
//1.后序遍历左子树
//2.后序遍历右子树
//3.访问根结点

void PostOrderTraversal(Tree T) {
	if (T) {
		PostOrderTraversal(T->Left);
		PostOrderTraversal(T->Right);
		cout << T->Element;
	}
}

#include <stdio.h>
#include <stdlib.h>

#define MaxTree 10 /* maximum number of nodes in a tree */
typedef int ElementType;

typedef struct TreeNode* Tree;
struct TreeNode {
	ElementType Element;
	Tree  Left;
	Tree  Right;
};

Tree BuildTree() {
	Tree T;
	T = (Tree)malloc(sizeof(struct TreeNode));
	T->Left = NULL;
	T->Right = NULL;
	return T;
}

void PrintNode(Tree NodePtr)
{
	printf(" %d", NodePtr->Element);
}

void Level_order(Tree T, void (*visit)(Tree ThisNode));

int main()
{
	Tree T = BuildTree();
	printf("Level-order:");
	Level_order(T, PrintNode);
	return 0;
}

void Level_order(Tree T, void (*visit)(Tree ThisNode)) {
	if (!T->Element)
		(*visit)(T);
	else {
		Tree* p;
		p = (Tree*)malloc(sizeof(Tree) * MaxTree);
		int p_f = -1;
		int p_r = -1;//一个前减后加队列
		int i = 0;
		p_r++;
		p[p_r] = T;
		while (p_f != p_r) {
			p_f++;
			if (p[p_f]->Left) {
				p_r++;
				p[p_r] = p[p_f]->Left;
			}
			if (p[p_f]->Right) {
				p_r++;
				p[p_r] = p[p_f]->Right;
			}
		}
		while (p[i] != NULL) {
			(*visit)(p[i]);
			i++;
		}
	}
}
void PrintNode(Tree NodePtr)
{
	printf(" %d", NodePtr->Element);
}
