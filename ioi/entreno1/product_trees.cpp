#include <bits/stdc++.h>

using namespace std;
using ld = long double;

ld power (ld n, int k) {
	ld res = 1;
	while (k) {
		if (k % 2) res *= n;
		n *= n;
		k /= 2;
	}
	return res;
}

int main () {
	int n;
	while (cin >> n) {
		if (n == 0) break;
		vector<ld> ar(n);
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		sort(ar.begin(), ar.end());
		ld tot = 1;
		int pw = 31 - __builtin_clz(n);
		int k = n - (1<<pw), i = 0;
		for (int j = k; j < n; j++) {
			if (i < k) {
				tot *= power(ar[i], pw + 2);
				tot *= power(ar[j], pw + 2);
				i++;
			} else {
				tot *= power(ar[j], pw + 1);
			}
		}
		cout << fixed << tot << '\n';
	}
}
