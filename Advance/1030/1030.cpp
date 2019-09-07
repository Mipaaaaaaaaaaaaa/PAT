// 1030.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <queue>
#define INF 99999999
using namespace std;
struct edge {
	int v,dis,cost;//末端结点、距离、权重
	edge( int _v, int _d, int _c) {
		v = _v;
		dis = _d;
		cost = _c;
	}
};
vector<vector<edge> > graph(505);
int dis[505], cost[505], pathLast[505];//起点到该点的距离,起点到该点的最小权重,起点到该点的父节点
bool visited[505] = {false};
int N, M, S, D;
void Dijkstra() {
	while (!visited[D]) {
		int v = -1, min = INF;
		for (int i = 0; i < N; i++) {
			if (!visited[i] && dis[i] < min) {
				v = i;
				min = dis[i];
			}
		}
		if (v == -1) return;//未联通
		visited[v] = true;//访问该点
		for ( edge&e : graph[v] ) {
			if (!visited[e.v] && dis[e.v] > dis[v] + e.dis ){
				dis[e.v] = dis[v] + e.dis;
				cost[e.v] = cost[v] + e.cost;
				pathLast[e.v] = v;
			}
			else if(dis[e.v] == dis[v]+ e.dis && cost[e.v]> cost[v] + e.cost){//花费更少
				cost[e.v] = cost[v] + e.cost;
				pathLast[e.v] = v;
			}
		}
	}
}

void DFS(int v) {
	if (v == S) {
		printf("%d", v);
	}
	else {
		DFS(pathLast[v]);
		printf(" %d", v);
	}
}

int main()
{
	cin >> N >> M >> S >> D;
	int a, b, c, d;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		graph[a].push_back(edge(b, c, d));
		graph[b].push_back(edge(a, c, d));
	}
	fill(dis, dis + N, INF);
	fill(cost, cost + N, INF);
	dis[S] = cost[S] = 0;
	Dijkstra();
	DFS(D);
	printf(" %d %d", dis[D], cost[D]);
    //cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 求解最短路径: 
//		1.从出发到终点最短路径
//		2.总距离