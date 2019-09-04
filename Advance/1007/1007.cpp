// 1007.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
int main()
{
	int K;
	int* a;
	int* b;
	cin >> K;
	a = (int*)malloc(sizeof(int) * (K + 1));
	b = (int*)malloc(sizeof(int) * (K + 1));
	a[0] = 0;
	b[0] = 0;
	int flag = 0;
	for (int i = 1; i <= K; i++) {
		cin >> a[i];
		if (a[i] >= 0) {//
			flag = 1;
		}
		b[i] = b[i - 1] + a[i];
	}
	if (flag) {
		int max = b[1], min = b[1];
		int start = 1, end = 1;
		for (int i = K; i >= 0; i--) {
			if (b[i] > max) {
				max = b[i];
				end = i;
			}
		}
		min = max;
		for (int i = end; i >= 0; i--) {
			if (b[i] < min) {
				min = b[i];
				start = i;
			}
		}
		cout << max - min << " " << a[start + 1] << " " << a[end];
	}
	else {
		cout << "0 " << a[1] << " " << a[K] << endl;
	}
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
