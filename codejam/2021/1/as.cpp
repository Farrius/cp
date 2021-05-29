#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 105;

int n, ar[MX], sol;

int fn (int i) {
	int mn = 200, pos = -1;
	for (int j = i; j < n; j++) {
		if (ar[j] < mn) {
			mn = ar[j];
			pos = j;
		}
	}
	int val = pos - i + 1;
	while (i < pos) swap(ar[i++], ar[pos--]);
	return val;
}

int main () {
	int t;
	cin >> t;
	for (int tt = 0; tt < t; tt++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		sol = 0;
		for (int i = 0; i < n - 1; i++) {
			sol += fn(i);
		}
		cout << "Case #" << tt + 1 << ": " << sol << '\n';
	}
}
