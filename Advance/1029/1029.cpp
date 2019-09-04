// 1029.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int main()
{
	int n1, n2;
	vector<int> s1;
	cin >> n1;
	for (int i = 0; i < n1; i++) {
		int temp;
		cin >> temp;
		s1.push_back(temp);
	}
	qsort(s1.data(),n1,sizeof(int),compare);
	cin >> n2;
	int mid = (n1 + n2 + 1) / 2;
	int count = 0;
	int i = 1;
	for (int j = 1; j < n2; j++) {
		int temp;
		cin >> temp;
		while (s1[i] < temp) {
			count++;
			if (count == mid) {
				cout << s1[i];
			}
			i++;
		}
		count++;
		if (count == mid) {
			cout << temp;
		}
	}
	while (i <= n1) {
		count++;
		if (count == mid) {
			cout << s1[i];
		}
		i++;
	}
	; return 0;
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
