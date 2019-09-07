// 1066.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
using namespace std;
struct node {
	int val;
	struct node* left, *right;
};
node* rotateLeft(node* root) {
	node* t = root->right;
	root->right = t->left;
	t->left = root;
	return t;
}
node* rotateRight(node* root) {
	node* t = root->left;
	root->left = t->right;
	t->right = root;
	return t;
}
node* rotateLeftRight(node* root) {
	root->left = rotateLeft(root->left);
	return rotateRight(root);
}

node* rotateRightLeft(node* root) {
	root->right = rotateRight(root->right);
	return rotateLeft(root);
}

int getHeight(node* root) {
	if (root == NULL)return 0;
	return max(getHeight(root->left), getHeight(root->right)) + 1;
}
node* insert(node* root, int val) {
	if (root == NULL) {
		root = new node();
		root->val = val;
		root->left = root->right = NULL;
	}
	else if (val < root->val) {
		root->left = insert(root->left, val);
		if (getHeight(root->left) - getHeight(root->right) == 2)
			root = val < root->left->val ? rotateRight(root) : rotateLeftRight(root);
	}
	else {
		root->right = insert(root->right, val);
		if (getHeight(root->left) - getHeight(root->right) == -2)
			root = val > root->right->val ? rotateLeft(root) : rotateRightLeft(root);
	}
	return root;
}
int main()
{
	int n, val;
	scanf("%d", &n);
	node* root = NULL;
	for (int i = 0; i < n; i++) {
		scanf("%d", &val);
		root = insert(root, val);
	}
    cout << root->val;
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
