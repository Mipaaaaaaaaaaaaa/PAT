// 1010.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//二分查找

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

long long convert( string n , long long radix) {
	long long sum = 0;
	int index = 0, temp = 0;
	for (auto it = n.rbegin(); it != n.rend(); it++) {
		temp = isdigit(*it) ? *it - '0' : *it - 'a' + 10;
		sum += temp * pow(radix, index++);
	}
	return sum;
}
long long find_radix(string n, long long num) {
	char it = *max_element(n.begin(), n.end());
	long long low = (isdigit(it) ? it - '0' : it - 'a' + 10) + 1;
	long long high = max(num, low);
	while (low <= high) {
		long long mid = (high + low) / 2;
		long long t = convert(n, mid);
		if (t<0 || t > num)
			high = mid - 1;
		else if (t == num)
			return mid;
		else
			low = mid + 1;
	}
	return -1;
}
int main()
{
	string n1, n2;
	long long tag, radix, result;
	cin >> n1 >> n2 >> tag >> radix;
	result = tag == 1 ? find_radix(n2, convert(n1, radix)) : find_radix(n1, convert(n2, radix));
	if (result != -1)
		printf("%lld", result);
	else
		printf("Impossible");
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
