#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

void qry (int x, int y) {
	cout.flush() << '?' << ' ' << x << ' ' << y << '\n';
}

int main () {
	int n;
	cin >> n;
	int mx = -1;
	for (int i = 0; i < n; i++) {
		if (mx == n - 1) break;
		int lo = mx + 1, hi = n - 1;
		if (i > 0) {
			qry(i, mx + 1);
			int res;
			cin >> res;
			if (res == 0) continue;
		}
		while (lo <= hi) {
			int m = lo + (hi - lo)/2;
			qry(i, m);
			int res;
			cin >> res;
			if (res == 1) {
				mx = max(mx, m);
				lo = m + 1;
			} else {
				if (mx >= m - 1) break;
				hi = m - 1;
			}
		}
	}
	cout.flush() << "! " << mx + 1 << '\n';
}
