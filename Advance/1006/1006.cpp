// 1006.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main() {
	string mins, maxs, str;
	string minT = "23:59:59";
	string maxT = "00:00:00";
	string tmp_in, tmp_out;
	int num, i;

	cin >> num;
	for (i = 0; i < num; i++) {
		cin >> str >> tmp_in >> tmp_out;
		if (tmp_in <= minT) {
			mins = str;
			minT = tmp_in;
		}
		if (tmp_out >= maxT) {
			maxs = str;
			maxT = tmp_out;
		}
	}
	cout << mins << " " << maxs << endl;
	return 0;
}
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

//  题目：
//  给出ID、登录登出时间 算出谁是第一个谁是最后一个
