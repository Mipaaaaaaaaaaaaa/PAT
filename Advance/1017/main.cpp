#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
struct node {
	int come, time;
	node(int _c,int _t) {
		come = _c;
		time = _t;
	}
};
bool cmp(node a, node b) {
	return a.come < b.come;
}

int main() {
	int N, K;
	vector<node> cus;
	cin >> N >> K ;
	for (int i = 0; i < N; i++) {
		int hh, mm, ss,t;
		scanf("%d:%d:%d %d", &hh, &mm, &ss, &t);
		int come = hh * 3600 + mm * 60 + ss;
		if (come > 61200) continue;//ÕÌ¿¥¡À
		cus.push_back(node(come, t*60));
	}
	sort(cus.begin(), cus.end(), cmp);
	vector<int> window(K, 28800);
	double result = 0.0;
	for (auto it = cus.begin(); it != cus.end(); it++) {
		int tempindex = 0, minfinish = window[0];
		for (int i = 0; i < K; i++) {
			if (minfinish > window[i]) {
				minfinish = window[i];
				tempindex = i;
			}
		}
		if (window[tempindex] <= it->come) {
			window[tempindex] = it->come + it->time;
		}
		else {
			result = result + window[tempindex] - it->come;
			window[tempindex] += it->time;
		}
	}
	if (cus.size() == 0)
		cout << "0.0" << endl;
	else
		printf("%.1f", result / 60.0 / cus.size());
	return 0;
}