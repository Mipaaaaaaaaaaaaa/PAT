// 1011.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
enum  Game{
	W = 0, T = 1, L = 2
};
int main()
{
	double win[3];
	double tie[3];
	double lose[3];
	char bet[3];
	double sum = 1;
	for (int i = 0; i < 3; i++) {
		cin >> win[i] >> tie[i] >> lose[i];
		if (win[i] > tie[i]) {
			if (win[i] > lose[i]) {
				bet[i] = 'W';
				sum *= win[i];
			}
			else {
				bet[i] = 'T';
				sum *= lose[i];
			}
		}
		else {
			if (tie[i] > lose[i]) {
				bet[i] = 'T';
				sum *= tie[i];
			}
			else {
				bet[i] = 'L';
				sum *= lose[i];
			}
		}
	}
	sum = (sum * 0.65 - 1) * 2;
	cout << bet[0] << " " << bet[1] << " " << bet[2] << " " << fixed << setprecision(2) << sum ;
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 题目：
// 1.选择三个比赛
// 2.选择输赢
// 3.计算最大收益
