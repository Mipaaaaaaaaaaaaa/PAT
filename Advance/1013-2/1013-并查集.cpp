//=======3-并查8集.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <set>
#define max 1002 
using namespace std;

struct edge {
	int u, v;
	edge(int _u, int _v) {
		u = _u;
		v = _v;
	}
};

int N, M, K;
vector<edge> edges;

int father[max];
set<int> fathers;

int find(int ch) {
	if (ch == father[ch])
		return ch;
	return father[ch] = find(father[ch]);
}

void merge(int u, int v) {
	int fu = find(u);
	int fv = find(v);
	if (fu != fv) {
		father[fu] = fv;
	}
}

int main()
{
	cin >> N >> M >> K;
	int a, b;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		edges.push_back(edge(a, b));
	}
	for (int i = 0; i < K; i++) {
		for (int j = 1; j <= N; j++) {
			father[j] = j;
		}
		int city, count=0;
		fathers.clear();
		scanf("%d", &city);
		for (int j = 0; j < edges.size(); j++) {
			if (edges[j].u == city || edges[j].v == city) {
				continue;
			}
			else
			merge(edges[j].u, edges[j].v);
		}
		for (int j = 1; j <= N; j++) {
			if (father[j] == j) {
				count++;
			}
			fathers.insert(find(j));
		}
		cout << fathers.size() - 2 << " " << count - 2 << endl;
	}
	return 0;
    //cout << "Hello Jeanne!\n";
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
