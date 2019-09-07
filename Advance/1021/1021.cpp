// 1021.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
vector< vector<int>> v;
bool visit[10010];
int n, maxheight = 0;
set<int>s;
vector<int> temp;
void dfs(int node, int height) {
	if (height > maxheight) {
		temp.clear();
		temp.push_back(node);
		maxheight = height;
	}
	else if (height == maxheight) {
		temp.push_back(node);
	}
	visit[node] = true;
	for (int i = 0; i < v[node].size(); i++) {
		if (visit[v[node][i]] == false)
			dfs(v[node][i], height + 1);
	}
}
int main() {
	scanf("%d", &n);
	v.resize(n + 1);
	int a, b, cnt = 0, s1 = 0;
	for (int i = 0; i < n - 1; i++) {
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (visit[i] == false) {
			dfs(i, 1);
			if (i == 1) {
				if (temp.size() != 0)s1 = temp[0];
				for (int j = 0; j < temp.size(); j++)
					s.insert(temp[j]);
			}
			cnt++;
		}
	}
	if (cnt >= 2) {
		printf("Error: %d components",cnt);
	}
	else {
		temp.clear();
		maxheight = 0;
		fill(visit, visit + 10010, false);
		dfs(s1, 1);
		for (int i = 0; i < temp.size(); i++)
			s.insert(temp[i]);
		for (auto& it : s) {
			printf("%d\n", it);
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
