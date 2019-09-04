// 1030.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stack>
#include <queue>
using namespace std;
struct edge {
	int u, v;
	edge(int _u, int _v) {
		u = _u;
		v = _v;
	}
};

int main()
{
	int N, M, S, D;
	cin >> N >> M >> S >> D;
	for (int i = 0; i < M; i++) {
		
	}
    cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 求解最短路径: 
//		1.从出发到终点最短路径
//		2.总距离