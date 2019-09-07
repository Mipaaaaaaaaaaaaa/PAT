// 1003.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <memory>
#define INF 9999


using namespace std;
int rescue[505];
int dis[505], num[505], sum[505];
int visit[505];
int a[505][505];

int n;//city numbers;
int m;//road numbers;
int c1;//start;
int c2;//destination;


void Dijkstra() {
	int minD,v;
	dis[c1] = 0;
	sum[c1] = rescue[c1];
	num[c1] = 1;
	for (int i = 0; i < n; i++) {
		minD = INF;
		v = -1;
		for (int j = 0; j < n; j++) {
			if (!visit[j] && dis[j] < minD) {
				minD = dis[j];
				v = j;
			}
		}
		visit[v] = 1;
		for (int j = 0; j < n; j++) {
			if (dis[j] > dis[v] + a[j][v]) {
				dis[j] = dis[v] + a[j][v];
				num[j] = num[v];
				sum[j] = sum[v] + rescue[j];
			}
			else if (dis[j] == dis[v] + a[j][v]) {
				num[j] += num[v];
				if (sum[j] < sum[v] + rescue[j]) {
					sum[j] = sum[v] + rescue[j];
				}
			}
		}

	}
}

int main()
{
	fill(rescue, rescue + 505, 0);
	fill(dis, dis + 505, INF);
	fill(visit, visit + 505, 0);
	memset(a, INF, sizeof(a));

	cin >> n >> m >> c1 >> c2;
	for (int i = 0; i < n; i++) {
		cin>> rescue[i];
	}
	for (int i = 0; i < m; i++) {
		int r1, r2,rd;
		cin >> r1 >> r2 >> rd;
		a[r1][r2] = rd;
		a[r2][r1] = rd;
	}
	
	Dijkstra();
	cout << num[c2] << " " << sum[c2] << endl;
    std::cout << "Hello World!\n";
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
