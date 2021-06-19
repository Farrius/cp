#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e5 + 5;

int mx[MX], mn[MX], ar[MX];

int main () {
	freopen("art2.in", "r", stdin);
	freopen("art2.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> ar[i];
	}
	for (int i = 0; i <= n + 1; i++) {
		mn[i] = 1e9;
		mx[i] = -1;
	}
	ar[0] = ar[n + 1] = 0;
	for (int i = 0; i <= n + 1; i++) {
		mx[ar[i]] = max(mx[ar[i]], i);
		mn[ar[i]] = min(mn[ar[i]], i);
	}
	int sol = 0;
	stack<int> stck;
	for (int i = 0; i <= n + 1; i++) {
		int c = ar[i];
		if (i == mn[c]) {
			stck.push(c);
			sol = max(sol, (int) stck.size());
		}
		if (stck.top() != c) {
			cout << -1 << '\n';
			return 0;
		}
		if (i == mx[c]) {
			stck.pop();
		}
	}
	cout << sol - 1 << '\n';
}
