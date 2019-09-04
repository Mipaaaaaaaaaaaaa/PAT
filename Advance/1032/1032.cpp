// 1032.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(int argc, const char* argv[]) {
	int next[100002];
	char data[100002];
	vector<int> temp;
	int head[2], N;
	int flag = 0;
	//cout << "Hello, World!\n";
	cin >> head[0] >> head[1] >> N;
	for (int i = 0; i < N; i++) {
		int temp1;
		int temp2;
		char da;
		//cin >> temp1 >> da >> temp2;
		scanf("%d %c %d", &temp1, &da, &temp2);
		data[temp1] = da;
		next[temp1] = temp2;
	}
	while (head[0] != -1 && !flag) {
		int i;
		i = head[1];
		while (head[1] != -1) {
			if (head[0] == head[1])
				break;
			else head[1] = next[head[1]];
		}
		if (head[0] == head[1])
			flag = 1;
		else head[0] = next[head[0]];
		head[1] = i;
	}
	if (head[0] != -1)
		printf("%05d", head[0]);
	else
		printf("-1");
	//cout << "Hello, World!\n";
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
