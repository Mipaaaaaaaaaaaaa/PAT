// 1013.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <memory.h>
#include <queue>
#define max 1001

using namespace std;
int edge[max][max];//邻接矩阵
int visited[max];
int N, M, K;

using namespace std;

void dfs( int v ) {
	visited[v] = 1;
	for (int i = 1; i <= N; i++) {
		if (!visited[i] && edge[i][v] == 1)
			dfs(i);
	}
}

void bfs(int v) {
	queue<int> q;
	q.push(v);
	visited[v] = 1;
	while (!q.empty()) {
		int n = q.front();
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (!visited[i] && edge[n][i] == 1) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

int main()
{
	cin >> N >> M >> K;
	for ( int i = 0; i < M; i++ ) {
		int e, d;
		scanf("%d%d", &e, &d);
		edge[e][d] = 1;
		edge[d][e] = 1;
	}
	for ( int i = 0; i < K; i++ ) {
		int count = 0;
		int city = 0;
		cin >> city;
		memset(visited, 0, sizeof(visited));
		visited[city] = 1;
		for (int j = 1; j <= N; j++) {
			if (visited[j] == 0) {
				bfs(j);
				count++;
			}//该点未连同 需要加一条边
		}
		cout << count - 1 << endl;
	}

	cout << "Hello World!\n";
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
