#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n, m;
	cin >> n >> m;
	int sol = 0;
	int ar[n];
	multiset<int> mex;
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		if (i < m) mex.insert(ar[i]);
	}
	int cur = 0;
	for (auto x : mex) {
		if (x > cur) {
			break;
		} else {
			if (x == cur) cur++;
		}
	}
	sol = cur;
	for (int i = m; i < n; i++) {
		mex.erase(mex.find(ar[i - m]));
		mex.insert(ar[i]);
		if (!mex.count(ar[i - m])) {
			sol = min(sol, ar[i - m]);
		}
	}
	cout << sol << '\n';
}
