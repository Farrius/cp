#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m, q;
		cin >> n >> m >> q;
		vector<pair<int, pair<int, int>>> query;
		for (int i = 0; i < q; i++) {
			char c;
			int k, x;
			cin >> c >> k >> x;
			if (c == 'F') query.push_back(make_pair(0, make_pair(k, x)));
			else query.push_back(make_pair(1, make_pair(k, x)));
		}
		reverse(query.begin(), query.end());
		vector<bool> rows(n + 1), cols(m + 1);
		ll sol = 0, f = 0, c = 0;
		for (auto cur : query) {
			int t = cur.first;
			int k, x;
			tie(k, x) = cur.second;
			if (t == 0) {
				if (rows[k]) continue;
				rows[k] = true;
				sol += x * (m - c);
				f++;
			} else {
				if (cols[k]) continue;
				cols[k] = true;
				sol += x * (n - f);
				c++;
			}
		}
		cout << sol << '\n';
	}
}
