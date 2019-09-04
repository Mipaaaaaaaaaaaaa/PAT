#include<iostream>
#include<iomanip>
using namespace std;

class Polynomials {
public:
	int exp;
	double coe;
	bool exs;
	Polynomials() {
		exp = 0;
		coe = 0;
		exs = false;
	}
	};

int main() {
	Polynomials a[12], b[12], c[22];
	int max = 0;
	int aN, bN;
	cin >> aN;
	for (int i = 0; i < aN; i++) {
		int k;
		double num;
		cin >> k >> num;
		a[i].exp = k;
		a[i].coe = num;
		a[i].exs = true;
	}
	cin >> bN;
	for (int i = 0; i < bN; i++) {
		int k;
		double num;
		cin >> k >> num;
		b[i].exp = k;
		b[i].coe = num;
		b[i].exs = true;
	}
	for (int i = 0, j = 0, k = 0; i < aN || j < bN ; ) {
		if (a[i].exp > b[j].exp) {
			c[k++] = a[i++];
			max = k;
		}
		else if (a[i].exp < b[j].exp) {
			c[k++] = b[j++];
			max = k;
		}
		else if (a[i].exp == b[j].exp && a[i].exs && b[j].exs ) {
			if (a[i].coe + b[j].coe != 0) {
				c[k].coe = a[i].coe + b[j].coe;
				c[k].exp = a[i].exp;
				c[k].exs = true;
				k++;
				max = k;
			}
			j++;
			i++;
		}
		else if (i >= aN && j < bN ) {
			c[k++] = b[j++];
			max = k;
		}
		else if (i < aN && j >= bN) {
			c[k++] = a[i++];
			max = k;
		}

		
	}
	cout << max;
	if (max != 0) {
		cout << " ";
	}
	for (int i = 0; i < max; i++) {
		cout << c[i].exp << " ";
		cout << setiosflags(ios::fixed) << setprecision(1) << c[i].coe;
		if (i != max-1) {
			cout << " ";
		}
	}
	return 0;
}