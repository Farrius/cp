#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const ll DIV = 1e5;

ll ceil (ll x, ll y) {
	return (x + y - 1)/y;
}

int main () {
	int t, m;
	cin >> t >> m;
	vector<bool> vis(m + 1);
	vector<int> sol(m + 1, -1);
	vis[0] = true;
	sol[0] = 0;
	for (int tt = 1; tt <= t; tt++) {
		int t, y;
		ll x;
		cin >> t >> x >> y;

		vector<bool> cur_vis = vis;
		auto op = [&] (ll &cur) {
			if (t == 1) {
				cur = cur + ceil(x, DIV);
			} else {
				cur = ceil(cur * x, DIV);
			}
		};

		for (int k = 0; k <= m; k++) {
			if (!vis[k]) continue;
			ll cur = k;
			op(cur);
			for (int a = 1; a <= y; a++) {
				if (cur > m || cur_vis[cur]) break;
				cur_vis[cur] = true;
				sol[cur] = tt;
				op(cur);
			}
		}
		vis = cur_vis;
	}

	for (int i = 1; i <= m; i++) {
		cout << sol[i] << (i == m ? '\n' : ' ');
	}
}
