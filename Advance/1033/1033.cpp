// 1033.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#define max 99999999
using namespace std;
struct station {
	double price;
	double distance;
} sta[505];

bool cmp(station a, station b) {
	return a.distance < b.distance;
};

int main()
{
	double result = 0;
	double c, d, davg;
	int n;
	double nowprice=0;
	double totalprice=0;
	double leftdistance=0;
	double maxdistance=0;
	double minprice=0;
	cin >> c >> d >> davg >> n;
	for (int i = 0; i < n; i++) {
		cin >> sta[i].price >> sta[i].distance;
	}
	sta[n].price = 0;
	sta[n].distance = d;
	sort(sta, sta + n, cmp);
	if (sta[0].distance != 0) {
		printf("The maximum travel distance = %.2f", result);
		return 0;
	}
	else {
		nowprice = sta[0].price;
	}
	while (result < d) {
		maxdistance = result + davg * c;
		double minprice = max;
		double minpricedis = 0;
		int flag = 0;
		for (int i = 1; i <= n && sta[i].distance <= maxdistance; i++) {
			if (sta[i].distance <= result) continue;
			if (sta[i].price < nowprice) {
				totalprice += (sta[i].distance - result - leftdistance) * nowprice / davg;
				leftdistance = 0;
				nowprice = sta[i].price;
				result = sta[i].distance;
				flag = 1;
				break;
			}
			if (sta[i].price < minprice) {
				minprice = sta[i].price;
				minpricedis = sta[i].distance;
			}
		}
		if (flag == 0 && minprice != max) {
			totalprice += (nowprice * (c - leftdistance / davg));
			leftdistance = c * davg - (minpricedis - result);
			nowprice = minprice;
			result = minpricedis;
		}
		if (flag == 0 && minprice == max) {
			result = maxdistance;
			printf("The maximum travel distance = %.2f", result);
			return 0;
		}
	}

   printf("%.2f",totalprice);
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
