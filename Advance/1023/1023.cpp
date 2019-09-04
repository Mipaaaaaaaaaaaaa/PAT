// 1023.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int book[10] = { 0 };
	char num[22];
	int flag = 0,flag1 = 0;
	cin >> num;
	//cout << num;
	int len = strlen(num);
	for (int i = len - 1; i >= 0; i--) {
		int temp = num[i] - '0';
		book[temp] ++;
		temp = temp * 2 + flag;
		flag = 0;
		if (temp >= 10) {
			temp = temp - 10;
			flag = 1;
		}
		num[i] = temp + '0';
		book[temp]--;
	}
	for (int i = 0; i < 10; i++) {
		if (book[i] != 0) {
			flag1 = 1;
		}
	}
	printf((flag || flag1) ? "No\n" : "Yes\n");
	if (flag == 1) {
		printf("1");
	}
    cout << num << endl;
	return 0;
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
