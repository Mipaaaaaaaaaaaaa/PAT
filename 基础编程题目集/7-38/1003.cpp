// 1003.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std;
int main()
{
	string A;
	int N;
	string S = "";
	string w = "";
	cin >> A;
	cin >> N;
	for (int i = 0; i < N; i++) {
		w = w + A;
		//字符串模拟运算
		int j;
		for (int j = 1; j <= S.length(); j++) {
			S.at(S.size() - j) = S.c_str()[S.size() - j] + w.c_str()[w.size() - j] - '0';
		}
		for (j = S.length()+1; j <= w.length() ; j++) {
			S = " " + S;
			S.at(S.length()-j) = w.c_str()[w.length()-j];
		}
		int carry = 0;
		for (int k = 1 ;k <= S.length();   k++) {
			int value = S.at(S.length()-k) - '0' + carry;
			carry = value / 10;
			S.at(S.length()-k) = value - carry * 10 + '0';
		}
	}
	if (S == "") {
		cout << "0" << endl;
	}
	else {
		cout << S << endl;
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
