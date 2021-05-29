#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	int sol = 2e9;

	for (int msk = 0; msk < (1<<n); msk++) {
		vector<int> cur;
		int a = 0;
		for (int i = 0; i < n; i++) {
			a |= ar[i];
			if ((msk>>i) & 1) {
				cur.push_back(a);
				a = 0;
			}
		}
		cur.push_back(a);
		int b = 0;
		for (auto x : cur) b ^= x;
		sol = min(sol, b);
	}
	cout << sol << '\n';
}
