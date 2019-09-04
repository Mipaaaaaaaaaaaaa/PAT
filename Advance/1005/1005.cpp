// 1005.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include<iostream>
#include<string>

using namespace std;

class sovle {
public:
	string num;
	int result;
	void innum() {
		cin >> num;
	}
	void calculate() {
		result = 0;
		for (int i = 0; i < num.length(); i++) {
			result += num[i] - '0';
		}
	}
	void print() {
		int resultn = result;
		int shu[8] = { 0 };
		int i = 0;
		while (resultn != 0) {
			shu[i] = resultn % 10;
			i++;
			resultn = resultn / 10;
			//cout << i << endl; 
		}
		i--;
		if (i = -1) {
			cout << "zero";
		}
		for (; i >= 0; i--) {
			switch (shu[i]) {
			case 0:  cout << "zero";
				break;
			case 1:  cout << "one";
				break;
			case 2:  cout << "two";
				break;
			case 3:  cout << "three";
				break;
			case 4:  cout << "four";
				break;
			case 5:  cout << "five";
				break;
			case 6:  cout << "six";
				break;
			case 7:  cout << "seven";
				break;
			case 8:  cout << "eight";
				break;
			case 9:  cout << "nine";
				break;
			}
			if (i > 0) {
				cout << " ";
			}
		}
	};
};

int main(int argc, char** argv) {
	sovle* re = new sovle();
	re->innum();
	re->calculate();
	re->print();
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
