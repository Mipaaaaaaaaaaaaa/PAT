// 1025.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct student {
	string num;
	int grade;
	int group;
	int rank1;
	int rank2;
}stu[30005] ;
int now_group;
int groupnum[100];

bool cmp1(student a, student b) {
	if (a.grade != b.grade)
		return a.grade > b.grade;
	else
		return a.num < b.num;
}
bool cmp2(student a, student b) {
	return a.rank1+a.rank2 < b.rank1+b.rank2;
}


int main()
{
	int n, k;
	cin >> n;
	int count = 0;
	for (int i = 0; i < n; i++) {
		cin >> k;
		for (int j = 0; j < k; j++) {//输入
			cin >> stu[count + j].num >> stu[count + j].grade;
			stu[count + j].group = i + 1;
		}
		sort(stu + count, stu + count + k, cmp1);//排序
		stu[count].rank1 = (int)1;
		for (int m = 1; m < k; m++) {//排名次
			if (stu[count + m].grade == stu[count + m - 1].grade) {
				stu[count + m].rank1 = stu[count + m - 1].rank1;
			}

			else
				stu[count + m].rank1 = m+1;
		}
		count += k;
	}
	sort(stu, stu + count, cmp1);
	stu[0].rank2 = 1;
	for (int i = 1; i < count; i++) {
		if (stu[i].grade == stu [i - 1].grade) {
			stu[i].rank2 = stu[i - 1].rank2;
		}
		else
			stu[i].rank2 = i + 1;
	}
	cout << count << endl;
	for (int i = 0; i < count; i++) {
		cout << stu[i].num << " " << stu[i].rank2 << " " << stu[i].group << " " << stu[i].rank1 << endl;
	}
    std::cout << "Hello World!\n";
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
