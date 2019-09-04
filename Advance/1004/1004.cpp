// 1004.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <deque>
using namespace std;


vector<int> T[100];
int leave[100];
int maxdep = -1;

void dfs(int index, int dep) {
	if (T[index].size() == 0) {
		leave[dep]++;
		maxdep = maxdep > dep ? maxdep : dep;
		return;
	}
	for (int i = 0; i < T[index].size(); i++) {
		dfs(T[index].at(i), dep + 1);
	}
}

int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int K;
		int ID;
		cin >> ID >> K;
		for (int j = 0; j < K; j++) {
			int ch;
			cin >> ch;
			T[ID].push_back(ch);
		}
	}
	dfs(1,0);
	for (int i = 0; i <= maxdep; i++) {
		cout << leave[i];
			if (i != maxdep) {
				cout << " ";
			}
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
