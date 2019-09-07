// 1026.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
using namespace std;
struct customer {
	int arriveTime;
	int playTime;
	int serveTime;
	int waitTime;
	int tag;
}cus[10002];

bool cmp(customer a, customer b) {
	return a.arriveTime < b.arriveTime;
}
int main()
{
	int n, m, k;
	int table[102];
	int tag[102];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int hh, mm, ss;
		int p1;
		scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &p1, &cus[i].tag);
		cus[i].arriveTime = hh * 3600 + mm * 60 + ss;
		cus[i].playTime = p1 * 60;
	}
	sort(cus, cus + n, cmp);
	cin >> k >> m;
	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		tag[temp] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {

		}
	}


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
