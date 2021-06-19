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
	vector<int> prv(n);
	stack<pair<int, int>> vis;
	for (int i = 0; i < n; i++) {
		while (!vis.empty() && vis.top().first >= ar[i]) vis.pop();
		if (vis.empty()) {
			prv[i] = 0;
		} else {
			prv[i] = vis.top().second + 1;
		}
		vis.push(make_pair(ar[i], i));
	}
	while (!vis.empty()) vis.pop();
	ll sol = 0;
	for (int i = n - 1; i >= 0; i--) {
		while (!vis.empty() && vis.top().first >= ar[i]) vis.pop();
		int j = 0;
		if (vis.empty()) {
			j = n - 1;
		} else {
			j = vis.top().second - 1;
		}
		vis.push(make_pair(ar[i], i));
		sol = max(sol, (j - prv[i] + 1) * 1LL * ar[i]);
	}
	cout << sol << '\n';
}

