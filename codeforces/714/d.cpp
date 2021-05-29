#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, p;
		cin >> n >> p;
		int ar[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		vector<pair<int, int>> posis;
		for (int i = 0; i < n; i++) {
			posis.emplace_back(ar[i], i);
		}
		sort(posis.begin(), posis.end());
		vector<bool> vis(n);
		ll sol = 0;
		for (auto cur : posis) {
			int div, i;
			tie(div, i) = cur;
			if (div >= p) break;
			while (i > 0) {
				if (vis[i - 1]) break;
				if (ar[i - 1] % div == 0) {
					vis[i - 1] = true;
					i--;
					sol += div;
				} else {
					break;
				}
			}
			i = cur.second;
			while (i < n - 1) {
				if (vis[i]) break;
				if (ar[i + 1] % div == 0) {
					vis[i] = true;
					i++;
					sol += div;
				} else {
					break;
				}
			}
		}
		for (int i = 0; i < n - 1; i++) {
			if (vis[i]) continue;
			sol += p;
		}
		cout << sol << '\n';
	}
}
