#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	vector<int> ar(n);
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		ar[i] = ar[i] % 200;
	}
	vector<pair<int, int>> ops[200];
	for (int l = 0; l < n; l++) {
		int cur = 0;
		for (int r = l; r < n; r++) {
			cur += ar[r];
			cur %= 200;
			ops[cur].push_back(make_pair(l, r));
		}
	}
	for (int i = 0; i < 200; i++) {
		if ((int) ops[i].size() > 1) {
			cout << "Yes" << '\n';
			int l, r;
			tie(l, r) = ops[i][0];
			cout << r - l + 1 << ' ';
			for (int i = l; i <= r; i++) {
				cout << i + 1 << ' ';
			}
			cout << '\n';
			tie(l, r) = ops[i][1];
			cout << r - l + 1 << ' ';
			for (int i = l; i <= r; i++) {
				cout << i + 1 << ' ';
			}
			cout << '\n';
			return 0;
		}
	}
	cout << "No" << '\n';
}
