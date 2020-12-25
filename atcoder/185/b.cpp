#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n, m, t, cur_t = 0;
	cin >> n >> m >> t;
	int charge = n;
	pair<int, int> times[m];
	for  (int i = 0; i < m; i++) {
		cin >> times[i].first >> times[i].second;
	}
	sort(times, times + m);
	bool ok = true;
	for (auto cur : times) {
		int a, b;
		tie(a, b) = cur;
		int dist = a - cur_t;
		charge -= dist;
		if (charge <= 0) ok = false;
		charge = min(n, charge + (b - a));
		cur_t = b;
	}
	if (ok && charge > t - cur_t) cout << "Yes" << '\n';
	else cout << "No" << '\n';
}
