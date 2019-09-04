// 1012.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
char course[4] = {'A', 'C', 'M', 'E'};
int Rank[1000000][4] = { 0 };
int now;

struct Student {
	int id;
	int grade[4];
}stu[2020];

bool cmp(Student a, Student b) {
	return a.grade[now] > b.grade[now];
}

int main()
{

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i ++ ) {
		cin >> stu[i].id >> stu[i].grade[1] >> stu[i].grade[2] >> stu[i].grade[3];
		stu[i].grade[0] = ( stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3] ) / 3;
	}
	now = 0;
	for (int i = 0; i < 4; i++,now++) {
		sort(stu, stu+N, cmp);
		for (int j = 0; j < N; j++) {
			Rank[stu[j].id][now] = 1;
			if (stu[j].grade[now] == stu[j - 1].grade[now])
				Rank[stu[j].id][now] = Rank[stu[j - 1].id][now];
			else
				Rank[stu[j].id][now] = j+1;
		}
	}
	for (int i = 0; i < M; i++) {
		int ID,max = 10000;
		now = 0;
		cin >> ID;
		for (int j = 0; j < 4; j++) {
			if (Rank[ID][j] < max) {
				max = Rank[ID][j];
				now = j;
			}
		}
		if (Rank[ID][now] == 0) {
			cout << "N/A" << endl;
		}
		else
		cout << Rank[ID][now] << " " << course[now] << endl;
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
