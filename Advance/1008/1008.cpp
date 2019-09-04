// 1008.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
struct node
{
	int data;
	node* next;
};
typedef struct node Node, * List;

void insert( List head, int data ) {
	Node* p = head;
	while (p->next != NULL) {
		p = p->next;
	}
			Node* t = new Node;
			t->data = data;
			t->next = NULL;
			p->next = t;
}
using namespace std;

int main()
{	
	int K,data,sum=0;
	cin >> K;
	List head = new Node;
	head->data = 0;
	head->next = NULL;
	for (int i = 0; i < K; i++) {
		cin >> data;
		insert( head, data );
	}
	for (Node* t = head; t != NULL; t = t->next) {
		if (t->next != NULL) {
			if ( t->next->data > t->data ) { //上楼梯
				sum += 6 * (t->next->data - t->data);
			}
			else if (t->next->data < t->data) {//下楼梯
				sum += 4 * ( t->data - t->next->data );
			}
		}
	}
	sum += 5 * K;
    cout << sum;
}


// 题目:
// 1.上楼6秒/层
// 2.下楼4秒/层
// 3.每个楼层停5秒
