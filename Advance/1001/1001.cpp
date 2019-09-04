// 1001.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int a, b, c;
	bool flag = true;
	cin >> a >> b;
	c = a + b;
	string output = to_string(c);
	if (abs(c) >= 1e6) {
		output.insert(output.length() - 6, ",");
	}
	if (abs(c) >= 1e3) {
		output.insert(output.length() - 3, ",");
	}
	cout << output << endl;
    std::cout << "Hello World!\n";
}



