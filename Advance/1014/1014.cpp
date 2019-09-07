// 1014.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <deque>
using namespace std;
int main()
{
	int window[22] = {0};
	deque<int> windows[22];
	int customers[1003];
	int leavetime[1003] = {0};
	bool sorry[1003] = {false};
	int n, m, k, q;
	cin >> n >> m >> k >> q;
	for (int i = 0; i < k; i++) {
		int temp;
		cin >> customers[i];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i * n + j < k) {
				windows[j].push_back(customers[i * n + j]);
				window[j] += customers[i * n + j];
				leavetime[i * n + j] = window[j];
			}
		}
	}
	for (int i = n*m ; i < k; i++) {
		int fast = windows[0].front();
		int tempwin = 0;
		for (int j = 1; j < n; j++) {
			if (windows[j].front() < fast) {//最快的柜台
				fast = windows[j].front();
				tempwin = j;
			}
		}
		windows[tempwin].pop_front();//出队
		for (int j = 0; j < n; j++) {//遍历每个窗口 减时间
			if (j == tempwin) continue;
			int temp = windows[j].front();
			temp = temp - fast;
			windows[j].pop_front();
			windows[j].push_front(temp);
		}
		if (window[tempwin] >= 540) {
			sorry[i] = true;
		}
		else {
			windows[tempwin].push_back(customers[i]);
			window[tempwin] += customers[i];
			leavetime[i] = window[tempwin];
		}
	}
	for (int i = 0; i < q; i++) {
		int ask;
		cin >> ask;
		int hh, mm;
		hh = 8 + leavetime[ask-1] / 60;
		mm = leavetime [ask-1]% 60;
		if ( sorry[ask-1] ) {
			cout << "Sorry" << endl;
		}
		else
			printf("%02d:%02d\n", hh, mm);
	}
    //std::cout << "Hello World!\n";
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
