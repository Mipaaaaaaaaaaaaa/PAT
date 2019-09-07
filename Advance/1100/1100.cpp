// 1100.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std;
string c[13] = { "tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
string b[13] = { "***","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };

void function1(int a) {
	if (a / 13) cout << b[a / 13];
	if ((a / 13) && (a % 13)) cout << " ";
	if (a % 13 || a == 0) cout << c[a % 13];
}
void function2(string a) {
	int t1 = 0, t2 = 0;
	string s1 = a.substr(0, 3);
	string s2;
	if (a.length() > 4) s2 = a.substr(4, 3);
	for (int i = 1; i <= 12; i++) {
		if (s1 == c[i] || s2 == c[i]) t2 = i;
		if (s1 == b[i]) t1 = i;
	}
	cout << t1 * 13 + t2;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string a;
		getline(cin,a);
		if (isdigit(a[0]))
			function1(stoi(a));
		else
			function2(a);
	}
	cout << endl;
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
