#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

void qry (int a, int b) {
	cout.flush() << '?' << ' ' << a << ' ' << b << '\n';
}

int main () {
	int n;
	cin >> n;
	int lo = 0, hi = n - 1;
	char res;
	while (lo < hi) {
		int mid = (lo + hi)/2;
		qry(mid, mid + 1);
		cin >> res;
		if (res == '<') {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	cout << "! " << lo << '\n';
}
